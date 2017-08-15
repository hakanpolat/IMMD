# Interleaving

## Effect of Interleaving on input current
![](./images/parasitic/current.png)

## Effect of Interleaving on DC link current ripple and EMI (ground voltage)
* Parasitic inductances (around 100nH)
* Parallel connected:
![](./images/dclink/inter_paras.png)
* Series connected:
![](./images/dclink/series_paras.png)
* Cause resonance problems at high frequencies and current ripple may even get worse with parallel connection.
* Cause EMI problem (common mode) and that Situation also worsens at very high frequencies

## Common mode currents in motor housing
![](./images/parasitic/commonmode.png)

## Capacitance in the same slots
![](./images/parasitic/slot_capac.png)

## Common mode currents w and w/o interleaving
![](./images/parasitic/cm_simul.png)

## Effect of Interleaving on machine current
* Machine Segments in Same Pole Pair but Different Slots: No significant Effect
* Machine Segments in Same Slots: There are parasitic capacitances. Any voltage mismatch will lead to large ripple currents. Interleaving is not recommended. This effect may be reduced by LC filters.

# Voltage balancing in series connected converter topology

## Passive voltage balancing
![](./images/control/passive.png)
* With resistors
* Small resistors will have better balancing capability
* Small resistors have significant loss
* Passive voltage balancing techniques:
![](./images/control/passive2.png)
* They will fail when there is a large mismatch as follows:
![](./images/control/mismatch.png)
![](./images/control/mismatch2.png)

## Centralised voltage balancing (CVB) control
* Block diagram is shown:
![](./images/control/active.png)
* Under mismatch, the voltages are balances as shown:
![](./images/control/active2.png)

## Distributed voltage balancing (DVB) control
* Block diagram is shown:
![](./images/control/dist1.png)
* Unstability problem as shown:
![](./images/control/dist2.png)

# Voltage balancing for Machine Segments in Different Slots
* Equivalent circuit is shown:
![](./images/control/diff_slot1.png)

# Voltage balancing for Machine Segments in Same Slot
* Equivalent circuit is shown:
![](./images/control/same_slot1.png)
* The machine segments in same pole pair has much stronger passive balancing performance.
* Due to the existence of parasitic capacitance, the machine-drive system will be very sensitive to PWM signal mismatch.
* Effect of mismatch on the PWM voltage on the current is shown:
![](./images/control/same_slot2.png)
* CVB and DVB are not even needed in this case because the inherent passive balancing is strong enough.
