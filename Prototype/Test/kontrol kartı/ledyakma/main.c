#include <F2837xD_Device.h>

/*extern void InitSysCtrl(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void InitCpuTimers(void);
extern void ConfigCpuTimer(struct CPUTIMER_VARS *, float, float);
interrupt void cpu_timer0_isr(void);
*/
void Gpio_Select();

int main(void)
{
    Gpio_Select();
    GpioDataRegs.GPADAT.bit.GPIO8 = 1;
    GpioDataRegs.GPADAT.bit.GPIO8 = 0;
    GpioDataRegs.GPADAT.bit.GPIO8 = 1;
    GpioDataRegs.GPADAT.bit.GPIO8 = 0;
    GpioDataRegs.GPADAT.bit.GPIO8 = 1;
    GpioDataRegs.GPADAT.bit.GPIO8 = 0;
    GpioDataRegs.GPADAT.bit.GPIO8 = 1;
    GpioDataRegs.GPADAT.bit.GPIO8 = 0;

    GpioDataRegs.GPCDAT.bit.GPIO75 = 1;
    GpioDataRegs.GPCDAT.bit.GPIO75 = 0;
    GpioDataRegs.GPCDAT.bit.GPIO75 = 1;
    GpioDataRegs.GPCDAT.bit.GPIO75 = 0;
    GpioDataRegs.GPCDAT.bit.GPIO75 = 1;
    GpioDataRegs.GPCDAT.bit.GPIO75 = 0;
    GpioDataRegs.GPCDAT.bit.GPIO75 = 1;
    GpioDataRegs.GPCDAT.bit.GPIO75 = 0;

    return 0;
}

void Gpio_Select()
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0;
    GpioCtrlRegs.GPAMUX2.all = 0;

    GpioCtrlRegs.GPBMUX1.all = 0;
    GpioCtrlRegs.GPBMUX2.all = 0;

    GpioCtrlRegs.GPAGMUX1.all = 0;
    GpioCtrlRegs.GPAGMUX2.all = 0;

    GpioCtrlRegs.GPBGMUX1.all = 0;
    GpioCtrlRegs.GPBGMUX2.all = 0;

    GpioCtrlRegs.GPCGMUX1.all = 0;
    GpioCtrlRegs.GPCGMUX2.all = 0;

    GpioCtrlRegs.GPCGMUX1.all = 0;
    GpioCtrlRegs.GPCGMUX2.all = 0;

    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 0; // enable pull up
    GpioDataRegs.GPASET.bit.GPIO8 = 1; // Load output latch. Recommended in rm
    GpioCtrlRegs.GPADIR.bit.GPIO8 = 1; // set it as output

    GpioCtrlRegs.GPCPUD.bit.GPIO75 = 0; // enable pull up
    GpioDataRegs.GPCSET.bit.GPIO75 = 1; // Load output latch. Recommended in rm
    GpioCtrlRegs.GPCDIR.bit.GPIO75 = 1; // set it as output

    EDIS;

}
