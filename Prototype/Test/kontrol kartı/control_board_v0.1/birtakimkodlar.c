// Single-phase PWM rectifier closed loop control code
// 2-level - interleaved
// phase shifted pwm
// 3.5 kW
// the code includes the following control blocks:
// 1. single phase PLL
// 2. Vdc PI controller
// 3. Reference current generation
// 4. Is1 PI controller
// 5. Is2 PI controller
// 6. Vs feedforward
// 7. Single-phase phase shifted unipolar PWM
// ePWM1&2 are for converter 1
// ePWM3&4 are for converter 2
// ePWM5 is for PLL
// ePWM3 is synched with ePWM1 by 90 degrees
// ePWM4 is synched with ePWM2 by 90 degrees

#include "DSP2833x_Device.h"
#include "math.h"
#include "IQmathLib.h"
#include "park_macro.h"
#include "loopfil_macro.h"
#include "osg_macro.h"
#include "pi_macro.h"
#pragma DATA_SECTION(sine_table,"IQmathTables");
_iq30 sine_table[512];
#define pi 3.141592654				// pi
#define grid_freq 50
#define D 4095					// ADC conversion
float out_buffer1[400]; // Buffer for graph-1
float out_buffer2[400]; // Buffer for graph-2
const short BUFFERLENGTH = 400; // Size of buffer
short i = 0; // buffer counter
float fsw1 = 20000;
float fsw = 1000;
unsigned int endeks = 0;
float Ts = 0;
float Ts1 = 0;
float adc_chan_0; // Vs1
float adc_chan_1; // Is1
float adc_chan_2; // Is2
float adc_chan_3; // Vdc
float adc_chan_4; // Vs2

unsigned int flag = 0;

// control.1.
float vs[3];
float valfa[3];
float vbeta[3];
float vd[2];
float vq[2];
float vpi[2];
float theta[2];
float wout;
float ws;
float vsin[2];
float vcos[2];
float error;
float Vs1;

// control.2.
float Vdc1;
float Vdc;
float Yv[2];
float Ev;

// control.3.
float Idc;
float Is1ref;
float Is2ref;

// control.4.
float Is1;
float Is11;
float Is2;
float Is22;
float Yi1[2];
float Ei1;
float Yi2[2];
float Ei2;

// control.5.
float Vs2;
float Vs;
float Iout1;
float Vmod1;
float Iout2;
float Vmod2;

// control.6.
float theta1 = 0;
float theta_upd = 0;
float Vdc_ref = 700;
float Vmod11 = 0;
float Vmod12 = 0;
float Vmod21 = 0;
float Vmod22 = 0;
float duty_a1 = 0;
float duty_b1 = 0;
float duty_a2 = 0;
float duty_b2 = 0;

OSG_MACRO osg1 = OSG_MACRO_DEFAULTS;
PARK_MACRO park1 = PARK_MACRO_DEFAULTS;
LOOPFIL_MACRO loopfil1 = LOOPFIL_MACRO_DEFAULTS;
PI_MACRO pi1 = PI_MACRO_DEFAULTS;

extern void InitPieCtrl(void);
extern void InitSysCtrl(void);
extern void InitPieVectTable(void);
extern void InitCpuTimers(void);
extern void InitAdc(void);
extern void ConfigCpuTimer(struct CPUTIMER_VARS *, float, float);
interrupt void cpu_timer0_isr(void);
interrupt void adc1_isr(void);
interrupt void adc2_isr(void);
interrupt void ePWM1A_compare_isr(void);
interrupt void ePWM5A_compare_isr(void);
void Gpio_select(void);
void Setup_ePWM(void);
void Setup_ADC(void);
void main(void)
{
	// system initialization
	InitSysCtrl();	 	// Basic Core Initialization
	EALLOW;
	SysCtrlRegs.WDCR = 0x00AF; // re-enable the watchdog
	EDIS;
	DINT;				// Disable all interrupts
	Gpio_select();		// GPIO9,GPIO11,GPIO34 and GPIO49 as output
	Setup_ePWM();		// ePWM
	InitPieCtrl();		// basic setup of pie table; from DSP2833x_PieCtrl.c
	InitPieVectTable(); // default ISR's in PIE
	InitAdc();
	Setup_ADC();		// ADC setup
	EALLOW;
	PieVectTable.TINT0 = &cpu_timer0_isr;
	PieVectTable.SEQ1INT = &adc1_isr;
	PieVectTable.SEQ2INT = &adc2_isr;
	PieVectTable.EPWM1_INT = &ePWM1A_compare_isr;
	PieVectTable.EPWM5_INT = &ePWM5A_compare_isr;
	EDIS;
	InitCpuTimers();	// basic setup CPU Timer0,1,2
	ConfigCpuTimer(&CpuTimer0, 150, 50);    // CPU - Timer0 at 100 usec
	PieCtrlRegs.PIEIER1.bit.INTx7 = 1;		 // cpu timer0
	PieCtrlRegs.PIEIER1.bit.INTx1 = 1;		 // adc1 (seq1 - pwm)
	PieCtrlRegs.PIEIER1.bit.INTx2 = 1;		 // adc2 (seq2 - pll)
	PieCtrlRegs.PIEIER3.bit.INTx1 = 1;		 // epwm1
	PieCtrlRegs.PIEIER3.bit.INTx5 = 1;		 // epwm5
	IER |= 5;
	EINT;
	ERTM;
	CpuTimer0Regs.TCR.bit.TSS = 0; // start Timer0
	Ts = 1/fsw;
	Ts1 = 1/fsw1;
	ws = 2*pi*grid_freq;
	osg1.k = 0.5;
	osg1.ws = ws;
	osg1.Ts = Ts1;
	loopfil1.loopfil_Kp = 10;
	loopfil1.loopfil_Ki = 27755.55;
	loopfil1.loopfil_Ts = 0.00002;
	loopfil1.loopfil_uplim = 128;
	loopfil1.loopfil_botlim	= -128;
	OSG_MACRO_PARAM(osg1);
	while(1)
	{
		if (AdcRegs.ADCST.bit.INT_SEQ1 == 1) // ADC seq1 interrupt for pwm (at prd)
		{
			// control start
			/// use theta information from pll @ 20 kHz

			// Vdc PI controller start
			// DC link voltage reading
			Vdc1 = (3.068*adc_chan_3)/(D*3.65*0.001);
			pi1.Kp = 0.02; //1
			pi1.Ki = 0.005; //1
			pi1.upperlim = 30;
			pi1.lowerlim = 0;
			pi1.Uset = Vdc_ref;
			pi1.Uin = Vdc1;
			pi1.error[1] = Ev;
			pi1.Yout[1] = Yv[1];
			PI_MACRO_MACRO(pi1);
			Ev = pi1.error[1];			// error[n-1]
			Yv[1] = pi1.Yout[1];		// output[n-1]
			Yv[0] = pi1.Yout[0];		// output[n]
			// Vdc PI controller end

			// Reference current generation start
			Idc = Yv[0]*0.6; //0.3
			Is1ref = Idc*vsin[0];
			Is2ref = Idc*vsin[0];
			// Reference current generation end

			// Is1 PI controller start
			// Secondary1 current reading
			Is1 = adc_chan_1-2180;
			//Is11 = Is1*3.1/(67.175*0.001*D); // Cp'ye göre
			Is11 = Is1*3.1/(133.223*0.001*D); // Cs1'e göre
			pi1.Kp = 5; //10
			pi1.Ki = 10; //40
			pi1.upperlim = 200; //100
			pi1.lowerlim = -200; //-100
			pi1.Uset = Is11;
			pi1.Uin = Is1ref;
			pi1.error[1] = Ei1;
			pi1.Yout[1] = Yi1[1];
			PI_MACRO_MACRO(pi1);
			Ei1 = pi1.error[1];			// error[n-1]
			Yi1[1] = pi1.Yout[1];		// output[n-1]
			Yi1[0] = pi1.Yout[0];		// output[n]
			// Is1 PI controller end

			// Vs feedforward start for converter 1
			// grid voltage reading
			Vs = adc_chan_0-2180;
			Vs2 = Vs*3.17/(2.5*0.001*D); /////////////// (2.5 olacak)-old:3.253
			Iout1 = 1*Yi1[0]; //1*Yi[0]
			Vmod1 = Iout1+Vs2;
			// Vs feedforward end

			// Single-phase unipolar PWM start for converter 1
			Vmod11 = Vmod1;
			Vmod12 = -Vmod1;
			duty_a1 = 1-((Vmod11+Vdc_ref)/(2*Vdc_ref));
			duty_b1 = 1-((Vmod12+Vdc_ref)/(2*Vdc_ref));
			// Single-phase unipolar PWM end

			// Is2 PI controller start
			// Secondary2 current reading
			Is2 = adc_chan_2-2180;
			//Is11 = Is1*3.1/(67.175*0.001*D); // Cp'ye göre
			Is22 = Is2*3.1/(133.223*0.001*D); // Cs2'ye göre
			pi1.Kp = 5; //10
			pi1.Ki = 10; //40
			pi1.upperlim = 200; //100
			pi1.lowerlim = -200; //-100
			pi1.Uset = Is22;
			pi1.Uin = Is2ref;
			pi1.error[1] = Ei2;
			pi1.Yout[1] = Yi2[1];
			PI_MACRO_MACRO(pi1);
			Ei2 = pi1.error[1];			// error[n-1]
			Yi2[1] = pi1.Yout[1];		// output[n-1]
			Yi2[0] = pi1.Yout[0];		// output[n]
			// Is1 PI controller end

			// Vs feedforward start for converter 2
			// grid voltage reading
			Vs = adc_chan_0-2180;
			Vs2 = Vs*3.17/(2.5*0.001*D); /////////////// (2.5 olacak)-old:3.253
			Iout2 = 1*Yi2[0]; //1*Yi[0]
			Vmod2 = Iout2+Vs2;
			// Vs feedforward end

			// Single-phase unipolar PWM start for converter 2
			Vmod21 = Vmod2;
			Vmod22 = -Vmod2;
			duty_a2 = 1-((Vmod21+Vdc_ref)/(2*Vdc_ref));
			duty_b2 = 1-((Vmod22+Vdc_ref)/(2*Vdc_ref));
			// Single-phase unipolar PWM end

			// update ePWM
			EPwm1Regs.CMPA.half.CMPA = EPwm1Regs.TBPRD*duty_a1;
			EPwm2Regs.CMPA.half.CMPA = EPwm2Regs.TBPRD*duty_b1;

			// control end

			AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;
		}

		if (AdcRegs.ADCST.bit.INT_SEQ2 == 1) // ADC seq2 interrupt for pll (at prd)
		{
			EALLOW;
			SysCtrlRegs.WDKEY = 0x55; // service WD #1
			EDIS;
			// PLL start
			// grid voltage reading
			Vs = adc_chan_4-2180;
			Vs1 = Vs*3.17/(2.5*0.001*D); /////////////// (2.5 olacak)-old:3.253
			if (endeks < 3)
			{
				vs[endeks] = Vs1;
			}
			else
			{
				vs[0] = Vs1;
				osg1.vs[0] = vs[0];
				osg1.vs[1] = vs[1];
				osg1.vs[2] = vs[2];
				OSG_MACRO_MACRO(osg1);
				valfa[0] = osg1.valfa[0];
				valfa[1] = osg1.valfa[1];
				valfa[2] = osg1.valfa[2];
				vbeta[0] = osg1.vbeta[0];
				vbeta[1] = osg1.vbeta[1];
				vbeta[2] = osg1.vbeta[2];
				park1.valfa[0] = valfa[0];
				park1.valfa[1] = valfa[1];
				park1.valfa[2] = valfa[2];
				park1.vbeta[0] = vbeta[0];
				park1.vbeta[1] = vbeta[1];
				park1.vbeta[2] = vbeta[2];
				park1.vcos[0] = vcos[0];
				park1.vcos[1] = vcos[1];
				park1.vsin[0] = vsin[0];
				park1.vsin[1] = vsin[1];
				PARK_MACRO_MACRO(park1);
				vd[0] = park1.vd;
				vq[0] = park1.vq;
				loopfil1.vq[0] = vq[0];
				loopfil1.vq[1] = vq[1];
				LOOPFIL_MACRO_MACRO(loopfil1);
				vpi[0] = loopfil1.vpi[0];
				vpi[1] = loopfil1.vpi[1];
				vd[1] = vd[0];
				vq[1] = vq[0];
				wout = grid_freq + vpi[0];
				theta[0] = theta[1] + wout*Ts1;
				if (theta[0] > 1)
					theta[0] = 0;
				theta[1] = theta[0];
				vsin[0] = sin(theta[0]*2*pi);
				vcos[0] = cos(theta[0]*2*pi);
				vsin[1] = vsin[0];
				vcos[1] = vcos[0];
				error = vs[0] - vsin[0];
				vs[2] = vs[1];
				vs[1] = vs[0];
			}
			endeks += 1;
			if (endeks > 2)
				endeks = 4;
			// PLL end

			AdcRegs.ADCST.bit.INT_SEQ2_CLR = 1;
		}

		if (EPwm1Regs.ETFLG.bit.INT == 1)	// epwm interrupt for pwm of second converter (at prd)
		{
			flag = 1;
			EPwm3Regs.CMPA.half.CMPA = EPwm3Regs.TBPRD*duty_a2;
			EPwm4Regs.CMPA.half.CMPA = EPwm4Regs.TBPRD*duty_b2;
			EPwm1Regs.ETCLR.bit.INT = 1;
		}

		if (EPwm5Regs.ETFLG.bit.INT == 1)
		{
			EPwm5Regs.ETCLR.bit.INT = 1;
		}
	}
}
void Gpio_select(void)
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.all = 0;		// GPIO15 ... GPIO00 = General Purpose I/O
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1; // activate epwm1a
	GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1; // activate epwm1b
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1; // activate epwm2a
	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1; // activate epwm2b
	GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1; // activate epwm3a
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1; // activate epwm3b
	GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1; // activate epwm4a
	GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1; // activate epwm4b
	GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1; // activate epwm5a
	GpioCtrlRegs.GPAMUX2.all = 0;		// GPIO31 ... GPIO16 = General Purpose I/O
	GpioCtrlRegs.GPBMUX1.all = 0;		// GPIO47 ... GPIO32 = General Purpose I/O
	GpioCtrlRegs.GPBMUX2.all = 0;		// GPIO63 ... GPIO48 = General Purpose I/O
	GpioCtrlRegs.GPCMUX1.all = 0;		// GPIO79 ... GPIO64 = General Purpose I/O
	GpioCtrlRegs.GPCMUX2.all = 0;		// GPIO87 ... GPIO80 = General Purpose I/O
	GpioCtrlRegs.GPADIR.all = 0;
	GpioCtrlRegs.GPBDIR.all = 0;		// GPIO63-32 as inputs
	GpioCtrlRegs.GPCDIR.all = 0;		// GPIO87-64 as inputs
	EDIS;
}
void Setup_ePWM(void)
{
	// for pwm of converter 1
	// leg-1
	EPwm1Regs.TBCTL.bit.CLKDIV = 0;		// CLKDIV = 1
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = 1;	// HSCLKDIV = 2
	EPwm1Regs.TBCTL.bit.CTRMODE = 2; 	// up down mode
	EPwm1Regs.TBCTL.bit.SYNCOSEL = 1; 	// syncout if ctr = 0
	EPwm1Regs.AQCTLA.all = 0x00060; 	// zero = set; period = clear
	EPwm1Regs.TBPRD = 37500;			    // 1 kHz PWM signal (37500)
	EPwm1Regs.CMPA.half.CMPA = 0;		// 100% duty cycle first
	EPwm1Regs.CMPB = 18750;				// for phase shift (90 degrees)
	EPwm1Regs.ETPS.all = 0x0000;		// Configure ADC start by ePWM1
	EPwm1Regs.ETPS.bit.SOCAPRD = 1;		// 01 = generate SOCA on first event
	EPwm1Regs.ETPS.bit.INTPRD = 1;		// 01 = interrupt on first event
	EPwm1Regs.ETSEL.all = 0x0000;		// Enable SOCA to ADC
	EPwm1Regs.ETSEL.bit.SOCAEN = 1;		// 1 = enable SOCA
	EPwm1Regs.ETSEL.bit.SOCASEL = 2;	// 010 = SOCA on PRD event
	EPwm1Regs.ETSEL.bit.INTEN = 1;		// Enable EPWM1INT
	EPwm1Regs.ETSEL.bit.INTSEL = 7;		// 001 = Interrupt on Zero Event
	EPwm1Regs.DBRED = 1500;				// 10 microseconds delay
	EPwm1Regs.DBFED = 1500;				// for rising and falling edge
	EPwm1Regs.DBCTL.bit.OUT_MODE = 3;	// ePWM1A = RED
	EPwm1Regs.DBCTL.bit.POLSEL = 2;		// S3=1 inverted signal at ePWM1B
	EPwm1Regs.DBCTL.bit.IN_MODE = 0;	// ePWM1A = source for RED & FED

	// leg-2
	EPwm2Regs.TBCTL.bit.CLKDIV = 0;		// CLKDIV = 1
	EPwm2Regs.TBCTL.bit.HSPCLKDIV = 1;	// HSCLKDIV = 2
	EPwm2Regs.TBCTL.bit.CTRMODE = 2; 	// up down mode
	EPwm2Regs.AQCTLA.all = 0x00060; 	// set ePWM2A on CMPA down, clear ePWM2A on CMPA up
	EPwm2Regs.TBPRD = 37500;		    // 1 kHz PWM signal
	EPwm2Regs.CMPA.half.CMPA = 0;		// 100% duty cycle first
	EPwm2Regs.DBRED = 1500;				// 10 microseconds delay
	EPwm2Regs.DBFED = 1500;				// for rising and falling edge
	EPwm2Regs.DBCTL.bit.OUT_MODE = 3;	// ePWM1A = RED
	EPwm2Regs.DBCTL.bit.POLSEL = 2;		// S3=1 inverted signal at ePWM1B
	EPwm2Regs.DBCTL.bit.IN_MODE = 0;	// ePWM1A = source for RED & FED


	// for pwm of converter 2
	// leg-1
	EPwm3Regs.TBCTL.bit.CLKDIV = 0;		// CLKDIV = 1
	EPwm3Regs.TBCTL.bit.HSPCLKDIV = 1;	// HSCLKDIV = 2
	EPwm3Regs.TBCTL.bit.CTRMODE = 2; 	// up down mode
	EPwm3Regs.TBCTL.bit.PHSEN = 1; 		// enable phase shift for ePWM3
	EPwm3Regs.TBCTL.bit.SYNCOSEL = 0; 	// syncin = syncout
	EPwm3Regs.TBPHS.half.TBPHS = 18750;	// 90 degrees phase shift
	EPwm3Regs.AQCTLA.all = 0x00060; 	// zero = set; period = clear
	EPwm3Regs.TBPRD = 37500;			// 1 kHz PWM signal (37500)
	EPwm3Regs.CMPA.half.CMPA = 0;		// 100% duty cycle first
	EPwm3Regs.DBRED = 1500;				// 10 microseconds delay
	EPwm3Regs.DBFED = 1500;				// for rising and falling edge
	EPwm3Regs.DBCTL.bit.OUT_MODE = 3;	// ePWM1A = RED
	EPwm3Regs.DBCTL.bit.POLSEL = 2;		// S3=1 inverted signal at ePWM1B
	EPwm3Regs.DBCTL.bit.IN_MODE = 0;	// ePWM1A = source for RED & FED

	// leg-2
	EPwm4Regs.TBCTL.bit.CLKDIV = 0;		// CLKDIV = 1
	EPwm4Regs.TBCTL.bit.HSPCLKDIV = 1;	// HSCLKDIV = 2
	EPwm4Regs.TBCTL.bit.CTRMODE = 2; 	// up down mode
	EPwm4Regs.TBCTL.bit.PHSEN = 1; 		// enable phase shift for ePWM3
	EPwm4Regs.TBCTL.bit.SYNCOSEL = 0; 	// syncin = syncout
	EPwm4Regs.TBPHS.half.TBPHS = 18750;	// 90 degrees phase shift
	EPwm4Regs.AQCTLA.all = 0x00060; 	// set ePWM2A on CMPA down, clear ePWM2A on CMPA up
	EPwm4Regs.TBPRD = 37500;		    // 1 kHz PWM signal
	EPwm4Regs.CMPA.half.CMPA = 0;		// 100% duty cycle first
	EPwm4Regs.DBRED = 1500;				// 10 microseconds delay
	EPwm4Regs.DBFED = 1500;				// for rising and falling edge
	EPwm4Regs.DBCTL.bit.OUT_MODE = 3;	// ePWM1A = RED
	EPwm4Regs.DBCTL.bit.POLSEL = 2;		// S3=1 inverted signal at ePWM1B
	EPwm4Regs.DBCTL.bit.IN_MODE = 0;	// ePWM1A = source for RED & FED

	// for pll
	EPwm5Regs.TBCTL.bit.CLKDIV = 0;		// CLKDIV = 1
	EPwm5Regs.TBCTL.bit.HSPCLKDIV = 0;	// HSCLKDIV = 2
	EPwm5Regs.TBCTL.bit.CTRMODE = 2; 	// up down mode
	EPwm5Regs.AQCTLA.all = 0x00060; 	// zero = set; period = clear
	EPwm5Regs.TBPRD = 3750;			    // 20 kHz
	EPwm5Regs.CMPA.half.CMPA = 0;		// 100% duty cycle first
	EPwm5Regs.ETPS.all = 0x0000;		// Configure ADC start by ePWM1
	EPwm5Regs.ETPS.bit.SOCBPRD = 1;		// 01 = generate SOCA on first event
	EPwm5Regs.ETPS.bit.INTPRD = 1;		// 01 = interrupt on first event
	EPwm5Regs.ETSEL.all = 0x0000;		// Enable SOCA to ADC
	EPwm5Regs.ETSEL.bit.SOCBEN = 1;		// 1 = enable SOCB
	EPwm5Regs.ETSEL.bit.SOCBSEL = 2;	// 010 = SOCB on PRD event
	EPwm5Regs.ETSEL.bit.INTEN = 1;		// Enable EPWM3INT
	EPwm5Regs.ETSEL.bit.INTSEL = 1;		// 001 = Interrupt on Zero Event
}

void Setup_ADC(void)
{
	AdcRegs.ADCREFSEL.bit.REF_SEL = 0;
	AdcRegs.ADCTRL1.all = 0;
	AdcRegs.ADCTRL1.bit.SEQ_CASC = 0;		// dual sequentier mode
	AdcRegs.ADCTRL1.bit.CONT_RUN = 0;		// single run mode
	AdcRegs.ADCTRL1.bit.ACQ_PS = 7;			// 8 X ADC clock
	AdcRegs.ADCTRL1.bit.CPS = 0;			// divide by 1
	AdcRegs.ADCTRL2.all = 0;

	// clear SOC flags
	AdcRegs.ADCTRL2.bit.SOC_SEQ1=0;
	AdcRegs.ADCTRL2.bit.SOC_SEQ2=0;

	// for pwm
	AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;	// ePWM_SOCA trigger (start of sequence)
	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1;	// enable ADC int for seq1
	AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1 = 0;	// interrupt after every EOS (end of sequence)
	// for pll
	AdcRegs.ADCTRL2.bit.EPWM_SOCB_SEQ2 = 1;	// ePWM_SOCB trigger (start of sequence)
	AdcRegs.ADCTRL2.bit.INT_ENA_SEQ2 = 1;	// enable ADC int for seq1
	AdcRegs.ADCTRL2.bit.INT_MOD_SEQ2 = 0;	// interrupt after every EOS (end of sequence)
	AdcRegs.ADCTRL3.bit.ADCCLKPS = 3;		// set FCLK to 12.5 MHz

	AdcRegs.ADCMAXCONV.bit.MAX_CONV1 = 3;
	AdcRegs.ADCMAXCONV.bit.MAX_CONV2 = 0;
	AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0;  // ADCINA0 - Vs
	AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 1;  // ADCINA1 - Is1
	AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 2;  // ADCINA2 - Is2
	AdcRegs.ADCCHSELSEQ1.bit.CONV03 = 3;  // ADCINA3 - Vdc
	AdcRegs.ADCCHSELSEQ3.bit.CONV08 = 8;  // ADCINB0 - Vs
}
interrupt void cpu_timer0_isr(void)
{
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
interrupt void adc1_isr(void)
{
	adc_chan_0 = AdcMirror.ADCRESULT0;		// vs
	adc_chan_1 = AdcMirror.ADCRESULT1;		// is1
	adc_chan_2 = AdcMirror.ADCRESULT2;		// is2
	adc_chan_3 = AdcMirror.ADCRESULT3;		// vdc
	AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1; 		// reset adc sequencer1
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; // acknowledge pie interrupt
}
interrupt void adc2_isr(void)
{
	adc_chan_4 = AdcMirror.ADCRESULT8;		// vs
	EALLOW;
	SysCtrlRegs.WDKEY = 0xAA; // servide WD #2
	EDIS;
	AdcRegs.ADCTRL2.bit.RST_SEQ2 = 1; 		// reset adc sequencer2
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; // acknowledge pie interrupt
}
interrupt void ePWM1A_compare_isr(void)
{
	PieCtrlRegs.PIEACK.all = 4;
}
interrupt void ePWM5A_compare_isr(void)
{
	out_buffer1[i] = Vs1;
	out_buffer2[i] = theta[0];
	//out_buffer1[i] = Is11;
	//out_buffer2[i] = Is22;
	i++;
	if (i == BUFFERLENGTH) i=0;
	PieCtrlRegs.PIEACK.all = 4;
}







// TI File $Revision: /main/2 $
// Checkin $Date: December 7, 2011   18:17:57 $
//###########################################################################
//
// FILE:    Example_posspeed.h
//
// TITLE:   Pos/speed measurement using EQEP peripheral
//
// DESCRIPTION:
//
// Header file containing data type and object definitions and
// initializers.
//
//###########################################################################
// Original Author: SD
//
// $TI Release: F2837xD Support Library v100 $
// $Release Date: Mon Dec  9 12:58:09 CST 2013 $
//###########################################################################

#ifndef __POSSPEED__
#define __POSSPEED__

#include "IQmathLib.h"         // Include header for IQmath library
/*-----------------------------------------------------------------------------
Define the structure of the POSSPEED Object
-----------------------------------------------------------------------------*/
typedef struct {int theta_elec;         // Output: Motor Electrical angle (Q15)
                int theta_mech;         // Output: Motor Mechanical Angle (Q15)
                int DirectionQep;       // Output: Motor rotation direction (Q0)
                int QEP_cnt_idx;        // Variable: Encoder counter index (Q0)
                int theta_raw;          // Variable: Raw angle from Timer 2 (Q0)
                int mech_scaler;        // Parameter: 0.9999/total count, total count = 4000 (Q26)
                int pole_pairs;         // Parameter: Number of pole pairs (Q0)
                int cal_angle;          // Parameter: Raw angular offset between encoder and phase a (Q0)
                int index_sync_flag;    // Output: Index sync status (Q0)

                Uint32 SpeedScaler;     // Parameter :  Scaler converting 1/N cycles to a GLOBAL_Q speed (Q0) - independently with global Q
                _iq Speed_pr;           // Output :  speed in per-unit
                Uint32 BaseRpm;         // Parameter : Scaler converting GLOBAL_Q speed to rpm (Q0) speed - independently with global Q
                int32 SpeedRpm_pr;      // Output : speed in r.p.m. (Q0) - independently with global Q

                _iq  oldpos;            // Input: Electrical angle (pu)
                _iq Speed_fr;           // Output :  speed in per-unit
                int32 SpeedRpm_fr;      // Output : Speed in rpm  (Q0) - independently with global Q
                void (*init)();         // Pointer to the init funcion
                void (*calc)();         // Pointer to the calc funtion
                }  POSSPEED;

/*-----------------------------------------------------------------------------
Define a POSSPEED_handle
-----------------------------------------------------------------------------*/
typedef POSSPEED *POSSPEED_handle;

/*-----------------------------------------------------------------------------
Default initializer for the POSSPEED Object.
-----------------------------------------------------------------------------*/
  #define POSSPEED_DEFAULTS {0x0, 0x0,0x0,0x0,0x0,16776,2,0,0x0,\
        250,0,6000,0,\
        0,0,0,\
        (void (*)(long))POSSPEED_Init,\
        (void (*)(long))POSSPEED_Calc }


/*-----------------------------------------------------------------------------
Prototypes for the functions in posspeed.c
-----------------------------------------------------------------------------*/
void POSSPEED_Init(void);
void POSSPEED_Calc(POSSPEED_handle);

#endif /*  __POSSPEED__ */






//###########################################################################
//
// FILE:	Example_EpwmSetup.c
//
// TITLE:	Pos speed measurement using EQEP peripheral
//
// DESCRIPTION:
//
// This file contains source for the ePWM initialization for the
// pos/speed module
//
//###########################################################################
// Original Author: SD
//
// $TI Release: F2837xD Support Library v100 $
// $Release Date: Mon Dec  9 12:58:09 CST 2013 $
//###########################################################################

#include "F28x_Project.h"     // Device Headerfile and Examples Include File
#include "Example_posspeed.h"   // Example specific Include file

#define TB_CLK   100e6

#define PWM_CLK   5e3              // 5kHz (300rpm) EPWM1 frequency. Freq. can be changed here
#define SP        TB_CLK/(2*PWM_CLK)
#define TBCTLVAL  0x200A           // up-down count, timebase=SYSCLKOUT

void initEpwm()
{
	EPwm1Regs.TBSTS.all=0;
	EPwm1Regs.TBPHS.half.TBPHS =0;
	EPwm1Regs.TBCTR=0;

	EPwm1Regs.CMPCTL.all=0x50;     // immediate mode for CMPA and CMPB
	EPwm1Regs.CMPA.half.CMPA=SP/2;
	EPwm1Regs.CMPB.all=0;

	EPwm1Regs.AQCTLA.all=0x60;     // CTR=CMPA when inc->EPWM1A=1, when dec->EPWM1A=0
	EPwm1Regs.AQCTLB.all=0x09;     // CTR=PRD ->EPWM1B=1, CTR=0 ->EPWM1B=0
	EPwm1Regs.AQSFRC.all=0;
	EPwm1Regs.AQCSFRC.all=0;

	EPwm1Regs.TZSEL.all=0;
	EPwm1Regs.TZCTL.all=0;
	EPwm1Regs.TZEINT.all=0;
	EPwm1Regs.TZFLG.all=0;
	EPwm1Regs.TZCLR.all=0;
	EPwm1Regs.TZFRC.all=0;

	EPwm1Regs.ETSEL.all=0x0A;      // Interrupt on PRD
	EPwm1Regs.ETPS.all=1;
	EPwm1Regs.ETFLG.all=0;
	EPwm1Regs.ETCLR.all=0;
	EPwm1Regs.ETFRC.all=0;

	EPwm1Regs.PCCTL.all=0;

	EPwm1Regs.TBCTL.all=0x0010+TBCTLVAL; // Enable Timer
	EPwm1Regs.TBPRD=SP;
}







//###########################################################################
//
// FILE:    Example_posspeed.c
//
// TITLE:   Pos/speed measurement using EQEP peripheral
//
// DESCRIPTION:
//
// This file includes the EQEP initialization and position and speed calculation
// functions called by Eqep_posspeed.c.  The position and
// speed calculation steps performed by POSSPEED_Calc() at  SYSCLKOUT =  200 MHz are described below:
//
//
// 1. This program calculates: **theta_mech**
//
//    theta_mech = QPOSCNT/mech_Scaler = QPOSCNT/4000, where 4000 is the number of
//                 counts in 1 revolution.(4000/4 = 1000 line/rev. quadrature encoder)
//
// 2. This program calculates: **theta_elec**
//
//    theta_elec = (# pole pairs) * theta_mech = 2*QPOSCNT/4000 for this example
//
// 3. This program calculates: **SpeedRpm_fr**
//
//    SpeedRpm_fr = [(x2-x1)/4000]/T                                             - Equation 1
//    Note (x2-x1) = difference in number of QPOSCNT counts. Dividing (x2-x1) by
//    4000 gives position relative to Index in one revolution.
// If base RPM  = 6000 rpm:   6000 rpm = [(x2-x1)/4000]/10ms                     - Equation 2
//                                     = [(x2-x1)/4000]/(.01s*1 min/60 sec)
//                                     = [(x2-x1)/4000]/(1/6000) min
//                         max (x2-x1) = 4000 counts, or 1 revolution in 10 ms
//
//
// If both sides of Equation 2 are divided by 6000 rpm, then:
//                            1 = [(x2-x1)/4000] rev./[(1/6000) min * 6000rpm]
//                          Because (x2-x1) must be <4000 (max) for QPOSCNT increment,
//                          (x2-x1)/4000 < 1 for CW rotation
//                          And because (x2-x1) must be >-4000 for QPOSCNT decrement,
//                          (x2-x1)/4000>-1  for CCW rotation
//                          speed_fr = [(x2-x1)/4000]/[(1/6000) min * 6000rpm]
//                                   = (x2-x1)/4000                              - Equation 3
//
// To convert speed_fr to RPM, multiply Equation 3 by 6000 rpm
//                           SpeedRpm_fr = 6000rpm *(x2-x1)/4000                 - Final Equation
//
//
// 2. **min rpm ** = selected at 10 rpm based on CCPS prescaler options available (128 is greatest)
//
// 3. **SpeedRpm_pr**
//    SpeedRpm_pr = X/(t2-t1)                                                    - Equation 4
//    where X = QCAPCTL [UPPS]/4000 rev. (position relative to Index in 1 revolution)
// If  max/base speed = 6000 rpm:
//               6000 = (32/4000)/[(t2-t1)/(200MHz/64)]
//           where 32 = QCAPCTL [UPPS] (Unit timeout - once every 32 edges)
//            32/4000 = position in 1 revolution (position as a fraction of 1 revolution)
//   t2-t1/(200MHz/64), t2-t1= # of QCAPCLK cycles, and
//      QCAPCLK cycle = 1/(200MHz/64)
//                    = QCPRDLAT
//
// So:       6000 rpm = [32(200MHz/64)*60s/min]/[4000(t2-t1)]
//              t2-t1 = [32(200MHz/64)*60s/min]/(4000*6000rpm)           - Equation 5
//                    = 250 CAPCLK cycles = maximum (t2-t1) = SpeedScaler
//
// Divide both sides by (t2-t1), and:
//            1 = 32/(t2-t1) = [32(200MHz/64)*60 s/min]/(4000*6000rpm)]/(t2-t1)
//       Because (t2-t1) must be < 250 for QPOSCNT increment:
//               250/(t2-t1) < 1 for CW rotation
//       And because (t2-t1) must be >-250 for QPOSCNT decrement:
//                250/(t2-t1)> -1 for CCW rotation
//
//       eed_pr = 250/(t2-t1)
//             or [32(200MHz/64)*60 s/min]/(4000*6000rpm)]/(t2-t1)  - Equation 6
//
// To convert speed_pr to RPM:
// Multiply Equation 6 by 6000rpm:
// SpeedRpm_fr  = 6000rpm * [32(200MHz/64)*60 s/min]/[4000*6000rpm*(t2-t1)]
//              = [32(200MHz/64)*60 s/min]/[4000*(t2-t1)]
//              or [(32/4000)rev * 60 s/min]/[(t2-t1)(QCPRDLAT)]- Final Equation
//
//
// More detailed calculation results can be found in the Example_freqcal.xls
// spreadsheet included in the example folder.
//
//
//
// This file contains source for the posspeed module
//
//###########################################################################
// Original Author: SD
//
// $TI Release: F2837xD Support Library v100 $
// $Release Date: Mon Dec  9 12:58:09 CST 2013 $
//###########################################################################

#include "F28x_Project.h"     // Device Headerfile and Examples Include File
#include "Example_posspeed.h"   // Example specific Include file

void  POSSPEED_Init(void)
{

    EQep1Regs.QUPRD=2000000;         // Unit Timer for 100Hz at 200 MHz SYSCLKOUT

    EQep1Regs.QDECCTL.bit.QSRC=00;      // QEP quadrature count mode

    EQep1Regs.QEPCTL.bit.FREE_SOFT=2;
    EQep1Regs.QEPCTL.bit.PCRM=00;       // PCRM=00 mode - QPOSCNT reset on index event
    EQep1Regs.QEPCTL.bit.UTE=1;         // Unit Timeout Enable
    EQep1Regs.QEPCTL.bit.QCLM=1;        // Latch on unit time out
    EQep1Regs.QPOSMAX=0xffffffff;
    EQep1Regs.QEPCTL.bit.QPEN=1;        // QEP enable

    EQep1Regs.QCAPCTL.bit.UPPS=5;       // 1/32 for unit position
    EQep1Regs.QCAPCTL.bit.CCPS=6;       // 1/64 for CAP clock
    EQep1Regs.QCAPCTL.bit.CEN=1;        // QEP Capture Enable


}

void POSSPEED_Calc(POSSPEED *p)
{
     long tmp;
     unsigned int pos16bval,temp1;
     _iq Tmp1,newp,oldp;

//**** Position calculation - mechanical and electrical motor angle  ****//
     p->DirectionQep = EQep1Regs.QEPSTS.bit.QDF;    // Motor direction: 0=CCW/reverse, 1=CW/forward

     pos16bval=(unsigned int)EQep1Regs.QPOSCNT;     // capture position once per QA/QB period
     p->theta_raw = pos16bval+ p->cal_angle;        // raw theta = current pos. + ang. offset from QA

     // The following lines calculate p->theta_mech ~= QPOSCNT/mech_scaler [current cnt/(total cnt in 1 rev.)]
     // where mech_scaler = 4000 cnts/revolution
     tmp = (long)((long)p->theta_raw*(long)p->mech_scaler);     // Q0*Q26 = Q26
     tmp &= 0x03FFF000;
     p->theta_mech = (int)(tmp>>11);                // Q26 -> Q15
     p->theta_mech &= 0x7FFF;

     // The following lines calculate p->elec_mech
     p->theta_elec = p->pole_pairs*p->theta_mech;  // Q0*Q15 = Q15
     p->theta_elec &= 0x7FFF;

// Check an index occurrence
     if (EQep1Regs.QFLG.bit.IEL == 1)
     {
        p->index_sync_flag = 0x00F0;
        EQep1Regs.QCLR.bit.IEL=1;                   // Clear __interrupt flag
     }


//**** High Speed Calculation using QEP Position counter ****//
// Check unit Time out-event for speed calculation:
// Unit Timer is configured for 100Hz in INIT function

    if(EQep1Regs.QFLG.bit.UTO==1)                    // If unit timeout (one 100Hz period)
    {
        /** Differentiator  **/
        // The following lines calculate position = (x2-x1)/4000 (position in 1 revolution)
        pos16bval=(unsigned int)EQep1Regs.QPOSLAT;                // Latched POSCNT value
        tmp = (long)((long)pos16bval*(long)p->mech_scaler);       // Q0*Q26 = Q26
        tmp &= 0x03FFF000;
        tmp = (int)(tmp>>11);                                     // Q26 -> Q15
        tmp &= 0x7FFF;
        newp=_IQ15toIQ(tmp);
        oldp=p->oldpos;

        if (p->DirectionQep==0)                     // POSCNT is counting down
        {
            if (newp>oldp)
                Tmp1 = - (_IQ(1) - newp + oldp);    // x2-x1 should be negative
            else
            Tmp1 = newp -oldp;
        }
        else if (p->DirectionQep==1)                // POSCNT is counting up
        {
            if (newp<oldp)
            Tmp1 = _IQ(1) + newp - oldp;
            else
            Tmp1 = newp - oldp;                     // x2-x1 should be positive
        }

        if (Tmp1>_IQ(1))
            p->Speed_fr = _IQ(1);
        else if (Tmp1<_IQ(-1))
            p->Speed_fr = _IQ(-1);
        else
            p->Speed_fr = Tmp1;

        // Update the electrical angle
        p->oldpos = newp;

        // Change motor speed from pu value to rpm value (Q15 -> Q0)
        // Q0 = Q0*GLOBAL_Q => _IQXmpy(), X = GLOBAL_Q
        p->SpeedRpm_fr = _IQmpy(p->BaseRpm,p->Speed_fr);
        //=======================================

        EQep1Regs.QCLR.bit.UTO=1;                   // Clear __interrupt flag
    }

//**** Low-speed computation using QEP capture counter ****//
    if(EQep1Regs.QEPSTS.bit.UPEVNT==1)                 // Unit position event
    {
        if(EQep1Regs.QEPSTS.bit.COEF==0)               // No Capture overflow
            temp1=(unsigned long)EQep1Regs.QCPRDLAT;   // temp1 = t2-t1
        else                                           // Capture overflow, saturate the result
            temp1=0xFFFF;

        p->Speed_pr = _IQdiv(p->SpeedScaler,temp1);    // p->Speed_pr = p->SpeedScaler/temp1
        Tmp1=p->Speed_pr;

        if (Tmp1>_IQ(1))
            p->Speed_pr = _IQ(1);
        else
            p->Speed_pr = Tmp1;

        // Convert p->Speed_pr to RPM
        if (p->DirectionQep==0)                                 // Reverse direction = negative
            p->SpeedRpm_pr = -_IQmpy(p->BaseRpm,p->Speed_pr);   // Q0 = Q0*GLOBAL_Q => _IQXmpy(), X = GLOBAL_Q
        else                                                    // Forward direction = positive
            p->SpeedRpm_pr = _IQmpy(p->BaseRpm,p->Speed_pr);    // Q0 = Q0*GLOBAL_Q => _IQXmpy(), X = GLOBAL_Q


        EQep1Regs.QEPSTS.all=0x88;                  // Clear Unit position event flag
                                                    // Clear overflow error flag
    }

}






//###########################################################################
// FILE:	Eqep_pos_speed.c
// TITLE:	EQEP Speed and Position measurement
//
//! \addtogroup cpu01_example_list
//! <h1>EQEP Speed and Position Measurement</h1>
//!
//! This example provides position measurement,speed measurement using the
//! capture unit, and speed measurement using unit time out. This example
//! uses the IQMath library. It is used merely to simplify high-precision
//! calculations.
//! The example requires the following hardware connections from EPWM1 and
//! GPIO pins (simulating QEP sensor) to QEP peripheral.
//!    - GPIO20/eQEP1A <- GPIO0/ePWM1A (simulates eQEP Phase A signal)
//!    - GPIO21/eQEP1B <- GPIO1/ePWM1B (simulates eQEP Phase B signal)
//!    - GPIO23/eQEP1I <- GPIO4 (simulates eQEP Index Signal)
//! See DESCRIPTION in Example_posspeed.c for more details on the calculations
//! performed in this example.
//! In addition to this file, the following files must be included in this project:
//!    - Example_posspeed.c - includes all eQEP functions
//!    - Example_EPwmSetup.c - sets up ePWM1A and ePWM1B as simulated QA and QB
//!                            encoder signals
//!    - Example_posspeed.h - includes initialization values for pos and speed structure
//!
//! Note:
//!    - Maximum speed is configured to 6000rpm(BaseRpm)
//!    - Minimum speed is assumed at 10rpm for capture pre-scalar selection
//!    - Pole pair is configured to 2 (pole_pairs)
//!    - QEP Encoder resolution is configured to 4000counts/revolution (mech_scaler)
//!    - which means: 4000/4 = 1000 line/revolution quadrature encoder (simulated by EPWM1)
//!    - EPWM1 (simulating QEP encoder signals) is configured for 5kHz frequency or 300 rpm
//!      (=4*5000 cnts/sec * 60 sec/min)/4000 cnts/rev)
//!    - SPEEDRPM_FR: High Speed Measurement is obtained by counting the QEP input pulses
//!                   for 10ms (unit timer set to 100Hz).
//!    - SPEEDRPM_FR = (Position Delta/10ms) * 60 rpm
//!    - SPEEDRPM_PR: Low Speed Measurement is obtained by measuring time period of QEP edges.
//!                   Time measurement is averaged over 64edges for better results and
//!                   capture unit performs the time measurement using pre-scaled SYSCLK
//!    - pre-scaler for capture unit clock is selected such that capture timer does not
//!      overflow at the required minimum RPM speed.
//!
//! \b External \b Connections \n
//!   - Connect eQEP1A(GPIO20) to ePWM1A(GPIO0)(simulates eQEP Phase A signal)
//!   - Connect eQEP1B(GPIO21) to ePWM1B(GPIO1)(simulates eQEP Phase B signal)
//!   - Connect eQEP1I(GPIO23) to GPIO4 (simulates eQEP Index Signal)
//!
//! \b Watch \b Variables \n
//!  - qep_posspeed.SpeedRpm_fr - Speed meas. in rpm using QEP position counter
//!  - qep_posspeed.SpeedRpm_pr - Speed meas. in rpm using capture unit
//!  - qep_posspeed.theta_mech  - Motor mechanical angle (Q15)
//!  - qep_posspeed.theta_elec  - Motor electrical angle (Q15)
//
//###########################################################################
// $TI Release: F2837xD Support Library v100 $
// $Release Date: Mon Dec  9 12:58:09 CST 2013 $
//###########################################################################

#include "F28x_Project.h"     // Device Headerfile and Examples Include File
#include "Example_posspeed.h"   // Example specific Include file

void initEpwm();
__interrupt void prdTick(void);

POSSPEED qep_posspeed=POSSPEED_DEFAULTS;
Uint16 Interrupt_Count = 0;

void main(void)
{

// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the F2837xD_SysCtrl.c file.
   InitSysCtrl();
// Step 2. Initialize GPIO:
// This example function is found in the F2837xD_Gpio.c file and
// illustrates how to set the GPIO to its default state.
// InitGpio();  // Skipped for this example

// For this case only init GPIO for eQEP1 and ePWM1
// This function is found in F2837xD_EQep.c
   InitEQep1Gpio();
   InitEPwm1Gpio();
   EALLOW;
   GpioCtrlRegs.GPADIR.bit.GPIO4 = 1;    // GPIO4 as output simulates Index signal
   GpioDataRegs.GPACLEAR.bit.GPIO4 = 1;  // Normally low
   EDIS;
// Step 3. Clear all __interrupts and initialize PIE vector table:
// Disable CPU __interrupts
   DINT;

// Initialize the PIE control registers to their default state.
// The default state is all PIE __interrupts disabled and flags
// are cleared.
// This function is found in the F2837xD_PieCtrl.c file.
   InitPieCtrl();

// Disable CPU __interrupts and clear all CPU __interrupt flags:
   IER = 0x0000;
   IFR = 0x0000;

// Initialize the PIE vector table with pointers to the shell Interrupt
// Service Routines (ISR).
// This will populate the entire table, even if the __interrupt
// is not used in this example.  This is useful for debug purposes.
// The shell ISR routines are found in F2837xD_DefaultIsr.c.
// This function is found in F2837xD_PieVect.c.
   InitPieVectTable();

// Interrupts that are used in this example are re-mapped to
// ISR functions found within this file.
   EALLOW;  // This is needed to write to EALLOW protected registers
   PieVectTable.EPWM1_INT= &prdTick;
   EDIS;    // This is needed to disable write to EALLOW protected registers

// Step 4. Initialize all the Device Peripherals:
   initEpwm();  // This function exists in Example_EPwmSetup.c

// Step 5. User specific code, enable __interrupts:
// Enable CPU INT1 which is connected to CPU-Timer 0:
   IER |= M_INT3;

// Enable TINT0 in the PIE: Group 3 __interrupt 1
   PieCtrlRegs.PIEIER3.bit.INTx1 = 1;

// Enable global Interrupts and higher priority real-time debug events:
   EINT;   // Enable Global __interrupt INTM
   ERTM;   // Enable Global realtime __interrupt DBGM

   qep_posspeed.init(&qep_posspeed);

	for(;;)
	{
	}

}

__interrupt void prdTick(void)                  // EPWM1 Interrupts once every 4 QCLK counts (one period)
{  Uint16 i;
   // Position and Speed measurement
   qep_posspeed.calc(&qep_posspeed);

   // Control loop code for position control & Speed control
   Interrupt_Count++;
   if (Interrupt_Count==1000)                 // Every 1000 __interrupts(4000 QCLK counts or 1 rev.)
   {
       EALLOW;
       GpioDataRegs.GPASET.bit.GPIO4 = 1;     // Pulse Index signal  (1 pulse/rev.)
       for (i=0; i<700; i++){
       }
       GpioDataRegs.GPACLEAR.bit.GPIO4 = 1;
	   Interrupt_Count = 0;                   // Reset count
	   EDIS;
   }

   // Acknowledge this __interrupt to receive more __interrupts from group 1
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
   EPwm1Regs.ETCLR.bit.INT=1;
}



