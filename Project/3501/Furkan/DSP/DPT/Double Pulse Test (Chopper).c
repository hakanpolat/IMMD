#include "DSP2833x_Device.h"
#include "DSP2833x_CpuTimers.h"
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
// Prototype statements for functions found within this file.
void Gpio_select(void);
void InitSystem(void);
void SetPWM(void);
// external function prototypes
extern void InitSysCtrl(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void InitCpuTimers(void);
extern void ConfigCpuTimer(struct CPUTIMER_VARS *, float, float);

// Prototype statements for functions found within this file.
interrupt void xint3_isr(void);
interrupt void ePWM1_TZ_isr(void);
//###########################################################################
//                      main code
//###########################################################################
void main(void)
{
    InitSystem();       // Basic Core Initialization
    InitSysCtrl();      // Initialize System Control
    DINT;               // Disable all interrupts
    Gpio_select();
    InitPieVectTable(); // Initialize PIE Vector Table
    InitPieCtrl();      // Initialize PIE Control
    IER = 0x0000;
    IFR = 0x0000;
    InitCpuTimers();    //Initialize Timers
    SetPWM();

    EALLOW;
    PieVectTable.XINT3 = &xint3_isr;
    // Re-mapped ISR
    PieVectTable.EPWM1_TZINT = &ePWM1_TZ_isr;
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;          // Enable the PIE block
    //PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // Enable PIE Group 1 INT4
    PieCtrlRegs.PIEIER2.bit.INTx1 = 1;          // ePWM1-TZ
    PieCtrlRegs.PIEIER12.bit.INTx1 = 1;         // Enable PIE Group 12 INT 1
    IER |= M_INT1 | M_INT12;                    // Enable CPU int1
    //IER |= 2;                                   // enable INT1 and INT2
    EINT;
    EDIS;

    EALLOW;
    GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 0;         // GPIO
    GpioCtrlRegs.GPBDIR.bit.GPIO58 = 0;          // input
    GpioCtrlRegs.GPBPUD.bit.GPIO58  = 1;        // Pull Up
    GpioCtrlRegs.GPBQSEL2.bit.GPIO58 = 2;        // Xint1 Synch to 6 samples
    GpioCtrlRegs.GPBCTRL.bit.QUALPRD2 = 0xFF;   // Each sampling window is 510*SYSCLKOUT
//    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 2;   // Xint1 is GPIO0
    GpioIntRegs.GPIOXINT3SEL.bit.GPIOSEL = 0x1A;
    EDIS;

    XIntruptRegs.XINT3CR.bit.POLARITY = 0;      // Falling edge interrupt
    XIntruptRegs.XINT3CR.bit.ENABLE = 1;        // Enable Xint3
    while(1)
    {
        EPwm1Regs.AQCSFRC.bit.CSFA = 1;     // force to low
        EPwm1Regs.AQCSFRC.bit.CSFB = 1;     // force to low
        GpioDataRegs.GPASET.bit.GPIO3 = 1;          // Gate Driver Enable
        XIntruptRegs.XINT3CR.bit.ENABLE = 1;        // Enable Xint3
    };
}
interrupt void ePWM1_TZ_isr(void)
{
    XIntruptRegs.XINT3CR.bit.ENABLE = 0;
    EALLOW;
    EPwm1Regs.TZCLR.bit.CBC = 1;
    EPwm1Regs.TZCLR.bit.INT = 1;    // reset interrupt flags
    EDIS;
   // while (GpioDataRegs.GPADAT.bit.GPIO17 == 0)
    //{
        GpioDataRegs.GPACLEAR.bit.GPIO3 = 1;
   // };
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

}
interrupt void xint3_isr(void)
{
    Uint16 TempPIEIER;
    TempPIEIER = PieCtrlRegs.PIEIER12.all;
    IER |= 2;
    IER &= 2;
    PieCtrlRegs.PIEACK.all = 0xFFFF;
    asm("NOP");
    EINT;
    EPwm1Regs.AQCSFRC.bit.CSFA = 0; // forcing disabled
    EPwm1Regs.AQCSFRC.bit.CSFB = 0; // forcing disabled
    while (CpuTimer0Regs.TIM.all >= 0xFFFC0005) // Waits for a period time 1.7476msec before forcing pwms to low
    {
        asm("None");
    }
    CpuTimer0Regs.TCR.bit.TSS = 1;          // Timer 0 Stops
    CpuTimer0Regs.TCR.bit.TRB = 1;          // Reload Period Value*/
    while (CpuTimer0Regs.TIM.all >= 0xD34BE87F) // Waits 5 secs before having button interrupt and force pwm to low
    {
        EPwm1Regs.AQCSFRC.bit.CSFA = 1; // force low
        EPwm1Regs.AQCSFRC.bit.CSFB = 1; // force low
    }
    CpuTimer0Regs.TCR.bit.TSS = 1;          // Timer 0 Stops
    CpuTimer0Regs.TCR.bit.TRB = 1;          // Reload Period Value*/
    // Acknowledge this interrupt to get more from group 12
   // PieCtrlRegs.PIEIER12.all = PIEACK_GROUP12;
    DINT;
    PieCtrlRegs.PIEIER12.all = TempPIEIER;
}

void Gpio_select(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // GPIO35 ... GPIO0 = General Purpose I/O
    GpioCtrlRegs.GPAMUX2.all = 0x00000000;  // GPIO31 ... GPIO36 = General Purpose I/O
    GpioCtrlRegs.GPBMUX1.all = 0x00000000;  // GPIO47 ... GPIO32 = General Purpose I/O
    GpioCtrlRegs.GPBMUX2.all = 0x00000000;  // GPIO63 ... GPIO48 = General Purpose I/O
    GpioCtrlRegs.GPCMUX1.all = 0x00000000;  // GPIO79 ... GPIO64 = General Purpose I/O
    GpioCtrlRegs.GPCMUX2.all = 0x00000000;  // GPIO87 ... GPIO80 = General Purpose I/O
    GpioCtrlRegs.GPADIR.all = 0x00000000;
    GpioCtrlRegs.GPBDIR.all = 0x00000000;
    GpioCtrlRegs.GPCDIR.all = 0x00000000;



    GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;          // output
    GpioDataRegs.GPASET.bit.GPIO3 = 1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 3;    // as TZ6
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1; // ePWM1A active
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1; // ePWM1B active
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
void SetPWM(void)
{
    EPwm1Regs.TBCTL.bit.CLKDIV =  0;    // CLKDIV = 1
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 1;  // HSPCLKDIV = 2
    EPwm1Regs.TBCTL.bit.CTRMODE = 2;    // up - down mode

    EPwm1Regs.AQCTLA.all = 0x0060;      // set ePWM1A on CMPA up
                                        // clear ePWM1A on CMPA down
    EPwm1Regs.AQCTLB.all = 0x0600;      // set ePWM1B on CMPB up
                                        // clear ePWM1B on CMPB down

    EPwm1Regs.TBPRD = 65535;            // 572Hz - PWM signal
    EPwm1Regs.CMPA.half.CMPA = EPwm1Regs.TBPRD - 38; // only 1 usec for B
    EPwm1Regs.CMPB  =   EPwm1Regs.TBPRD / 2;
    EPwm1Regs.PCCTL.bit.CHPFREQ = 7;    // SYSCLKOUT / 64  = 2.34375MHz
    EPwm1Regs.PCCTL.bit.CHPDUTY = 5;    // 75% duty cycle -> 100 ns dead time - 300 ns charging time
    EPwm1Regs.PCCTL.bit.CHPEN = 1;      // 1= enable chopper mode
    EPwm1Regs.PCCTL.bit.OSHTWTH = 14;   // 120 *6.67 ns = 800 ns
}

//===========================================================================
// End of SourceCode.
//===========================================================================
