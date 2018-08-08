## PhD Thesis Outline

### Chapter 1: Introduction

#### 1.1. Motivation
General motivation for this study
#### 1.2. Integrated Modular Motor Drives
A brief explanation of IMMD, how it works, advantages, disadvantages, possible applications, challenges
#### 1.3. Aim of the Thesis
Related to the motivation and IMMD introduction, the research topics covered in this study are explained. The fundamental aim of the study is explained.
#### 1.4. Scope of the Thesis
The content of the thesis is summarized according to the outline.

### Chapter 2: Integrated Modular Motor Drives - State of the Art
#### 2.1. IMMD Concept
The following will be covered in detail:
* Integration
* Modularization
* What is IMMD
* Advantages
* Challenges
* Research opportunities
* Possible applications

#### 2.2. Wide Band Gap Power Semiconductor Devices
* Existing Devices and Their Properties are shortly covered.
* GaN is explained more in detail.
* Relation of using WBG PSD (especially GaN) with IMMD is explained.
* Example prototypes that used WBG are mentioned.

#### 2.3. Motor Drive Topologies
* Conventional motor drive topologies are shown (VSI-CSI, 2L-3L).
* Motor drive topologies (previously proposed) suitable for IMMD are introduced and their operating principles are explained.
* A classification is given (single-input, multiple-input etc.). The focus is on series and parallel connection, their motivation and advantages.
* Comparison of the topologies.
* The comparison categories are: component quantity, sizing, extra requirements, degree of modularity (redundancy), stress on devices and windings etc.

#### 2.4. Machine Configurations
* The machine types suitable for IMMD are introduced with reasoning and referencing to the previous work.
* The segmentation of the motor (split winding) and its methods (types) are given from previous work.
* The focus will be on PMSM.
* Winding configurations are explained more in detail.

#### 2.5. Fault Tolerance Concept
* The definition is given and the concept of fault tolerance is explained by also mentioning reliability and redundancy concepts (and their relations with each other).
* The fault tolerant motor drive examples from previous work are explained.
* The critical applications where fault tolerance is important are mentioned.
* The relation of fault tolerance with IMMD and this thesis is explained in detail.

#### 2.6. Passive Components
* Passive components in motor drives.
* The motivation behind minimizing them.
* DC Link capacitor types and comparison. Selection methods, parameters.
* Relation with IMMD (interleaving concept).
* Motivation behind using AC filters (GaN fast switching, motor insulation etc).
* Types of filters used previously. Selection methods, parameters.

#### 2.7. Previous IMMD's
* A list of IMD examples are provided with different kinds of classifications.
* Pictures are provided.
* Modular ones (IMMD) are mentioned separately.
* This section is more like "who made what kind of IMMD for which reason".
* A chronological order is preferred for being able to see the development of IMMD technology.
* Their applications are also mentioned.

### Chapter 3: Design of an 8 kW IMMD Prototype

#### 3.1. Introduction
Aim of this design: Proof of concept (integration, modularity, fault tolerance, GaN drive etc.)

Specifications of the system (design inputs)

How is this prototype different from the previous work (design with GaN at 8 kW etc.)

Main decisions:
* Type of the motor
* Winding configuration, slot/pole number
* Motor drive topology, Parallel-series configuration (intro)

#### 3.2. Design of the Motor

###### 3.2.1. Main dimensions
* Selection of constraints (A's, B's, efficiency, power factor, current density, fill factor etc.), calculation of shear stress
* Calculation of torque, torque per volume
* Selection of aspect ratio
* Selection of stator, rotor diameter, axial length etc.
* Calculation of voltage and current requirements from the inverter model
* Possible winding configurations for the Qs/p combination
* Calculation of slot pitch, pole pitch, winding factor etc.

###### 3.2.2. Electromagnetic design
* Magnetic circuit model of FSCW PMSM
* Selection of magnet and resultant parameters
* Selection of air gap length
* Calculation of flux density for air gap and in other sections
* Calculation of required tooth width
* Calculation of required back core height
* Calculation of slot width1

###### 3.2.3. Stator winding design
* Frequency calculation
* Flux per pole calculation (for each harmonic)
* Induced voltage per coil calculation
* Selection of number of turns
* Selection of wire

###### 3.2.4. Slot design
Calculation of slot width2, slot height, slot area
Outer diameter of the motor

###### 3.2.5. Resistance and inductance
* Leakage, armature reaction
* Mutual inductance
* Resistance, thermal effect
* Copper loss

###### 3.2.6. Core loss
* Modeling
* Calculation

###### 3.2.7. Torque ripple and cogging torque
* Magnet shape design
* Skewing
* 2D FEA results

###### 3.2.8. Mechanical design and Assembly
Mechanical design tricks
Mechanical drawings
Assembly drawings
Pictures of the machine parts
Pictures of the machine assembled

#### 3.3. Design of the Drive

###### 3.3.1. Topology Selection
Topologies suitable for the applications
Evaluation of topologies (other than loss, capacitor etc.)
Selection of the topology (2S-2P-2LVSI) and reasoning

###### 3.3.2. Power Semiconductor Device Selection and Loss Analysis
Power semiconductor device selection (for the selected topology) and device parameters
Loss characterisation (methodology)
Evaluation of topologies by efficiency
Variation with switching frequency
Loss results for the selected topology

###### 3.3.3. Capacitor Selection
* Methodology (model) for capacitor selection
* Calculation of required capacitance, current etc.
* Effect of interleaving (relation with topology)
* Some stuff from the ISIE paper
* Thermal model, lifetime etc.
* Variation with switching frequency
* Selection (commercial) and results

###### 3.3.4. Selection of switching frequency
* Loss (previously analyzed)
* Component size (previously analyzed)
* AC side harmonics
* Other considerations and limitations: fast switching, EMI, controller constraints, parasitics etc.
* Selection and discussions

###### 3.3.5. Gate Drive Design
* Critical points
* Design (schematic)
* Design (layout)

###### 3.3.6. PCB Design
* Architecture (block diagram)
* Modules on PCB (gate drive, control)
* Explanation of the schematic design: very short
* Selection of major components
* Layout tricks: Related to GaN etc.
* Pictures of the PCBs

###### 3.3.7. Design of the Control System
Control block diagram
Control method explanation
Implementation of the control on the micro-controller
* Interleaving etc.
* How to synchronize different modules

###### 3.3.8. Thermal Analysis and Heat Sink Design
* Thermal model (lumped parameter)
* Thermal design on the pcb, isolator etc.
* Heat sink thermal resistance calculation
* Conduction and convection analytical models
* Calculation of heat sink dimensions
* Simulation and experiment on the heat sink for verification
* Pictures of the heat sink
* Pictures of the heat sink along with PCBs

#### 3.4. Design Verification with Simulation Results

###### 3.4.1. Motor Drive Simulations
Simulation model
* DC Link voltages
* DC Link currents
* Motor voltages
* Motor currents
Staeady state and transient etc.

###### 3.4.2. Machine Simulations
RMxprt results (table)
2D FEA results:
* Induced voltage
* Line current
* Core loss
* Flux density distribution
* Inductance
* Torque
No load, full load etc.

#### 3.5. Design Verification with Experimental Results

###### 3.5.1. Introduction
Experimental setup: block diagram, picture, explanation
Test procedures
Parameters of the setup (table)
Pictures of the IMMD assembled
Overall block diagram of the IMMD

###### 3.5.2. Testing of machine
Another motor ???
* Resistance, inductance
* Induced voltage

###### 3.5.3. Testing of drive
RL load ???
* DC Link voltages: Ripple, transient
* DC Link currents: Not possible ???
* AC voltages: PWM
* AC currents: Waveform quality
* GaN waveforms: Verification of the PCB design and GaN modeling
* Thermal tests

###### 3.5.3. Testing of IMMD
* Voltage and current waveforms: Balance etc.
* Showing interleaving would be very nice
* If any unbalanced situation is present, show it
* What else ????
* Machine operation: Acceleration, deceleration etc.

###### 3.5.4. Evaluation of the IMMD Design and Discussions
Performance of the IMMD
* Efficiency
* Power density
* Temperature rise
* Fault tolerance
* Other aspects ???

###### 3.5.5. Shortcomings of the IMMD Design
* Voltage balancing
* Circulating currents
* Any possible unbalance
* Fault tolerance => Another topology - redundant
* Fast switching => LC filter
* Single point of failure: DSP etc.
* Unprecedented GaN behaviour => Parasitic modeling

### Chapter 4: Design of a X kW IMMD Prototype for an Aircraft Engine Fuel Pump

#### 4.1. Motivation
Using the experince gained from the 8 kW prototype design
Improvements for the shortcomings
Requirements specific to the application
Importance of weight and volume reduction (in the aspect of the application)
Importance of redundancy and fault tolerance (in the aspect of the application)

#### 4.2. Design procedure

###### 4.2.1. Introduction
Specifications of the design
Main foci of the design
Main selections (motor etc.)

###### 4.2.2. Topology and winding configuration selection

Existing motor drive topologies proposed for enhanced fault tolerance
Existing winding configurations proposed for enhanced fault tolerance
Comparison of the topologies in terms of fault tolerance
Discussions on fault tolerance and reliability (mutual coupling, short circuit current etc.)
Comparison of the topologies in terms of motor drive efficiency
Comparison of winding configurations in terms of motor efficiency
discussions on effieciny
Comparison of the topologies in terms of power density (kW/kg, kW/lt)
Other considerations: Cost, manufacturability etc.

###### 4.2.3. Detailed design of the system
Topology and winding selections from the results of the previous part
Using the previously obtained models, a short explanation of the design, component selection etc. etc.

###### 4.2.4. Circulating current and voltage balancing issues
* Literature: balancing methods etc.
* Analytical modeling
* Analysis of the situation using simulations
* Precautions taken on the control system (proposition)
* Simulation results for the proposed measures

###### 4.2.5. Fault tolerance
Fault types and classification
Fault detection methods
Analytical modeling of fault cases
Analysis of the faults using simulations
Proposition for faulted operation
Simulatioın results for the proposed methods
Aim of using dedicated controllers
Architecture of the control system (including fault tolerance)
Selection of micro-controllers
Implementation

###### 4.2.6. Fast switching issue
GaN and fast switching (introduction)
Effects of the fast switching
Modeling (GaN model and obtained waveforms): trade-offs etc.
GaN switching test circuit and results (experimental)
LC filter deisgn: Selection of parameters, physical design

#### 4.3. Results

###### 4.3.1. Introduction
Experimental setup: block diagram, picture, explanation
Test procedures for the improved design items
Parameters of the setup (table)
Pictures of the IMMD assembled
Overall block diagram of the IMMD

###### 4.3.2. Tests under normal operation
Basic waveforms
Thermal

###### 4.3.3. Fault tolerance tests
Waveforms for faulted cases

###### 4.3.3. Tests and unbalance situations
Waveforms for unbalanced cases

###### 4.3.4. Performance
* Efficiency
* Power density
* Temperature rise
* Fault tolerance
* Other aspects ???

#### 4.4. Discussions



### Chapter 5: Results and Discussions





### Chapter 6: Conclusions
