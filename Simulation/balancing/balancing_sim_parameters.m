% Induced Voltage
Ts = 1e-6; % sec
Tfinal = 0.1; % sec
Ripth = 0.08; % sec
fsw = 10e3; % Hz
Vdc = 540; % Volts
Pout = 4e3/0.94; % W
Ef = 80; % Volts
Ls = 3.5e-3; % Henries
Rs = 1e-3; % Ohms
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 2;
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
Rin = 70;
Vin = Vdc + Rin*(Pout/Vdc);
Cdc = 100e-6;


%% RL Load
Ts = 1e-6; % sec
Tfinal = 0.1; % sec
Ripth = 0.08; % sec
fsw = 10e3; % Hz
Vdc = 540; % Volts
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 2;
n = ns*np;
phase = [0 90 0 90];
Cdc = 100e-6;
delta = 0; % deg

Lload1 = 20e-3; % Henries
Rload1 = 10; % Ohms
Lload2 = 30e-3; % Henries
Rload2 = 10; % Ohms
X1 = 2*pi*fout*Lload1; % Ohm
X2 = 2*pi*fout*Lload2; % Ohm
Z1 = sqrt(Rload1^2+X1^2); % Ohm
Z2 = sqrt(Rload2^2+X2^2); % Ohm
pf1 = Rload1/Z1;
pf2 = Rload2/Z2;

% Calculate ma's
%ma1 = 0.9;
%ma2 = 0.9;

ratioma = sqrt(Rload1/Rload2)*(pf2/pf1);
ma2 = 0.9;
ma1 = ma2*ratioma;

ratio_R = Rload2/Rload1;
ratio_pf = (pf1/pf2)^2;
ratio_ma = (ma1/ma2)^2;
ratio = ratio_ma*ratio_pf*ratio_R;
Vdc1 = Vdc/(ratio+1);
Vdc2 = Vdc-Vdc1;
V1 = 0.612*ma1*Vdc1/sqrt(3);
I1 = V1/Z1;
S1 = 3*V1*I1;
P1 = S1*pf1;
V2 = 0.612*ma2*Vdc2/sqrt(3);
I2 = V2/Z2;
S2 = 3*V2*I2;
P2 = S2*pf2;

Pout = P1 + P2;
Rin = 70;
Vin = Vdc + Rin*(Pout/Vdc);
