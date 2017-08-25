%% Machine Design for IMMD Project
% This file is the design process of the motor in the IMMD system based on
% analytical tools and calculations. The outputs of this procedure are
% slot-pole numbers, main dimensions etc.
% The motor is a permanent magnet synchronous motor (PMSM) having
% fractional slot concentrated winding (FSCW) stator configuration
% It is a high torque low speed application.

%%
% Input parameters
% Phase number per module: 3-phase
% Total output power: 8 kW
% Efficiency aim: % 93
% Number of modules: 4
% DC link voltage: 540
% Modules: 2-series, 2-parallel
% Rated speed: 600 rpm
% Power factor: 0.9 (how to set this for a PMSM ????)
%% The following are not certain
% Average winding temp rise: 130 degree C
% Hot spot temp rise: 160 degree C
% Maximum winding temp: 200 degree C

%% Design inputs
Prated = 8e3; % watts
m = 3;
Vdc = 540; % volts
n = 4;
series = 2;
parallel = 2;
Nrated = 600; %rpm
power_factor = 0.9;
efficiency = 0.93;

%% Selected Inputs
B = 0.9; % Tesla
A = 50e3; % A/m (rms)
J = 4; % A/mm^2
ma = 0.9;
% w: slot/module/phase
w = 1;
layer = 2;

%% Calculated Inputs
Vdcm = Vdc/series; % volts
Vline = 0.612*ma*Vdcm; % volts
Vphase = Vline/sqrt(3); % volts

wrated = Nrated*2*pi/60; % rad/s
Trated = Prated/wrated; % Nm

Pin = Prated/efficiency; % W
Pinm = Pin/n; % W
Iline = Pinm/(Vphase*3); % A

pole = 20;
pole_pair = pole/2;
frated = Nrated*pole/120; % Hz

stress_tensor = B*A; % Pa
Di2L = 2*Trated/(pi*stress_tensor); % m^3
aspect = (pi/pole)*(pole_pair)^(1/3);
Dis = (Di2L/aspect)^(1/3); % m
L = aspect*Dis; % m
ris = Dis/2; % m

% Air gap
lg = 1.6*(0.18+0.006*Prated^0.4); % mm

% The following is assumed, probably wrong
DoDi = 1.2;
Dos = Dis*1.2; % m

Qs = w*m*n*2; % stator slots

% Winding factor
kw = 0.933;

% Induced EMF
Erms = Vphase; % volts
flux_per_pole = 4*ris*L*B/pole; % Wb
Nphm = Erms/(4.44*frated*flux_per_pole*kw);
zQ = Nphm*2/(w*layer);


%Nph = zQ*w*layer/2;

% MMF waveform
% Harmonics




