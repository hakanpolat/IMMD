##### The test procedure for a single inverter module under load

Please refer to: **test_procedure_data.xlsx**


###### Double pulse test:
Requirements:
1. Inverter module  
2. Power supply (15V)
3. Oscilloscope, voltage probes
4. Inverter module mounted to heat sink
5. Current probes
6. DSP code for double-pulse test (DPT)
7. Inductive (L) load
8. Heat sink grounding
9. Bol bol jumper

Procedure:
1. Observe the signals for DPT.
2. Connect the L load to a single half-bridge.
3. Apply the test under 100V DC bias for Phase-A, B and C. (**Test 0**). **Ptotal = NULL**

Observations:
1. Load current
2. VDS voltage for all phases: Special care for the effects of parasitics


###### No load test:
Additional Requirements:
1. DSP with 3-phase sinusoidal PWM software

Procedure:
1. Apply 3-phase sinusoidal PWM to the inverter at a modulation index of 0.9 and switching frequency of 40 kHz under no load and no DC bus voltage. Observe the gate signals. (**Test 1**). **Ptotal = 0 W.**
2. Apply a DC bus voltage and increase it slowly up to 100 V. Observe the output voltages.

Observations:
1. 3-phase PWM outputs (3 different frequencies)
2. Line-to-line voltages (with filtering to see the fundamental)


###### Light load test:
Additional Requirements:
1. Current probes
2. RL load
3. Thermal camera

Procedure:
1. Connect the load. Adjust it to no-load.
2. Apply 3-phase sinusoidal PWM to the inverter at a modulation index of 0.9 and switching frequency of 10 kHz under no load and low DC bus voltage. Increase the voltage up to 100V.
3. Apply 100 Vdc. Adjust the load to R = 50 Ohms, L = 100 mH. (**Test 2**). **Ptotal = 60 W.**
4. Increase the load up to R = 10 Ohms, L = 20 mH in a discrete manner. (**Test 3**). **Ptotal = 300 W.**

Observations:
1. Observe the line current waveforms on oscilloscope (3-phase).
2. Observe and record the temperatures of different critical points.
3. Observe the time required for thermal steady state.


###### Full load test:
Additional Requirements:
1. Variac
2. Rectifier with a large DC bus capacitor (Semiteach).
3. 3-phase watt-meter.
4. Connections

Procedure:
1. Apply the PWM at 10 kHz with high DC bus voltage (ma = 0.87). Increase the voltage up to 270 V slowly, by observing its ripple under no-load.
2. Apply 270 Vdc. Adjust the load to R = 50 Ohms, L = 100 mH. (**Test 4**). **Ptotal = 413 W.**
3. Increase the load up to R = 10 Ohms, L = 20 mH in a discrete manner. (**Test 5**). **Ptotal = 2066 W.**
4. Increase the switching frequency up to 40 kHz gradually. (**Test 6**). **Ptotal = 2066 W.**

Observations:
1. Line-to-line voltages (with filtering to see the fundamental).
2. Observe the line current waveforms on oscilloscope (3-phase).
3. Observe and record the **temperatures** of different critical points.
4. Observe the output of the current measurement circuits along with phase currents (for each phase).
5. VDS voltage for all phases: Special care for the effects of parasitics.
6. Voltages waveforms of different capacitors (use them for current data analysis).
7. PCB temperatures at different parts.

###### Performance tests
1. GaN MaN
