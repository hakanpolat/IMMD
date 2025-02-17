%% IMMD DESIGN TOOL
%% M. U�ur
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

%% CATALOG DATA IMPORT
Prated = motor_data(:,1); % Watts
pole_number = motor_data(:,2);
Nrated = motor_data(:,3); % rpm
Tstall_cont = motor_data(:,4); % Nm
Tstall_peak = motor_data(:,5); % Nm
torque_sens = motor_data(:,6); % Nm/Arms
back_emfc = motor_data(:,7); % Vrms/kRPM
length = motor_data(:,8); % mm
Do_stator = motor_data(:,9); % mm
Di_stator = motor_data(:,10); % mm
Di_rotor = motor_data(:,11); % mm
slot_number = motor_data(:,12);
motor_num = numel(motor_data(:,1));

%% INPUTS
module = 4;
layer = 2;
zQ = 50; % number of turns per coil side
phase_s = 3;
Bgap = 0.9; % Tesla
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
q_s = slot_s./(phase_s.*pole_r);
y_s = slot_s/module; % slot per module

%% DRIVE FREQUENCY
fdrive = pole_number.*Nrated/120; % Hz

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
kw1 = zeros(1,motor_num);
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
    for k = 1:motor_num
        if slot_s(k) == 12 && pole_r(k) == 10
            kw1(k) = 0.933; % all teeth wound
            %kw1 = 0.966; % alternate teeth wound
        elseif slot_s(k) == 36 && pole_r(k) == 38
            kw1(k) = 0.953; % all teeth wound
            %kw1 = 0.956; % alternate teeth wound
        elseif slot_s(k) == 36 && pole_r(k) == 46
            kw1(k) = 0.867; % all teeth wound
            %kw1 = 0.87; % alternate teeth wound
        end
    end
end
kw1 = kw1';

%% Stator Parameters
% ??????
% pole_s = 8;
% ??????

%% INDUCED VOLTAGE CALCULATION
Nphm = layer*zQ*q_s; % Number of turns per phase per module
flux_pp = 4*(Di_s/2).*L_s*Bgap./pole_r; % Weber
% induced_voltage_per_module_per_phase
Erms = 4.44*fdrive.*flux_pp.*kw1.*Nphm; % Volts

%% DC LINK CALCULATION
fs = 50; % Hz
Vs_ll = 400; % Volts
Vdc = (3/pi)*Vs_ll*sqrt(2); % Volts

%% INVERTER PARAMETER CALCULATIONS
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
% power and current by module
pf = 0.87;
Pout_inv_module = Pout_module/motor_eff; % W
Sout_inv_module = Pout_inv_module/pf; % VA
Iline = Sout_inv_module/(3*Vph_module); % Amps
% switching frequency
fsw = 100e3; % Hz

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

%% Power stage loss analysis (draft) to estimate efficiency

% WE HAVE SO FAR
% Pout_inv_module
% Vdc_module
% Vph_module
% ma
% fsw
% Iline
% pf
% Sout_inv_module


% Parameter calculation
Vce_p = Vdc_module; % V, peak diode voltage
Icp = Iline*sqrt(2); % A, peak current
Iep = Iline*sqrt(2); % A, peak current
Irr = Iep; % A, peak reverse recovery current

% Device selection
voltage_req_min = Vdc_module; % V
voltage_rating_min = voltage_req_min*1.5; % V
current_req_min = Iline*2; % A
current_rating_min = current_req_min*2; % A

% http://www.gansystems.com/gs66506t.php

%%
% Suppose an IGBT is selected
% Infineon SKB15N60HS IGBT + Diode, 600V, 27A
% http://www.infineon.com/cms/en/product/power/igbt/igbt-discrete/discrete-igbt-with-anti-parallel-diode/SKB15N60HS/productType.html?productType=ff80808112ab681d0112ab6e35f41850

%fsw = 1e3:1e3:20e3; % Hz
fsw = 20e3; % Hz

% Datasheet values
Vce_sat = 2.3; % V, @ A peak
Eon = 0.45e-3; % J, @ 400V
Eon = Eon*Vdc_module/400; % J, @270V
Eoff = 0.275e-3; % J, @400V
Eoff = Eoff*Vdc_module/400; % J, @270V
% Err = 8e-3; % J, @400V
% Err = Err*Vdc_module/600; % J, @270V
Vec = 1.25; % V
trr = 184e-9; % s, @400V
trr = trr*Vdc_module/400; % s, @270V
Irr = 18; % A, @400V
Irr = Irr*Vdc_module/400; % A, @270V

% Loss calculation
Psc = Icp*Vce_sat*(1/8+ma*pf/(3*pi)); % W
Pdc = Iep*Vec*(1/8-ma*pf/(3*pi)); % W
Pss = (Eon+Eoff)*fsw*(1/pi); % W
Pds = (1/8)*Irr*trr*Vce_p*fsw; % W
%Pds = (Err)*fsw*(1/pi); % W
Ploss1 = Psc+Pdc+Pss+Pds; % W
Ploss = Ploss1*6; % W
efficiency1 = 100*Pout_inv_module/(Ploss+Pout_inv_module); % percent
fprintf('Efficiency value with IGBT with 20kHz is %g %%\n',efficiency1);


%%
% Suppose a GaN is selected
% Transphorm TPH3212PS GaN FET, 650V, 26.5A
% http://www.transphormusa.com/product/tph3212ps/

%fsw = 10e3:10e3:100e3; % Hz
fsw = 100e3; % Hz

% Datasheet values
Rds_onB = 72e-3; % Ohms, @25C, @17A, @8V Vgs
Tj = 125; % C
Rds_on = Rds_onB*(Tj/125+0.8); % Ohms
% It is assumed that, Rds_on is not affected by current amplitude up to 80A
% This assumption is based on datasheet graph (Ids vs Vds)
VsdB = 0.5; % V
Vsd = Iep*0.09163+VsdB; % V
% The following time values should be normalized
tdon = 24e-9; % s,VDS=400V, ID = 18A, 25C
tdoff = 55.5e-9; % s,VDS=400V, ID = 18A, 25C
tr = 7.5e-9; % s,VDS=400V, ID = 18A, 25C
tf = 5e-9; % s,VDS=400V, ID = 18A, 25C
trr = 35e-9; % s,VDS=400V, ID = 18A, 1000A/ms, 25C
ton = tdon+tr; % s
toff = tdoff+tf; % s
Eon = Vdc_module*Icp*ton/6; % J
Eoff = Vdc_module*Icp*toff/6; % J
% Irr value was not present in the datasheet. Peak value is taken
Irr = Iep; % A

% Loss calculation
Psc = Rds_on*Icp^2*(1/8+ma*pf/(3*pi)); % W
Pdc = Iep*Vsd*(1/8-ma*pf/(3*pi)); % W
Pss = (Eon+Eoff)*fsw*(1/pi); % W
Pds = (1/8)*Irr*trr*Vce_p*fsw; % W

Ploss1 = Psc+Pdc+Pss+Pds; % W
Ploss = Ploss1*6; % W
efficiency2 = 100*Pout_inv_module./(Ploss+Pout_inv_module); % percent
fprintf('Efficiency value with GaN with 100kHz is %g %%\n',efficiency2);


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




%% DISCARD BELOW
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
        %fprintf('Winding factor for %d slot and %d pole is %1.3g.\n',slot(k),pole(l),winding);
    end
end

%% ANOTHER TRIAL

slot = 6;
pole = 8;
winding = sin(pole*pi/slot);
winding = abs(winding);
%disp(winding);


