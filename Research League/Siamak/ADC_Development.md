//
//
//###########################################################################

//###########################################################################
#include "DSP2833x_Device.h"


// Prototype statements for functions found within this file.
void Gpio_select(void);
void InitSystem(void);
void delay_loop(long);
void Init_ADC(void);


unsigned int Voltage_VR1;
//###########################################################################
//                      main code
//###########################################################################
void main(void)
{
    int counter=0;      // binary counter for digital output

    InitSystem();       // Basic Core Initialization

    DINT;               // Disable all interrupts

    Gpio_select();      // GPIO9, GPIO11, GPIO34 and GPIO49 as output
                        // to 4 LEDs at Peripheral Explorer)
    while(1)
    {
        Voltage_VR1 = AdcMirror.ADCRESULT0;
            if(GpioDataRegs.GPADAT.bit.GPIO17&1) GpioDataRegs.GPASET.bit.GPIO2 = 1;
                else GpioDataRegs.GPACLEAR.bit.GPIO2 = 1;

            delay_loop(30800);   // 100 ms take aprox.308000 loops
            counter++;
    }
}

void delay_loop(long end)
{
    long i;

    for (i = 0; i < end; i++)
    {

            EALLOW;
            SysCtrlRegs.WDKEY = 0x55;
            SysCtrlRegs.WDKEY = 0xAA;       // service watchdog
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
    GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;  // peripheral explorer: LED LD1 at GPIO0
    GpioCtrlRegs.GPADIR.bit.GPIO17 = 0; // peripheral explorer: SW1 at GPIO17

    GpioCtrlRegs.GPBDIR.all = 0;        // GPIO63-32 as inputs

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
void Init_ADC(void)
{
        InitAdc();          // Basic ADC setup, incl. calibration

        AdcRegs.ADCTRL1.all = 0;
        AdcRegs.ADCTRL1.bit.ACQ_PS = 7;     // 7 = 8 x ADCCLK
        AdcRegs.ADCTRL1.bit.SEQ_CASC =1;    // 1=cascaded sequencer
        AdcRegs.ADCTRL1.bit.CPS = 0;        // divide by 1
        AdcRegs.ADCTRL1.bit.CONT_RUN = 1;   // single run mode

        AdcRegs.ADCTRL2.all = 0;
        AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 0;   // 1=enable SEQ1 interrupt
        AdcRegs.ADCTRL2.bit.SOC_SEQ1 =1;  // 1=SEQ1 start from ePWM_SOCA trigger
        AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1 = 0;   // 0= interrupt after every end of sequence

        AdcRegs.ADCTRL3.bit.ADCCLKPS = 3;   // ADC clock: FCLK = HSPCLK / 2 * ADCCLKPS
                                            // HSPCLK = 75MHz (see DSP2833x_SysCtrl.c)
                                            // FCLK = 12.5 MHz

        AdcRegs.ADCMAXCONV.all = 0x0000;    // 2 conversions from Sequencer 1

        AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0; // Setup ADCINA0 as 1st SEQ1 conv.
}
//===========================================================================
// End of SourceCode.
//===========================================================================
