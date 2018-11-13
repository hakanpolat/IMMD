%% Initial Configurations
clear all;clc;

%% Source parameters
PulseAmplitude = 9;
fsw = 50e3;
ffund = 50;
ModulationIndex = 0.85;
Vdc = 270;
VpulseMax = 6; 
VpulseMin = -3;
% Quantities in below are in percent
Dtop = 45; % duty cycle of top
Dbot = 45; % duty cycle of bot
DelayTop = 0;
DelayBot = 50;

Ls = 0.9e-9;
Ld = 0.9e-9;

%% Load parameters
LoadCurrent = 10;
Lload = 400e-6;
Rload = 10;
Zload = sqrt(Rload^2 + (2*pi*ffund*Lload)^2);
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
InitialCurrent = 0;
LoadA = -InitialCurrent;
LoadB = InitialCurrent/2;
LoadC = InitialCurrent/2;
% Source
SourceVolt = Vdc;
SourceCurrent = InitialCurrent;
%% Run Simulink 
model = 'Inverter';
load_system(model);
set_param(model, 'StopTime','20e-3')
sim(model);

