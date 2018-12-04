%% Initial Configurations
clear all;
%% Device Parameters
Temp = 25; % Junction Temp in Celcius
Cgd = 2e-12;
Cgs = 258e-11;
Cds = 63e-12;

Ls = 0.9e-9;
Ld = 0.9e-9;
Lg = 1e-9;
Lss = 1e-9;

Rg = 1.5;

Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0135*(Temp - 25))) / 295;% + 1e-4;
Rd =(3.6/8) * (0.95*0.82*(1 - (-0.0135*(Temp - 25))) * 18.2 / 295);% + 1e-4;
Rss = 1e-3;

Rt = (0.9*0.95*0.82*18.2/295 + 3.6*0.238*0.82/295);
%% Circuit Parasitics
Ldc = 7.1e-9;
Lground = 5.7e-9;
Lp = 7.5e-9;
%% Gate Driver
Lgex = 1.5e-9;
Ron = 10;
Roff = 2;
PulseAmplitude = 9;
fsw = 1000e3;
VpulseMax = 6;
VpulseMin = -3;
RiseTime = 1e-9;
FallTime = 1e-9;
%% Source parameters
Vdc = 80;
% Quantities in below are in percent
Dtop = 40; % duty cycle of top
Dbot = 40; % duty cycle of bot
Resr = 21.1e-3; %DC Link Capacitor Resistance
Lesl = 19e-9; %DC Link Capacitor Inductance
C = 5e-6; %DC Link Capacitance
%% Load parameters
LoadCurrent = 0;
Lload = 35e-3;
Rload = 1e6;
InitialCurrent = LoadCurrent;
%% Initial Conditions
% First Bottom ON
% CurrDSBot = LoadCurrent;
% VoltDSBot = 0;
% VoltGSBot = VpulseMax;
% VoltGDBot = VoltDSBot - VoltGSBot;
% CurrDSTop = 0;
% VoltDSTop = Vdc;
% VoltGSTop = VpulseMin;
% VoltGDTop = VoltDSTop - VoltGSTop;
% DelayTop = 50;
% DelayBot = 0;

% First Top ON
CurrDSBot = 0;
VoltDSBot = Vdc;
VoltGSBot = VpulseMin;
VoltGDBot = VoltDSBot - VoltGSBot;
CurrDSTop = -LoadCurrent;
VoltDSTop = 0;
VoltGSTop = VpulseMax;
VoltGDTop = VoltDSTop - VoltGSTop;
DelayTop = 0;
DelayBot = 50;
%% Run Simulink
SampleTime = 1e-11;
TrigTime = 0.4e-6;
model = 'DPTSpiceModel';
load_system(model);
set_param(model, 'StopTime','1.5e-6')
sim(model);