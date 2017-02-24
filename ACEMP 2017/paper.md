# Elimination of sixth harmonic on the DC link

The first idea was to eliminate the sixth harmonic occuring on the DC link due to motor drive inverter by phase shifting of fundamental componenets of different 3-phase modules. The motor slots would also be shifted to cancel the effect on the AC side. It did not work since there is no sixth harmonic due to the inverter :)

This has been shown analytically and also by simulation.

Still, it might be a good idea because a sixth harmonic will occur on the DC link in case a simple diode bridge rectifier is used.

The phase shifting did not work. It is understood that a frequency component should be injected to the AC system. The question is which component...

For this, many analytical derivations have been made and a sixth harmonic on the DC link was achieved theoretically. But, this would require third harmonic injection on the AC side. Well, a three phase inverter has a nice property of cancelling out the third harmonic, so it is not practically possible to inject these harmonic with the conventional Y connected three phase configuration. There is no such thins as a "delta connected inverter", so this is also a failure.

Next, an unconventional motor and drive configuration is considered. A machine with concentrated coils can be used where each winding is driven by its own single phase full bridge (H-bridge) converter.

An aexample machine is given in the following:
* T. M. Jahns, “Hardware Integration for an Integrated Modular Motor Drive Including Distributed Control,” pp. 4881–4887, 2014.

Paper organisation:
- Abstract:

- Sec1: Introduction:

- Sec2: Rectifier model, 6th harmonic component injection, LC filter characteristics

- Sec3: Proposed method: Sixth harmonic creation on the DC link with third harmonic injection (analytical)

- Sec4: New IMMD scheme for third harmonic injection, practical considerations, effects on other components, torque ripple, copper loss etc.

- Sec5: Simulation results

- Sec6: Conclusions:

- References:
