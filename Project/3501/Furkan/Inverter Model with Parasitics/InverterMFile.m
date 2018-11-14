%% Initial Configurations
clear all;clc;

%% Source parameters
PulseAmplitude = 9;
fsw = 50e3;
ffund = 50;
frms = 50;
ModulationIndex = 0.9;
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

%% Parasitics
% Tüm parazitikler var
ACapToDrain = 7.14e-9;
ACapToSource = 5.65e-9;
ASourceToLoad = 3.724e-9;
ADrainToLoad = 3.724e-9;
APosToCap = 29.8e-9;
ANegToCap = 48.6e-9;

BCapToDrain = 7.233e-9;
BCapToSource = 5.434e-9;
BSourceToLoad = 3.933e-9;
BDrainToLoad = 3.933e-9;
BPosToCap = 2.63e-9;
BNegToCap = 3.183e-9;

CCapToDrain = 7.145e-9;
CCapToSource = 5.4e-9;
CSourceToLoad = 3.242e-9;
CDrainToLoad = 3.242e-9;
CPosToCap = 43.665e-9;
CNegToCap = 31.2e-9;

% Tüm parazitikler yok
% ACapToDrain = 1e-15;
% ACapToSource = 1e-15;
% ASourceToLoad = 1e-15;
% ADrainToLoad = 1e-15;
% APosToCap = 1e-15;
% ANegToCap = 1e-15;
% 
% BCapToDrain = 1e-15;
% BCapToSource = 1e-15;
% BSourceToLoad = 1e-15;
% BDrainToLoad = 1e-15;
% BPosToCap = 1e-15;
% BNegToCap = 1e-15;
% 
% CCapToDrain = 1e-15;
% CCapToSource = 1e-15;
% CSourceToLoad = 1e-15;
% CDrainToLoad = 1e-15;
% CPosToCap = 1e-15;
% CNegToCap = 1e-15;

%% Load parameters
Vln = 0.612*Vdc/sqrt(3)*ModulationIndex;
PF = 0.98;
P = 2e3;
S = P/PF;
Z = Vln^2/(S/3);
Rload = Z*PF;
Xload = sqrt(Z^2 - Rload^2);
Lload = Xload/(2*pi*ffund);
Iload = Vln/Z;

Idc = P/Vdc;
Rin = 10;
Vin = Vdc + Idc*Rin;
%% Initial Conditions
% % Phase A Top
% CurrAT = 0;
% VoltDSAT = 0;
% VoltGSAT = 0;
% VoltGDAT = VoltDSAT - VoltGSAT;
% % Phase A Bot
% CurrAB = InitialCurrent;
% VoltDSAB = 0;
% VoltGSAB = 0;
% VoltGDAB = VoltDSAB - VoltGSAB;
% % Phase B Top
% CurrBT = InitialCurrent/2;
% VoltDSBT = 0;
% VoltGSBT = 0;
% VoltGDBT = VoltDSBT - VoltGSBT;
% % Phase B Bot
% CurrBB = 0;
% VoltDSBB = 0;
% VoltGSBB = 0;
% VoltGDBB = VoltDSBB - VoltGSBB;
% % Phase C Top
% CurrCT = InitialCurrent/2;
% VoltDSCT = 0;
% VoltGSCT = 0;
% VoltGDCT = VoltDSCT - VoltGSCT;
% % Phase C Bot
% CurrCB = 0;
% VoltDSCB = 0;
% VoltGSCB = 0;
% VoltGDCB = VoltDSCB - VoltGSCB;
% % Load
InitialCurrent = 0;
LoadA = -InitialCurrent;
LoadB = InitialCurrent/2;
LoadC = InitialCurrent/2;
% Source
SourceVolt = Vdc;
SourceCurrent = InitialCurrent;
%% Run Simulink 
model = 'Inverter';
SampleTime = 1e-8;
load_system(model);
set_param(model, 'StopTime','25e-3')
sim(model);

