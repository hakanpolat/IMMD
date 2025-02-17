/*
 * sinusWithOUTPotsAndDeadBand.c
 *
 *  Created on: Oct 3, 2018
 *      Author: ROG
 */


#include "DSP2833x_Device.h"
#include <math.h>
# define PI 3.14159265358979323846  /* pi */
/////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                               //
////////////////////////////////////////////////////////////////////////////////////////////   //
                                                                                          //   //
 long switchingFrequency=40000;// = 48000;      // switching frequency in Hz                       //   //
                                                                                          //   //
 float fundamentalSinusoidalFrequency = 50;  // sinusoidal output frequency in Hz        //   //
                                                                                          //   //
 double phaseAngle = 0;   // starting angle of sinus                                       //   //
                                                                                          //   //
 float fundamentalSinusoidalMagnitude = 0.9;//Peaktopeak Value of output sinus waveform     //   //

 long RisingEdgeDelay = 15;         // Rising Edge Delay = TTBCLK x DBRED(=RisingEdgeDelay)

 long FallingEdgeDelay = 15;        // Falling Edge Delay = TTBCLK x DBFED(=FallingEdgeDelay)
                                    // TTBCLK = 13.3333ns to give 666ns delay we can use that number

 ///////////////////////////////////////////////////////////////////////////////////////////   //
                                                                                               //
 ////////////////////////////////////////////////////////////////////////////////////////////////
 long deviceClockFrequency = 150000000; // f28335 clock frequency in hz

 float maximumDeviceVoltage = 1;  // This is scaled to 1

 int cmp_phaseA;
 int cmp_phaseB;
 int cmp_phaseC;

 double counter = 0;

 double frequencyModulationRatio =0;
 float magnitudeModulationRatio = 0;

 float sinus=0;
 float sinus2=0;
 float sinus3=0;
 int CLKDIV = 1;
 int HSPCLKDIV = 1;

 float voltage_vr1;
 float voltage_vr2;
 float voltage_vr3;
 float voltage_vr4;

// Prototype statements for functions found within this file.
void Gpio_select(void);
extern void InitSysCtrl(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
interrupt void ePWMA_compare_isr(void);
void Setup_ePWM(void);
extern void display_ADC(unsigned int);
extern void InitAdc(void);
interrupt void adc_isr(void);

//###########################################################################
//                      main code
//###########################################################################

void main(void)
{



    InitSysCtrl();      // Basic Core Initialization
        EALLOW;
        SysCtrlRegs.WDCR = 0x00AF;
        EDIS;

        DINT;               // Disable all interrupts

        Gpio_select();      // GPIO9,GPIO11,GPIO34 and GPIO49 as output (LEDs @ peripheral explorer)
        Setup_ePWM();
        InitPieCtrl();

        InitPieVectTable();

        InitAdc();

        AdcRegs.ADCTRL1.all = 0;
        AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;   // cascaded Sequencer Mode
        AdcRegs.ADCTRL1.bit.CONT_RUN = 0;   // Single Run Mode
        AdcRegs.ADCTRL1.bit.ACQ_PS = 7;     // 8 x ADC-Clock
        AdcRegs.ADCTRL1.bit.CPS = 0;        // divide by 1

        AdcRegs.ADCTRL2.all = 0;
        AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;     // ePWM_SOCA trigger
        AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1; // enable ADC int for seq1
        AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1 = 0; // interrupt after every EOS

        AdcRegs.ADCTRL3.bit.ADCCLKPS = 3;       // set FCLK to 12.5 MHz
        AdcRegs.ADCMAXCONV.all = 0x0000; // 4 conversions

        //AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0; // 1st channel ADCINA0 //current A phase measurement
        //AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 1; // 2nd channel ADCINA1   //current B phase measurement
        //AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 2;          //current C phase measurement

        GpioDataRegs.GPASET.bit.GPIO12 = 1;
        GpioDataRegs.GPASET.bit.GPIO13 = 1;
        GpioDataRegs.GPASET.bit.GPIO14 = 1;
        GpioDataRegs.GPASET.bit.GPIO15 = 1;
        GpioDataRegs.GPASET.bit.GPIO16 = 1;
        GpioDataRegs.GPASET.bit.GPIO17 = 1;

        EALLOW;
        PieVectTable.EPWM1_INT = &ePWMA_compare_isr;
        PieVectTable.ADCINT = &adc_isr;
        EDIS;

        PieCtrlRegs.PIEIER1.bit.INTx6 = 1;
        PieCtrlRegs.PIEIER3.bit.INTx1 = 1;

        IER |= 5;
        EINT;
        ERTM;


        while(1)
        {
                //EALLOW;
                //SysCtrlRegs.WDKEY = 0x55;   // service WD #1
                //EDIS;
        }

}


void Gpio_select(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0;       // GPIO15 ... GPIO0 = General Puropse I/O
//    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1; // ePWM1A active
//    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1; // ePWM1B active
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1; // ePWM1A active  A Phase
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1; // ePWM1B active
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1; // ePWM2A active
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1; // ePWM2B active  B Phase
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1; // ePWM3A active  C Phase
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1; // ePWM3B active
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1; // ePWM4A active
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1; // ePWM4B active
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1; // ePWM5A active
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1; // ePWM5B active
    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1; // ePWM6A active
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1; // ePWM6B active

    GpioCtrlRegs.GPAMUX2.all = 0;       // GPIO31 ... GPIO16 = General Purpose I/O
    GpioCtrlRegs.GPBMUX1.all = 0;       // GPIO47 ... GPIO32 = General Purpose I/O
    GpioCtrlRegs.GPBMUX2.all = 0;       // GPIO63 ... GPIO48 = General Purpose I/O
    GpioCtrlRegs.GPCMUX1.all = 0;       // GPIO79 ... GPIO64 = General Purpose I/O
    GpioCtrlRegs.GPCMUX2.all = 0;       // GPIO87 ... GPIO80 = General Purpose I/O

    GpioCtrlRegs.GPADIR.all = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;  // enable
    GpioCtrlRegs.GPADIR.bit.GPIO13 = 1;  // enable
    GpioCtrlRegs.GPADIR.bit.GPIO14 = 1; // enable
    GpioCtrlRegs.GPADIR.bit.GPIO15 = 1;  // enable
    GpioCtrlRegs.GPADIR.bit.GPIO16 = 1;  // enable
    GpioCtrlRegs.GPADIR.bit.GPIO17 = 1; // enable

    GpioCtrlRegs.GPBDIR.all = 0;        // GPIO63-32 as inputs
    GpioCtrlRegs.GPCDIR.all = 0;        // GPIO87-64 as inputs
    EDIS;
}


void Setup_ePWM(void){

    EPwm1Regs.TBPRD = (0.5 * deviceClockFrequency) / (switchingFrequency * CLKDIV * HSPCLKDIV);
    EPwm2Regs.TBPRD = (0.5 * deviceClockFrequency) / (switchingFrequency * CLKDIV * HSPCLKDIV);        //the maximum number for TBPRD is (216 -1) or 65535
    EPwm3Regs.TBPRD = (0.5 * deviceClockFrequency) / (switchingFrequency * CLKDIV * HSPCLKDIV);
    EPwm4Regs.TBPRD = (0.5 * deviceClockFrequency) / (switchingFrequency * CLKDIV * HSPCLKDIV);
    EPwm5Regs.TBPRD = (0.5 * deviceClockFrequency) / (switchingFrequency * CLKDIV * HSPCLKDIV);
    EPwm6Regs.TBPRD = (0.5 * deviceClockFrequency) / (switchingFrequency * CLKDIV * HSPCLKDIV);

    EPwm1Regs.TBCTL.all = 0;
    EPwm1Regs.TBCTL.bit.CLKDIV = 0;
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 0;
    EPwm1Regs.TBCTL.bit.CTRMODE = 2;         // Count up and down operation (10) = 2
    EPwm1Regs.TBCTL.bit.SYNCOSEL = 1;   // generate a syncout if CTR = 0
    EPwm1Regs.AQCTLA.all = 0x0060;          //set ePWM1A to 1 on �CMPA - up match�//clear ePWM1A on event �CMPA - down match�
    EPwm1Regs.AQCTLB.all = 0x0090;         //clear ePWM1B on �CMPA - up match�//set ePWM1B to 1 on event �CMPA - down match� // we made reverse action to obtain complementary wave
    EPwm1Regs.DBRED = RisingEdgeDelay;                  // Rising Edge Delay = TTBCLK x DBRED
    EPwm1Regs.DBFED = FallingEdgeDelay;                  // Falling Edge Delay = TTBCLK x DBFED// TTBCLK = 13.3333ns to give 666ns delay we can use that number
    EPwm1Regs.DBCTL.all = 0x0000;          // S5 = S4 = S2 = 0    S0 = S1 = S3 = 1  RED & FED active also Active high complementary mode also PWMxA is source for RED and FED
    EPwm1Regs.DBCTL.bit.POLSEL = 2;
    EPwm1Regs.DBCTL.bit.IN_MODE = 0;
    EPwm1Regs.DBCTL.bit.OUT_MODE = 3;

    EPwm1Regs.ETSEL.all = 0;
    EPwm1Regs.ETSEL.bit.INTEN = 1;      // interrupt enable for ePWM1
    EPwm1Regs.ETSEL.bit.INTSEL = 1;     // interrupt on CMPA up match
    EPwm1Regs.ETPS.all = 0;
    EPwm1Regs.ETPS.bit.INTPRD = 1;      // interrupt on first event

    EPwm2Regs.TBCTL.all = 0;
    EPwm2Regs.TBCTL.bit.CLKDIV = 0;
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = 0;
    EPwm2Regs.TBCTL.bit.CTRMODE = 2;         // Count up and down operation (10) = 2
    EPwm2Regs.TBCTL.bit.PHSEN = 1;
    EPwm2Regs.TBPHS.half.TBPHS = 0;
    EPwm2Regs.AQCTLA.all = 0x0060;          //set ePWM1A to 1 on �CMPA - up match�//clear ePWM1A on event �CMPA - down match�
    EPwm2Regs.AQCTLB.all = 0x0090;         //clear ePWM1B on �CMPA - up match�//set ePWM1B to 1 on event �CMPA - down match� // we made reverse action to obtain complementary wave
    EPwm2Regs.DBRED = RisingEdgeDelay;                  // Rising Edge Delay = TTBCLK x DBRED
    EPwm2Regs.DBFED = FallingEdgeDelay;                  // Falling Edge Delay = TTBCLK x DBFED// TTBCLK = 13.3333ns to give 666ns delay we can use that number
    EPwm2Regs.DBCTL.all = 0x0000;          // S5 = S4 = S2 = 0    S0 = S1 = S3 = 1  RED & FED active also Active high complementary mode also PWMxA is source for RED and FED
    EPwm2Regs.DBCTL.bit.POLSEL = 2;
    EPwm2Regs.DBCTL.bit.IN_MODE = 0;
    EPwm2Regs.DBCTL.bit.OUT_MODE = 3;

    EPwm3Regs.TBCTL.all = 0;
    EPwm3Regs.TBCTL.bit.CLKDIV = 0;
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = 0;
    EPwm3Regs.TBCTL.bit.CTRMODE = 2;         // Count up and down operation (10) = 2
    EPwm3Regs.TBCTL.bit.PHSEN = 1;
    EPwm3Regs.TBPHS.half.TBPHS = 0;
    EPwm3Regs.AQCTLA.all = 0x0060;          //set ePWM1A to 1 on �CMPA - up match�//clear ePWM1A on event �CMPA - down match�
    EPwm3Regs.AQCTLB.all = 0x0090;         //clear ePWM1B on �CMPA - up match�//set ePWM1B to 1 on event �CMPA - down match� // we made reverse action to obtain complementary wave
    EPwm3Regs.DBRED = RisingEdgeDelay;                  // Rising Edge Delay = TTBCLK x DBRED
    EPwm3Regs.DBFED = FallingEdgeDelay;                  // Falling Edge Delay = TTBCLK x DBFED// TTBCLK = 13.3333ns to give 666ns delay we can use that number
    EPwm3Regs.DBCTL.all = 0x0000;          // S5 = S4 = S2 = 0    S0 = S1 = S3 = 1  RED & FED active also Active high complementary mode also PWMxA is source for RED and FED
    EPwm3Regs.DBCTL.bit.POLSEL = 2;
    EPwm3Regs.DBCTL.bit.IN_MODE = 0;
    EPwm3Regs.DBCTL.bit.OUT_MODE = 3;

    EPwm4Regs.TBCTL.all = 0;
    EPwm4Regs.TBCTL.bit.CLKDIV = 0;
    EPwm4Regs.TBCTL.bit.HSPCLKDIV = 0;
    EPwm4Regs.TBCTL.bit.CTRMODE = 2;         // Count up and down operation (10) = 2
    EPwm4Regs.TBCTL.bit.PHSEN = 1;
    EPwm4Regs.TBPHS.half.TBPHS = EPwm1Regs.TBPRD;
    EPwm4Regs.AQCTLA.all = 0x0060;          //set ePWM1A to 1 on �CMPA - up match�//clear ePWM1A on event �CMPA - down match�
    EPwm4Regs.AQCTLB.all = 0x0090;         //clear ePWM1B on �CMPA - up match�//set ePWM1B to 1 on event �CMPA - down match� // we made reverse action to obtain complementary wave
    EPwm4Regs.DBRED = RisingEdgeDelay;                  // Rising Edge Delay = TTBCLK x DBRED
    EPwm4Regs.DBFED = FallingEdgeDelay;                  // Falling Edge Delay = TTBCLK x DBFED// TTBCLK = 13.3333ns to give 666ns delay we can use that number
    EPwm4Regs.DBCTL.all = 0x0000;          // S5 = S4 = S2 = 0    S0 = S1 = S3 = 1  RED & FED active also Active high complementary mode also PWMxA is source for RED and FED
    EPwm4Regs.DBCTL.bit.POLSEL = 2;
    EPwm4Regs.DBCTL.bit.IN_MODE = 0;
    EPwm4Regs.DBCTL.bit.OUT_MODE = 3;

    EPwm5Regs.TBCTL.all = 0;
    EPwm5Regs.TBCTL.bit.CLKDIV = 0;
    EPwm5Regs.TBCTL.bit.HSPCLKDIV = 0;
    EPwm5Regs.TBCTL.bit.CTRMODE = 2;         // Count up and down operation (10) = 2
    EPwm5Regs.TBCTL.bit.PHSEN = 1;
    EPwm5Regs.TBPHS.half.TBPHS = EPwm1Regs.TBPRD;
    EPwm5Regs.AQCTLA.all = 0x0060;          //set ePWM1A to 1 on �CMPA - up match�//clear ePWM1A on event �CMPA - down match�
    EPwm5Regs.AQCTLB.all = 0x0090;         //clear ePWM1B on �CMPA - up match�//set ePWM1B to 1 on event �CMPA - down match� // we made reverse action to obtain complementary wave
    EPwm5Regs.DBRED = RisingEdgeDelay;                  // Rising Edge Delay = TTBCLK x DBRED
    EPwm5Regs.DBFED = FallingEdgeDelay;                  // Falling Edge Delay = TTBCLK x DBFED// TTBCLK = 13.3333ns to give 666ns delay we can use that number
    EPwm5Regs.DBCTL.all = 0x0000;          // S5 = S4 = S2 = 0    S0 = S1 = S3 = 1  RED & FED active also Active high complementary mode also PWMxA is source for RED and FED
    EPwm5Regs.DBCTL.bit.POLSEL = 2;
    EPwm5Regs.DBCTL.bit.IN_MODE = 0;
    EPwm5Regs.DBCTL.bit.OUT_MODE = 3;

    EPwm6Regs.TBCTL.all = 0;
    EPwm6Regs.TBCTL.bit.CLKDIV = 0;
    EPwm6Regs.TBCTL.bit.HSPCLKDIV = 0;
    EPwm6Regs.TBCTL.bit.CTRMODE = 2;         // Count up and down operation (10) = 2
    EPwm6Regs.TBCTL.bit.PHSEN = 1;
    EPwm6Regs.TBPHS.half.TBPHS = EPwm1Regs.TBPRD;
    EPwm6Regs.AQCTLA.all = 0x0060;          //set ePWM1A to 1 on �CMPA - up match�//clear ePWM1A on event �CMPA - down match�
    EPwm6Regs.AQCTLB.all = 0x0090;         //clear ePWM1B on �CMPA - up match�//set ePWM1B to 1 on event �CMPA - down match� // we made reverse action to obtain complementary wave
    EPwm6Regs.DBRED = RisingEdgeDelay;                  // Rising Edge Delay = TTBCLK x DBRED
    EPwm6Regs.DBFED = FallingEdgeDelay;                  // Falling Edge Delay = TTBCLK x DBFED// TTBCLK = 13.3333ns to give 666ns delay we can use that number
    EPwm6Regs.DBCTL.all = 0x0000;          // S5 = S4 = S2 = 0    S0 = S1 = S3 = 1  RED & FED active also Active high complementary mode also PWMxA is source for RED and FED
    EPwm6Regs.DBCTL.bit.POLSEL = 2;
    EPwm6Regs.DBCTL.bit.IN_MODE = 0;
    EPwm6Regs.DBCTL.bit.OUT_MODE = 3;

    EPwm5Regs.ETSEL.all = 0;
    EPwm5Regs.ETSEL.bit.INTEN = 1;
    EPwm5Regs.ETSEL.bit.INTSEL = 2;
    EPwm5Regs.ETSEL.bit.SOCAEN = 1;
    EPwm5Regs.ETSEL.bit.SOCASEL = 2;
    EPwm5Regs.ETPS.all = 0;
    EPwm5Regs.ETPS.bit.INTPRD = 1;
    EPwm5Regs.ETPS.bit.SOCAPRD = 1;

    EPwm1Regs.CMPA.half.CMPA = EPwm1Regs.TBPRD / 2; // 50% duty cycle first
    EPwm2Regs.CMPA.half.CMPA = EPwm2Regs.TBPRD / 2; // 50% duty cycle first
    EPwm3Regs.CMPA.half.CMPA = EPwm3Regs.TBPRD / 2; // 50% duty cycle first
    EPwm4Regs.CMPA.half.CMPA = EPwm4Regs.TBPRD / 2; // 50% duty cycle first
    EPwm5Regs.CMPA.half.CMPA = EPwm4Regs.TBPRD / 2; // 50% duty cycle first
    EPwm6Regs.CMPA.half.CMPA = EPwm4Regs.TBPRD / 2; // 50% duty cycle first

    EPwm1Regs.CMPCTL.bit.LOADAMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm1Regs.CMPCTL.bit.SHDWAMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.
    EPwm1Regs.CMPCTL.bit.LOADBMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm1Regs.CMPCTL.bit.SHDWBMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.

    EPwm2Regs.CMPCTL.bit.LOADAMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm2Regs.CMPCTL.bit.SHDWAMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.
    EPwm2Regs.CMPCTL.bit.LOADBMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm2Regs.CMPCTL.bit.SHDWBMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.

    EPwm3Regs.CMPCTL.bit.LOADAMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm3Regs.CMPCTL.bit.SHDWAMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.
    EPwm3Regs.CMPCTL.bit.LOADBMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm3Regs.CMPCTL.bit.SHDWBMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.

    EPwm4Regs.CMPCTL.bit.LOADAMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm4Regs.CMPCTL.bit.SHDWAMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.
    EPwm4Regs.CMPCTL.bit.LOADBMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm4Regs.CMPCTL.bit.SHDWBMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.

    EPwm5Regs.CMPCTL.bit.LOADAMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm5Regs.CMPCTL.bit.SHDWAMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.
    EPwm5Regs.CMPCTL.bit.LOADBMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm5Regs.CMPCTL.bit.SHDWBMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.

    EPwm6Regs.CMPCTL.bit.LOADAMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm6Regs.CMPCTL.bit.SHDWAMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.
    EPwm6Regs.CMPCTL.bit.LOADBMODE = 0; // Load on CTR = Zero: Time-base counter equal to zero (TBCTR = 0x0000)
    EPwm6Regs.CMPCTL.bit.SHDWBMODE = 0; // Shadow mode. Operates as a double buffer. All writes via the CPU access the shadow register.

}

interrupt void ePWMA_compare_isr(void) {

  //  GpioDataRegs.GPASET.bit.GPIO10 = 1;
    EALLOW;
    SysCtrlRegs.WDKEY = 0xAA;   // service WD #2
    EDIS;

    frequencyModulationRatio = fundamentalSinusoidalFrequency / switchingFrequency;
    magnitudeModulationRatio = fundamentalSinusoidalMagnitude / maximumDeviceVoltage;
    sinus = (sin(2 * PI * (frequencyModulationRatio) * counter + phaseAngle) + 1) / 2;
    sinus2 = (sin(2 * PI * (frequencyModulationRatio) * counter - 2 * PI / 3 + phaseAngle) + 1) / 2;
    sinus3 = (sin(2 * PI * (frequencyModulationRatio) * counter - 4 * PI / 3 + phaseAngle) + 1) / 2;
    cmp_phaseA = EPwm1Regs.TBPRD - (magnitudeModulationRatio) * EPwm1Regs.TBPRD * sinus - 1; //
    cmp_phaseB = EPwm2Regs.TBPRD - (magnitudeModulationRatio) * EPwm2Regs.TBPRD * sinus2 - 1; //
    cmp_phaseC = EPwm3Regs.TBPRD - (magnitudeModulationRatio) * EPwm3Regs.TBPRD * sinus3 - 1;

    counter +=1;
    if( counter > ((1 / frequencyModulationRatio)-1)) counter = 0;

    EPwm1Regs.ETCLR.bit.INT = 1;
    PieCtrlRegs.PIEACK.all = 4;

   // GpioDataRegs.GPACLEAR.bit.GPIO10 = 1;

}
interrupt void adc_isr(void){

    EALLOW;
    SysCtrlRegs.WDKEY = 0x55;   // service WD #2
    EDIS;

    EPwm1Regs.CMPA.half.CMPA = cmp_phaseA;
    EPwm2Regs.CMPA.half.CMPA = cmp_phaseB;
    EPwm3Regs.CMPA.half.CMPA = cmp_phaseC;
    EPwm4Regs.CMPA.half.CMPA = cmp_phaseA;
    EPwm5Regs.CMPA.half.CMPA = cmp_phaseB;
    EPwm6Regs.CMPA.half.CMPA = cmp_phaseC;

    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;
    AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

}


