
//#include <F2837xD_EPwm_defines.h>
//#include <F2837xD_EPwm.h>
//#include <F2837xD_GlobalPrototypes.h>

#include <F2837xD_Device.h>
#include <math.h>
#include <F2837xD_Pie_defines.h>
#include <F2837xD_Examples.h>
#include <F2837xD_Adc_defines.h>
#include <F2837xD_EPwm_defines.h>

__interrupt void epwm1_isr(void);
__interrupt void epwm2_isr(void);
__interrupt void epwm3_isr(void);
__interrupt void cpu_timer0_isr(void);
__interrupt void cpu_timer1_isr(void);
__interrupt void cpu_timer2_isr(void);
void Gpio_Select1();
#define ISRS_GROUP1  (M_INT3)
Uint64 denemelik1=0, denemelik2=0, denemelik3=0;

void InitializePWMs(void);
void InitEQep3Gpio_me(void);
void SetupSerialChannels(void);
Uint16 valuetobesent = 0b00000000;
Uint16 valuereceived = 0;
long double DelayValue = 20;
float CpuTimer1Value = 500;

/**
 * main.c
 */
int main(void)
{
    /**/
    InitSysCtrl();// first link F2837xD_SysCtrl.c
    InitPeripheralClocks();


    InitPieCtrl();
    // Disable CPU interrupts and clear all CPU interrupt flags:
    //
    IER = 0x0000;
    IFR = 0x0000;

    InitPieVectTable();

    //
    // For this example, only initialize the ePWM
    //
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;   /*disable epwm clock to initialize epwm modules*/
    CpuSysRegs.PCLKCR0.bit.GTBCLKSYNC =0;
    EDIS;
    InitCpuTimers();   // For this example, only initialize the Cpu Timers
    ConfigCpuTimer(&CpuTimer0, 100, 2000000); //2 miliseconds
    ConfigCpuTimer(&CpuTimer1, 100, 1000000); //1 seconds
    ConfigCpuTimer(&CpuTimer2, 100, 1000000); //2 seconds

    //CpuTimer0Regs.PRD.all = 0xFFFFFFFF;
    CpuTimer0Regs.TCR.all = 0x4000; // Use write-only instruction to set TSS bit = 0
    CpuTimer1Regs.TCR.all = 0x4000; // Use write-only instruction to set TSS bit = 0
    CpuTimer2Regs.TCR.all = 0x4000; // Use write-only instruction to set TSS bit = 0
    /*
    InitializePWMs();
    */
    InitPieCtrl();// first link F2837xD_PieCtrl.c
    IER = 0x0000;
    IFR = 0x0000;
    //PieVectTable.TIMER0_INT = &cpu_timer0_isr;
    InitPieVectTable();

    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.EPWM1_INT = &epwm1_isr;
    PieVectTable.EPWM2_INT = &epwm2_isr;
    PieVectTable.EPWM3_INT = &epwm3_isr;
    PieVectTable.TIMER0_INT = &cpu_timer0_isr;
    PieVectTable.TIMER1_INT = &cpu_timer1_isr;
    PieVectTable.TIMER2_INT = &cpu_timer2_isr;
    EDIS;

    Gpio_Select1();

    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    CpuSysRegs.PCLKCR0.bit.GTBCLKSYNC =1;

    EDIS;
    IER |= M_INT1;
    IER |= M_INT3;
    IER |= M_INT13;
    IER |= M_INT14;

    SetupSerialChannels();
    /*
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
    PieCtrlRegs.PIEIER3.bit.INTx2 = 1;
    PieCtrlRegs.PIEIER3.bit.INTx3 = 1;
    */
    EINT;  // Enable Global interrupt INTM
    ERTM;  // Enable Global realtime interrupt DBGM
    ScibRegs.SCITXBUF.bit.TXDT = 0b01010101;
    while(1)
    {
#if 1
        DELAY_US(200);
        if(ScibRegs.SCIFFTX.bit.TXFFST!=0)
        {
            //DelayValue+=1;
        }

        if(ScicRegs.SCIFFRX.bit.RXFFST!=0)
        {
            //DelayValue-=1;
        }
        DELAY_US(DelayValue);
        //while (ScibRegs.SCIFFTX.bit.TXFFST != 0) {}
        //while (ScicRegs.SCIFFRX.bit.RXFFST != 0) {}
        if(ScibRegs.SCITXBUF.bit.TXDT==0b01010101)
        {
            ScibRegs.SCITXBUF.bit.TXDT=0b00010101;
        }
        else if(ScibRegs.SCITXBUF.bit.TXDT==0b00010101)
        {
            ScibRegs.SCITXBUF.bit.TXDT = 0b11111110;
        }
        else if(ScibRegs.SCITXBUF.bit.TXDT==0b11111110)
        {
            ScibRegs.SCITXBUF.bit.TXDT = 0b01010101;
        }
        valuereceived = ScicRegs.SCIRXBUF.bit.SAR;
#endif
#if 0
        DELAY_US(1000);
        if(ScibRegs.SCIFFTX.bit.TXFFST!=0)
        {
            CpuTimer1Value+=1;
        }

        if(ScicRegs.SCIFFRX.bit.RXFFST!=0)
        {
            CpuTimer1Value-=1;
        }
        ConfigCpuTimer(&CpuTimer1, 100, CpuTimer1Value); //1 seconds
        CpuTimer1Regs.TCR.bit.TSS   = 0;
#endif
    }
}

void InitializePWMs(void)
{
    InitEPwm1Gpio();
    InitEPwm2Gpio();
    EALLOW;
    /***********Configure GPIO Pins*************/
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;    // Disable pull-up on GPIO0 (EPWM1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;    // Disable pull-up on GPIO1 (EPWM1B)

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B

    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;    // Disable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;    // Disable pull-up on GPIO3 (EPWM2B)

    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B

    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;    // Disable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;    // Disable pull-up on GPIO5 (EPWM3B)

    GpioCtrlRegs.GPAGMUX1.bit.GPIO4 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B
    /*******************************************/
    EDIS;
    //InitEPwm3Gpio();
    EALLOW;
    /*init epwm1 - generates a and b signals which are 90 degrees out of phase, pwm1b leads pwm1a*/
    EPwm1Regs.TBPRD = 50000;       // Set timer period 500 TBCLKs
    EPwm1Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm1Regs.TBCTR = 0x0000;                  // Clear counter

    EPwm1Regs.CMPA.bit.CMPA = 250;    // Set compare A value
    EPwm1Regs.CMPB.bit.CMPB = 0;    // Set Compare B value

    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up and down
    EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;        // Disable phase loading
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 5;       // Clock ratio to SYSCLKOUT
    EPwm1Regs.TBCTL.bit.CLKDIV = 6;
    EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;


    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_IMMEDIATE;
    EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_IMMEDIATE;
    //EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // Load on Zero
    //EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    EPwm1Regs.AQCTLA.bit.CAU = AQ_SET;            // Set PWM1A on event A, up
                                                  // count
    EPwm1Regs.AQCTLA.bit.CAD = AQ_CLEAR;          // Clear PWM1A on event A,
                                                  // down count
    EPwm1Regs.AQCTLB.bit.ZRO = AQ_SET;

    EPwm1Regs.AQCTLB.bit.PRD = AQ_CLEAR;
    EPwm1Regs.ETSEL.bit.INTSEL = 1;//when TBCTR == 0
    EPwm1Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    EPwm1Regs.ETPS.bit.INTPRD = 1;           // Generate INT on first event


    /*init epwm1 end*/

    /*init epwm2 - generates the index event signal*/
    EPwm2Regs.TBPRD = 12500;       // Set timer period 500 TBCLKs
    EPwm2Regs.TBPHS.bit.TBPHS = 0x0000;        // Phase is 0
    EPwm2Regs.TBCTR = 0x0000;                  // Clear counter

    EPwm2Regs.CMPA.bit.CMPA = 49500;    // Set compare A value
    EPwm2Regs.CMPB.bit.CMPB = 0;    // Set Compare B value

    EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UPDOWN; // Count up and down
    EPwm2Regs.TBCTL.bit.PHSEN = TB_ENABLE;        // Disable phase loading
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = 5;       // Clock ratio to SYSCLKOUT
    EPwm2Regs.TBCTL.bit.CLKDIV = 6;
    EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_IN;


    EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_IMMEDIATE;
    EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_IMMEDIATE;
    //EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO; // Load on Zero
    //EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

    EPwm2Regs.AQCTLA.bit.CAU = AQ_SET;
    EPwm2Regs.AQCTLA.bit.PRD = AQ_CLEAR;
    EPwm2Regs.ETSEL.bit.INTSEL = 1;//when TBCTR == 0
    EPwm2Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    EPwm2Regs.ETPS.bit.INTPRD = 1;
    //EPwm1Regs.AQCTLB.bit.ZRO = AQ_SET;

    //EPwm1Regs.AQCTLB.bit.PRD = AQ_CLEAR;
    /*init epwm2 end*/
    EDIS;

}


void InitEQep3Gpio_me(void)
{
    EALLOW;

    /* Disable internal pull-up for the selected output pins
       for reduced power consumption */
    // Pull-ups can be enabled or disabled by the user.
    // Comment out other unwanted lines.
    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;     // Disable pull-up on GPIO6 (EQEP3A)
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;     // Disable pull-up on GPIO7 (EQEP3B)
    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 1;     // Disable pull-up on GPIO8 (EQEP3S)
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;     // Disable pull-up on GPIO9 (EQEP3I)


    /* Synchronize inputs to SYSCLK */
    // Synchronization can be enabled or disabled by the user.
    // Comment out other unwanted lines.

    GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0;    // Sync GPIO6 to SYSCLK  (EQEP3A)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO7 = 0;    // Sync GPIO7 to SYSCLK  (EQEP3B)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO8 = 0;    // Sync GPIO8 to SYSCLK  (EQEP3S)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 0;    // Sync GPIO9 to SYSCLK  (EQEP3I)


    /* Configure EQEP-1 pins using GPIO regs*/
    // This specifies which of the possible GPIO pins will be EQEP3 functional pins.
    // Comment out other unwanted lines.

    GpioCtrlRegs.GPAGMUX1.bit.GPIO6 = 1;    // Configure GPIO6 as EQEP3A
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;     // Configure GPIO6 as EQEP3A
    GpioCtrlRegs.GPAGMUX1.bit.GPIO7 = 1;    // Configure GPIO7 as EQEP3B
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;     // Configure GPIO7 as EQEP3B
    GpioCtrlRegs.GPAGMUX1.bit.GPIO8 = 1;    // Configure GPIO8 as EQEP3S
    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;     // Configure GPIO8 as EQEP3S
    GpioCtrlRegs.GPAGMUX1.bit.GPIO9 = 1;    // Configure GPIO9 as EQEP3I
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;     // Configure GPIO9 as EQEP3I


    EDIS;
}
__interrupt void epwm1_isr(void)
{
    /*
    DINT;
    GpioDataRegs.GPASET.bit.GPIO31 = 1; //blue
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
    PieCtrlRegs.PIEIFR3.bit.INTx2 = 1,
    IER |= M_INT3;
    EPwm1Regs.ETCLR.bit.INT = 1;

    EINT;
    */
    denemelik1++;
    //DELAY_US(100000);

    GpioDataRegs.GPACLEAR.bit.GPIO31 = 1;   //blue
    EPwm1Regs.ETCLR.bit.INT = 1;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

}
__interrupt void epwm2_isr(void)
{
    GpioDataRegs.GPBSET.bit.GPIO34 = 1; //red

    denemelik2++;
    //DELAY_US(50000);

    EPwm2Regs.ETCLR.bit.INT = 1;

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
    GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1; //red

}
__interrupt void epwm3_isr(void)
{

    EPwm3Regs.ETCLR.bit.INT = 1;


    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
__interrupt void cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

__interrupt void cpu_timer1_isr(void)
{
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;   //blue
    CpuTimer1.InterruptCount++;
    /*
    ScibRegs.SCITXBUF.bit.TXDT = valuetobesent++;
    valuereceived = ScicRegs.SCIRXBUF.bit.SAR;
    */
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

__interrupt void cpu_timer2_isr(void)
{
    CpuTimer2.InterruptCount++;

}
void Gpio_Select1()
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0;
    GpioCtrlRegs.GPAMUX2.all = 0;
    GpioCtrlRegs.GPAGMUX1.all = 0;
    GpioCtrlRegs.GPAGMUX2.all = 0;

    GpioCtrlRegs.GPBMUX1.all = 0;
    GpioCtrlRegs.GPBMUX2.all = 0;
    GpioCtrlRegs.GPBGMUX1.all = 0;
    GpioCtrlRegs.GPBGMUX2.all = 0;

    GpioCtrlRegs.GPCMUX1.all = 0;
    GpioCtrlRegs.GPCMUX2.all = 0;
    GpioCtrlRegs.GPCGMUX1.all = 0;
    GpioCtrlRegs.GPCGMUX2.all = 0;

    GpioCtrlRegs.GPDMUX1.all = 0;
    GpioCtrlRegs.GPDMUX2.all = 0;
    GpioCtrlRegs.GPDGMUX1.all = 0;
    GpioCtrlRegs.GPDGMUX2.all = 0;

    GpioCtrlRegs.GPEMUX1.all = 0;
    GpioCtrlRegs.GPEMUX2.all = 0;
    GpioCtrlRegs.GPEGMUX1.all = 0;
    GpioCtrlRegs.GPEGMUX2.all = 0;

    GpioCtrlRegs.GPFMUX1.all = 0;
    //GpioCtrlRegs.GPFMUX2.all = 0;
    GpioCtrlRegs.GPFGMUX1.all = 0;
    //GpioCtrlRegs.GPFGMUX2.all = 0;

    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0; // enable pull up
    GpioDataRegs.GPASET.bit.GPIO31 = 1; // Load output latch. Recommended in rm
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1; // set it as output

    GpioCtrlRegs.GPBPUD.bit.GPIO34 = 0; // enable pull up
    GpioDataRegs.GPBSET.bit.GPIO34 = 1; // Load output latch. Recommended in rm
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1; // set it as output



    GpioDataRegs.GPACLEAR.bit.GPIO31 = 1;
    GpioDataRegs.GPBSET.bit.GPIO34 = 1;


    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 2;    /*set as SCITXDB*/
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 2;    /*set as SCIRXDB*/

    GpioCtrlRegs.GPEGMUX1.bit.GPIO139 = 1;
    GpioCtrlRegs.GPEMUX1.bit.GPIO139  = 2;  /*set as SCIRXDC*/
    GpioCtrlRegs.GPBGMUX2.bit.GPIO56  = 1;
    GpioCtrlRegs.GPBMUX2.bit.GPIO56   = 2;  /*set as SCITXDC*/


    EDIS;

    /*TODO pullup settings can be done here*/
    /***************************************/

}
void SetupSerialChannels(void)
{
    /*LSPCLK = SYSCLK/4 (25MHz)*/
    /*SCIB will be transmitter */
    /*SCIC will be receiver    */
    /*SCI - B settings --- start*/
    ScibRegs.SCICCR.bit.STOPBITS        = 0;    /*one stop bit*/
    ScibRegs.SCICCR.bit.PARITY          = 0;    /*odd parity*/
    ScibRegs.SCICCR.bit.PARITYENA       = 1;    /*parity is enabled*/               /*be careful*/
    ScibRegs.SCICCR.bit.LOOPBKENA       = 0;    /*loop back disabled*/              /*be careful*/
    ScibRegs.SCICCR.bit.ADDRIDLE_MODE   = 0;    /*for ipc - dont care*/
    ScibRegs.SCICCR.bit.SCICHAR         = 7;    /*8 bits of char of length*/

    ScibRegs.SCICTL1.bit.RXERRINTENA    = 1;    /*enable receive error interrupt*/
    ScibRegs.SCICTL1.bit.SWRESET        = 1;    /*re-enable sci*/                   /*be careful*/
    ScibRegs.SCICTL1.bit.TXWAKE         = 1;    /*ipc related dont care*/           /*be careful*/
    ScibRegs.SCICTL1.bit.SLEEP          = 0;    /*sleep mode is disabled*/
    ScibRegs.SCICTL1.bit.RXENA          = 0;    /*disable rx for this*/
    ScibRegs.SCICTL1.bit.TXENA          = 1;    /*enable tx for this*/

    ScibRegs.SCIHBAUD.all = 0;                  /*both set for baud 115200*/
    ScibRegs.SCILBAUD.all = 53;                 /*both set for baud 115200*/

    ScibRegs.SCICTL2.bit.TXRDY          = 1;    /*this bit shows whether it is ok to get the next character*/
                                                /*1 is for showing that the transmitter ready to receive next character*/
    ScibRegs.SCICTL2.bit.TXEMPTY        = 0;    /*tx buffer or shift register or both are full*/
                                                /*1 is for both empty*/
    ScibRegs.SCICTL2.bit.RXBKINTENA     = 0;    /*rxrdy and brkdt interrupts are disabled*/
    ScibRegs.SCICTL2.bit.TXINTENA       = 1;    /*tx int enabled*/

    ScibRegs.SCIRXST.all                = 0x0000;
    ScibRegs.SCIRXEMU.bit.ERXDT         = 0x0000;   /*Receive emulation buffer data*/

    /*for SCIB not important for now*/
    ScibRegs.SCIRXBUF.bit.SCIFFFE       = 0;        /*SCI FIFO Framing error flag bit*/
    ScibRegs.SCIRXBUF.bit.SCIFFPE       = 0;        /*SCI FIFO parity error flag bit*/
    ScibRegs.SCIRXBUF.bit.SAR           = 0x00;     /*this is the receive buffer*/

    ScibRegs.SCITXBUF.bit.TXDT          = 0b01101001;

    ScibRegs.SCIFFTX.bit.SCIRST         = 1;        /*1 to go*/
    ScibRegs.SCIFFTX.bit.SCIFFENA       = 1;        /*enable fifo enhancements*/
    ScibRegs.SCIFFTX.bit.TXFIFORESET    = 1;        /*Re-enable transmit FIFO operation*/
    ScibRegs.SCIFFTX.bit.TXFFST         = 0;        /*see the number of elements in fifo*/      /*nicetohave*/
    // ScibRegs.SCIFFTX.bit.TXFFINT                 /*read only bit, interrupt occured if it is 1*/
    ScibRegs.SCIFFTX.bit.TXFFINTCLR     = 1;        /*clear the interurpt flag*/
    ScibRegs.SCIFFTX.bit.TXFFIENA       = 1;        /*transmit fifo interrupt enable*/
    ScibRegs.SCIFFTX.bit.TXFFIL         = 0;        /*for generating fifo interrupt after some threshold value*/

    //ScibRegs.SCIFFRX.bit.RXFFOVF        = 1;      /*read only bit, shows if the receive fifo is overflowed*/
    ScibRegs.SCIFFRX.bit.RXFFOVRCLR     = 1;        /*clear the overflow flag*/
    ScibRegs.SCIFFRX.bit.RXFIFORESET    = 1;        /*Re-enable receive FIFO operation*/
    ScibRegs.SCIFFRX.bit.RXFFST         = 0;        /*see the number of elements in fifo*/
    //ScibRegs.SCIFFRX.bit.RXFFINT        = 1;      /*read only bit, interrupt occured if it is 1*/
    ScibRegs.SCIFFRX.bit.RXFFINTCLR     = 1;        /*clear the interrupt flag*/
    ScibRegs.SCIFFRX.bit.RXFFIENA       = 1;        /*receive fifo interrupt enable*/
    ScibRegs.SCIFFRX.bit.RXFFIL         = 0;        /*for generating fifo interrupt after some threshold value*/

    ScibRegs.SCIFFCT.bit.ABD            = 0;        /**/
    ScibRegs.SCIFFCT.bit.ABDCLR         = 1;        /*clear abd flag*/
    ScibRegs.SCIFFCT.bit.CDC            = 0;        /*Disables auto-baud alignment*/
    //ScibRegs.SCIFFCT.bit.FFTXDLY        = 0;

    ScibRegs.SCIPRI.bit.FREESOFT        = 1;        /* Complete current receive/transmit sequence before stopping*/
    /*SCI - B settings --- end*/

    /*SCIB will be transmitter */
    /*SCIC will be receiver    */
    /*SCI - C settings --- start*/
    ScicRegs.SCICCR.bit.STOPBITS        = 0;    /*one stop bit*/
    ScicRegs.SCICCR.bit.PARITY          = 0;    /*odd parity*/
    ScicRegs.SCICCR.bit.PARITYENA       = 1;    /*parity is enabled*/               /*be careful*/
    ScicRegs.SCICCR.bit.LOOPBKENA       = 0;    /*loop back disabled*/              /*be careful*/
    ScicRegs.SCICCR.bit.ADDRIDLE_MODE   = 0;    /*for ipc - dont care*/
    ScicRegs.SCICCR.bit.SCICHAR         = 7;    /*8 bits of char of length*/

    ScicRegs.SCICTL1.bit.RXERRINTENA    = 1;    /*enable receive error interrupt*/
    ScicRegs.SCICTL1.bit.SWRESET        = 1;    /*re-enable sci*/                   /*be careful*/
    ScicRegs.SCICTL1.bit.TXWAKE         = 1;    /*ipc related dont care*/           /*be careful*/
    ScicRegs.SCICTL1.bit.SLEEP          = 0;    /*sleep mode is disabled*/
    ScicRegs.SCICTL1.bit.RXENA          = 1;    /*enable rx for this*/
    ScicRegs.SCICTL1.bit.TXENA          = 0;    /*disable tx for this*/

    ScicRegs.SCIHBAUD.all = 0;                  /*both set for baud 115200*/
    ScicRegs.SCILBAUD.all = 53;                 /*both set for baud 115200*/

    ScicRegs.SCICTL2.bit.TXRDY          = 1;    /*this bit shows whether it is ok to get the next character*/
                                                /*1 is for showing that the transmitter ready to receive next character*/
    ScicRegs.SCICTL2.bit.TXEMPTY        = 0;    /*tx buffer or shift register or both are full*/
                                                /*1 is for both empty*/
    ScicRegs.SCICTL2.bit.RXBKINTENA     = 1;    /*rxrdy and brkdt interrupts are enabled*/
    ScicRegs.SCICTL2.bit.TXINTENA       = 0;    /*tx int disabled*/

    ScicRegs.SCIRXST.all                = 0x0000;
    ScicRegs.SCIRXEMU.bit.ERXDT         = 0x0000;   /*Receive emulation buffer data*/

    /*for SCIB not important for now*/
    ScicRegs.SCIRXBUF.bit.SCIFFFE       = 0;        /*SCI FIFO Framing error flag bit*/
    ScicRegs.SCIRXBUF.bit.SCIFFPE       = 0;        /*SCI FIFO parity error flag bit*/
    ScicRegs.SCIRXBUF.bit.SAR           = 0x00;     /*this is the receive buffer*/

    //ScicRegs.SCITXBUF.bit.TXDT          = 0b01101001;

    ScicRegs.SCIFFTX.bit.SCIRST         = 1;        /*1 to go*/
    ScicRegs.SCIFFTX.bit.SCIFFENA       = 1;        /*enable fifo enhancements*/
    ScicRegs.SCIFFTX.bit.TXFIFORESET    = 1;        /*Re-enable transmit FIFO operation*/
    ScicRegs.SCIFFTX.bit.TXFFST         = 0;        /*see the number of elements in fifo*/      /*nicetohave*/
    // ScibRegs.SCIFFTX.bit.TXFFINT                 /*read only bit, interrupt occured if it is 1*/
    ScicRegs.SCIFFTX.bit.TXFFINTCLR     = 1;        /*clear the interurpt flag*/
    ScicRegs.SCIFFTX.bit.TXFFIENA       = 1;        /*transmit fifo interrupt enable*/
    ScicRegs.SCIFFTX.bit.TXFFIL         = 0;        /*for generating fifo interrupt after some threshold value*/

    //ScibRegs.SCIFFRX.bit.RXFFOVF        = 1;      /*read only bit, shows if the receive fifo is overflowed*/
    ScicRegs.SCIFFRX.bit.RXFFOVRCLR     = 1;        /*clear the overflow flag*/
    ScicRegs.SCIFFRX.bit.RXFIFORESET    = 1;        /*Re-enable receive FIFO operation*/
    ScicRegs.SCIFFRX.bit.RXFFST         = 0;        /*see the number of elements in fifo*/
    //ScibRegs.SCIFFRX.bit.RXFFINT        = 1;      /*read only bit, interrupt occured if it is 1*/
    ScicRegs.SCIFFRX.bit.RXFFINTCLR     = 1;        /*clear the interrupt flag*/
    ScicRegs.SCIFFRX.bit.RXFFIENA       = 1;        /*receive fifo interrupt enable*/
    ScicRegs.SCIFFRX.bit.RXFFIL         = 0;        /*for generating fifo interrupt after some threshold value*/

    ScicRegs.SCIFFCT.bit.ABD            = 0;        /**/
    ScicRegs.SCIFFCT.bit.ABDCLR         = 1;        /*clear abd flag*/
    ScicRegs.SCIFFCT.bit.CDC            = 0;        /*Disables auto-baud alignment*/
    //ScibRegs.SCIFFCT.bit.FFTXDLY        = 0;

    ScicRegs.SCIPRI.bit.FREESOFT        = 1;        /* Complete current receive/transmit sequence before stopping*/
    /*SCI - C settings --- end*/


}
