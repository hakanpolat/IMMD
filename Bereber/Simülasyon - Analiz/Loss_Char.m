clc
clear

%initilize the PWM parameters

f_sw=1000;

V_dc=400;
sim('inverter_model')
Current=simout.Data;