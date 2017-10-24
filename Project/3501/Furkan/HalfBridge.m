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
PulseAmplitude = 6;
fsw = 1000e3;
Vdc = 300;
% Quantities in below are in percent
Dtop = 49; % duty cycle of top
Dbot = 49; % duty cycle of bot
DelayTop = 0;
DelayBot = 50;


%% Load parameters
Rload = 10;
Lload = 10e-6;
%% Run Simulink
SampleTime = 1e-12;
model = 'GaN_HalfBridge';
load_system(model);
set_param(model, 'StopTime','1.4e-6' )
sim(model);