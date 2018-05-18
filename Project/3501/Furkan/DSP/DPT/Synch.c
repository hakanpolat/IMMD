//###########################################################################
//
// FILE:    Lab7_9.c
//
// TITLE:   DSP28335ControlCARD; EPwm1A 500KHz PWM signal
//          sine wave output via EPwm1A at low pass filter "DAC-1" (J11-1)
//          solution file for Lab7_9
//###########################################################################
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  3.0 | 18 Apr 2009 | F.B. | Lab7_9 for F28335;
//  3.1 | 11 Nov 2009 | F.B  | Lab7_9 for F28335 and PE revision 5
//###########################################################################
#include "DSP2833x_Device.h"
// external function prototypes
extern void InitSysCtrl(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);

// Prototype statements for functions found within this file.
void Gpio_select(void);
void Setup_EPwm1(void);
interrupt void ePWM1A_compare_isr(void);
interrupt void xint1_isr(void);
//###########################################################################
//                      main code
//###########################################################################
void main(void)
{
    InitSysCtrl();  // Basic Core Init from DSP2833x_SysCtrl.c
    DINT;               // Disable all interrupts
    Gpio_select();      // GPIO9, GPIO11, GPIO34 and GPIO49 as output
                        // to 4 LEDs at Peripheral Explorer Board
    Setup_EPwm1();      // init of EPwm1A
    InitPieCtrl();      // basic setup of PIE table; from DSP2833x_PieCtrl.c
    InitPieVectTable(); // default ISR's in PIE
    EALLOW;
    PieVectTable.EPWM1_INT = &ePWM1A_compare_isr;
    PieVectTable.XINT1 = &xint1_isr;    // Re-mapped ISR
    EDIS;
    // Enable EPwm1A INT in the PIE: Group 3 interrupt 1
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;  // Enable the PIE block
    PieCtrlRegs.PIEIER1.bit.INTx4 = 1;  // Enable PIE Group 1 INT4
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
    IER |= 4;           // enable INT3 for EPwm1
    IER |= M_INT1;      // Enable CPU int1
    EINT;
    ERTM;
    XIntruptRegs.XINT1CR.bit.POLARITY = 0;      // Falling edge interrupt
    XIntruptRegs.XINT1CR.bit.ENABLE = 1;        // Enable Xint1

    while(1)
    {
        EALLOW;
        SysCtrlRegs.WDKEY = 0x55;   // service WD #1
        EDIS;
    }
}

void Gpio_select(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0;       // GPIO15 ... GPIO0 = General Puropse I/O
    GpioCtrlRegs.GPAMUX2.all = 0;       // GPIO31 ... GPIO16 = General Purpose I/O
    GpioCtrlRegs.GPBMUX1.all = 0;       // GPIO47 ... GPIO32 = General Purpose I/O
    GpioCtrlRegs.GPBMUX2.all = 0;       // GPIO63 ... GPIO48 = General Purpose I/O
    GpioCtrlRegs.GPCMUX1.all = 0;       // GPIO79 ... GPIO64 = General Purpose I/O
    GpioCtrlRegs.GPCMUX2.all = 0;       // GPIO87 ... GPIO80 = General Purpose I/O

    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;         // GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 0;          // input
    GpioCtrlRegs.GPAPUD.bit.GPIO2   = 1;        // Pull Up
    GpioCtrlRegs.GPAQSEL1.bit.GPIO2 = 2;        // Xint1 Synch to 6 samples
    GpioCtrlRegs.GPACTRL.bit.QUALPRD2 = 0xFF;   // Each sampling window is 510*SYSCLKOUT
    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 2;    // Xint1 is GPIO2

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;     // EPwm1A active
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;    // GPIO
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;     // output
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;    // GPIO
    GpioCtrlRegs.GPBDIR.bit.GPIO32 = 1;     // output
    EDIS;
}

void Setup_EPwm1(void)
{
    EPwm1Regs.TBCTL.bit.CLKDIV =  0;    // CLKDIV = 1
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 3;  // HSPCLKDIV = 6
    EPwm1Regs.TBCTL.bit.CTRMODE = 2;    // up-down mode

    EPwm1Regs.AQCTLA.all = 0x0006;      // toggle when CMPA = CTR
                                        //
    EPwm1Regs.TBPRD = 1;                // timer period for 12.5 MHz
                                        // TBPRD = 1/2 ( 150 MHz / 12.5 MHz / 6)
    EPwm1Regs.CMPA.half.CMPA = EPwm1Regs.TBPRD / 2; // 50% duty cycle first

    EPwm1Regs.ETSEL.all = 0;
    EPwm1Regs.ETSEL.bit.INTEN = 1;      // interrupt enable for EPwm1
    EPwm1Regs.ETSEL.bit.INTSEL = 2;     // interrupt on CTR = PRD match
    EPwm1Regs.ETPS.bit.INTPRD = 1;      // disabled

}

interrupt void ePWM1A_compare_isr(void)
// ISR runs every 2000 ns (PWM-frequency = 500 KHz)
// and is triggered by EPwm1 compare event
// run - time of ISR is 630 ns
{
    EPwm1Regs.ETCLR.bit.INT = 1;        // Clear EPwm1 Interrupt flag
    // Acknowledge this interrupt to receive more interrupts from group 3
    PieCtrlRegs.PIEACK.all = 4;
}

interrupt void xint1_isr(void)
{
    EPwm1Regs.TBSTS.bit.CTRMAX = 1; // Clear the counter

    // Acknowledge this interrupt to get more from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
//===========================================================================
// End of SourceCode.
//===========================================================================


