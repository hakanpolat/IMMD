# ADC
Most physical signals such as temperature, humidity, pressure, current, speed and acceleration are analogue signals. With the aid of the appropriate transducer, almost all of these can be represented as an electrical voltage between Vmin and Vmax, e.g. 0...3V, which is proportional to the original signal. The purpose of the ADC is to convert this analogue voltage to a digital number.
The relationship between the analogue input -voltage (Vin), the number of binary digits to represent the digital number (n), bit resolution, and the digital number (D) is given by:
\[
\V{in}  = D * ( V_{REF+} -V_{REF-})/2^n-1 + V{REF-}
\]
Where V{REF+} and V{REF-} are the maximum and minimum analogue limits. Values upper and lower than these limits will interpreted as saturation.
In F28335x V{REF-} is set at 0v and V{REF+} is connected to +3v. The bit resolution for F2833x is 12.
The equation above becomes simplified as:
\[
V{in}=(3.0*D)/4095
\]

The F2833x has 16 analogue input pins but one ADC. So the analogue to digital conversion is taken place within a multiplexer sequentially. During any A-D conversion the analogue input must be constant. This is done by a sample and hold unit. The F2833x has two sample and hold units to sample two different inputs simultaneously.
In addition, the F2833x ADC has an “auto-sequencer” capability of 16 stages. This means that the ADC can automatically continue with the conversion of the next input channels after the previous channels are completed. Thanks to this enhancement, we do not have to fetch the digital results in the middle of a measurement sequence, the task being carried out by a single interrupt service routine at the end of the sequence.

Assuming an input voltage range from 0...+3V, we obtain a voltage resolution of 3.0V/4095 = 0.732mV per bit.
We have two Sample-and-Hold units, which can be used in parallel; the corresponding operating mode is called “simultaneous sampling”. Each sample and hold unit is connected to 8 multiplexed input lines. There is also an auto sequencer, which is a programmable state machine that is capable of automatically converting up to 16 input signals. Each state of the auto sequencer stores a measurement in its own dedicated result register.
The fastest conversion time is 80ns per sample in a sequence and 160ns for the very first sample. Of course we will have to adapt this conversion rate to the signal system that is actually used.
### F2833x ADC Module
* 12-bit ADC
* 16 Analogue inputs (0~3volts)
* Maximum conversion rate: 12.5 MSPS (80nsec)
* 2 analogue input multiplexers and 2 sample holders
* Auto sequential sampling and conversion capability up to 16 inputs
* 16 individually addressable result registers
* Trigger sources for start of conversion(external triggers, S/W or ePWM-Modules)

A start of a conversion sequence can be initiated from three sources:

• By software - just set a start bit to 1

• By an external signal on pin “GPIO/XINT2_ADCSOC”

• By an event (period, compare or underflow) of one of the PWM-units ePWM1 to ePWM6

### ADC Operation Modes
* Sequencer Mode
  * Cascaded Sequencer(16 states)
  * Dual Sequencer Mode(2*8states)
* Sampling Mode
  * Sequential Sampling (1 channel at a time)
  * Simultaneous Sampling (2 channels at a time)
* Start Mode
  * Single Sequence Mode (stop at the end of sequence)
  * Continuous Mode (wrap sequencer at the end of sequence)
