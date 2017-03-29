%% An example motor from Kollmorgen

% Datasheet parameters
% KBM(S)-45X02-X - B
pole = 10;
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

% Back emf at rated speed
Ea = Kb*Nrated
% Phase resistance
Ra = Rlinetoline/2; % Ohms

