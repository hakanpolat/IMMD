% Vbyf Control Simulation Parameters
% 
% pole_pair = 10;
% motor_speed = 600; % rpm
% Ts = 100e-9; % sec
% Tfinal = 0.1; % sec
% Ripth = 0.08; % sec
% fsw = 10e3; % Hz
% Tsw = 1/fsw; % sec
% Vdc = 300; % Volts
% Pout = 2e3; % W
% Ef = 85; % Volts
% Ls = 13.8e-3; % Henries
% Rs = 1e-3; % Ohms
% fout = 50; % Hz
% wout = 2*pi*fout; % rad/sec
% m = 3;
% np = 1;
% ns = 1;
% n = ns*np;
% Poutm = Pout/n; % Watts
% Is = Poutm/(Ef*m); % amps
% Xs = wout*Ls; % Ohms
% Vdrop = Is*Xs; % Volts
% Vt = sqrt(Ef^2+Vdrop^2); % Volts
% Vdcm = Vdc/ns; % volts
% ma = Vt*sqrt(3)/(Vdcm*0.612);
% delta = acos(Ef/Vt); % radians
% deltad = delta*180/pi; % degrees
% pf = cos(delta);
% phase = [0 90 0 90];
% Rin = 10;
% %Lin = 1e-3;
% Vin = Vdc + Rin*(Pout/Vdc);
% Cdc = 100e-6;

%%
% IM drive parameter settings
Ts = 1e-6; % sec
Tfinal = 10; % sec
Ripth = 0.08; % sec
fsw = 10e3; % Hz
Tsw = 1/fsw; % sec
Vdc = 750; % Volts
Vllrated = 400;
frated = 50;
Prated = 4e3;
Nrated = 1430;
pole = 4;
wrated = Nrated*2*pi/60;
Trated = Prated/wrated;
Irated = Prated/(Vllrated*sqrt(3)*0.85);
Vrated = Vllrated/sqrt(3);
Vboost = 20; % V
VbyfFreqSteps = 2; % Hz -2
Initial_freq = 5;
VbyfStepTime = 0.2; % s -0.5
start_time = 1;
start_time_deceleration = 10;
Tload = 10;
delta = 0;
%Rin = 10;
%Vin = Vdc + Rin*(Pout/Vdc);
Vin = Vdc;
Rin = 1e-6;
Cdc = 100e-6;

% Adjust these
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
ma = 0.9;

