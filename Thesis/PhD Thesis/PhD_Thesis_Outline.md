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
The following concepts will be covered in detail:
* Integration (IMD)
* Modularization
* What is IMMD?
* Advantages
* Challenges
* Research opportunities
* Possible applications

#### 2.2. Wide Band Gap Power Semiconductor Devices
* Existing Devices and Their Properties are shortly covered.
* GaN is explained more in detail.
* Relation of using WBG PSD (especially GaN) with IMMD is explained.
* Example prototypes that used WBG are mentioned.
* Challenges of using GaN are summarized

#### 2.3. Motor Drive Topologies
* Conventional motor drive topologies are shown (VSI-CSI, 2L-3L).
* Motor drive topologies (previously proposed) suitable for IMMD are introduced and their operating principles are explained.
* A classification is given (single-input, multiple-input etc.). The focus is on series and parallel connection, their motivation and advantages.
* Comparison of the topologies.
* The comparison categories are: component quantity, waveform quality (related to passive component size), sizing, extra requirements, degree of modularity (redundancy), stress on devices and windings etc.

#### 2.4. Machine Configurations
* The machine types suitable for IMMD are introduced with reasoning and referencing to the previous work.
* The segmentation of the motor (split winding) and its methods (types) are given from previous work.
* The focus will be on PMSM.
* Winding configurations are explained more in detail focusing on redundancy, torque quality etc.

#### 2.5. Fault Tolerance Concept
* The definition is given and the concept of fault tolerance is explained by also mentioning reliability and redundancy concepts (and their relations with each other).
* The fault tolerant motor drive examples from previous work are explained.
* The critical applications where fault tolerance is important are mentioned.
* The relation of fault tolerance with IMMD and this thesis is explained in detail.

#### 2.6. Passive Components
* Passive components in motor drives.
* The motivation behind minimizing them in IMMD.
* DC Link capacitor types and comparison. Selection methods, parameters.
* interleaving concept and its application in IMMDs (capacitor size)
* Motivation behind using AC filters (GaN fast switching, motor insulation etc).
* Types of filters used previously. Selection methods, parameters.

#### 2.7. Previous IMMD's
* A list of IMD examples are provided with different kinds of classifications.
* Pictures are provided.
* Modular ones (IMMD) are mentioned separately.
* This section is more like "who made what kind of IMMD for which reason".
* A chronological order is preferred for being able to see the development of IMMD technology.
* The performance of the state-of-the-art (power density etc.) are shown
* Their applications are also mentioned.

### Chapter 3: Design of an 8 kW IMMD Prototype

#### 3.1. Introduction
Aim of this design: Proof of concept (integration, modularity, fault tolerance, GaN drive etc.)

Specifications of the system (design inputs)

How is this prototype different from the previous work (design with GaN at 8 kW etc.)

Main decisions:
* Type of the motor
* Introduction to topology selection, parallel-series configuration,
* Why 2-series must be used
* 2-series 2-parallel is selected (details are in the corresponding sub-section denebilir)
* Winding configuration selection, slot/pole number (possibilities)

#### 3.2. Design of the Motor

###### 3.2.1. Main dimensions
* Selection of constraints (A's, B's, efficiency, power factor, current density, fill factor etc.)
* Calculation of shear stress
* Calculation of torque, torque per volume
* Selection of aspect ratio
* Calculation of stator, rotor diameter, axial length etc.
* Calculation of voltage and current requirements from the inverter model (2S-2P configuration)
* Selection of Qs/p from the combinations
* Selection of winding configuration
* Calculation of slot pitch, pole pitch, winding factor etc.

###### 3.2.2. Electromagnetic design
* Magnetic circuit model (MCM) of FSCW PMSM
* Selection of magnet and list of parameters
* Selection of air gap length
* Calculation of magnet length (MCM)
* Calculation of required tooth width (MCM)
* Calculation of required back core height (MCM)
* Calculation of resultant flux density for air gap and in all other sections (Verify Bg, Bm, Bts, Bys, Byr)
* Calculation of slot width1

###### 3.2.3. Stator winding design
* Frequency calculation
* Flux per pole calculation (for each harmonic)
* Induced voltage per coil calculation
* Selection of number of turns
* Selection of wire
* Verify Jrms
* Verify Arms

###### 3.2.4. Slot design
* Calculation of required slot area
* Calculation of slot width2, slot height
* Verify kcu
* Calculation of outer diameter of the motor

###### 3.2.5. Resistance and inductance
* Leakage inductance calculation
* Self inductance (La + Llk) calculation
* Mutual inductance (just show how mutual coupling may affect the modular design)
* Calculation of load angle
* Verify power factor
* Calculation of short circuit current (verify Isc)
* Resistance calculation (include thermal effect)
* Copper loss calculation

###### 3.2.6. Core loss
* Model ???
* Calculation of core loss (via FEA ?)
* Verify motor efficiency

###### 3.2.7. Torque ripple and cogging torque
* Magnet shape design (embrace and offset)
* Design of skewing
* 2D FEA results and verification

###### 3.2.8. Mechanical design and Assembly
* Mechanical design tricks
* Mechanical drawings
* Assembly drawings
* Pictures of the machine parts
* Pictures of the machine assembled

#### 3.3. Design of the Drive

###### 3.3.1. Topology Selection
* Topologies suitable for the application
* Evaluation of topologies (other than loss, capacitor etc. ???)
* Selection of the topology (2S-2P-2LVSI) and reasoning

###### 3.3.2. Power Semiconductor Device Selection and Loss Analysis
* Power semiconductor device selection (for the selected topology) and device parameters
* Loss characterisation: Methodology (aproximation, integration and using GaN model)
* Loss characterisation: Verification
* Evaluation of topologies by efficiency
* Variation with switching frequency and discussion

###### 3.3.3. Capacitor Selection
* Methodology (model) for capacitor selection
* Calculation of required capacitance, current etc.
* Effect of interleaving (relation with topology)
* Some stuff from the ISIE paper
* Thermal model, lifetime etc.
* Variation with switching frequency and discussion
* Selection (commercial) and resultant parameter list

###### 3.3.4. Selection of switching frequency
* Loss results discussions
* Component size discussions
* AC side harmonic analysis and discussions
* Other considerations and limitations: fast switching, EMI, controller constraints, parasitics etc. and discussions
* Selection and resultant expected performance

###### 3.3.5. Gate Drive Design
* Issues related to GaN, how we overcomed them (use app. note)
* Schematic design (just critical points) - show schematic
* Layout design (just critical points)- show layout

###### 3.3.6. PCB Design
* Architecture (block diagram)
* Modules on PCB (gate drive, control, measurement etc.)
* Explanation of the schematic design (very briefly) and selection of major components
* Layout tricks: Other than gate drive
* Pictures of the PCBs

###### 3.3.7. Design of the Control System
* Control block diagram
* Control method explanation
* Implementation of the control on the micro-controller (Interleaving, sync. of different modules etc.)

###### 3.3.8. Thermal Analysis and Heat Sink Design
* Thermal model (lumped parameter)
* Thermal design on the pcb (vias, thickness etc.), selection of isolator etc.
* Heat sink thermal resistance requirement calculation
* Conduction and convection analytical models of heat sink
* Calculation of heat sink dimensions
* Simulation and experiment on the heat sink for the verification of model
* Pictures of the heat sink
* Pictures of the heat sink along with PCBs

#### 3.4. Design Verification with Simulation Results

###### 3.4.1. Motor Drive Simulations
* Simulation model, parameters etc.
* Steady state performance: DC Link voltages, DC Link currents, Motor line voltages, Motor line currents
* Transient performance ???

###### 3.4.2. Machine Simulations
* RMxprt results (table)
* 2D FEA results, Induced voltage, Line current, Flux density distribution, Inductances, Torque (No load, full load etc.)

###### 3.4.3. Thermal Simulations
* Lumped parameter model simulations at steady state
* FEA simulation results

#### 3.5. Design Verification with Experimental Results

###### 3.5.1. Introduction
* Experimental setup: block diagram, picture, explanation
* Test procedures explanation
* Parameters of the setup (table)
* Overall block diagram of the IMMD
* Pictures of the IMMD

###### 3.5.2. Testing of the machine
* Resistance, inductance
* Induced voltage (running as generator at no-load)

###### 3.5.3. Testing of drive
Using RL load:
* DC Link voltage: Ripple etc.
* DC Link currents: Not possible ???
* AC voltages: PWM
* AC currents: Waveform quality
* GaN waveforms: Verification of the PCB design and GaN modeling
* Thermal results with thermal camera

###### 3.5.3. Testing of IMMD
Using some test procedure (Acceleration, deceleration etc.):
* Voltage and current waveforms: Balance etc.
* Showing interleaving would be very nice if possible
* Thermal results with thermal camera
* Speed and torque (using RÜZGEM setup)
* If any unbalanced situation is present, show it

###### 3.5.4. Evaluation of the IMMD Design and Discussions
Performance of the IMMD:
* Waveform quality (electrical)
* Torque quality
* Efficiency (motor, drive, overall)
* Power density
* Temperature rise
* Fault tolerance discussions
* Other aspects ???

###### 3.5.5. Shortcomings of the IMMD Design
* Voltage balancing requirement
* Circulating currents (if applicable)
* Any possible unforeseen unbalance at steady state
* Any unbalance under fault (can we test this at this prototype ???)
* Fault tolerance => Use another topology (increased redundancy)
* Fast switching => Requirement of LC filter
* Single point of failure: Reconfigure the architecture (distributed control etc.)
* GaN behaviour => Parasitic modeling is required

### Chapter 4: Design of a X kW IMMD Prototype for an Aircraft Engine Fuel Pump

#### 4.1. Motivation
* Using the experience gained from the 8 kW prototype design
* Improvements for the shortcomings
* MEA concept (a very short introduction)
* Requirements specific to the application (aircraft)
* Importance of weight and volume reduction (in the aspect of the application)
* Importance of redundancy and fault tolerance (in the aspect of the application)

#### 4.2. Design procedure

###### 4.2.1. Introduction
* Specifications of the design
* Main foci of the design
* Main decisions (motor type etc.)

###### 4.2.2. Topology and winding configuration selection
* Existing motor drive topologies proposed for enhanced fault tolerance
* Existing winding configurations proposed for enhanced fault tolerance
* Comparison of the topologies in terms of fault tolerance
* Discussions on fault tolerance and reliability (mutual coupling, short circuit current etc.)
* Comparison of the topologies in terms of motor drive efficiency
* Comparison of winding configurations in terms of motor efficiency
* Discussions on effiecieny
* Comparison of the topologies in terms of power density (kW/kg, kW/lt)
* Other considerations: Cost, manufacturability etc.

###### 4.2.3. Detailed design of the system
* Topology and winding selections from the results of the previous sub-section
* Using the previously developed models and methodologies, a short explanation of this design, component selection etc. etc. (including motor, drive, heat sink, controller and all)

###### 4.2.4. Circulating current and voltage balancing issues
* Literature: balancing methods etc.
* Some formulation
* Analysis of the situation using simulations
* Precautions taken on the control system (proposition)
* Simulation results for the proposed measures and verification

###### 4.2.5. Fault tolerance
* Fault types and classification
* Fault detection methods
* Analytical modeling of fault cases
* Analysis of the faults using simulations
* Proposition for faulted operation
* Simulatioın results for the proposed methods
* Aim of using dedicated controllers
* Architecture of the control system (including fault tolerance)
* Selection of controller architecture on the hardware
* Implementation

###### 4.2.6. Fast switching issue
* GaN and fast switching (introduction)
* Effects of the fast switching
* Modeling (GaN model and obtained waveforms): trade-offs etc.
* GaN switching test circuit and results (experimental)
* LC filter deisgn: Selection of parameters, physical design

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



### Chapter 5: Conclusions
