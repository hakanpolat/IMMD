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
% Cooling: Forced air cooling
% Motor efficiency aim = 98 % 
% Power stage efficiency aim = 98 % 
% Average winding temperature rise: 130 C
% Hot spot temperature rise: 160 C
% Semiconductor temperature rise: 100 C
% Maximum winding temperature: 200 C


%% Fundamental blocks:
% Rotor
% Stator
% Inverter
% DC Link
% Rectifier
% Controller
% Heat sink

%% General Inputs
total_output_power = 8e3; % Watts
number_of_modules = 4;
rated_speed = 1500; % rpm
rated_torque = total_output_power/rated_speed; % Nm
power_per_module = total_output_power/number_of_modules; % Watts
% Inverter configuration: 0 for H-bridge, 1 for 3-phase bridge
inverter_configuration = 0;
% winding configuration: 0 for distributed, 1 for concentrated
winding_configuration = 1;


%% Stator Parameters
stator_slot_number = 48;
stator_phase_number = 3;
stator_pole_number = 8;
stator_slot_per_pole_per_phase = stator_slot_number/stator_phase_number/stator_pole_number;
stator_slot_per_mocule = stator_slot_number/number_of_modules;
stator_layer = 2;
stator_conductor_per_coil_side = 10;

number_of_turns_per_phase_per_module = 1;


stator_outer_diameter = 150; % mm
stator_inner_diameter = 100; % mm
stack_length = 100; % mm


% pitch factor
% distribution factor
% winding factor
% fill factor
% induced_voltage_per_module_per_phase


%% Rotor Parameters
rotor_pole_numner = 8;
rotor_outer_diameter = 100; % mm
rotor_inner_diameter = 30; % mm

%% Inverter Parameters
fundamental_frequency = 100; % Hz
power_factor = 0.87;
line_to_line_voltage = 400; % Volts





%% DC Link parameters



%% Rectifier parameters




%% NOT USED RIGHT NOW

%% An example motor from Kollmorgen

% Datasheet parameters
% KBM(S)-45X02-X - B
rotor_pole = 10;
Prated = 7200; % W
Tstall_cont = 43.5; % Nm
Tstall_peak = 171; % Nm
Icont = 14.9; % Arms
Nrated = 2350; % rpm
Kt = 2.98; % Nm/Arms
Kb = 180; % Vrms/krpm
Rlinetoline = 0.76; %Ohms
Lm = 12; % mH
Vt_ll = 480; % V

% Back emf at rated speed (line-to-line)
Ea_ll = Kb*Nrated*1e-3; % V
Ea = Ea_ll/sqrt(3); % V
% Terminal voltage
Vt = Vt_ll/sqrt(3);
% Phase resistance
Ra = Rlinetoline/2; % Ohms
% Drive frequency

%%
% Datasheet parameters
% KBM(S)-88X00-X - B
rotor_pole = 46;
Prated = 5460; % W
Tstall_cont = 102; % Nm
Tstall_peak = 197; % Nm
Icont = 34; % Arms
Nrated = 1000; % rpm
Kt = 3.04; % Nm/Arms
Kb = 184; % Vrms/krpm
Rlinetoline = 0.165; %Ohms
Lm = 1.6; % mH
Vt_ll = 240; % V

% Back emf at rated speed (line-to-line)
Ea_ll = Kb*Nrated*1e-3; % V
Ea = Ea_ll/sqrt(3); % V
% Terminal voltage
Vt = Vt_ll/sqrt(3);
% Phase resistance
Ra = Rlinetoline/2; % Ohms

stator_slot = 36;
phase = 3;

% Drive frequency





%% BELOW ARE THE MATLAB CODE FOR 564 MACHINE DESIGN PROJECT


