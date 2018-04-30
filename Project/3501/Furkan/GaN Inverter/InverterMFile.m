%% Initial Configurations
clear all;clc;
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
fsw = 1e5;
Vdc = 400;
VpulseMax = 6;
VpulseMin = -3;
% Quantities in below are in percent
Dtop = 48; % duty cycle of top
Dbot = 48; % duty cycle of bot
DelayTop = 0;
DelayBot = 50;



%% Load parameters
LoadCurrent = 10;
Lload = 100e-6;
Rload = 1;
Zload = sqrt(Rload^2 + (2*pi*fsw*Lload)^2);
InitialCurrent = Vdc/Zload;
%% Initial Conditions
% Phase A Top
CurrAT = 0;
VoltDSAT = 0;
VoltGSAT = 0;
VoltGDAT = VoltDSAT - VoltGSAT;
% Phase A Bot
CurrAB = InitialCurrent;
VoltDSAB = 0;
VoltGSAB = 0;
VoltGDAB = VoltDSAB - VoltGSAB;
% Phase B Top
CurrBT = InitialCurrent/2;
VoltDSBT = 0;
VoltGSBT = 0;
VoltGDBT = VoltDSBT - VoltGSBT;
% Phase B Bot
CurrBB = 0;
VoltDSBB = 0;
VoltGSBB = 0;
VoltGDBB = VoltDSBB - VoltGSBB;
% Phase C Top
CurrCT = InitialCurrent/2;
VoltDSCT = 0;
VoltGSCT = 0;
VoltGDCT = VoltDSCT - VoltGSCT;
% Phase C Bot
CurrCB = 0;
VoltDSCB = 0;
VoltGSCB = 0;
VoltGDCB = VoltDSCB - VoltGSCB;
% Load
LoadA = -InitialCurrent;
LoadB = InitialCurrent/2;
LoadC = InitialCurrent/2;
% Source
SourceVolt = Vdc;
SourceCurrent = InitialCurrent;
%% Run Simulink 
SampleTime = 5e-13;
model = 'InverterModel';
load_system(model);
set_param(model, 'StopTime','10e-6')
sim(model);

