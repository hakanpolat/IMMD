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
Vdc = 100; % Volts
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 2;
n = ns*np;
phase = [0 90 0 90];
Cdc = 15e-6;
delta = 0; % deg

Lload_1A = 36e-3; % Henries
Lload_1B = 34e-3; % Henries
Lload_1C = 36e-3; % Henries
Rload_1A = 15.26; % Ohms
Rload_1B = 15.31; % Ohms
Rload_1C = 15.26; % Ohms

Lload_2A = 26e-3; % Henries
Lload_2B = 26e-3; % Henries
Lload_2C = 26e-3; % Henries
Rload_2A = 14.02; % Ohms
Rload_2B = 14.03; % Ohms
Rload_2C = 14.00; % Ohms

X1A = 2*pi*fout*Lload_1A; % Ohm
X1B = 2*pi*fout*Lload_1B; % Ohm
X1C = 2*pi*fout*Lload_1C; % Ohm
X2A = 2*pi*fout*Lload_2A; % Ohm
X2B = 2*pi*fout*Lload_2B; % Ohm
X2C = 2*pi*fout*Lload_2C; % Ohm

Z1A = sqrt(Rload_1A^2+X1A^2); % Ohm
Z1B = sqrt(Rload_1B^2+X1B^2); % Ohm
Z1C = sqrt(Rload_1C^2+X1C^2); % Ohm
Z2A = sqrt(Rload_2A^2+X2A^2); % Ohm
Z2B = sqrt(Rload_2B^2+X2B^2); % Ohm
Z2C = sqrt(Rload_2C^2+X2C^2); % Ohm

pf1A = Rload_1A/Z1A;
pf1B = Rload_1B/Z1B;
pf1C = Rload_1C/Z1C;
pf2A = Rload_2A/Z2A;
pf2B = Rload_2B/Z2B;
pf2C = Rload_2C/Z2C;

% Calculate ma's
ma1 = 0.9;
ma2 = 0.9;
%ratioma = sqrt(Rload1/Rload2)*(pf2/pf1);
%ma2 = 0.9;
%ma1 = ma2*ratioma;

ratio_R = mean([Rload_2A,Rload_2B,Rload_2C])/mean([Rload_1A,Rload_1B,Rload_1C]);
ratio_pf = mean([pf1A,pf1B,pf1C])^2/mean([pf2A,pf2B,pf2C])^2;
ratio_ma = (ma1/ma2)^2;
ratio = ratio_ma*ratio_pf*ratio_R;
Vdc1 = Vdc/(ratio+1);
Vdc2 = Vdc-Vdc1;
V1 = 0.612*ma1*Vdc1/sqrt(3);
I1 = V1/mean([Z1A,Z1B,Z1C]);
S1 = 3*V1*I1;
P1 = S1*pf1;
V2 = 0.612*ma2*Vdc2/sqrt(3);
I2 = V2/mean([Z2A,Z2B,Z2C]);
S2 = 3*V2*I2;
P2 = S2*pf2;

Pout = P1 + P2;
Rin = 70;
Vin = Vdc + Rin*(Pout/Vdc)+3;
