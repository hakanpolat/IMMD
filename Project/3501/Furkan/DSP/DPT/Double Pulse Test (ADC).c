#include "DSP2833x_Device.h"
#include "DSP2833x_CpuTimers.h"
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
// Prototype statements for functions found within this file.
void Gpio_select(void);
void InitSystem(void);
void SetADC(void);
void SetPWM(void);
// external function prototypes
extern void InitSysCtrl(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void InitCpuTimers(void);
extern void ConfigCpuTimer(struct CPUTIMER_VARS *, float, float);
extern void InitAdc(void);
// Global Variables
int DeadTimeClock = 500 / 6.667; // DeadTime = 100ns & Clock = 6.667ns
int GapTimeClock = 1500 / 6.667; // GapTime = 5us & Clock = 6.667ns
int LoadCurrent = 30;            // 30 Amps Inductor Current
double Inductance = 50 * 0.001; // 250 uH Inductance
int Voltage = 400;               // DC Voltage Level
int LEMvoltage = 0;
// Prototype statements for functions found within this file.
interrupt void xint1_isr(void);
interrupt void adc_isr(void);
//###########################################################################
//						main code									
//###########################################################################
void main(void)
{
 	InitSystem();	 	// Basic Core Initialization
	InitSysCtrl();      // Initialize System Control
	DINT;				// Disable all interrupts
	Gpio_select();      // Set GPIOs
    InitPieVectTable(); // Initialize PIE Vector Table
	InitPieCtrl();      // Initialize PIE Control
	IER = 0x0000;
	IFR = 0x0000;
	InitCpuTimers();    //Initialize Timers
    InitAdc();          //Initialize ADCs
    SetADC();           //Change configurations of ADC
    SetPWM();           //ADC trigger PWM is set

	EALLOW;
	PieVectTable.XINT1 = &xint1_isr;    // Re-mapped ISR
	PieVectTable.ADCINT = &adc_isr;
	EDIS;

	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;          // Enable the PIE block
	PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // Enable PIE Group 1 INT4
	PieCtrlRegs.PIEIER1.bit.INTx6 = 1;          // Enable ADCINT in PIE
	IER |= M_INT1;                              // Enable CPU int1
	EINT;                                       // Enable Global Interrupts

	EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;         // GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 0;          // input
    GpioCtrlRegs.GPAPUD.bit.GPIO2   = 1;        // Pull Up
    GpioCtrlRegs.GPAQSEL1.bit.GPIO2 = 2;        // Xint1 Synch to 6 samples
    GpioCtrlRegs.GPACTRL.bit.QUALPRD2 = 0xFF;   // Each sampling window is 510*SYSCLKOUT
    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 2;   // Xint1 is GPIO0
    EDIS;

    XIntruptRegs.XINT1CR.bit.POLARITY = 0;      // Falling edge interrupt
    XIntruptRegs.XINT1CR.bit.ENABLE = 1;        // Enable Xint1
    while(1)
    {
        GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
        GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;
    };
}
interrupt void adc_isr(void)
{
        LEMvoltage = AdcMirror.ADCRESULT0; // store results global
        GpioDataRegs.GPATOGGLE.bit.GPIO1 = 1;
        // Reinitialize for next ADC sequence
        AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;       // Reset SEQ1
        AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;     // Clear INT SEQ1 bit
        PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; // Acknowledge interrupt to PIE
}

interrupt void xint1_isr(void)
{
    //Code For DPT PWM

    double ChargeTime = Inductance*LoadCurrent/Voltage; // t=L*I/Vdc
    Uint32 ChargeTimeClock = ChargeTime * 150000000;    // Clock = Time/Tclock = Time*ClockFreq
    Uint32 WhileStop = ChargeTimeClock + GapTimeClock*2 + DeadTimeClock*5;
    int t1 = ChargeTimeClock;
    int t2 = t1 + DeadTimeClock;
    int t3 = t1 + GapTimeClock;
    int t4 = t3 + DeadTimeClock;
    int t5 = t4 + 3*DeadTimeClock/5;
    Uint32 temp = 0;
    LEMvoltage = 0;
    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;   // Reset Sequencer
    AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;   // Start Conversion*/
    CpuTimer0Regs.TCR.bit.TSS = 0;  //Timer 0 Starts
    while (1)
    {   temp = 0xFFFFFFFF - CpuTimer0Regs.TIM.all;
        if (temp <= t1)
        {
            GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;    // GPIO32 is cleared
            GpioDataRegs.GPBSET.bit.GPIO34 = 1;      // GPIO34 is set

        }
        else if(temp <= t2)
        {
            GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;   // GPIO34 is cleared
            GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;   // GPIO32 is cleared

        }
        else if(temp <= t3)
        {
            GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;   //GPIO34 is cleared
            GpioDataRegs.GPBSET.bit.GPIO32 = 1;     //GPIO32 is set

        }
        else if(temp <= t4)
        {
            GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;     //GPIO32 is cleared
            GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;   //GPIO34 is cleared

        }
        else if(temp <= t5)
        {
            GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;     //GPIO32 is cleared
            GpioDataRegs.GPBSET.bit.GPIO34 = 1;   //GPIO34 is set
        }
        else
        {
            GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;   // GPIO34 is cleared
            GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;   // GPIO32 is cleared
            break;
        }
    }
    GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;   // GPIO34 is cleared
    GpioDataRegs.GPBCLEAR.bit.GPIO32 = 1;   // GPIO32 is cleared
    AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 0;       // Halts Conversion
    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;       // Reset Sequencer*/
    CpuTimer0Regs.TCR.bit.TSS = 1;          // Timer 0 Stops
    CpuTimer0Regs.TCR.bit.TRB = 1;          // Reload Period Value
    // Protection
    CpuTimer0Regs.TCR.bit.TSS = 0;          // Timer Starts
    while (CpuTimer0Regs.TIM.all >= 0xD34BE87F) // Waits 5 secs to have next interrupt
    {
        asm("None");
    }
    CpuTimer0Regs.TCR.bit.TSS = 1;          // Timer 0 Stops
    CpuTimer0Regs.TCR.bit.TRB = 1;          // Reload Period Value
    // Acknowledge this interrupt to get more from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

void Gpio_select(void)
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.all = 0x00000000;	// GPIO15 ... GPIO0 = General Purpose I/O
	GpioCtrlRegs.GPAMUX2.all = 0x00000000;	// GPIO31 ... GPIO16 = General Purpose I/O
	GpioCtrlRegs.GPBMUX1.all = 0x00000000;	// GPIO47 ... GPIO32 = General Purpose I/O
	GpioCtrlRegs.GPBMUX2.all = 0x00000000;	// GPIO63 ... GPIO48 = General Purpose I/O
	GpioCtrlRegs.GPCMUX1.all = 0x00000000;	// GPIO79 ... GPIO64 = General Purpose I/O
	GpioCtrlRegs.GPCMUX2.all = 0x00000000;	// GPIO87 ... GPIO80 = General Purpose I/O
    GpioCtrlRegs.GPADIR.all = 0x00000000;
    GpioCtrlRegs.GPBDIR.all = 0x00000000;
	GpioCtrlRegs.GPCDIR.all = 0x00000000;


    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;        // GPIO
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;         // output
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;        // GPIO
    GpioCtrlRegs.GPBDIR.bit.GPIO32 = 1;         // output
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;
	EDIS;
}   

void InitSystem(void)
{
	EALLOW; // Enables some core registers of CPU
    //SysCtrlRegs.SCSR = 0x5;
	SysCtrlRegs.WDCR = 0xA8;
	SysCtrlRegs.PLLSTS.bit.DIVSEL = 2;
	SysCtrlRegs.PLLCR.bit.DIV = 10;
	SysCtrlRegs.HISPCP.all = 0x0001;
   	SysCtrlRegs.LOSPCP.all = 0x0002;
	SysCtrlRegs.PCLKCR0.all = 0x0000;
	SysCtrlRegs.PCLKCR1.all = 0x0000;
	SysCtrlRegs.PCLKCR3.all = 0x0000;
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;
    EDIS; // Disables some core registers of CPU
}

void SetADC(void)
{
    AdcRegs.ADCTRL1.all = 0;
    AdcRegs.ADCTRL1.bit.ACQ_PS = 7;     // 7 = 8 x ADCCLK
    AdcRegs.ADCTRL1.bit.SEQ_CASC =1;    // 1=cascaded sequencer
    AdcRegs.ADCTRL1.bit.CPS = 0;        // divide by 1
    AdcRegs.ADCTRL1.bit.CONT_RUN = 0;   // single run mode

    AdcRegs.ADCTRL2.all = 0;
    AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1;   // 1=enable SEQ1 interrupt
    AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 =1;  // 1=SEQ1 start from ePWM_SOCA trigger
    AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1 = 0;   // 0= interrupt after every end of sequence

    AdcRegs.ADCTRL3.bit.ADCCLKPS = 3;   // ADC clock: FCLK = HSPCLK / 2 * ADCCLKPS
                                        // HSPCLK = 75MHz (see DSP2833x_SysCtrl.c)
                                        // FCLK = 12.5 MHz

    AdcRegs.ADCMAXCONV.all = 0x0000;    // 1 conversion from Sequencer 1
    AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0; // Setup ADCINA0 as 1st SEQ1 conv.
}

void SetPWM(void)
{
    EPwm2Regs.TBCTL.all = 0xC030;    // Configure timer control register
        /*
         bit 15-14     11:     FREE/SOFT, 11 = ignore emulation suspend
         bit 13        0:      PHSDIR, 0 = count down after sync event
         bit 12-10     000:    CLKDIV, 000 => TBCLK = HSPCLK/1
         bit 9-7       000:    HSPCLKDIV, 000 => HSPCLK = SYSCLKOUT/1
         bit 6         0:      SWFSYNC, 0 = no software sync produced
         bit 5-4       11:     SYNCOSEL, 11 = sync-out disabled
         bit 3         0:      PRDLD, 0 = reload PRD on counter=0
         bit 2         0:      PHSEN, 0 = phase control disabled
         bit 1-0       00:     CTRMODE, 00 = count up mode
        */

        EPwm2Regs.TBPRD = 150; // TPPRD +1  =  TPWM / (HSPCLKDIV * CLKDIV * TSYSCLK)
                                //           =  100 ns / 6.667 ns

        EPwm2Regs.ETPS.all = 0x0100;            // Configure ADC start by ePWM2
        /*
         bit 15-14     00:     EPWMxSOCB, read-only
         bit 13-12     00:     SOCBPRD, don't care
         bit 11-10     00:     EPWMxSOCA, read-only
         bit 9-8       01:     SOCAPRD, 01 = generate SOCA on first event
         bit 7-4       0000:   reserved
         bit 3-2       00:     INTCNT, don't care
         bit 1-0       00:     INTPRD, don't care
        */

        EPwm2Regs.ETSEL.all = 0x0A00;           // Enable SOCA to ADC
        /*
         bit 15        0:      SOCBEN, 0 = disable SOCB
         bit 14-12     000:    SOCBSEL, don't care
         bit 11        1:      SOCAEN, 1 = enable SOCA
         bit 10-8      010:    SOCASEL, 010 = SOCA on PRD event
         bit 7-4       0000:   reserved
         bit 3         0:      INTEN, 0 = disable interrupt
         bit 2-0       000:    INTSEL, don't care
        */
}


//===========================================================================
// End of SourceCode.
//===========================================================================
