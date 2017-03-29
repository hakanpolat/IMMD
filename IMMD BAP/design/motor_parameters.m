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

