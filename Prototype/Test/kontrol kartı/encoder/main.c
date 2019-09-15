#include <F2837xD_Device.h>
#include <math.h>

#define HIGHSPEED           1
#define LOWSPEED            0
#define CLOCKWISE           1
#define COUNTERCLOCKWISE    0
#define CLOCKHZ             100000000 //200MHz
#define EQEP3UNITTIMECOEFF   (double)CLOCKHZ/((double)EQep3Regs.QUPRD)
#define ENCODERTICKCOUNT    16000
#define PI 3.14159
#define ENCODERRESOLUTION   3600
#define NUMBEROFTICKSPERQAB 4
#define ENCODERMAXTICKCOUNT ENCODERRESOLUTION*NUMBEROFTICKSPERQAB
#define NUMBEROFPOLEPAIRS   10

#define VBYFCONTROLENABLE   0

float32 fAngularMechanicalPosition = 0;  // mechanical, radians
float32 fAngularMechanicalSpeed = 0; // mechanical, radians/second
unsigned int uiUpEventTickValue = 16;
float fAngularElectricalPosition; // electrical, radians
float fAngularElectricalSpeed; //electrical, radians/second


float32 dAngularSpeed=0;
float32 fRPM=0;
float32 fAngularPosition;
float32 fAngularSpeed;
float32 fAngularMechanicalSpeedRPM;
double dTimerCoefficient=0;
unsigned int uiHighSpeedFlag=0; //0:low speed, 1 high speed
Uint32 uiPositionLatched = 0;
Uint32 uiPositionLatchedPrevious = 0;
Uint16 uiDirectonOfRotation = 0; //CW=0,CCW=1
Uint32 uiPositionTotalCounted;
Uint32 ticktimes=0;
float32 maxangle = 0;
unsigned int uiUpEventValue=16;

#if 4
float32 fVbyfFreqSteps        = 10;        //hz, each push on the button will increase the fundamental frequency by that value
float32 fFrequencySaturation  = 50;       //hz, max value for fundamental frequency
float32 fVrated               = 230.1;    //Vrms, ma value is calculated depending on this value when there is a change in frequency
float32 fFrequencyInitial     = 25;        //hz, initial frequency value
float32 fAppliedFrequency     = 0;        //hz, this is the applied frequency to the motor
float32 vbyf_ma_value         = 0;
float32 fVdc                  = 750;
#endif
unsigned int numberoftimes = 0;
unsigned int numberoftimesmax = 0;

void Gpio_Select1();
void InitSystem();
void InitEpwm1();
void InitEpwm2();
void InitEpwm3();
void InitEQep3Gpio_me(void);
void InitEQep3Module(void);
void PositionSpeedCalculate(void);
#if VBYFCONTROLENABLE
interrupt void isr_Increment_freq(void);
interrupt void isr_Decrement_freq(void);
#endif

//interrupt void cpu_timer0_isr(void);
__interrupt void cpu_timer0_isr(void);
__interrupt void cpu_timer1_isr(void);
__interrupt void cpu_timer2_isr(void);
__interrupt void epwm1_isr(void);
__interrupt void epwm2_isr(void);
__interrupt void epwm3_isr(void);

int main(void)
{

    InitSysCtrl();// first link F2837xD_SysCtrl.c
    EALLOW;
    //ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 0;
    CpuSysRegs.PCLKCR2.bit.EPWM1 = 1;/*enable clock for epwm1*/
    CpuSysRegs.PCLKCR2.bit.EPWM2 = 1;/*enable clock for epwm1*/
    CpuSysRegs.PCLKCR2.bit.EPWM3 = 1;/*enable clock for epwm1*/
    CpuSysRegs.PCLKCR2.bit.EPWM4 = 1;/*enable clock for epwm1*/
    CpuSysRegs.PCLKCR4.bit.EQEP3 = 1;/*enable clock for EQEP3*/
    InitPeripheralClocks();

    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC =0;
    CpuSysRegs.PCLKCR0.bit.GTBCLKSYNC =0;
    /*GPIO selection is as follows
     *GPIO0 generates   A signal of the encoder (check the angle)
     *GPIO2 generates   B signal of the encoder
     *GPIO4 generates   I signal of the encoder (lower the duty cycle)
     *
     *GPIO6 reads       A signal of the encoder
     *GPIO7 reads       B signal of the encoder
     *GPI08 reads       S signal
     *GPIO9 reads       I signal of the encoder
     * */
    EDIS;
    Gpio_Select1();
    InitEPwm1Gpio();

    EALLOW;
    /***********Configure GPIO Pins*************/
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;    // Disable pull-up on GPIO0 (EPWM1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;    // Disable pull-up on GPIO1 (EPWM1B)

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B

    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;    // Disable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;    // Disable pull-up on GPIO3 (EPWM2B)

    //GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
    //GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B
    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;   // Configure GPIO2 as GPIO
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;  //set as output
    GpioDataRegs.GPACLEAR.bit.GPIO2 = 0;

    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;    // Disable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;    // Disable pull-up on GPIO5 (EPWM3B)

    GpioCtrlRegs.GPAGMUX1.bit.GPIO4 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B
    /*******************************************/
    EDIS;
    DINT; //disable the interrupts

    InitPieCtrl();// first link F2837xD_PieCtrl.c
    IER = 0x0000;
    IFR = 0x0000;
    //PieVectTable.TIMER0_INT = &cpu_timer0_isr;
    InitPieVectTable();

    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.TIMER0_INT = &cpu_timer0_isr;
    PieVectTable.TIMER1_INT = &cpu_timer1_isr;
    PieVectTable.TIMER2_INT = &cpu_timer2_isr;
    PieVectTable.EPWM1_INT = &epwm1_isr;
    PieVectTable.EPWM2_INT = &epwm2_isr;
    PieVectTable.EPWM3_INT = &epwm3_isr;
    EDIS;
#if VBYFCONTROLENABLE
    fAppliedFrequency = fFrequencyInitial;
    vbyf_ma_value = fAppliedFrequency*(fVrated/fFrequencySaturation)*(sqrt(3)/(fVdc*0.612));
    EALLOW;
    /*vbyfcontrol*/
    GpioCtrlRegs.GPBGMUX1.bit.GPIO32 = 0;
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO32 = 0;   // GPIO32 = input /*BUTTON for frequency increment*/
    PieVectTable.XINT1_INT = &isr_Increment_freq;
    XintRegs.XINT1CR.bit.ENABLE = 1;    /*enable XINT interrupt*/
    XintRegs.XINT1CR.bit.POLARITY = 1;  /*rising edge trigger*/
    GPIO_SetupXINT1Gpio(32);            /*set GPIO32 as the source of the trigger*/
    EDIS;
    /*hakansrc: WARNING -- donot merge these EDIS and EALLOW*/
    EALLOW;
    GpioCtrlRegs.GPAGMUX2.bit.GPIO19 = 0;
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO19 = 0;     // GPIO19 = input /*BUTTON for frequency decrement*/
    PieVectTable.XINT2_INT = &isr_Decrement_freq;
    XintRegs.XINT2CR.bit.ENABLE = 1;    /*enable XINT interrupt*/
    XintRegs.XINT2CR.bit.POLARITY = 1;  /*rising edge trigger*/
    GPIO_SetupXINT2Gpio(19);            /*set GPIO32 as the source of the trigger*/
    EDIS;

    /**/
#endif
    EALLOW;
    InitEpwm1();    /*pwm 1a and 1b generates eqep a and b signals*/
    /*InitEpwm2();    /*pwm 2a generates eqep index signal*/
    InitEpwm3();
    EDIS;
    EALLOW;
    InitEQep3Gpio_me();
    EDIS;
    EALLOW;
    InitEQep3Module();
    EDIS;
    InitCpuTimers();   // For this example, only initialize the Cpu Timers
    ConfigCpuTimer(&CpuTimer0, 200, 1000); //2 miliseconds
    ConfigCpuTimer(&CpuTimer1, 100, 11428571); //1 seconds
    ConfigCpuTimer(&CpuTimer2, 200, 1000000); //2 seconds

    //CpuTimer0Regs.PRD.all = 0xFFFFFFFF;
    CpuTimer0Regs.TCR.all = 0x4000; // Use write-only instruction to set TSS bit = 0
    CpuTimer1Regs.TCR.all = 0x4000; // Use write-only instruction to set TSS bit = 0
    CpuTimer2Regs.TCR.all = 0x4000; // Use write-only instruction to set TSS bit = 0
    IER |= M_INT1;
    IER |= M_INT3;
    IER |= M_INT13;
    IER |= M_INT14;

    PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
    PieCtrlRegs.PIEIER3.bit.INTx2 = 1;
    PieCtrlRegs.PIEIER3.bit.INTx3 = 1;
    PieCtrlRegs.PIEIER1.bit.INTx4 = VBYFCONTROLENABLE;   /*VBYFCONTROLENABLE: used for XINT1_ISR enabling*/
    PieCtrlRegs.PIEIER1.bit.INTx5 = VBYFCONTROLENABLE;   /*VBYFCONTROLENABLE: used for XINT2_ISR enabling*/

    EINT;  // Enable Global interrupt INTM
    ERTM;  // Enable Global realtime interrupt DBGM
    EALLOW;
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC =1;
    CpuSysRegs.PCLKCR0.bit.GTBCLKSYNC =1;

    EDIS;
    EALLOW;
    WdRegs.WDCR.all = 0x0028;//set the watch dog
    EDIS;
    while(1)
    {
        while(!CpuTimer0.InterruptCount)
        {

        }
        WdRegs.WDKEY.all = 0x55;// serve to watchdog
        CpuTimer0.InterruptCount = 0;

    }
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
    GpioCtrlRegs.GPFMUX2.all = 0;
    GpioCtrlRegs.GPFGMUX1.all = 0;
    GpioCtrlRegs.GPFGMUX2.all = 0;

    GpioCtrlRegs.GPAPUD.bit.GPIO31 = 0; // enable pull up
    GpioDataRegs.GPASET.bit.GPIO31 = 1; // Load output latch. Recommended in rm
    GpioCtrlRegs.GPADIR.bit.GPIO31 = 1; // set it as output

    GpioCtrlRegs.GPBPUD.bit.GPIO34 = 0; // enable pull up
    GpioDataRegs.GPBSET.bit.GPIO34 = 1; // Load output latch. Recommended in rm
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1; // set it as output



    GpioDataRegs.GPACLEAR.bit.GPIO31 = 1;
    GpioDataRegs.GPBSET.bit.GPIO34 = 1;




    EDIS;

    /*TODO pullup settings can be done here*/
    /***************************************/

}
void InitSystem(void)
{
    EALLOW;
    WdRegs.WDCR.all = 0x0028;         // Watchdog enabled, 4.3 milliseconds
    CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1; //enable cputimer0
    EDIS;
}
__interrupt void cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;
    WdRegs.WDKEY.all = 0xAA;

    // Acknowledge this interrupt to receive more interrupts from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

__interrupt void cpu_timer1_isr(void)
{
    CpuTimer1.InterruptCount++;
    // The CPU acknowledges the interrupt.
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = 1;
    GpioDataRegs.GPASET.bit.GPIO2 = 1;
    DELAY_US(10);
    GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;
}

__interrupt void cpu_timer2_isr(void)
{
    CpuTimer2.InterruptCount++;
    // The CPU acknowledges the interrupt.
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;

}
__interrupt void epwm1_isr(void)
{


    EPwm1Regs.ETCLR.bit.INT = 1;

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
__interrupt void epwm2_isr(void)
{
    EPwm2Regs.ETCLR.bit.INT = 1;
    //GpioDataRegs.GPATOGGLE.bit.GPIO31 = 1;
    //EPwm2Regs.TBCTR = 0x0000;                     // Clear counter

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
__interrupt void epwm3_isr(void)
{
    fAngularMechanicalPosition = ((float32) EQep3Regs.QPOSCNT
            / (ticktimes)) * 360; // mech-degrees

    uiDirectonOfRotation = EQep3Regs.QEPSTS.bit.QDF; // Quadrature direction flag: 1=Clockwise
    if (EQep3Regs.QEPSTS.bit.UPEVNT == 1)
    {
        fAngularMechanicalSpeed = 1.0*(((float32) CLOCKHZ / (float32) 2.0)/ (float32) EQep3Regs.QCPRD) * (float32) 2* (float32) PI;/*TODO; parameterize the values,uiUpEventTickValue comes from UPPS value = 16 for now,128 comes from ccps value*/
        fAngularMechanicalSpeed = fAngularMechanicalSpeed  / (float32) (ENCODERTICKCOUNT);
        fAngularMechanicalSpeedRPM = fAngularMechanicalSpeed * (float32) 60.0
                / (2 * PI);
        fAngularElectricalSpeed = fAngularMechanicalSpeed * NUMBEROFPOLEPAIRS; //electrical, radians/second

        EQep3Regs.QEPSTS.bit.UPEVNT = 1;              // Clear status flag
    }
    if(EQep3Regs.QPOSCNT>ticktimes)
    {
       ticktimes = EQep3Regs.QPOSCNT;
    }
    if(maxangle<fAngularMechanicalPosition)
    {
       maxangle = fAngularMechanicalPosition;
    }
    // Update the CMPA and CMPB values
    //update_compare(&epwm1_info);
    // Clear INT flag for this timer
    EPwm3Regs.ETCLR.bit.INT = 1;
    //GpioDataRegs.GPATOGGLE.bit.GPIO1  = 1;
    /*
     *if(EPwm1Regs.CMPA.half.CMPA>=45000)
     *    EPwm1Regs.CMPA.half.CMPA=0;    // Set compare A value
     *else
     *    EPwm1Regs.CMPA.half.CMPA+=1000;
     */

    // Acknowledge this interrupt to receive more interrupts from group 3
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}
void InitEpwm1(void){
    EPwm1Regs.TBPRD = 17858;
    EPwm1Regs.TBPHS.half.TBPHS = 0;          // Phase is 0
    EPwm1Regs.TBCTR = 0x0000;                     // Clear counter
    EPwm1Regs.TBCTL.bit.SYNCOSEL = 1;
    EPwm1Regs.TBCTL.bit.PHSEN = 0;

    EPwm1Regs.CMPA.half.CMPA = 17858/2;    // Set compare A value
    EPwm1Regs.CMPB.half.CMPB = 0;    // Set Compare B value

    EPwm1Regs.TBCTL.bit.CTRMODE = 2; // Count up and douwn
    EPwm1Regs.TBCTL.bit.PHSEN = 0; //disable phase loading
    EPwm1Regs.TBCTL.bit.CLKDIV = 1; //TBCLOK = EPWMCLOCK/(64*10) = 156250Hz
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 1;

    //EPwm1Regs.CMPCTL.bit.SHDWAMODE = 1;//only active registers are used
    //EPwm1Regs.CMPCTL.bit.SHDWBMODE = 1;//only active registers are used
    EPwm1Regs.TBCTL.bit.PHSDIR = 1;


    EPwm1Regs.AQCTLB.bit.CAU = 2; //set high
    EPwm1Regs.AQCTLB.bit.CAD = 1; //setlow

    EPwm1Regs.AQCTLA.bit.ZRO = 2; //set high
    EPwm1Regs.AQCTLA.bit.PRD = 1; //setlow

    EPwm1Regs.ETSEL.bit.INTSEL = 1;//when TBCTR == 0
    EPwm1Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    EPwm1Regs.ETPS.bit.INTPRD = 1;           // Generate INT on first event
}
void InitEpwm2(void){
    EPwm2Regs.TBPRD = 39062;
    EPwm2Regs.TBCTL.bit.PHSEN = 0;
    EPwm2Regs.TBPHS.half.TBPHS = 0;          // Phase is 0
    EPwm2Regs.TBCTR = 0x0000;                     // Clear counter
    EPwm2Regs.TBCTL.bit.SYNCOSEL = 0;

    EPwm2Regs.CMPA.half.CMPA = 39062-125;    // Set compare A value
    EPwm2Regs.CMPB.half.CMPB = 250;    // Set Compare B value

    EPwm2Regs.TBCTL.bit.CTRMODE = 0;    // Count up and douwn
    EPwm2Regs.TBCTL.bit.PHSEN = 0;      //enable phase loading
    EPwm2Regs.TBCTL.bit.CLKDIV = 7;     //TBCLOK = EPWMCLOCK/(64*10) = 156250Hz
    EPwm2Regs.TBCTL.bit.HSPCLKDIV = 5;
    EPwm2Regs.TBCTL.bit.PHSDIR = 0;

    //EPwm2Regs.CMPCTL.bit.SHDWAMODE = 1;//only active registers are used
    //EPwm2Regs.CMPCTL.bit.SHDWBMODE = 1;//only active registers are used


    EPwm2Regs.AQCTLA.bit.CAU = 2; //set high
    EPwm2Regs.AQCTLA.bit.PRD = 1; //setlow

    //EPwm2Regs.AQCTLB.bit.CBU = 2; //set high
    //EPwm2Regs.AQCTLB.bit.CBD = 1; //setlow

    EPwm2Regs.ETSEL.bit.INTSEL = 1;//when TBCTR == 0
    EPwm2Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    EPwm2Regs.ETPS.bit.INTPRD = 1;
}
void InitEpwm3(void){
    EPwm3Regs.TBPRD = 1000;
    EPwm3Regs.TBCTL.bit.PHSEN = 1;
    EPwm3Regs.TBPHS.half.TBPHS = 0;          // Phase is 0
    EPwm3Regs.TBCTR = 0x0000;                     // Clear counter
    EPwm3Regs.TBCTL.bit.SYNCOSEL = 0;

    EPwm3Regs.CMPA.half.CMPA = 42500+2500+4500;    // Set compare A value
    EPwm3Regs.CMPB.half.CMPB = 42500+2500+4500;    // Set Compare B value

    EPwm3Regs.TBCTL.bit.CTRMODE = 2; // Count up and douwn
    EPwm3Regs.TBCTL.bit.PHSEN = 1; //enable phase loading
    EPwm3Regs.TBCTL.bit.PHSDIR = 1;
    EPwm3Regs.TBCTL.bit.CLKDIV = 0; //TBCLOK = EPWMCLOCK/(64*10) = 156250Hz
    EPwm3Regs.TBCTL.bit.HSPCLKDIV = 0;

    //EPwm3Regs.CMPCTL.bit.SHDWAMODE = 1;//only active registers are used
    //EPwm3Regs.CMPCTL.bit.SHDWBMODE = 1;//only active registers are used


    EPwm3Regs.AQCTLA.bit.CAU = 2; //set high
    EPwm3Regs.AQCTLA.bit.PRD = 1; //setlow

    EPwm3Regs.AQCTLB.bit.CBU = 2; //set high
    EPwm3Regs.AQCTLB.bit.CBD = 1; //setlow

    EPwm3Regs.ETSEL.bit.INTSEL = 1;//when TBCTR == 0
    EPwm3Regs.ETSEL.bit.INTEN = 1;                // Enable INT
    EPwm3Regs.ETPS.bit.INTPRD = 1;
}

void InitEQep3Module(void)
{
    // ARC-H-50-3600-TTL-6-3M-10-FC
      // ARC: Optik, H: Hollow, 50: 50mm, 3600: Resolution, TTL: 5VDC supply, 6: A, An, B, Bn, Z, Zn
      // 1: A  - Yellow
      // 2: Bn - White
      // 3: +V - Red
      // 4: 0V - Black
      // 5: An - Blue
      // 6: B  - Green
      // 7: Zn - Grey
      // 8: Z  - Pink
      // 9: GND - Shield

      // QEPI: Gated to A and B (zero marker)
      // A leads B, forward direction (quadrature clock mode)

      /*the formula will be X/(t(k)-t(k-1)) at low  speeds, can be used with UPEVNT */
      /*the formula will be (x(k)-x(k-1))/T at high speeds, can be used with eqep unit timer or CAPCLK */

      // added by hakansrc
      EQep3Regs.QUPRD = 40000;        // Unit Timer for 100Hz at 200 MHz SYSCLKOUT

      // Quadrature Decoder Unit (QDU) Registers
      EQep3Regs.QDECCTL.all = 0x00;     // Quadrature Decoder Control
      EQep3Regs.QDECCTL.bit.QSRC = 0; // Position-counter source selection: Quadrature count mode (QCLK = iCLK, QDIR = iDIR)
      // hakansrc QSRC=2 girmis -- "0"
      EQep3Regs.QDECCTL.bit.SOEN = 0;   // Disable position-compare sync output
      EQep3Regs.QDECCTL.bit.SPSEL = 1; // Strobe pin is used for sync output: Don't care
      EQep3Regs.QDECCTL.bit.XCR = 0; // External Clock Rate: 2x resolution: Count the rising/falling edge
      EQep3Regs.QDECCTL.bit.SWAP = 0; // CLK/DIR Signal Source for Position Counter: Quadrature-clock inputs are not swapped
      EQep3Regs.QDECCTL.bit.IGATE = 0;  // Disable gating of Index pulse
      EQep3Regs.QDECCTL.bit.QAP = 0;    // QEPA input polarity: No effect
      EQep3Regs.QDECCTL.bit.QBP = 0;    // QEPB input polarity: No effect
      EQep3Regs.QDECCTL.bit.QIP = 0;    // QEPI input polarity: No effect
      EQep3Regs.QDECCTL.bit.QSP = 0;    // QEPS input polarity: No effect

      // Position Counter and Control Unit (PCCU) Registers
      EQep3Regs.QEPCTL.all = 0x00;      // QEP Control
      EQep3Regs.QEPCTL.bit.FREE_SOFT = 0; // Emulation mode: Position counter stops immediately on emulation suspend
      // hakansrc FREE_SOFT=2 devam etsin demis
      EQep3Regs.QEPCTL.bit.PCRM = 0;   // Position counter reset on an index event
      EQep3Regs.QEPCTL.bit.IEI = 2; // Initializes the position counter on the rising edge of the QEPI signal
      // hakansrc IEI=0 nedeni bilinmiyor
      EQep3Regs.QEPCTL.bit.IEL = 1; // Latches position counter on rising edge of the index signal
      // hakansrc IEL=0 nedeni bilinmiyor
      EQep3Regs.QEPCTL.bit.QPEN = 0; // Reset the eQEP peripheral internal operating flags/read-only registers.
      EQep3Regs.QEPCTL.bit.QCLM = 0; // QEP capture latch mode: Latch on position counter read by CPU
      // hakansrc QCLM=1 latch on unit timeout
      EQep3Regs.QEPCTL.bit.UTE = 1;    // QEP unit timer enable: Enable unit timer
      EQep3Regs.QEPCTL.bit.WDE = 1;     // Enable the eQEP watchdog timer

      EQep3Regs.QPOSINIT = 0; // Initial QPOSCNT , QPOSCNT set to zero on index event (or strobe or software if desired)
      EQep3Regs.QPOSMAX = 0xffffffff;       // Max value of QPOSCNT

      // Quadrature edge-capture unit for low-speed measurement (QCAP)
      EQep3Regs.QCAPCTL.all = 0x00;
      EQep3Regs.QCAPCTL.bit.CEN = 1;    // eQEP capture unit is enabled
      EQep3Regs.QCAPCTL.bit.CCPS = 1; // eQEP capture timer clock prescaler: // CAPCLK = SYSCLKOUT/64
      EQep3Regs.QCAPCTL.bit.UPPS = 0; // Unit position event prescaler: UPEVNT = QCLK/1 , QCLK is triggered in every rising or falling edge of A or B
      // UPPS reiz veri important

      // Position Compare Control
      EQep3Regs.QPOSCTL.all = 0x0000;   // Position Compare Control: Disabled
      // hakansrc enable etmis: PCE=1, PCSPW=0xFFF
      /*
       EQep3Regs.QPOSCTL.bit.PCSHDW = 0;   // shadow disabled
       EQep3Regs.QPOSCTL.bit.PCLOAD = 0;   // does not matter, shadow already disabled
       EQep3Regs.QPOSCTL.bit.PCPOL = 0;    // polarity of sync output is set to high pulse output
       EQep3Regs.QPOSCTL.bit.PCE = 1;      // position compare enable
       EQep3Regs.QPOSCTL.bit.PCSPW = 0xFFF;// Select-position-compare sync output pulse width, 4096 * 4 * SYSCLKOUT cycles
       */

      // QEP Interrupt Control (EQEPxINT)
      // Eleven interrupt events (PCE, PHE, QDC, WTO, PCU, PCO, PCR, PCM, SEL, IEL and UTO) can be generated.
      EQep3Regs.QEINT.all = 0x00;
      EQep3Regs.QEINT.bit.WTO = 1;      // Watchdog time out interrupt enabled
      // added by hakansrc
      EQep3Regs.QEINT.bit.UTO = 1; // unit timeout interrupt enabled, check QCAPCTL.bit.CCPS (NOTE: can be used for speed calculations at high speeds,check technical reference manual page 1996)
      // UTO currently not used
      EQep3Regs.QEINT.bit.IEL = 1;        // Index event latch interrupt enabled
      // IEL currently not used

      // added by hakansrc
      EQep3Regs.QFLG.all = 0;             // Interrupts are flagged here
      EQep3Regs.QCLR.all = 0;             // QEP Interrupt Clear

      // added by hakansrc
      EQep3Regs.QCTMR = 0; // This register provides time base for edge capture unit. 16 bit
      EQep3Regs.QCPRD = 0; // This register holds the period count value between the last successive eQEP position events
      EQep3Regs.QCTMRLAT = 0; // QCTMR latch register, latching can be stopped by clearing QEPCTL[QCLM] register
      EQep3Regs.QCPRDLAT = 0; // QCPRD latch register, latching can be stopped by clearing QEPCTL[QCLM] register

      /*
       // Registers to be watched
       EQep3Regs.QPOSCNT   // Position counter: This counter acts as a position integrator whose count value is proportional to position from a give reference point
       EQep3Regs.QPOSINIT  // Position counter init: contains the position value that is used to initialize the position counter based on external strobe or index event
       EQep3Regs.QPOSMAX   // Maximum Position Count: contains the maximum position counter value.
       EQep3Regs.QPOSCMP   // Position Compare: is compared with the position counter (QPOSCNT) to generate sync output and/or interrupt on compare match
       EQep3Regs.QPOSILAT  // Index Position Latch: The position-counter value is latched into this register on an index event as defined by the QEPCTL[IEL] bits.
       EQep3Regs.QPOSLAT   // Position Latch: The position-counter value is latched into this register on a unit time out event.
       EQep3Regs.QUTMR        // QEP Unit Timer: This register acts as time base for unit time event generation. When this timer value matches the unit time period value a unit time event is generated.
       EQep3Regs.QUPRD     // QEP unit period: contains the period count for the unit timer to generate periodic unit time events.
       EQep3Regs.QWDTMR    // Watchdog timer: time base for the watchdog to detect motor stalls
       EQep3Regs.QWDPRD   // Watchdog period: contains the time-out count for the eQEP peripheral watch dog timer
       EQep3Regs.QCTMR        // QEP Capture Timer: This register provides time base for edge capture unit
       EQep3Regs.QCPRD        // QEP Capture Period: This register holds the period count value between the last successive eQEP position events

       EQep3Regs.QFLG.bit.INT   // Global interrupt status flag
       EQep3Regs.QCLR.bit.INT   // Global interrupt clear flag
       EQep3Regs.QFLG.bit.WTO  // Watchdog timeout interrupt flag
       EQep3Regs.QCLR.bit.WTO = 1;     // Clear watchdog timeout interrupt flag

       EQep3Regs.QEPSTS.bit.UPEVNT     // 1h (R/W) = Unit position event detected. Write 1 to clear
       EQep3Regs.QEPSTS.bit.QDF    // Quadrature direction flag: 1=Clockwise
       */

      EQep3Regs.QEPCTL.bit.QPEN = 1;    // eQEP position counter is enabled


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

void PositionSpeedCalculate(void)
{
    /*TODO cover up the reverse direction case*/
    fAngularMechanicalPosition = (float32) EQep3Regs.QPOSCNT
            / (float32) ticktimes * 2 * PI; // mech-radians
    uiDirectonOfRotation = EQep3Regs.QEPSTS.bit.QDF; // Quadrature direction flag: 1=Clockwise
    fAngularElectricalPosition = fAngularMechanicalPosition*NUMBEROFPOLEPAIRS; // electrical, radians

    /*Not used currently*/
    /*
    if (uiHighSpeedFlag == HIGHSPEED)
    {
        if (EQep3Regs.QFLG.bit.UTO == 1)   // If unit timeout (depends on QUPRD)
                {
            uiPositionLatchedPrevious = uiPositionLatched;
            uiPositionLatched = EQep3Regs.QPOSLAT;
            if (uiPositionLatched > uiPositionLatchedPrevious)
                uiPositionTotalCounted = (uiPositionLatched
                        - uiPositionLatchedPrevious);
            else
                uiPositionTotalCounted = ENCODERTICKCOUNT + uiPositionLatched
                        - uiPositionLatchedPrevious;
            //fRPM = uiPositionTotalCounted*(CLOCKHZ/EQep3Regs.QUPRD)*60;
            //fRPM = fRPM/(float32)(ENCODERTICKCOUNT*4);
            fAngularMechanicalSpeed = uiPositionTotalCounted * (CLOCKHZ / EQep3Regs.QUPRD)
                    * 2 * PI;
            fAngularMechanicalSpeed = fAngularMechanicalSpeed / (float32) (ENCODERTICKCOUNT * 4);
            EQep3Regs.QCLR.bit.UTO = 1;
        }
    } else
        */
        if (uiHighSpeedFlag == LOWSPEED) {
        if (EQep3Regs.QEPSTS.bit.UPEVNT == 1) {
            //fRPM = 16*((CLOCKHZ/128)/EQep3Regs.QCPRDLAT)*60;
            //fRPM = fRPM/(float32)(ENCODERTICKCOUNT*4);
            fAngularMechanicalSpeed =
                    uiUpEventTickValue * ((CLOCKHZ / 128) / EQep3Regs.QCPRDLAT) * 2 * PI;/*TODO; parameterize the values,uiUpEventTickValue comes from UPPS value = 16 for now,128 comes from ccps value*/
            fAngularMechanicalSpeed = fAngularMechanicalSpeed / (float32) (ticktimes);
            fAngularElectricalSpeed = fAngularMechanicalSpeed*NUMBEROFPOLEPAIRS; //electrical, radians/second
            EQep3Regs.QEPSTS.bit.UPEVNT = 1;              // Clear status flag
        }
    }
}
#if VBYFCONTROLENABLE
interrupt void isr_Increment_freq(void) /*ISR for increment*/
{
    //Xint1Count++;
    if((fAppliedFrequency+fVbyfFreqSteps)>fFrequencySaturation)
    {
        fAppliedFrequency = fFrequencySaturation;
    }
    else
    {
        fAppliedFrequency = fAppliedFrequency + fVbyfFreqSteps;
    }
    vbyf_ma_value = fAppliedFrequency*(fVrated/fFrequencySaturation)*(sqrt(3)/(fVdc*0.612));


    // Acknowledge this interrupt to get more from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
interrupt void isr_Decrement_freq(void)  /*ISR for decrement*/
{
    //Xint2Count++;
    if((fAppliedFrequency-fVbyfFreqSteps)<fFrequencyInitial)
    {
        fAppliedFrequency = fFrequencyInitial;
    }
    else
    {
        fAppliedFrequency = fAppliedFrequency - fVbyfFreqSteps;

    }
    vbyf_ma_value = fAppliedFrequency*(fVrated/fFrequencySaturation)*(sqrt(3)/(fVdc*0.612));

    // Acknowledge this interrupt to get more from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
#endif
