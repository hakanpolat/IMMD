# An introduction to Brushless DC Machine Drives
### BLDC Machines
#### BLDC vs DC and Induction motors:
* Better Torque vs Speed
* Higher Speed implementations
* Faster dynamic response
* Noiseless operation
* slip=0

#### BLDC vs Slip ring Synchronous Machines
##### Advantages:
* Better Power/Torque Density
* Elimination of slip ring and brushes (maintenance, reliability, durability)
* More Efficiency (no resistive loss on field excitation)
* Higher PF (absence of magnetizing current)

##### Disadvantages:
* Needs Electronic parts to run
* Needs precise position and current sensors

BLDC Structure:
![](/Images/BLDC_stator.jpg)
Stator is comprised of steel laminations and axially slotted with even number of windings.


![](/Images/BLDC_rotor.jpg)
Rotor is comprise of N-S magnet poles surface mounted or embedded in the rotor core. The higher number of magnet poles causes a lower torque ripple, on the other side making the design of power electronics complex.

#### Basics of operation
The power switches energize the stator windings sequentially to create a rotating electric field making the rotor rotate.
A sensor on the rotor indicate the position of magnets to determine switching the gates at the right moment.
![](/Images/BLDC_sensors.jpg)
In sensor-less applications the EMF variations are observed and used to determine the position of magnets. This makes possible the elimination of sensors, but in the start-up moment a stationary machine does not have any EMF. Thus the motor should start in open-loop configuration for a start-up period.

#### Control of BLDC's
![](/Images/BLDC_Control.gif)
In each electrical period six commutation is done by the controller. The control signal involves a PWM signal to adjust the average voltage and current on the coils.

#### BLDC Motor Control Algorithms
Two requirements to speed control of BLDC:
* Rotor speed or position
* Stator currents
PWM signals are produced based on the feedback measurements.
PWM signals can be edge-aligned or center aligned. Six individual PWM signals are sent to drive gates. In most applications edge aligned PWM's are used. If the application needs servo-positioning or dynamic braking or dynamic reversal, the center aligned PWM's are used.

The control algorithm must provide three things:
* PWM voltage to control the motor speed.

PWM is used to apply an average voltage to the motor. The duty cycle of pulses adjusts the voltage level. The voltage controls the rotating speed by changing the available torque.

* Mechanism to commutate the motor.


* Method to estimate the rotor position using the back-EMF or Hall Sensors

#### Trapezoidal Commutation of BLDC Motor
![](/Images/trap_waveforms.gif)

In this scheme, current is controlled through motor terminals one pair at a time, with the third motor terminal always electrically disconnected from the source of power.
Three Hall devices embedded in the motor are usually used to provide digital signals which measure rotor position within 60 degree sectors and provide this information to the motor controller. Because at any time, the currents in two of the windings are equal in magnitude and the third is zero, this method can only produce current space vectors having one of six different directions. As the motor turns, the current to the motor terminals is electrically switched (commutated) every 60 degrees of rotation so that the current space vector is always within the nearest 30 degrees of the quadrature direction.
The current waveform for each winding is therefore a staircase from zero, to positive current, to zero, and then to negative current.
This produces a current space vector that approximates smooth rotation as it steps among six distinct directions as the rotor turns.
The trapezoidal-current drive systems are popular because of the simplicity of their control circuits but suffer from a torque ripple problem during commutation.

#### Sinusoidal Commutation for BDLC Motors
The torque produced in a three phase brushless motor (with a sine wave back-EMF) is defined by the following equation:

Shaft Torque = Kt [ I R Sin(o ) + I S Sin(o+120) + I T Sin(o+240)]
where:
o is the electrical angle of the shaft,
Kt is the torque constant of the motor and
I R , I S and I T are the phase currents.

If the phase currents are sinusoidal: I R = I 0 Sino; I S = I 0 Sin (+120o); I T = I 0 Sin (+240o)
this reduces to:

Shaft Torque = 1.5I 0 *Kt (a constant independent of the shaft angle)

Sinusoidally commutated brushless motor controllers attempt to drive the three motor windings with three currents that vary smoothly and sinusoidally as the motor turns. The relative phases of these currents are chosen so that they should result in a smoothly rotating current space vector that is always in the quadrature direction with respect to the rotor and has constant magnitude. This eliminates the torque ripple and commutation spikes associated with trapezoidal commutation.

In order to generate smooth sinusoidal modulation of the motor currents as the motor turns, an accurate measurement of rotor position is required. The Hall devices provide only a coarse measure of rotor position and are inadequate for this purpose. For this reason, angle feedback from an encoder, or similar device, is required.
![](/Images/sinus_bldc.jpg)

Since the winding currents must combine to produce a smoothly rotating current space vector of constant magnitude, and because the stator windings are oriented 120 degrees apart from each other, currents in each winding must be sinusoidal and phase shifted by 120 degrees. Position information from the encoder is used to synthesize two sinusoids, one 120 degrees phase shifted from the other. These signals are then multiplied by the torque command so that the amplitudes of the sine waves are proportional to desired torque. The result is two sinusoidal current command signals appropriately phased to produce a rotating stator current space vector in the quadrature direction.

The sinusoidal current command signals are provided as inputs to a pair of P-I controllers that regulate current in the two appropriate motor windings. The current in the third motor winding is the negative sum of the currents in the controlled windings and therefore cannot be separately controlled. The output from each P-I controller is fed to a PWM modulator and then to the output bridge and two motor terminals. Voltage applied to the third motor terminal is derived as the negative sum of the signals applied to the first two windings, as appropriate for three sinusoidal voltages each separated by 120 degrees.

To the extent that the actual output current waveform accurately tracks the sinusoidal current command signals, the resulting current space vector is smoothly rotating, constant in magnitude and oriented in the quadrate direction as desired.

Sinusoidal commutation results in smoothness of control that is generally unachievable with trapezoidal commutation. However, while it is very effective at low motor speeds, it tends to fall apart at high motor speeds. This is because as speed goes up the current loop controllers must track a sinusoidal signal of increasing frequency. At the same time they must overcome the motor back-EMF that also increases in amplitude and frequency as speed goes up.

Because the P-I controllers have limited gain and frequency response, the time-variant perturbations to the current control loop cause phase lag and gain error in the motor currents. Higher speeds result in larger errors. This perturbs the direction of the current space vector relative to the rotor, causing it to shift away from the quadrature direction.

When this happens, less torque is produced by a given amount of current and therefore more current is required to maintain torque. Efficiency deteriorates.

This degradation continues as speed increases. At some point motor current phase shift crosses through 90 degrees. When this happens torque is reduced to zero. With sinusoidal commutation, speeds above this point result in negative torque and are therefore not achievable.

![](/Images/TORQUE_SPEED_CHARACTERISTICS.jpg)
