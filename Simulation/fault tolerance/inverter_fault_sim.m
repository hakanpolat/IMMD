% Design and Simulation with IGBT

Ts = 1e-6; % s
Tfinal = 0.2; % s
Tfault = 0.1; % s
Ripth = 0.15; % s
fsw = 10e3; % Hz
Vdc = 540; % Volts
Pout = 8e3/0.96; % W
Ef = 160; % Volts
Ls = 3e-3; % Henries
%Rs = 0.277; % Ohms
Rs = 0.277e-6; % Ohms
Nr = 600; %rpm
p = 10;
Tm = 127; % Nm
fout = Nr*p/60;
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
Vin = Vdc + Rin*(Pout/Vdc);
Cdc = 200e-6;
So = Pout/pf; % VA
Vcon = Ef*sqrt(2)*sqrt(3)/Nr*1000;
Jm = 0.003; % kgm^2
Fs = 0.0005; % Nms
Foct = 0;
Fsct = 0;
Focw = 0;
Fscw = 0;

%%
sim('inverter_fault_sim.slx');


