##### In this file, the procedure for the PCB design of the IMMD system for BAP project will be explained.

##### Schematic files:
1. Main: All the interconnections of the sub-modules and connections with the outside.
2. Rectifier: The rectifier circuit including diode bridge rectifier, the filter inductor and DC bus filter capacitor.
3. Power stage: Motor drive inverter power stage with GaN FETs.
4. Control: The control circuit including microcontrollers.
5. Measurement: Position measurement (common) and current measurement for all the modules.
6. Gate drive: The gate drive circuitry for GAN FETS.
7. Power supply: The auxiliary supply for the PCB.


1. Rectifier:
http://tr.farnell.com/vishay/vs-26mt100/bridge-rectifier-25a-3ph/dp/9098550
http://www.farnell.com/datasheets/2049266.pdf

The rectifier packages are not suitable for PCB mount, so they will be mounted to a chasis along with a separate heat sink. In fact, all the rectifier circuit may be a separate unit outside the IMMD system.

Controller: TMS320F28374S	(ACTIVE)
Single-Core Delfino Microcontroller

http://www.ti.com/product/tms320f28374s

AMC1200 for current measurement
http://www.ti.com/lit/ds/symlink/amc1200.pdf
http://www.ti.com/lit/an/sbaa229/sbaa229.pdf
http://www.ti.com/lit/ug/sbau187a/sbau187a.pdf

GaN: http://www.gansystems.com/gs66508b.php


Gate drive: https://www.silabs.com/documents/public/data-sheets/Si827x.pdf
Si8273
SOIC-16 NB

LP2985IM5-6.1/NOPB
SOT23

At first, non-isolated bootstrap half-bridge gate driver was studied. However, as it was used in the EVM of the selected GaN FET, isolated separate gate drivers will be used. **SI8271GB-IS**.
No negative voltage will be used. 5V will be the input to the whole gate drive circuit. +9V will be obtained via **PES1-S5-S9-M**, then it will be converted to 6V which is the gate voltage via **LP2985IM5-6.1**.
