%% Initial Configurations
clear all;
%% Device Parameters
Temp = 75; % Junction Temp in Celcius
Cgd = 1.748e-12;
Cgs = 150e-12;
Cds = 1000e-12;

Ls = 62e-12;
Ld = 450e-12;
Lg = 0.65e-9;
Lss = 0.43e-9;

Rg = 1.5;

Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0135*(Temp - 25))) / 295;% + 1e-4;
Rd =(3.6/8) * (0.95*0.82*(1 - (-0.0135*(Temp - 25))) * 18.2 / 295);% + 1e-4;
Rss = 1e-3;

Rt = (0.9*0.95*0.82*18.2/295 + 3.6*0.238*0.82/295);
%% Circuit Parasitics
Ldc = 3e-9;
Lground = 5e-9;

%% Gate Driver
Lgex = 3e-9;
Ron = 10;
Roff = 1;
PulseAmplitude = 9;
fsw = 1000e3;
VpulseMax = 6;
VpulseMin = -3;
RiseTime = 1e-9;
FallTime = 1e-9;
%% Source parameters
Vdc = 400;
% Quantities in below are in percent
Dtop = 40; % duty cycle of top
Dbot = 40; % duty cycle of bot


%% Load parameters
LoadCurrent = 15;
Lload = 35e-3;
Rload = 8;
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
SampleTime = 5e-13;
model = 'DPTSpiceModel';
load_system(model);
set_param(model, 'StopTime','1.7e-6')
sim(model);