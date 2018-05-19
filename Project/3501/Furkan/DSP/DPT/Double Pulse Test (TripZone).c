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
interrupt void xint1_isr(void);
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
    PieVectTable.XINT1 = &xint1_isr;    // Re-mapped ISR
    PieVectTable.EPWM1_TZINT = &ePWM1_TZ_isr;
    EDIS;

    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;          // Enable the PIE block
    PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // Enable PIE Group 1 INT4
    PieCtrlRegs.PIEIER2.bit.INTx1 = 1;          // ePWM1-TZ
    IER |= M_INT1;                              // Enable CPU int1
    IER |=3;                                    // enable INT1 and INT2
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
interrupt void ePWM1_TZ_isr(void)
{
    EALLOW;
    EPwm1Regs.TZCLR.bit.OST = 1;
    EPwm1Regs.TZCLR.bit.INT = 1;    // reset interrupt flags
    EDIS;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}
interrupt void xint1_isr(void)
{
    //Code For DPT PWM
    int DeadTimeClock = 500 / 6.667; // DeadTime = 100ns & Clock = 6.667ns
    int GapTimeClock = 1500 / 6.667; // GapTime = 5us & Clock = 6.667ns
    int LoadCurrent = 30;            // 30 Amps Inductor Current
    double Inductance = 50*0.001; // 250 uH Inductance
    int Voltage = 400;               // DC Voltage Level
    double ChargeTime = Inductance*LoadCurrent/Voltage; // t=L*I/Vdc
    Uint32 ChargeTimeClock = ChargeTime * 150000000;    // Clock = Time/Tclock = Time*ClockFreq
    Uint32 temp = 0;
    Uint32 t1 = ChargeTimeClock;
    Uint32 t2 = t1 + DeadTimeClock;
    Uint32 t3 = t1 + GapTimeClock;
    Uint32 t4 = t3 + DeadTimeClock;
    Uint32 t5 = t4 + DeadTimeClock;
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
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // GPIO15 ... GPIO0 = General Purpose I/O
    GpioCtrlRegs.GPAMUX2.all = 0x00000000;  // GPIO31 ... GPIO16 = General Purpose I/O
    GpioCtrlRegs.GPBMUX1.all = 0x00000000;  // GPIO47 ... GPIO32 = General Purpose I/O
    GpioCtrlRegs.GPBMUX2.all = 0x00000000;  // GPIO63 ... GPIO48 = General Purpose I/O
    GpioCtrlRegs.GPCMUX1.all = 0x00000000;  // GPIO79 ... GPIO64 = General Purpose I/O
    GpioCtrlRegs.GPCMUX2.all = 0x00000000;  // GPIO87 ... GPIO80 = General Purpose I/O
    GpioCtrlRegs.GPADIR.all = 0x00000000;
    GpioCtrlRegs.GPBDIR.all = 0x00000000;
    GpioCtrlRegs.GPCDIR.all = 0x00000000;


    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0;        // GPIO
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;         // output
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;        // GPIO
    GpioCtrlRegs.GPBDIR.bit.GPIO32 = 1;         // output

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
    EALLOW;
    EPwm1Regs.TZSEL.bit.OSHT6 = 1;    // select TZ6 as one shot over current source
    //EPwm1Regs.TZSEL.bit.CBC6 = 1;       // now TZ6 as cycle by cycle over current
    EPwm1Regs.TZEINT.bit.OST = 1;       // enable OST interrupt
    EDIS;
}

//===========================================================================
// End of SourceCode.
//===========================================================================
