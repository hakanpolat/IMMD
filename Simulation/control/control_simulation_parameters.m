% Control simulation Parameters

global pole_pair;
pole_pair = 10;
Ts = 500e-9; % sec
Tfinal = 0.1; % sec
Ripth = 0.08; % sec
fsw = 10e3; % Hz
Tsw = 1/fsw; % sec
Vdc = 300; % Volts
Pout = 2e3; % W
Ef = 155; % Volts
Ls = 13.8e-3; % Henries
Rs = 1e-3; % Ohms
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 1;
n = ns*np;
Poutm = Pout/n; % Watts
Is = Poutm/(Ef*m); % amps
Xs = wout*Ls; % Ohms
Vdrop = Is*Xs; % Volts
Vt = sqrt(Ef^2+Vdrop^2); % Volts
Vdcm = Vdc/ns; % volts
ma = Vt*sqrt(3)/(Vdcm*0.612);
delta = acos(Ef/Vt); % radians
deltad = delta*180/pi; % degrees
pf = cos(delta);
phase = [0 90 0 90];
Rin = 10;
%Lin = 1e-3;
Vin = Vdc + Rin*(Pout/Vdc);
Cdc = 100e-6;

motor_speed = 600; % rpm

%%
% Control algorithm model
Kp = 100;
Ki = 100;
Ymax = 300;
Ymin = -300;
