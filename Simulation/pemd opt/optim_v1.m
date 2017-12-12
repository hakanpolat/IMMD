%% Multi-physics Optimization of IMMD
%%
% In this file, the system model is developed for the purpose of
% multi-physics optimization of the IMMD system for PEMD paper.
%%
% M. Uður
%
% 12.12.2017
%
% All rights reserved
%% Definitions
% The system is composed of the following parts:
%
% * Drive power electronics (DC link + inverter)
% * Machine (windings, geometry)
% * Heatsink (geometry)
%% Parameters
% The following categories are proposed:
%
% * Constant parameters
% * Optimization parameters
% * Dependent parameters
% * Constraint parameters
% * Objective parameters
%
%% Constant parameters with definitions

% Number of phases in each module
m = 3;
% Average DC link voltage
Vdc = 540; % V


%% Everything below is subject to change
% %%
% Q = 48;
% layer = 2;
% n = 4;
% p = 40;
% Pout = 8e3;
% Poutm = Pout/n;
% Nrated = 540;
% length = 0.15;
% Din = 0.15;
% Dout = 0.23;
% effmotor = 0.9;
% 
% w = Q/(n*m);
% ffund = Nrated*p/120;
% kw = 0.933;
% 
% Bgapa = 0.6;
% Bgap = Bgapa*pi/2;
% fluxpp = 2*Din*length*Bgap/p;
% 
% zQ = 22;
% Nph = zQ*w*layer/2;
% E = 4.44*Nph*ffund*fluxpp*kw;
% Vln = E*1.1;
% 
% Vdc = 540;
% Vdcm = Vdc/2;
% 
% Vllrms = Vln*sqrt(3);
% scale = sqrt(3)/(2*sqrt(2));
% ma = Vllrms/(scale*Vdcm);
% 
% Pdrout = Poutm/effmotor;
% pf = 0.9;
% Sdrout = Pdrout/pf;
% Iphase = Sdrout/(sqrt(3)*Vllrms);
% 
% 
% %%
% % Design ans Simulation with IGBT
% 
% Ts = 1e-6; % sec
% % Modulation index
% ma = 0.8;
% % Switching frequency
% fsw = 10e3; % Hz
% % DC link voltage
% Vdc = 400; % Volts
% % Load
% Ptotal = 8e3/0.9; % W
% Pout = Ptotal; % W
% pf = 0.9;
% Sout = Pout/pf; % VA
% fout = 50; % Hz
% wout = 2*pi*fout; % rad/sec
% Vll_rms = ma*Vdc*0.612; % Volts
% Iline = Sout/(Vll_rms*sqrt(3)); % Amps
% Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
% Rload = Zload*pf; % Ohms
% Xload = sqrt(Zload^2-Rload^2); % Ohms
% Lload = Xload/wout; % Henries
% 
% Rin = 10;
% %Lin = 1e-3;
% Vin = Vdc + Rin*(Ptotal/Vdc);
% Cdc = 200e-6;
% 
% Iphase = Iline;
% Idct = Ptotal/Vdc;
% Idcc = (3/(2*sqrt(2)))*ma*Iphase*pf;
% Irmss = Iphase*sqrt(2*ma*(sqrt(3)/(4*pi) + pf^2*(sqrt(3)/pi-9*ma/16)));
% Irms_perc = 100*Irmss/Idcc;
% 
% fsw = 10e3; % Hz
% volt_ripple_perc = 1;
% volt_ripple = volt_ripple_perc*Vdc/100;
% Iapeak = Iphase*sqrt(2);
% Cdc = ma*(Iapeak - Idcc)/(volt_ripple*fsw*2);
% Cdcm = Cdc*1e6;
% 
% 
% %%
% % Capacitor selection
% M = 0.8;
% Iline = Iphase;
% cosphi = 0.9;
% module = 4;
% efficiency = 0.98;
% 
% Icrms = module/2*Iphase*sqrt(2*M*(sqrt(3)/(4*pi) +...
%     cosphi^2*(sqrt(3)/pi-9*M/16)));
% Idc = module/2*(3/(2*sqrt(2)))*M*Iline*cosphi/efficiency;
% Icrms_perc = 100*Icrms/Idc;
% 
% fsw = 40e3; % Hz
% Cdc = 40e-6; % F
% Iapeak = Iline*sqrt(2);
% volt_ripple = M*(Iapeak - Idc/2)/(Cdc*fsw*sqrt(2))
% volt_ripple_perc = volt_ripple/Vdc*100


