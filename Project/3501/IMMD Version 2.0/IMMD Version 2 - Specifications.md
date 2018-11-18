### Technical specifications of the 2nd IMMD prototype

#### Input Parameters
|Parameter|Value|Parameter|Value|
|:--:|:--:|:--:|:--:|:--:|
|Rated output power|10 kW|Rated speed|1500 rpm|
|DC Link voltage, Vdc|270 V|Rated torque|64 Nm|
|Electric loading, Arms|35 kA/m|Magnetic loading, Bpeak|0.9 T|
|Current desity, Jrms|4 A/mm^2|Winding type|FSCW|
|Fill factor|0.4|Motor efficiency|96 %|
|Drive efficiency|98 %|Power factor|0.95|
|Drive power density|10 kW/lt|Motor power density|1 kW/lt|
|Drive cooling|Natural|Motor cooling|Forced air|
|Junction temperature|140 0C|Winding temperature| 0C|
|Magnet temperature| 0C||||

#### Design Parameters
|Parameter|Value|Parameter|Value|
|:--:|:--:|:--:|:--:|:--:|
|Module configuration|Half-bridge/Full-bridge|Number of modules|2-n|
|Module connection|Series/Parallel/Series-Parallel|Switching frequency|20-100 kHz|
|Integration|Axial/Radial/Case/Back iron|Rotor type|Inner/Outer/SPM/IPM|
|Layer number|1/2|Number of phases|3-6|
|Slot number|20|Pole number|22|
|Module connections on motor|Equal/Shifted|||
|Control architecture|Each phase/Each module/Single|Master controller|Yes/No|
|Device cooling|Top/Bottom/Double side|Cooling topology|Each half-bridge/Each module/single|
|Overdesign factor|0-100 %|Skewing|Yes/No|

#### Calculated Design Parameters
|Parameter|Value|Parameter|Value|
|:--:|:--:|:--:|:--:|:--:|
|Air gap lenght|1.5 mm|Voltage frequency|275 Hz|
|Dos||Dis||
|Dir||La||
|Nphm||Phase voltage||
|Induced voltage|80 Vrms|Phae current|12.5 Arms|
|Magnet length||Magnet embrace||
|Icrms||Capacitance||
|Rth-hs|||||

#### Selections
|Parameter|Value|Parameter|Value|
|:--:|:--:|:--:|:--:|:--:|
|Power device|GaN, 650V-30A|Capacitor||
|Lamination||Magnet|(Br)|

#### Performance
|Parameter|Value|Parameter|Value|
|:--:|:--:|:--:|:--:|:--:|
|Short circuit current||Winding factor||
|MMF THD||EMF THD||
|Torque ripple||Cogging torque||
|Mutual inductance|% of self|kVA rating of inverter||
|Copper loss||Core loss||
|Magnet loss||Conduction loss||
|Switching loss||Motor efficiency||
|Drive efficiency||Power factor||
|Number of switches||V x I ratings||
|Unbalanced radial forces|||||
|End winding|||

#### Power Density
|Parameter|Value|Parameter|Value|
|:--:|:--:|:--:|:--:|:--:|
|Motor mass| kg|Motor volume| lt|
|Drive mass| kg|Drive volume| lt|
|Cooling mass| kg|Cooling volume| lt|
|Drive power density| kW/lt|Motor power density| kW/lt|
|Total power density| kW/lt|Drive power density| kW/kg|
|Motor power density| kW/kg|Total power density| kW/kg|
|Torque density| Nm/A|Torque density| Nm/kg|

#### Fault tolerance
|Parameter|Value|Parameter|Value|
|:--:|:--:|:--:|:--:|:--:|
|One-phase OC||One-phase SC||
|Two-phases OC||||
|Transistor OC||Transistor SC||
|Controller failure||Control signal failure||
|Redundancy|% xyz|||
|Torque ripple after fault|||||

#### Cost
|Parameter|Value|Parameter|Value|
|:--:|:--:|:--:|:--:|:--:|
|Power device||Capacitor||
|Heat sink||Copper||
|Iron||Magnet||
|Controller||||
It may be assumed that, electronics, mechanical, manufacturing, assembly etc. costs are the same for similar systems. Therefore, only material costs will be considered.
