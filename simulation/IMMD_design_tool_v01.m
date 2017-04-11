%% IMMD DESIGN TOOL
%% M. Uður
%% 2017
%%
% In this file, design of the IMMD system will be conducted.
% Analytical design methods will be used with the aid of simulations.
% The relations between the blocks will be considered.
% The design is for the prototype on BAP Project.

%% SPECIFICATIONS
% Permanent Magnet Brushless DC Motor (PM-BLDC)
%%
% Cooling: Forced air cooling
%%
% Motor efficiency aim = 98 %
%%
% Power stage efficiency aim = 98 %
%%
% Average winding temperature rise: 130 C
%%
% Hot spot temperature rise: 160 C
%%
% Semiconductor temperature rise: 100 C
%%
% Maximum winding temperature: 200 C


%% Fundamental blocks:
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

%% General Inputs
% motor catalog (Kollmorgen, KBM(S)-88X00-X, B)
%%
% http://productpage.3dpublisher.net/3dproductpage/Qsvalidlogin.asp?GUID=1249850940083&name=KBM(S)-88&isCate=true
%%
% http://www.kollmorgen.com/en-us/products/motors/direct-drive/kbm-series-frameless/_literature/kbm-selection-guide-en-us_revg/
Prated = 5.46e3; % Watts
Nrated = 1000; % rpm
Tstall_cont = 102; % Nm
Icont = 20.5; % Amps
Tstall_peak = 145; % Nm
Ipeak = 48.3; % amps
torque_sens = 5.06; % Nm/Arms
back_emfc = 306; % Vrms/kRPM
motor_cons = 6.10; % Nm/sqrt(Watt)
res_ltol = 0.46; % Omhs
induct = 4.5; % mH
inertia = 5.26e-2; % kgm^2
friction_static = 1.08; % Nm
Tcogging_pp = 0.81; % Nm
friction_viscous = 0.385; % Nm/kRPM
Rth = 0.305; % C/W
pole_number = 46;
slot_number = 36;

length = 36.37; % mm
outer_dia = 331.46; % mm
Di_rotor = 155.02; % mm

% basic inputs and calculations
module = 4;
wrated = Nrated*2*pi/60; % rad/s
Pout_total = Prated; % Watts
Trated = Pout_total/wrated; % Nm
Pout_module = Pout_total/module; % Watts
% Inverter configuration: 0 for H-bridge, 1 for 3-phase bridge
inverter_config = 0;
% winding configuration: 0 for distributed, 1 for concentrated
winding_config = 0;

%% Stator Parameters
slot_s = slot_number;
phase_s = 3;
pole_r = pole_number;
q_s = slot_s/phase_s/pole_r;
% slot per module
y_s = slot_s/module;
layer_s = 2;
zQ = 10; % number of turns per coil side

% Number of turns per phase per module
Nphm = layer_s*zQ*q_s;

% mechanical
Do_s = 0.15; % m
Di_s = 0.1; % m
L_s = 0.1; % m
Surface_s = pi*Di_s*L_s; % m^2
Circum_s = pi*Di_s; % m
Volume_i = Di_s^2*L_s*pi/4; % m^3

% winding factor
if winding_config == 0
    pitch = 2/3;
    pitch_angle = pitch*pi; % electrical radians
    slot_angle = (pole_s/2)*2*pi/slot_s; % electrical radians
    slot_pitch =Circum_s/slot_s; % m
    % pitch factor
    kp1 = sin(pitch_angle/2);
    % distribution factor
    kd1 = sin(q_s*slot_angle/2)/(q_s*sin(slot_angle/2));
    % winding factor
    kw1 = kp1*kd1;
elseif winding_config == 1
    kw1 = 0.867; % 36/46, all teeth wound
    %kw1 = 0.87; % 36/46, alternate teeth wound
end

% peak flux density and flux
Bgap = 0.9; % Tesla

flux_pp = 4*(Di_s/2)*L_s*Bgap/pole_s; % Weber


%% Rotor Parameters
pole_r = 8;
Do_r = 100; % mm
Di_r = 30; % mm
shaft_dia = Di_r; % mm

motor_eff = 0.9;


%% Rectifier parameters

fs = 50; % Hz
Vs_ll = 400; % Volts
Vdc = (3/pi)*Vs_ll*sqrt(2); % Volts



%% DC Link parameters




%% Inverter Parameters

% connection
series = 2;
parallel = module/series;

% modulation technique: 0 for SPWM, 1 for SVPWM
mod_tech = 1;

% voltage by module
Vdc_module = Vdc/series;
ma = 1;
if mod_tech == 0
    Vph_module = Vdc_module*ma/(2*sqrt(2)); % Vrms
    % 0.612 = sqrt(3/2)/2: Mohan equation for line-line voltage
elseif mod_tech == 1
    Vph_module = Vdc_module*ma/(sqrt(2*3)); % Vrms
end


% power by module
pf = 0.87;
Pout_inv_module = Pout_module/motor_eff; % W
Sout_inv_module = Pout_inv_module/pf; % VA
Iline = Sout_inv_module/(3*Vph_module); % Amps


% frequency and speed
ffund = 100; % Hz
Nsync = 120*ffund/pole_s; % rpm
wsync = Nsync*2*pi/60; % rad/s
fsw = 100e3; % Hz

% induced_voltage_per_module_per_phase
Erms = 4.44*ffund*flux_pp*kw1*Nphm; % Volts


%% Motor design continue

Ipeak = Iline*sqrt(2); % Amps
MMF_peak = (phase_s/2)*(4/pi)*(Nphm*Ipeak)*kw1; % A-t
perm_air = 4*pi*1e-7; % H/m

% conductors

% frequency constraint
fmax = ffund*2; % Hz
copper_res = 1.7e-8; % Ohm*m
copper_perm = 1.256629e-6; % H/m
ang_freq = 2*pi*fmax; % rad/sec
skin_depth = sqrt(copper_res*2/(ang_freq*copper_perm)); % m
max_cond_dia = 2*skin_depth; % m

% current constraint
current_density = 7; % A/mm^2
copper_area = Iline/current_density; % mm^2
copper_radius = sqrt(copper_area/pi); % mm
copper_diameter = copper_radius*2; % mm

% wire selection: % AWG#16
wire_diameter = 1.29032; % mm
wire_radius = wire_diameter/2; % mm
wire_strand = 1;
wire_area = pi*wire_radius^2; % mm^2
stator_current_density = Iline/(wire_area*wire_strand); % A/mm^2

% fill factor
wire_diameter_insulation = wire_diameter*1.1; % mm
wire_area_insulation = pi*(wire_diameter_insulation/2)^2; % mm^2
total_stator_wire_area = wire_strand*wire_area_insulation; % mm^2
total_stator_slot_wire_area = layer_s*zQ*total_stator_wire_area; % mm^2
% this value is not set right now
slot_area = 100; % mm^2
fill_factor = total_stator_slot_wire_area/slot_area;



%% RL Load design
V1load = Vph_module; % V
S1load = Sout_inv_module/3; % VA
I1load = S1load/V1load; % A
Z1load = V1load/I1load; % Ohms
R1load = Z1load*pf; % Ohms
X1load = sqrt(Z1load^2-R1load^2); % Ohms
L1load = X1load/(2*pi*ffund); % Henries

% resistor
res_val = R1load; % Ohms
res_cur = I1load; % A
res_pow = I1load^2*R1load; % W

%%
% sample: http://tr.farnell.com/arcol-ohmite/fpa100-100r-j/res-thick-film-100r-5-1kv-screw/dp/2505103
%%
% heat sink design is required for the resistive load


%% JUST A SMALL TEST CODE
slot = [6,9,12,15,18,21,24,27,30,33,36];
%slot = 6;
pole = [4,6,8,10,12,14,16,20,22,24,26,28,30,32,34,42];
%pole = 4;
for k = 1:numel(slot)
    for l = 1:numel(pole)
        full_pitch = 180/(pole(l)/2);
        slot_pitch = 360/slot(k);
        span = slot_pitch/full_pitch;
        winding = abs(sin(span*pi));
        fprintf('Winding factor for %d slot and %d pole is %1.3g.\n',slot(k),pole(l),winding);
    end
end

%% ANOTHER TRIAL

slot = 6;
pole = 8;
winding = sin(pole*pi/slot)

