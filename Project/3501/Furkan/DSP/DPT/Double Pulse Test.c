#include "DSP2833x_Device.h"
#include "DSP2833x_CpuTimers.h"
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File
// Prototype statements for functions found within this file.
void Gpio_select(void);
void InitSystem(void);

// external function prototypes
extern void InitSysCtrl(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void InitCpuTimers(void);
extern void ConfigCpuTimer(struct CPUTIMER_VARS *, float, float);

// Prototype statements for functions found within this file.
interrupt void xint1_isr(void);

//###########################################################################
//						main code									
//###########################################################################
void main(void)
{
	InitSystem();	 	// Basic Core Initialization
	InitSysCtrl();      // Initialize System Control
	DINT;				// Disable all interrupts
	Gpio_select();
    InitPieVectTable(); // Initialize PIE Vector Table
	InitPieCtrl();      // Initialize PIE Control
	IER = 0x0000;
	IFR = 0x0000;


	EALLOW;
	PieVectTable.XINT1 = &xint1_isr;    // Re-mapped ISR
	EDIS;

	PieCtrlRegs.PIECTRL.bit.ENPIE = 1;          // Enable the PIE block
	PieCtrlRegs.PIEIER1.bit.INTx4 = 1;          // Enable PIE Group 1 INT4
	IER |= M_INT1;                              // Enable CPU int1
	EINT;                                       // Enable Global Interrupts

	EALLOW;
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;         // GPIO
	GpioCtrlRegs.GPADIR.bit.GPIO0 = 0;          // input
	GpioCtrlRegs.GPAQSEL1.bit.GPIO0 = 0;        // Xint1 Synch to SYSCLKOUT only
	GpioCtrlRegs.GPACTRL.bit.QUALPRD0 = 0xFF;   // Each sampling window is 510*SYSCLKOUT
	EDIS;

    EALLOW;
    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 0;   // Xint1 is GPIO0
    EDIS;

    XIntruptRegs.XINT1CR.bit.POLARITY = 0;      // Falling edge interrupt
    XIntruptRegs.XINT1CR.bit.ENABLE = 1;        // Enable Xint1
    while(1);
}

interrupt void xint1_isr(void)
{
    //Code For DPT PWM

    // Acknowledge this interrupt to get more from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

void Gpio_select(void)
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.all = 0x00000000;	// GPIO15 ... GPIO0 = General Puropse I/O
	GpioCtrlRegs.GPAMUX2.all = 0x00000000;	// GPIO31 ... GPIO16 = General Purpose I/O
	GpioCtrlRegs.GPBMUX1.all = 0x00000000;	// GPIO47 ... GPIO32 = General Purpose I/O
	GpioCtrlRegs.GPBMUX2.all = 0x00000000;	// GPIO63 ... GPIO48 = General Purpose I/O
	GpioCtrlRegs.GPCMUX1.all = 0x00000000;	// GPIO79 ... GPIO64 = General Purpose I/O
	GpioCtrlRegs.GPCMUX2.all = 0x00000000;	// GPIO87 ... GPIO80 = General Purpose I/O
    GpioCtrlRegs.GPADIR.all = 0x00000000;
    GpioCtrlRegs.GPBDIR.all = 0x00000000;
	GpioCtrlRegs.GPCDIR.all = 0x00000000;
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

//===========================================================================
// End of SourceCode.
//===========================================================================
