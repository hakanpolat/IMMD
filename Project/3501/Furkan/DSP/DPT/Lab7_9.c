//
//      Lab7_9: TMS320F28335
//      (c) Frank Bormann
//
//###########################################################################
//
// FILE:	Lab7_9.c
// 
// TITLE:	DSP28335ControlCARD; ePWM1A 500KHz PWM signal
//			sine wave output via ePWM1A at low pass filter "DAC-1" (J11-1)
//			solution file for Lab7_9
//###########################################################################
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  3.0 | 18 Apr 2009 | F.B. | Lab7_9 for F28335; 
//  3.1 | 11 Nov 2009 | F.B  | Lab7_9 for F28335 and PE revision 5
//###########################################################################
#include "DSP2833x_Device.h"
#include "IQmathLib.h"
#pragma DATA_SECTION(sine_table,"IQmathTables");
_iq30 sine_table[512];
// external function prototypes
extern void InitSysCtrl(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);

// Prototype statements for functions found within this file.
void Gpio_select(void);
void Setup_ePWM1(void);
interrupt void ePWM1A_compare_isr(void);

//###########################################################################
//						main code									
//###########################################################################
void main(void)
{
	InitSysCtrl();	// Basic Core Init from DSP2833x_SysCtrl.c

	EALLOW;
   	SysCtrlRegs.WDCR= 0x00AF;	// Re-enable the watchdog 
   	EDIS;			// 0x00AF  to NOT disable the Watchdog, Prescaler = 64

	DINT;				// Disable all interrupts
	
	Gpio_select();		// GPIO9, GPIO11, GPIO34 and GPIO49 as output
					    // to 4 LEDs at Peripheral Explorer Board

	Setup_ePWM1();		// init of ePWM1A

	InitPieCtrl();		// basic setup of PIE table; from DSP2833x_PieCtrl.c
	
	InitPieVectTable();	// default ISR's in PIE

	EALLOW;
	PieVectTable.EPWM1_INT = &ePWM1A_compare_isr;
	EDIS;

	// Enable EPWM1A INT in the PIE: Group 3 interrupt 1
   	PieCtrlRegs.PIEIER3.bit.INTx1 = 1;

	IER |=4;			// enable INT3 for ePWM1

	EINT;
	ERTM;

	while(1)
	{    
	  	EALLOW;
		SysCtrlRegs.WDKEY = 0x55;	// service WD #1
		EDIS;
	}
} 

void Gpio_select(void)
{
	EALLOW;
	GpioCtrlRegs.GPAMUX1.all = 0;		// GPIO15 ... GPIO0 = General Puropse I/O
	GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;	// ePWM1A active
	
	GpioCtrlRegs.GPAMUX2.all = 0;		// GPIO31 ... GPIO16 = General Purpose I/O
	GpioCtrlRegs.GPBMUX1.all = 0;		// GPIO47 ... GPIO32 = General Purpose I/O
	GpioCtrlRegs.GPBMUX2.all = 0;		// GPIO63 ... GPIO48 = General Purpose I/O
	GpioCtrlRegs.GPCMUX1.all = 0;		// GPIO79 ... GPIO64 = General Purpose I/O
	GpioCtrlRegs.GPCMUX2.all = 0;		// GPIO87 ... GPIO80 = General Purpose I/O
	 
	GpioCtrlRegs.GPADIR.all = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;	// peripheral explorer: LED LD1 at GPIO9
	GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;	// peripheral explorer: LED LD2 at GPIO11


	GpioCtrlRegs.GPBDIR.all = 0;		// GPIO63-32 as inputs
	GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;	// peripheral explorer: LED LD3 at GPIO34
	GpioCtrlRegs.GPBDIR.bit.GPIO49 = 1; // peripheral explorer: LED LD4 at GPIO49
	GpioCtrlRegs.GPCDIR.all = 0;		// GPIO87-64 as inputs
	EDIS;
}  

void Setup_ePWM1(void)
{
	EPwm1Regs.TBCTL.bit.CLKDIV =  0;	// CLKDIV = 1		
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = 0;	// HSPCLKDIV = 1
	EPwm1Regs.TBCTL.bit.CTRMODE = 2;	// up - down mode

	EPwm1Regs.AQCTLA.all = 0x0060;		// set ePWM1A on CMPA up
										// clear ePWM1A on CMPA down
	EPwm1Regs.TBPRD = 150;				// timer period for 500 KHz
										// TBPRD = 1/2 ( 150 MHz / 500 kHz) 
	EPwm1Regs.CMPA.half.CMPA = EPwm1Regs.TBPRD / 2;	// 50% duty cycle first
	
	EPwm1Regs.ETSEL.all = 0;
	EPwm1Regs.ETSEL.bit.INTEN = 1;		// interrupt enable for ePWM1
	EPwm1Regs.ETSEL.bit.INTSEL = 5;		// interrupt on CMPA down match
	EPwm1Regs.ETPS.bit.INTPRD = 1;		// interrupt on first event
	
} 

interrupt void ePWM1A_compare_isr(void)
// ISR runs every 2000 ns (PWM-frequency = 500 KHz)
// and is triggered by ePWM1 compare event
// run - time of ISR is 630 ns
{
	static unsigned int index=0;  
   	// Service watchdog every interrupt
   	EALLOW;
	SysCtrlRegs.WDKEY = 0xAA;		// Service watchdog #2
	EDIS;
   
	EPwm1Regs.CMPA.half.CMPA =  EPwm1Regs.TBPRD - _IQsat(_IQ30mpy((sine_table[index]+_IQ30(0.9999))/2,EPwm1Regs.TBPRD),EPwm1Regs.TBPRD,0);
 
    index +=1;          // use next element out of lookup table
    if (index >511) index = 0;
   
	EPwm1Regs.ETCLR.bit.INT = 1;		// Clear ePWM1 Interrupt flag
    
   	// Acknowledge this interrupt to receive more interrupts from group 3
   	PieCtrlRegs.PIEACK.all = 4;
}
//===========================================================================
// End of SourceCode.
//===========================================================================
