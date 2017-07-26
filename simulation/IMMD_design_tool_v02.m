%% IMMD DESIGN TOOL v.02
%% M. Uður
%% 2017

%% SPECIFICATIONS
% Fractional Slot Concentrated Winding Permanent Magnet Synchronous Motor
% FSCW-PMSM
%%
% Cooling: ???
%%
% Motor efficiency aim = ??? %
%%
% Power stage efficiency aim = 98 %
%%
% Average winding temperature rise: 130 C
%%
% Hot spot temperature rise: 160 C
%%
% Semiconductor temperature: 125 C
%%
% Maximum winding temperature: 200 C

%% Fundamental blocks
% Rotor
%%
% Stator
%%
% Inverter
%%
% DC Link
%%
% Rectifier
%%
% Controller
%%
% Heat sink

%% Motor data
Prated = 6000; %W
pole_number = 30;
Nrated = 600; % rpm
length = 37; % mm
Do_stator = 330; % mm
Di_stator = 220; % mm
Di_rotor = 155; % mm
slot_number = 36;

%% INPUTS
module = 4;
layer = 2; % all teeth
zQ = 100; % number of turns per coil side
phase_s = 3;
Bgap = 0.9; % Tesla, peak
motor_eff = 0.9;
% Inverter configuration: 0 for H-bridge, 1 for 3-phase bridge
inverter_config = 1;
% winding configuration: 0 for distributed, 1 for concentrated
winding_config = 1;

%% BASIC CALCULATIONS
wrated = Nrated*2*pi/60; % rad/s
Pout_total = Prated; % Watts
Trated = Pout_total/wrated; % Nm
Pout_module = Pout_total/module; % Watts
slot_s = slot_number;
pole_r = pole_number;
q_s = slot_s./(phase_s.*pole_r); % slots per pole per phase
y_s = slot_s/(phase_s*module); % slot per module per phase

%% DRIVE FREQUENCY
fdrive = pole_r.*Nrated/120; % Hz

%% MECHANICAL CALCULATIONS
Do_s = Do_stator*1e-3; % m
Di_s = Di_stator*1e-3; % m
L_s = length*1e-3; % m
Di_r = Di_rotor*1e-3; % m
Surface_s = pi*Di_s.*L_s; % m^2
Circum_s = pi*Di_s; % m
Volume_s = Di_s.^2.*L_s*pi/4; % m^3

%% WINDING CALCULATIONS
% winding factor
kw = 0.933;

%% INDUCED VOLTAGE CALCULATION
Nphm = layer*zQ*y_s/2; % Number of turns per phase per module
flux_pp = 4*(Di_s/2).*L_s*Bgap./pole_r; % Weber
% induced_voltage_per_module_per_phase
Erms = 4.44*fdrive*flux_pp*kw*Nphm; % Volts

%% DC LINK CALCULATION
fs = 50; % Hz
Vs_ll = 400; % Volts
Vdc = (3/pi)*Vs_ll*sqrt(2); % Volts

%% INVERTER PARAMETER CALCULATIONS
% connection
series = 2;
parallel = module/series;
% modulation technique: 0 for SPWM, 1 for SVPWM
mod_tech = 0;
% voltage by module
Vdc_module = Vdc/series;
ma = 0.9;
if mod_tech == 0
    Vph_module = Vdc_module*ma/(2*sqrt(2)); % Vrms
    % 0.612 = sqrt(3/2)/2: Mohan equation for line-line voltage
elseif mod_tech == 1
    Vph_module = Vdc_module*ma/(sqrt(2*3)); % Vrms
end
% power and current by module
pf = 0.87;
Pout_inv_module = Pout_module/motor_eff; % W
Sout_inv_module = Pout_inv_module/pf; % VA
Iline = Sout_inv_module/(3*Vph_module); % Amps
% switching frequency
fsw = 40e3; % Hz

%% PCB DIMENSIONS
allowable_height = 5; % cm
pcb_outer = Do_s*1e2; % cm
pcb_inner = Di_r*1e2; % cm

pcb_area = pi*((pcb_outer/2).^2-(pcb_inner/2).^2); % cm^2
area_per_module = pcb_area/module; % cm^2

pcb_volume = pcb_area*allowable_height; % cm^3
volume_per_module = pcb_volume/module; % cm^3
volume_per_module_in3 = volume_per_module*0.0610237; % in^3

%power_density = Pout_inv_module./volume_per_module_in3; % W/in^3
power_density = Pout_inv_module./volume_per_module; % W/cm^3

