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

In this paper, a novel method to eliminate the harmonic component occurring on the DC bus which is six times the grid frequency is proposed. This harmonic component is present due to natural commutation of the passive diode bridge rectifier in motor drive applications. In conventional drives, bulky LC filters are utilized to reduce the effect of this harmonic component to the motor drive inverter. With this method, DC bus capacitance requirement can be minimized which will enhance the power density and decrease the cost of the overall system. Third harmonic injection is used with modular inverters in an integrated modular motor drive application. Both rectifier and inverter side analytical models are presented, the elimination of the sixth harmonic component is described analytically, and verified by simulations performed on MATLAB/Simulink. The possible adverse effects of third harmonic injection method are also discussed.

- Sec1: Introduction:

- Sec2: Rectifier model, 6th harmonic component injection, LC filter characteristics

- Sec3: Proposed method: Sixth harmonic creation on the DC link with third harmonic injection (analytical)

- Sec4: New IMMD scheme for third harmonic injection, practical considerations, effects on other components, torque ripple, copper loss etc.

- Sec5: Simulation results

- Sec6: Conclusions:

- References:
