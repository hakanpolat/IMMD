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

Gate drive: https://www.silabs.com/documents/public/data-sheets/Si827x.pdf
Si8273
