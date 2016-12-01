# Semiconductor devices

The table below shows the commercially available cascode GaN manufacturers.
![](./images/gan_commercial.png)

The table below shows the commercially available enhancement mode GaN manufacturers.
![](./images/gan_commercial2.png)

# Wide band-gap devices
Material properties-I:
![](./images/device/materi,al_property.png)
Material properties-II:
![](./images/device/thermal.png)
* For normal Si semiconductor, the operating temperature cannot be high because of the significant leakage current
* The higher critical field will allow a higher breakdown voltage for identical epitaxial thickness.
* The SiC and GaN devices can reach very low resistance.
* Since GaN have largest electron mobility, it should ultimately be the best material for high frequency operation
* The thermal conductivity of SiC is better than Si and GaN.
* BFoM: Baliga‘s figure of merit: a measure of the on-resistance of a unipolar device. Higher value means a lower Ron.

Specific on-resistance vs breakdown voltage:
![](./images/device/Ron.png)

# Existing WBG devices

* SiC schottky diode: The SiC schottky diodes with rating voltage up to 1.7 kV are available. The operating temperature can e as high as 200 C.

* SiC FET: Rating voltage up to 1.7 kV are available. CoolMOS (Si technology) may compare, but their ratings are up to 900V. Have very low Ron.

Switching performance comparison of Si and SiC FET devices having similar Ron:
![](./images/device/sameRon.png)

* GaN FET: Use of Si substrate is more suitable for commercial products (due to cost). Depletion mode GaNs are normally-on (not desirable). Enhancement mode are normall-off. Cascode solution can be used as shown below:
![](./images/device/cascode.png)

* WBG IGBT: IGBT is bipolar where MOSFET is unipolar, thus IGBTs have smaller Ron. But, IGBT has on-state voltage drop.
