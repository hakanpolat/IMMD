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

Cgd = 2e-12;
Cgs = 258e-12;
Cds = 63e-12;

Ls = 0.05e-9;
Ld = 3e-9;
Lg = 3e-9;

Rg = 1;
Rd = 25e-3;
Rs = 25e-3;

%% Gate Driver
Ron = 12;
Roff = 2;
%% Source parameters
PulseAmplitude = 10;
fsw = 800e3;
Vdc = 300;
D = 50; % duty cycle 

%% Load parameters
Rload = 10;
%% Run Simulink
SampleTime = 1e-12;
model = 'GaN_SimScape_Nonsegmented';
load_system(model);
set_param(model, 'StopTime','2e-6' )
sim(model);