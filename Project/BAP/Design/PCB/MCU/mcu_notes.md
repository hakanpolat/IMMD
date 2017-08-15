#### External oscillator (XTAL)
1. 3.3V external oscillator: Connect Clk to X1. X2 is NC. VDDOSC is at 3.3V, VSSOSC is at GND.
2. Crystal: Connect XTAL to X1 and X2. VDDOSC is at 3.3V. Connect capacitors between X1-VSSOSC and X2-VSSOSC
3. External resonator: same as XTAL.

Our design:

![](./images/ext_clk.png)

#### AUXCLKIN
Seems optional. Just connect CLK of an external oscillator (3.3V) to this pin.

#### ERRORSTS
Always output. Low unless an error is detected in chip. Remains high until the error flag is cleared. An active-high pin. Connect external pull-down.

#### XCLKOUT
GPIO73. The clock signal is chosen using the CLKSRCCTL3.XCLKOUTSEL bit field while the divide
ratio is chosen using the XCLKOUTDIVSEL.XCLKOUTDIV bit field.

#### PLL
fPLLSYSCLK = fOSCCLK * (SYSPLLMULT.IMULT + SYSPLLMULT.FMULT) / SYSCLKDIVSEL.PLLSYSCLKDIV
fAUXPLLCLK = fAUXOSCCLK * (AUXPLLMULT.IMULT + AUXPLLMULT.FMULT) / AUXCLKDIVSEL.AUXPLLDIV

#### Boot modes
GPIO72 and GPIO84

#### USB
GPIO42-43-46-47 are the only USB pins.

#### Crossbar (XBAR)
Input X-BAR is used to route signals from a GPIO to many different IP blocks such as
the ADC(s), eCAP(s), ePWM(s), and external interrupts.

The available IP destination(s):
![](./images/xbar.png)

Output X-BAR takes signals from inside the device and brings them out to a GPIO.

#### JTAG
![](./images/jtag.png)


.
