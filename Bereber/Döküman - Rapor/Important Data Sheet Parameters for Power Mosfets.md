# Power Mosfet Data Sheet Notes

### Key Performance Parameters

- Vds at Tj,max
- Rds(on),max
- Id
- Qg,typ
- Id,pulse
- Eoss for a voltage value 


# MOSFET Converter Losses

## a) Conduction losses (Pc)

conduction losses of  MOSFET:

**Vds(Id) = Rds,on(Id) x Id**  &nbsp; &nbsp; &nbsp;*Id  MOSFET on-state current*

**Pcm(t)=Rds,on x Id(t)^2** &nbsp; &nbsp; &nbsp;  *the instantaneous value of the MOSFET conduction losses*

conduction losses of the anti-parallel diode:

**Vd(Id) = Vdo + Rd x If** *Vd=voltage across the diode, Vdo=diode on-state zero-current voltage, Rd= diode on-state resistance, If=current through the diode*

![](images/RdvsId.jpg "RdvsId")
![](images/RdvsId.jpg)


Rds,on variation:

![](images/Rdsonvary.jpg "Rdsonvary") &nbsp; &nbsp; &nbsp;  *TJ is the junction temperature,Rdsonmax the maximum value of Rdson at 25°C, α temperature coefficient* then finding alpha:


![](images/alpha.jpg "alpha")





## b) Switching losses (Psw)

#### Switch-on transient

1) **Vdr (driver voltage): from 0 to Vdr** ---> **Vgs (gate voltage): from 0 to Vgs(th)** with time constant (Rgate and Ciss=(Cgd+Cgs))

2) **Vgs>Vgs(th**) ---> **Ids (drain current): 0 to Id,on *(from datasheet)* with rise time tri** free wheeling diode still conduct abd Vds=Vdd

3) **Reverse Recovery**: In order for the diode to switch off, all the minority carriers stored in it have to be removed. This reverse-recovery current has to be absorbed by the MOSFET, causing additional power
losses. ---> **reverse-recovery charge (Qrr) and duration (trr)** (from data sheet)


![](images/switch.jpg "alpha")

4) **After trr time, Vds: from Vdd to (Rds,on x Ion)** ---> **Vgs=Vplateau (miller effect)** then **Vds start to decrease**. Non linearity of Vds (see Cgd vs Vds), two point approximation to find tfu (voltage fall time, as well as the rise time during switch off) 


![](images/Cgd.jpg "alpha")

- Why this approximation is the worst case?:

when Vdd < Vds < (Vdd/2) ---> Cgd1=Cgd x Vdd,  when (Vdd/2) < Vds < 0 ---> Cgd2=Cgd(Rds,on x Ion). Finding Cgd1 and Cgd2 is above.
 
![](images/tfu12.jpg "alpha")&nbsp; &nbsp; &nbsp;because&nbsp; &nbsp; &nbsp; ![](images/Igate_on.jpg "alpha")


![](images/tfu.jpg "alpha")
#### Switch-off transient

Note that:

- No reverse recovery loss


![](images/tfu12_off2.jpg "alpha") &nbsp; &nbsp; &nbsp;because&nbsp; &nbsp; &nbsp; ![](images/Igate_off.jpg "alpha")


![](images/tfu.jpg "alpha")


### What about Energy and Loss during Switching?

**switch-on energy**

The switch-on energy caused by 2 components:

- MOSFET switch-on
- Reverse-recovery of the free-wheeling diode 


![](images/E_mosfet_on.jpg "alpha")

 
![](images/E_freew_on.jpg "alpha")

**switch-off energy**

![](images/E_mosfet_off.jpg "alpha")


**Total Loss**

![](images/totalloss.jpg "alpha")

## Consider Three-Phase AC Motor Drive

![](images/acmotor.jpg "alpha")

Vdd: input voltage

Vo: Output line to line voltage

Van1: Output phase voltage

Iorms:Output rms current

S0=3 x Van1 x Iorms: output apparent power

cos(fi1): öorot displacement factor

L: equalent stator inductance

fsw: switching freq

fo: output freq (motor electrical)

ma:  inverter amplitude modulation index


**conduction losses**

MOSFET conduction loss:

![](images/ac_conduction.jpg "alpha")

Diode conduction loss:

![](images/diode_conduction.jpg "alpha")


In order to find a simple solution for the switching loss calculation, it is supposed that the losses generated in
the inverter in one half-wave of the output frequency (1/(2 fo) ) correspond to the losses generated if instead
of AC output current a DC equivalent output current is applied. The equivalent DC output current value is: 

![](images/swac.jpg "alpha")

This value can be used for [IDon, IDoff] in the switching loss calculation.