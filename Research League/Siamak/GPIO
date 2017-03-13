# Digital GPIO LAB
## Objectives:
* Digital input/output

//
//      GPIO: TMS320F28335
//      (c) Siamak.PK
//
//###########################################################################
//
// FILE:    GPIO1.c
//
// TITLE:   DSP28335ControlCARD; Digital Output
//          4 - bit - 4 LEDs LD1(GPIO9), LD2(GPIO11), LD3(GPIO34)
//          and LD4 (GPIO49)
//          software delay loop; watchdog disabled
//
//###########################################################################
//This code switches 4 LEDS sequentially.
//###########################################################################

#include "DSP2833x_Device.h"

// Prototype statements for functions found within this file.
void Gpio_select(void);
void InitSystem(void);
void delay_loop(long);

//###########################################################################
//                      main code
//###########################################################################
void main(void)
{
   int i=1;      // binary counter for digital output

   InitSystem();       // Basic Core Initialization

   DINT;               // Disable all interrupts

   Gpio_select();      // GPIO9,GPIO11,GPIO34 and GPIO49 as output (LEDs @ peripheral explorer)

   while(1)
   {
           for (i=1;i<=5;i++)
       {
           if(i==1) GpioDataRegs.GPASET.bit.GPIO9 = 1;
               else GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
           if(i==2) GpioDataRegs.GPASET.bit.GPIO11 = 1;
               else GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;
           if(i==3) GpioDataRegs.GPBSET.bit.GPIO34 = 1;
               else GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
           if(i==4) GpioDataRegs.GPBSET.bit.GPIO49 = 1;
               else GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1;
           delay_loop(1000000);
   }
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
   GpioCtrlRegs.GPAMUX1.all = 0;       // GPIO15 ... GPIO0 = General Puropse I/O
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

void InitSystem(void)
{
   EALLOW;
   SysCtrlRegs.WDCR = 0x0028;          // Watchdog enabled, 4.3 milliseconds
   SysCtrlRegs.PLLSTS.bit.DIVSEL = 2;
   SysCtrlRegs.PLLCR.bit.DIV = 10;     // 30MHz * 10 / 2 = 150 MHz
   SysCtrlRegs.HISPCP.all = 0x0001;
   SysCtrlRegs.LOSPCP.all = 0x0002;
   SysCtrlRegs.PCLKCR0.all = 0x0000;
   SysCtrlRegs.PCLKCR1.all = 0x0000;
   SysCtrlRegs.PCLKCR3.all = 0x0000;
   SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;
   EDIS;
}
//===========================================================================
// End of SourceCode.
//===========================================================================




//
//      GPIO : TMS320F28335
//
//
//###########################################################################
//
// FILE:    GPIO2.c
//
// TITLE:   DSP28335ControlCARD and Peripheral Explorer Board
//          Digital Input and Digital Output
//          read value from GPIO12 and copy the value to GPIO49
//          toggle GPIO9 and GPIO12
//          software delay loop; watchdog enabled
//
//###########################################################################

//###########################################################################
#include "DSP2833x_Device.h"

// Prototype statements for functions found within this file.
void Gpio_select(void);
void InitSystem(void);
void delay_loop(long);
//###########################################################################
//                      main code
//###########################################################################
void main(void)
{
    InitSystem();       // Basic Core Initialization

    DINT;               // Disable all interrupts

    Gpio_select();      // GPIO9, GPIO11, GPIO34 and GPIO49 as output
                        // to 4 LEDs at Peripheral Explorer)

    while(1)
    {
        GpioDataRegs.GPBDAT.bit.GPIO34=0;
        GpioDataRegs.GPADAT.bit.GPIO11=1;
        delay_loop(1500000);
        GpioDataRegs.GPBDAT.bit.GPIO34=1;
        GpioDataRegs.GPADAT.bit.GPIO11=0;
        delay_loop(1500000);
        GpioDataRegs.GPBDAT.bit.GPIO49 = GpioDataRegs.GPADAT.bit.GPIO12;
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
    GpioCtrlRegs.GPAMUX1.all = 0;       // GPIO15 ... GPIO0 = General Puropse I/O
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

void InitSystem(void)
{
    EALLOW;
    SysCtrlRegs.WDCR = 0x0028;          // Watchdog enabled, 4.3 milliseconds
    SysCtrlRegs.PLLSTS.bit.DIVSEL = 2;
    SysCtrlRegs.PLLCR.bit.DIV = 10;     // 30MHz * 10 / 2 = 150 MHz
    SysCtrlRegs.HISPCP.all = 0x0001;
    SysCtrlRegs.LOSPCP.all = 0x0002;
    SysCtrlRegs.PCLKCR0.all = 0x0000;
    SysCtrlRegs.PCLKCR1.all = 0x0000;
    SysCtrlRegs.PCLKCR3.all = 0x0000;
    SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;
    EDIS;
}

//===========================================================================
// End of SourceCode.
//===========================================================================
