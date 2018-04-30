%% Initial Configurations
clear all;
%% Device Parameters

%% Circuit Parasitics
Ldc = 1.5e-9;
Lground = 5e-9;
%% Gate Driver
Lgex = 3e-9;
Ron = 10;
Roff = 1;
RiseTime = 55e-9;
FallTime = 55e-9;
%% Source parameters
PulseAmplitude = 9;
fsw = 10e3;
Vdc = 175;
VpulseMax = 6;
VpulseMin = 0;
% Quantities in below are in percent
Dtop = 49; % duty cycle of top
Dbot = 49; % duty cycle of bot
DelayTop = 0;
DelayBot = 50;


%% Load parameters
LoadCurrent = 15;
Lload = 1e-3;
Cload = 350e-6;
CurrRipple = Vdc*(Dbot/100)/(fsw*Lload);
InitialCurrent = 0;% LoadCurrent + CurrRipple/2;
%% Run Simulink
SampleTime = 5e-6;
model = 'SynchBuckSLX';
load_system(model);
set_param(model, 'StopTime','20000e-6')
sim(model);
