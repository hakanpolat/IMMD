// 
//      Lab5_1: TMS320F28335
//      (c) Frank Bormann
//
//###########################################################################
//
// FILE:    Lab5_1.c
//
// TITLE:   DSP28335ControlCARD; Digital Output
//          4 - bit - counter at 4 LEDs LD1(GPIO9), LD2(GPIO11), LD3(GPIO34)
//          and LD4 (GPIO49)
//          software delay loop; watchdog disabled
//          template file for Lab5_1
//###########################################################################
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  3.0 | 02 May 2008 | F.B. | Lab5_1 for F28335;
//  3.1 | 06 Nov 2009 | F.B  | Lab5_1 for F28335 and PE revision5
//###########################################################################
#include "DSP2833x_Device.h"

// Prototype statements for functions found within this file.
void Gpio_select(void); 
extern void InitSysCtrl(void);
extern void InitSysCtrl(void);
interrupt void cpu_timer0_isr(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void InitCpuTimers(void);
extern void ConfigCpuTimer(struct CPUTIMER_VARS *, float, float);
interrupt void ePWM1_TZ_isr(void);

void Setup_ePWM1(void);
//###########################################################################
//                      main code
//###########################################################################
void main(void)
{


    int counter=0;      // binary counter for digital output

        InitSysCtrl();      // Basic Core Initialization
        EALLOW;
        SysCtrlRegs.WDCR = 0x00AF;
        EDIS;


        DINT;               // Disable all interrupts

        Gpio_select();      // GPIO9,GPIO11,GPIO34 and GPIO49 as output (LEDs @ peripheral explorer)
        Setup_ePWM1();
        InitPieCtrl();

        InitPieVectTable();

        EALLOW;
        PieVectTable.TINT0 = &cpu_timer0_isr;
        PieVectTable.EPWM1_TZINT = &ePWM1_TZ_isr;
        EDIS;
        InitCpuTimers();

        ConfigCpuTimer(&CpuTimer0, 150, 100000);

        PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
        PieCtrlRegs.PIEIER2.bit.INTx1 = 1;
        IER |= 3;
        EINT;
        ERTM;
        CpuTimer0Regs.TCR.bit.TSS = 0;

        while(1)
        {

                while(CpuTimer0.InterruptCount == 0);
                CpuTimer0.InterruptCount = 0;

                EALLOW;
                SysCtrlRegs.WDKEY = 0x55;   // service WD #1
                EDIS;
                counter++;

        }
}


void Gpio_select(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0;       // GPIO15 ... GPIO0 = General Puropse I/O
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1; // ePWM1A active
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1; // ePWM1B active
    GpioCtrlRegs.GPAMUX2.all = 0;       // GPIO31 ... GPIO16 = General Purpose I/O
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 3;
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
interrupt void cpu_timer0_isr(void){

    CpuTimer0.InterruptCount++;
    EALLOW;
    SysCtrlRegs.WDKEY = 0xAA;
    EDIS;

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

void Setup_ePWM1(void){
    EPwm1Regs.TBCTL.all = 0;
    EPwm1Regs.TBCTL.bit.CLKDIV = 7;            //CLKDIV = 14
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 7;        //HSPCLKDIV = 128
    EPwm1Regs.TBCTL.bit.CTRMODE = 2;         // Count up and down operation (10) = 2
    EPwm1Regs.AQCTLA.all = 0x0060;          //set ePWM1A to 1 on �CMPA - up match�
                                           //clear ePWM1A on event �CMPA - down match�
    EPwm1Regs.AQCTLB.all = 0x0600;         //clear ePWM1B on �CMPB - up match�
                                            //set ePWM1B to 1 on event �CMPB - down match�
                                            // we made reverse action to obtain complementary wave

    int fpwm = 1;       // in Hz
    long fcpu = 150000000; // we determine up in configcputimer

    EPwm1Regs.TBPRD = 0.5 * fcpu / (fpwm * EPwm1Regs.TBCTL.bit.CLKDIV * EPwm1Regs.TBCTL.bit.HSPCLKDIV);

    /*  TBPRD = 0.5*fcpu/(fpwm*CLKDIV*HSPCLKDIV)
         * fcpu = 60 MHz , fpwm = 1 KHz

         */
    EALLOW;
    EPwm1Regs.TZCTL.bit.TZA = 2;
    EPwm1Regs.TZCTL.bit.TZB = 2;
    //EPwm1Regs.TZSEL.bit.OSHT6 = 1;
    EPwm1Regs.TZSEL.bit.CBC6 = 1;
    EPwm1Regs.TZEINT.bit.CBC = 1;
    EDIS;
    EPwm1Regs.CMPA.half.CMPA = EPwm1Regs.TBPRD / 2;    //50%  duty cycle first
    EPwm1Regs.CMPB = EPwm1Regs.TBPRD / 2;               // 50% duty cycle first
}

void ePWM1_TZ_isr(void)
{
    EALLOW;
    EPwm1Regs.TZCLR.bit.CBC = 1;
    EPwm1Regs.TZCLR.bit.INT = 1;
    SysCtrlRegs.WDKEY = 0x55;
    EDIS;
    GpioDataRegs.GPATOGGLE.bit.GPIO9 = 1;   // toggle LED at GPIO9
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;
}




//===========================================================================
// End of SourceCode.
//===========================================================================
