## GRW-2017 Abstract
### Integrated Modular Motor Drives (IMMDs)

In this research work, a new concept called Integrated Modular Motor Drive (IMMD) is presented. The limitations of conventional electric motor drive systems are explained. The motivation for integrating the motor drive and motor into a single package is explained. 




In this research work, a new switching algorithm is proposed in order to suppress the circulating currents
between two interleaved single-phase, voltage-source Pulse Width Modulated (PWM) rectifiers supplied from
a common ac source. In general, two 2-level phase-shifted, sinusoidal PWM converters are connected in
parallel via a common DC link, by using two isolated windings on the secondary side of a front-end
transformer, to ensure a circulating-current free operation of the converters. Such circulating currents would
adversely affect the proper operation of the system, and cause malfunctioning of the power converter.
However, with the application of the switching algorithm proposed in this work, two interleaved, single-phase
PWM rectifiers can be connected to the same input terminals at the ac supply side, without any circulating
currents between the converters. The main advantage of such connection is eliminating the need for a bulky,
multi-winding transformer at the input of interleaved converters. A dedicated algorithm has been developed
for this purpose, which picks up the switching states responsible from circulating currents between
converters, defined as invalid switching states, and then substitutes them with some predetermined, valid
switching states for an equivalent converter operation in each operating mode. The main application of this
algorithm is high power AC locomotive traction converters. High power AC locomotives usually employ a
multi-winding step-down traction transformer to supply several traction motors. Utilization of interleaved
front-end PWM rectifiers is a common practice to reduce the harmonic content of the input current and
current rating of each power semiconductor, and for redundancy. With the proposed method, the number of
rectifiers to be interleaved can be increased without the need of any additional secondary windings of
conventional traction transformers. Circuit diagram of an interleaved PWM rectifier without an input
transformer is shown in Figure 1-a. The proposed switching algorithm has been verified by some computer
simulations carried out on MATLAB/Simulink environment and the resultant voltage and current waveforms
are shown in Figure 1-b.
