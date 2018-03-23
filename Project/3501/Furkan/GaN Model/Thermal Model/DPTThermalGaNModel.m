%% Initial Configurations
clear all;
%% Device Parameters
Temp = 125; % Junction Temp in Celcius
Cgd = 1.748e-12;
Cgs = 160e-12;
Cds = 65.7e-12;

Ls = 62e-12;
Ld = 450e-12;
Lg = 0.65e-9;
Lss = 0.43e-9;

Rg = 1.5;
Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0128*(Temp - 25))) / 295 + 1e-4;
Rd = (3.6/4) * (0.95*0.82*(1 - (-0.0128*(Temp - 25))) * 18.2 / 295) + 1e-4;
Rss = 1e-3;

Rt = (0.9*0.95*0.82*18.2/295 + 3.6*0.238*0.82/295);
%% Circuit Parasitics
Ldc = 1.5e-9;
Lground = 5e-9;

%% Gate Driver
Lgex = 3e-9;
Ron = 10;
Roff = 2;
%% Source parameters
PulseAmplitude = 9;
fsw = 2000e3;
Vdc = 400;
VpulseMax = 6;
VpulseMin = -3;
% Quantities in below are in percent
Dtop = 48; % duty cycle of top
Dbot = 48; % duty cycle of bot
DelayTop = 0;
DelayBot = 50;


%% Load parameters
LoadCurrent = 30;
Lload = 480e-6;

CurrRipple = Vdc*(Dbot/100)/(fsw*Lload);
InitialCurrent = LoadCurrent + CurrRipple/2;
%% Run Simulink
SampleTime = 5e-13;
model = 'DPTThermalGaNModelSLX';
load_system(model);
set_param(model, 'StopTime','0.55e-6')
sim(model);
