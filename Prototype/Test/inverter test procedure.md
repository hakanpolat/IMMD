##### The test procedure for a single inverter module under load

Please refer to: **test_procedure_data.xlsx**

###### No load test:
Requirements:
1. Inverter module  
2. DSP with 3-phase sinusoidal PWM software
3. Power supply (15V)
4. Oscilloscope, voltage probes

Procedure:
1. Apply 3-phase sinusoidal PWM to the inverter at a modulation index of 0.9 and switching frequency of 40 kHz under no load and no DC bus voltage. Observe the gate signals. (**Test 1**). **Ptotal = 0 W.**
2. Apply a DC bus voltage and increase it up to 100 V. Observe the output voltages.


###### Light load test:
Additional Requirements:
1. Thermal pad cut, heat sink drill
2. Inverter module bottom side cuts (through hole component pins etc.)
3. Inverter module mounted to heat sink
4. Current probes
5. RL load

Procedure:
1. Apply 3-phase sinusoidal PWM to the inverter at a modulation index of 0.9 and switching frequency of 10 kHz under no load and low DC bus voltage. Increase the voltage up to 100V.
2. Apply 100 Vdc. Connect the load with R = 50 Ohms, L = 100 mH. Observe the output voltage and current waveforms. Observe the temperatures. (**Test 2**). **Ptotal = 60 W.**
3. Increase the load up to R = 10 Ohms, L = 20 mH in a discrete manner. Observe the output voltage and current waveforms. Observe the temperatures. (**Test 3**). **Ptotal = 300 W.**


###### Full load test:
Additional Requirements:
1. Rectifier with a large DC bus capacitor (Semiteach).
2. 3-phase watt-meter.

Procedure:
1. Apply the PWM at 10 kHz with high DC bus voltage (ma = 0.87). Increase the voltage up to 270 V slowly, by observing its ripple under no-load.
2. Apply 270 Vdc. Connect the load with R = 50 Ohms, L = 100 mH. Observe the output voltage and current waveforms. Observe the temperatures. (**Test 4**). **Ptotal = 413 W.**
3. Increase the load up to R = 10 Ohms, L = 20 mH in a discrete manner. Observe the output voltage and current waveforms. Observe the temperatures. (**Test 5**). **Ptotal = 2066 W.**
4. Increase the switching frequency up to 40 kHz gradually and observe output voltage and current waveforms. Observe the temperatures. (**Test 6**). **Ptotal = 2066 W.**
