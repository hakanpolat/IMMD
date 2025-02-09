## PWM, Capture and QEP
* F28335 has 6 PWM channels.
* The F2833x is also able to perform time measurements by capture unite using edges of signals. It can be used to determine the rotating speed of the machine.
* Quadrature Encoder Pulse unit (QEP) is a unit that is used to derive the speed and direction information of a rotating shaft directly from hardware signals from incremental encoders or resolvers.

### ePWM
![](/Images/ePWM_Block_Diagram.jpg)

As you can see from the slide, to generate a physical output signal we will have to setup a few units: time base, compare logic, action qualifier, dead band unit, chopper and trip zone. On first glance this looks cumbersome. However, it does allow us to setup a range of different operating modes, all of which can be used in modern digital control.
### ePWM Time Base Unit
#### Time-Base Module Registers
![](/Images/Timebase_PWM_REGS.jpg)




//      Lab7_2: TMS320F28335
//
//###########################################################################
// This code produces a three phase PWM pulse 50% Duty cycle with 1KHZ frequency and 120 degrees phase shift.
//###########################################################################
#include "DSP2833x_Device.h"

// external function prototypes
extern void InitSysCtrl(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void InitCpuTimers(void);
extern void ConfigCpuTimer(struct CPUTIMER_VARS *, float, float);


// Prototype statements for functions found within this file.
void Gpio_select(void);
void Setup_ePWM(void);
interrupt void cpu_timer0_isr(void);

//###########################################################################
//                      main code
//###########################################################################
void main(void)
{
    int counter=0;  // binary counter for digital output

    InitSysCtrl();  // Basic Core Init from DSP2833x_SysCtrl.c

    EALLOW;
    SysCtrlRegs.WDCR= 0x00AF;   // Re-enable the watchdog
    EDIS;           // 0x00AF  to NOT disable the Watchdog, Prescaler = 64

    DINT;               // Disable all interrupts

    Gpio_select();      // GPIO9, GPIO11, GPIO34 and GPIO49 as output
                        // to 4 LEDs at Peripheral Explorer)

    Setup_ePWM();     // init of ePWM1A

    InitPieCtrl();      // basic setup of PIE table; from DSP2833x_PieCtrl.c

    InitPieVectTable(); // default ISR's in PIE

    EALLOW;
    PieVectTable.TINT0 = &cpu_timer0_isr;
    EDIS;

    InitCpuTimers();    // basic setup CPU Timer0, 1 and 2

    ConfigCpuTimer(&CpuTimer0,150,100000);

    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

    IER |=1;

    EINT;
    ERTM;

    CpuTimer0Regs.TCR.bit.TSS = 0;  // start timer0

    while(1)
    {
            while(CpuTimer0.InterruptCount == 0);
            CpuTimer0.InterruptCount = 0;

            EALLOW;
            SysCtrlRegs.WDKEY = 0x55;   // service WD #1
            EDIS;

            counter++;
            if(counter&1) GpioDataRegs.GPASET.bit.GPIO9 = 1;
                else GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
            if(counter&2) GpioDataRegs.GPASET.bit.GPIO11 = 1;
                else GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;
            if(counter&4) GpioDataRegs.GPBSET.bit.GPIO34 = 1;
                else GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
            if(counter&8) GpioDataRegs.GPBSET.bit.GPIO49 = 1;
                else GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1;

    }
}

void Gpio_select(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0;       // GPIO15 ... GPIO0 = General Puropse I/O
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1; // ePWM1A active
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1; // ePWM1A active
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1; // ePWM1A active

    GpioCtrlRegs.GPAMUX2.all = 0;       // GPIO31 ... GPIO16 = General Purpose I/O
    GpioCtrlRegs.GPBMUX1.all = 0;       // GPIO47 ... GPIO32 = General Purpose I/O
    GpioCtrlRegs.GPBMUX2.all = 0;       // GPIO63 ... GPIO48 = General Purpose I/O
    GpioCtrlRegs.GPCMUX1.all = 0;       // GPIO79 ... GPIO64 = General Purpose I/O
    GpioCtrlRegs.GPCMUX2.all = 0;       // GPIO87 ... GPIO80 = General Purpose I/O

    GpioCtrlRegs.GPADIR.all = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;  // peripheral explorer: LED LD1 at GPIO9
    GpioCtrlRegs.GPADIR.bit.GPIO11 = 1; // peripheral explorer: LED LD2 at GPIO11


    GpioCtrlRegs.GPBDIR.all = 0;        // GPIO63-32 as inputs
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1; // peripheral explorer: LED LD3 at GPIO34
    GpioCtrlRegs.GPBDIR.bit.GPIO49 = 1; // peripheral explorer: LED LD4 at GPIO49
    GpioCtrlRegs.GPCDIR.all = 0;        // GPIO87-64 as inputs
    EDIS;
}

void Setup_ePWM(void)
{
    EPwm1Regs.TBCTL.bit.CLKDIV =  3;    // CLKDIV = 1
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 0;  // HSPCLKDIV = 1
    EPwm1Regs.TBCTL.bit.CTRMODE = 2;    // up - down mode
    EPwm1Regs.TBCTL.bit.SYNCOSEL = 1;   // Sync output select
    EPwm1Regs.AQCTLA.all = 0x0006;      // ZRO = set, PRD = clear

    EPwm1Regs.TBPRD = 9375;            // 1KHz - PWM signal

    EPwm2Regs.TBCTL.bit.CLKDIV =  3;    // CLKDIV = 1
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = 0;  // HSPCLKDIV = 1
    EPwm2Regs.TBCTL.bit.CTRMODE = 2;    // up - down mode
    EPwm2Regs.TBCTL.bit.SYNCOSEL = 0;   // Sync output select
    EPwm2Regs.TBCTL.bit.PHSEN = 1;
    EPwm2Regs.AQCTLA.all = 0x0006;      // ZRO = set, PRD = clear
    EPwm2Regs.TBPHS.half.TBPHS= 3125;
    EPwm2Regs.TBPRD = 9375;

    EPwm3Regs.TBCTL.bit.CLKDIV =  3;    // CLKDIV = 1
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = 0;  // HSPCLKDIV = 1
    EPwm3Regs.TBCTL.bit.CTRMODE = 2;    // up - down mode
    EPwm3Regs.TBCTL.bit.PHSEN = 1;
    EPwm3Regs.AQCTLA.all = 0x0006;      // ZRO = set, PRD = clear
    EPwm3Regs.TBPHS.half.TBPHS= 6250;
    EPwm3Regs.TBPRD = 9375;
}

interrupt void cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;
    EALLOW;
    SysCtrlRegs.WDKEY = 0xAA;   // service WD #2
    EDIS;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
//===========================================================================
// End of SourceCode.
//===========================================================================




//
//      Lab7_3: TMS320F28335
//
//###########################################################################
//
//
//
// TITLE:   DSP28335ControlCARD; ePWM1A 1KHz output
//          solution file for Lab7_3
//###########################################################################
// This code produces a varying duty cycle PWM from 0% up to 100%
//###########################################################################
#include "DSP2833x_Device.h"

// external function prototypes
extern void InitSysCtrl(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void InitCpuTimers(void);
extern void ConfigCpuTimer(struct CPUTIMER_VARS *, float, float);


// Prototype statements for functions found within this file.
void Gpio_select(void);
void Setup_ePWM1A(void);
interrupt void cpu_timer0_isr(void);

//###########################################################################
//                      main code
//###########################################################################
void main(void)
{
    int counter=0;  // binary counter for digital output

    InitSysCtrl();  // Basic Core Init from DSP2833x_SysCtrl.c

    EALLOW;
    SysCtrlRegs.WDCR= 0x00AF;   // Re-enable the watchdog
    EDIS;           // 0x00AF  to NOT disable the Watchdog, Prescaler = 64

    DINT;               // Disable all interrupts

    Gpio_select();      // GPIO9, GPIO11, GPIO34 and GPIO49 as output
                        // to 4 LEDs at Peripheral Explorer)

    Setup_ePWM1A();     // init of ePWM1A

    InitPieCtrl();      // basic setup of PIE table; from DSP2833x_PieCtrl.c

    InitPieVectTable(); // default ISR's in PIE

    EALLOW;
    PieVectTable.TINT0 = &cpu_timer0_isr;
    EDIS;

    InitCpuTimers();    // basic setup CPU Timer0, 1 and 2

    ConfigCpuTimer(&CpuTimer0,150,100);

    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

    IER |=1;

    EINT;
    ERTM;

    CpuTimer0Regs.TCR.bit.TSS = 0;  // start timer0

    while(1)
    {
            while(CpuTimer0.InterruptCount == 0);
            CpuTimer0.InterruptCount = 0;

            EALLOW;
            SysCtrlRegs.WDKEY = 0x55;   // service WD #1
            EDIS;

            counter++;
            if(counter&1) GpioDataRegs.GPASET.bit.GPIO9 = 1;
                else GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
            if(counter&2) GpioDataRegs.GPASET.bit.GPIO11 = 1;
                else GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;
            if(counter&4) GpioDataRegs.GPBSET.bit.GPIO34 = 1;
                else GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
            if(counter&8) GpioDataRegs.GPBSET.bit.GPIO49 = 1;
                else GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1;

    }
}

void Gpio_select(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0;       // GPIO15 ... GPIO0 = General Puropse I/O
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1; // ePWM1A active

    GpioCtrlRegs.GPAMUX2.all = 0;       // GPIO31 ... GPIO16 = General Purpose I/O
    GpioCtrlRegs.GPBMUX1.all = 0;       // GPIO47 ... GPIO32 = General Purpose I/O
    GpioCtrlRegs.GPBMUX2.all = 0;       // GPIO63 ... GPIO48 = General Purpose I/O
    GpioCtrlRegs.GPCMUX1.all = 0;       // GPIO79 ... GPIO64 = General Purpose I/O
    GpioCtrlRegs.GPCMUX2.all = 0;       // GPIO87 ... GPIO80 = General Purpose I/O

    GpioCtrlRegs.GPADIR.all = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;  // peripheral explorer: LED LD1 at GPIO9
    GpioCtrlRegs.GPADIR.bit.GPIO11 = 1; // peripheral explorer: LED LD2 at GPIO11


    GpioCtrlRegs.GPBDIR.all = 0;        // GPIO63-32 as inputs
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1; // peripheral explorer: LED LD3 at GPIO34
    GpioCtrlRegs.GPBDIR.bit.GPIO49 = 1; // peripheral explorer: LED LD4 at GPIO49
    GpioCtrlRegs.GPCDIR.all = 0;        // GPIO87-64 as inputs
    EDIS;
}

void Setup_ePWM1A(void)
{
    EPwm1Regs.TBCTL.bit.CLKDIV =  0;    // CLKDIV = 1
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 1;  // HSPCLKDIV = 2
    EPwm1Regs.TBCTL.bit.CTRMODE = 2;    // up - down mode
    EPwm1Regs.CMPA.half.CMPA  = 0;      // duty cycle
    EPwm1Regs.AQCTLA.all = 0x0060;      // ZRO = set, PRD = clear

    EPwm1Regs.TBPRD = 37500;            // 1KHz - PWM signal
}

interrupt void cpu_timer0_isr(void)
{
    if (EPwm1Regs.CMPA.half.CMPA<EPwm1Regs.TBPRD)
    {
        EPwm1Regs.CMPA.half.CMPA++;
    }
    else if (EPwm1Regs.CMPA.half.CMPA>=EPwm1Regs.TBPRD)
    {
        EPwm1Regs.CMPA.half.CMPA=0;
    }
    CpuTimer0.InterruptCount++;
    EALLOW;
    SysCtrlRegs.WDKEY = 0xAA;   // service WD #2
    EDIS;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
//===========================================================================
// End of SourceCode.
//===========================================================================
