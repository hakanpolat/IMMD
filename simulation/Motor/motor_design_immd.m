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
ns = 2;
np = 2;
Nrated = 600; %rpm
power_factor = 0.9;
eff_m = 0.94;
eff_d = 0.98;

%% Selected Inputs
B = 0.9; % Tesla
A = 50e3; % A/m (rms)
J = 4; % A/mm^2
ma = 0.85;
% w: slot/module/phase
w = 1;
layer = 2;
kcu = 0.6;

%% Calculated Inputs
Vdcm = Vdc/ns; % volts
Vline = 0.612*ma*Vdcm; % volts
Vphase = Vline/sqrt(3); % volts

wrated = Nrated*2*pi/60; % rad/s
Trated = Prated/wrated; % Nm

Pin = Prated/eff_m; % W
Pinm = Pin/n; % W
Iline = Pinm/(Vphase*3); % A

pole = 20;
pole_pair = pole/2;
frated = Nrated*pole/120; % Hz

stress_tensor = B*A; % Pa
Di2L = 2*Trated/(pi*stress_tensor); % m^3
%aspect = (pi/pole)*(pole_pair)^(1/3);
L = 0.15;
Dis = (Di2L/L)^(1/2); % m
%L = aspect*Dis % m
ris = Dis/2; % m

% Air gap
lg = 1.6*(0.18+0.006*Prated^0.4); % mm

% The following is assumed, probably wrong
DoDi = 1.4;
Dos = Dis*DoDi; % m

Qs = w*m*n*2; % stator slots
slot_pitch = pi*Dis/Qs; % m

% Winding factor
if Qs == 48 && pole == 40
    kw = 0.933;
elseif Qs == 48 && pole == 44
    kw = 0.949;
elseif Qs == 48 && pole == 46
    kw = 0.954;
end

% Winding factor
if Qs == 24 && pole == 20
    kw = 0.933;
elseif Qs == 24 && pole == 22
    kw = 0.949;
elseif Qs == 24 && pole == 26
    kw = 0.949;
elseif Qs == 24 && pole == 28
    kw = 0.933;
end

% Induced EMF
Erms = Vphase/1.1; % volts
flux_per_pole = 4*ris*L*B/pole; % Wb
Nphm = Erms/(4.44*frated*flux_per_pole*kw);
zQ = Nphm*2/(w*layer);

% Coils
copper_resistivity = 1.7e-8; % Ohm*m
copper_permeability = 1.256629e-6; % H/m
angular_frequency = 2*pi*frated; % rad/sec
skin_depth = 1e3*sqrt(copper_resistivity*2/(angular_frequency*copper_permeability)); % mm
copper_area = Iline/J; % mm^2
copper_radius = sqrt(copper_area/pi); % mm
copper_diameter = copper_radius*2; % mm
% AWG - wire #14
wire_strand = 1;
wire_diameter = 1.62814; % mm
wire_radius = wire_diameter/2; % mm
wire_diameter_insulation = wire_diameter*1.02; % mm
wire_area_insulation = pi*(wire_diameter_insulation/2)^2; % mm^2
total_stator_wire_area = wire_strand*wire_area_insulation; % mm^2
ohm_per_m = 1e-3*8.282; % Ohm/km

% Fill factor
ht = 0.8*(Dos-Dis)/2; % m
bs = slot_pitch/2; % m
bt = slot_pitch/2; % m
slot_area = bs*ht; % m^2
winding_area = wire_area_insulation*zQ*1e-6;
fill_factor = winding_area/slot_area



% MMF waveform
% Harmonics

