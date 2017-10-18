%% Initial Configurations
clear all;

%% Device Parameters
K1 = 0.283;
b1 = 2.035;
c1 = 0.124;
d1 = 1.159;
e1 = -0.204;
m1 = 30.972;
n1 = -4.48;
K2 = 7.114;
b2 = 2.054;
c2 = 0.153;

Cgd = 0.5e-12;
Cgs = 64.5e-12;
Cds = 16.5e-12;

Rg = 1;
Rd = 0.1;
Rs = 0.1;
%% Source parameters
PulseAmplitude = 6;
fsw = 100e3;
Vdc = 300;
%% Run Simulink
SampleTime = 1e-12;
model = 'GaNModel_Nonsegmented';
load_system(model);
set_param(model, 'StopTime','4e-5' )
sim(model);