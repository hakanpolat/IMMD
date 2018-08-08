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
The following will be covered in detail: Integration, modularization, what is IMMD, Advantages, Challenges, Research Opportunities, Possible applications

#### 2.2. Wide Band Gap Power Semiconductor Devices
Existing Devices and Their Properties are shortly covered. GaN is explained more in detail. Relation of using WBG PSD (especially GaN) with IMMD is explained. Example prototypes that used WBG are mentioned.

#### 2.3. Motor Drive Topologies
Conventional mkotor drive topologies are shown (VSI-CSI, 2L-3L). Motor drive topologies suitable for IMMD are introduced and their operating principles are explained. A classification is given (single-input, multiple-input etc.). The focus is on series and parallel connection, their motivation and advantages. Their advantages and disadvantages are told (comparison). The comparison categories are: component quantity, sizing, extra requirements, degree of modularity (redundancy), stress on devices and windings etc.

#### 2.4. Machine Configurations
The machine types suitable for IMMD are introduced with reasoning and referencing to the previous work. The segmentation of the motor (split winding) and its methods (types) are given from previous work. The focus will be on PMSM. Winding configurations are explained more in detail.

#### 2.5. Fault Tolerance Concept
The definition is given and the concept of fault tolerance is explained by also mentioning reliability and redundancy concepts (and their relations with each other). The fault tolerant motor drive examples from previous work are explained. The relation of fault tolerance with IMMD and this thesis is explained in detail.

#### 2.6. Passive Components
Passive components in motor drives. The motivation behind minimizing them. DC Link capacitor types. Selection methods, parameters. Relation with IMMD (interleaving concept). Motivation behind using AC filters (GaN fast switching, motor insulation etc). Types of filters used previously. Selection methods, parameters.

#### 2.7. Previous IMMD's
A list of IMD examples are provided with different kinds of classifications. Pictures are provided. Modular ones (IMMD) are mentioned separately. This section is more like "who made what kind of IMMD for which reason". A chronological order is preferred for being able to see the development of IMMD technology. Their applications are also mentioned.

### Chapter 3: Design of an 8 kW IMMD Prototype

#### 3.1. Introduction
Aim of this design: Proof of concept (integration, modularity, fault tolerance, GaN drive etc.)

Specifications of the system (design inputs)

Main decisions:
* Type of the motor
* Winding configuration, slot/pole number
* Motor drive topology, Parallel-series configuration (intro)

#### 3.2. Design of the Motor

###### 3.2.1. Main dimensions
Selection of constraints (A's, B's, efficiency, power factor, current density, fill factor etc.), calculation of shear stress
Calculation of torque, torque per volume
Selection of aspect ratio
Selection of stator, rotor diameter, axial length etc.
Calculation of voltage and current requirements from the inverter model
Possible winding configurations for the Qs/p combination
Calculation of slot pitch, pole pitch, winding factor etc.

###### 3.2.2. Electromagnetic design
Magnetic circuit model of FSCW PMSM
Selection of magnet and resultant parameters
Selection of air gap length
Calculation of flux density for air gap and in other sections
Calculation of required tooth width
Calculation of required back core height
Calculation of slot width1

###### 3.2.3. Stator winding design
Frequency calculation
Flux per pole calculation (for each harmonic)
Induced voltage per coil calculation
Selection of number of turns
Selection of wire

###### 3.2.4. Slot design
Calculation of slot width2, slot height, slot area
Outer diameter of the motor

###### 3.2.5. Resistance and inductance
Leakage, armature reaction
Resistance, thermal effect
Copper loss

###### 3.2.6. Core loss
Calculation

###### 3.2.7. Torque ripple and cogging torque
Magnet shape design
Skewing
Results

###### 3.2.8. Mechanical design and Assembly
Mechanical design tricks
Mechanical drawings
Assembly drawings

#### 3.3. Design of the Drive

###### 3.3.1. Topology Selection
Topologies suitable for the applications
Evaluation of topologies (other than loss, capacitor etc.)
Selection of the topology (2S-2P-2LVSI) and reasoning

###### 3.3.2. Power Semiconductor Device Selection and Loss Analysis
Power semiconductor device selection (for the selected topology) and device parameters
Loss characterisation (methodology)
Evaluation of topologies by efficiency
Loss results for the selected topology

###### 3.3.3. Capacitor Selection
Methodology (model) for capacitor selection
Calculation of required capacitance, current etc.
Effect of interleaving (relation with topology)
Some stuff from the ISIE paper
Practical selection and results

###### 3.3.4. Gate Drive Design
Critical points
Design (schematic)
Design (layout)

###### 3.3.5. PCB Design
Modules on PCB (gate drive, control)
Explanation of the schematic design
Selection of major components
Layout tricks

###### 3.3.6. Thermal Analysis and Heat Sink Design
Thermal model (lumped parameter)
Thermal design on the pcb, isolator etc.
Heat sink thermal resistance calculation
Conduction and convection analytical models
Calculation of heat sink dimensions
Simulation and experiment on the heat sink for verification

#### 3.4. Design Verification with Simulation Results


###### 3.4.1. Motor Drive Simulations


###### 3.4.2. Machine Simulations


#### 3.5. Design Verification with Experimental Results

#### 3.5. Evaluation of the Prototype and Discussions

###### 3.5.1. Performance of the IMMD
Efficiency
Power density
Temperature
Fault tolerance

###### 3.5.1. Shortcomings of the IMMD prototype



### Chapter 4: Design of a 6 kW IMMD Prototype for an Aircraft Engine Fuel Pump

#### 4.1. Motivation
Improvements for the shortcomings





### Chapter 5: Results and Discussions





### Chapter 6: Conclusions
