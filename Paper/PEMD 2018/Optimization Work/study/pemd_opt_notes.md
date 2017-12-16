## Multi-physics optimization of an integrated modular motor drive system

### Constants
1. Vdc: DC link voltage = 540 V
2. Inverter topology = 3-phase 2-level bridge inverter
3. PWM technique = Sinusoidal PWM (SPWM)
4. Machine type = Permanent magnet synchronous motor (PMSM)
5. Stator winding = Fractional slot concentrated winding (FSCW)
6. Winding configuration = Alternate teeth **???**
7. Pout: Rated total output power = 8 kW
8. Nrated: Rated speed = 600 rpm
9. Heat sink ile ilgili **???**

### Parameters

#### General
1. n: number of modules
2. ns: number of series modules
3. np: number of parallel modules

#### Machine side dimensions
1. Dos: stator outer diameter
2. Dis: stator inner diamater
3. Dir: rotor inner diameter
4. lg: gap length
5. lm: magnet thickness
6. La: axial length

#### Machine windings and numbers
1. w: number of losts per module per phase
2. l: number of layers
3. p: number of rotor poles
4. zQ: number of turns per coil side **??? this can be inherent**

#### Drive Inverter
1. fsw: switching frequency
2. gamma: interleaving angle **??**
3. ma: modulation depth

#### DC Link
1. Cdc: Capacitance

#### Heat sink
1. Lhs: Heat sink length
2. Dihs: Heat sink inner diameter
3. Dohs: Heat sink outer diameter

### Constraints
1. Vdcr: Percent peak-to-peak DC link voltage ripple = 1%
2. THDi: Total harmonic distortion of current = 5% **??**
3. Tcg: Cogging torque = 1% **??**
4. Drive efficiency: 98%
5. Motor efficiency: 94%

### Cost function
1. Total power density (motor, pcb, heat sink and dc link capacitor)

**Efficiency-PowerDensity product ????**

**How to include actual cost ????**


### References
1. Heat sink fischer http://www.fischerelektronik.de/web_fischer/en_GB/heatsinks/A05/Extruded%20heatsinks%20for%20DC-DC%20converter/PR/SK_DC_4_1_117_SA_/$productCard/parameters/index.xhtml
2. GaN: http://www.gansystems.com/gs66508b.php
