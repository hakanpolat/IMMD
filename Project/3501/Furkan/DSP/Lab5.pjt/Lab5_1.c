//
//      Lab5_1: TMS320F28335
//      (c) Frank Bormann
//
//###########################################################################
//
// FILE:	Lab5_1.c
// 
// TITLE:	DSP28335ControlCARD; Digital Output
//			4 - bit - counter at 4 LEDs LD1(GPIO9), LD2(GPIO11), LD3(GPIO34)
//			and LD4 (GPIO49) 
//			software delay loop; watchdog disabled
//			template file for Lab5_1
//###########################################################################
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  3.0 | 02 May 2008 | F.B. | Lab5_1 for F28335; 
//  3.1 | 06 Nov 2009 | F.B  | Lab5_1 for F28335 and PE revision5
//###########################################################################
#include "DSP2833x_Device.h"

// Prototype statements for functions found within this file.
void Gpio_select(void);
void InitSystem(void);
void delay_loop(long);

//###########################################################################
//						main code									
//###########################################################################
void main(void)
{
	int counter=0;		// binary counter for digital output

	InitSystem();	 	// Basic Core Initialization

	DINT;				// Disable all interrupts
	
	Gpio_select();		// GPIO9,GPIO11,GPIO34 and GPIO49 as output (LEDs @ peripheral explorer)

	while(1)
	{    
	  		counter++;
			// place your code to analyze counter here 
	  		if ((counter & 0x0001) == 1) // if bit 0 of counter = 1, set GPIO9 to 1
	  		{
	  		  GpioDataRegs.GPASET.bit.GPIO9 = 1;
	  		}
	  		else
	  		  GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
	  		if (((counter >> 1) & 0x0001) == 1)// if bit 1 of counter = 1, set GPIO11 to 1
	  		{
	  		  GpioDataRegs.GPASET.bit.GPIO11 = 1;
	  		}
	  		else
	  		  GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;
	  		if (((counter >> 2) & 0x0001) == 1)// if bit 2 of counter = 1, set GPIO34 to 1
	  		{
	  		  GpioDataRegs.GPBSET.bit.GPIO34 = 1;
	  		}
	  		else
	  		  GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
            if (((counter >> 3) & 0x0001) == 1)// if bit 3 of counter = 1, set GPIO49 to 1
            {
              GpioDataRegs.GPBSET.bit.GPIO49 = 1;
            }
            else
              GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1;
			delay_loop(1000000);
	}
} 

void delay_loop(long end)
{
	long i;
	for (i = 0; i < end; i++)
	{
		asm(" NOP");
		EALLOW;
		SysCtrlRegs.WDKEY = 0x55;
		SysCtrlRegs.WDKEY = 0xAA;
		EDIS;
	}
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
	 
	GpioCtrlRegs.GPADIR.all = 0x00000A00;
	// peripheral explorer: LED LD1 at GPIO9
	// peripheral explorer: LED LD2 at GPIO11
	GpioCtrlRegs.GPBDIR.all = 0x00020004;
	// peripheral explorer: LED LD3 at GPIO34
	// peripheral explorer: LED LD4 at GPIO49	
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
