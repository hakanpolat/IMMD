#Sixth Week Report 

**Optocoupler**

http://tr.farnell.com/fairchild-semiconductor/fod817c3sd/opto-cplr-phototrans-5kv-smd/dp/2322516

FOD817C3SD has been chosen. 

**Diode Rectifier**  

FAIRCHILD SEMICONDUCTOR  DF06M  Bridge Rectifier Diode has been chosen.

http://www.farnell.com/datasheets/2212136.pdf?_ga=1.84777817.1794372046.1488194088

**Bulk Capacitance Calculation**  

![](./Images/flyback_efficiency_typical.jpg)  
Source: https://www.fairchildsemi.com/application-notes/AN/AN-8033.pdf  

By assuming 70% efficiency for flyback to be designed, we can find maximum input power P<sub>in</sub> as follows:  
  P<sub>in</sub> = P<sub>out</sub>/Efficiency = (15X3+5X3+5X3)/0.7=107W 

Lets select the minimum AC input voltage as 170V. Then V<sub>bulk(min)</sub>=0.7X150 X V2 = 168V by allowing 30% drop in bulk capacitance. 


![](./Images/bulk_capacitance.jpg)  

Here in the formula, N<sub>HC</sub> states the number of half cycle without AC voltage supply to maintain operation and selected as 1 cycle. Moreover, minimum line frequency is selected as 48 Hz.  


C<sub>bulk</sub>> 118 uF  

Following capacitor has been chosen with ratings V = 400V and C = 120 uF  

http://tr.farnell.com/rubycon/400kxw120mefc18x30/cap-alu-elec-120uf-400v-rad/dp/1547017

