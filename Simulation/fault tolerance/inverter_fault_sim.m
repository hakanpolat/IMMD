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
wm = Nr*pi/30;
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
Focw = 1;
Fscw = 0;
Roc = 1e4;

%%
sim('inverter_fault_sim.slx');


%%
% Short circuit limiting trial
Ts = 1e-6; % s
Tfinal = 0.2; % s
Tfault = 0; % s
Ripth = 0.15; % s
fsw = 10e3; % Hz
Vdc = 540; % Volts
Pout = 7e3/0.96; % W
Ls = 3e-3; % Henries
%Rs = 0.277; % Ohms
Rs = 0.277e-6; % Ohms
Nr = 600; %rpm
wm = Nr*pi/30;
p = 10;
Tm = 127; % Nm
fout = Nr*p/60;
wout = 2*pi*fout; % rad/sec
m = 3;
np = 1;
ns = 1;
n = ns*np;
Poutm = Pout/n; % Watts
Xs = wout*Ls; % Ohms
Vdcm = Vdc/ns; % volts

scale = 1;
scale2 = 1;
%shift = 30*pi/180;
shift = 0;

Efnom = 160; % Volts
Isnom = Poutm/(Ef*m); % Amps
Iam = Isnom*scale;
Ibm = Isnom*scale;
Icm = Isnom*scale2;
Iap = 0-shift;
Ibp = -2*pi/3+shift;
Icp = 2*pi/3;
Eam = Efnom;
Ebm = Efnom;
Ecm = Efnom;
Eap = 0;
Ebp = -120*pi/180;
Ecp = -240*pi/180;
Ia = Iam*cos(Iap) + 1i*Iam*sin(Iap);
Ib = Ibm*cos(Ibp) + 1i*Ibm*sin(Ibp);
Ic = Icm*cos(Icp) + 1i*Icm*sin(Icp);
Efa = Eam*cos(Eap) + 1i*Eam*sin(Eap);
Efb = Ebm*cos(Ebp) + 1i*Ebm*sin(Ebp);
Efc = Ecm*cos(Ecp) + 1i*Ecm*sin(Ecp);
Vdropa = Ia*1i*Xs;
Vdropb = Ib*1i*Xs;
Vdropc = Ic*1i*Xs;
Vta = Efa + Vdropa;
Vtam = abs(Vta);
Vtap = angle(Vta);
deltada = Vtap*180/pi;
Vtb = Efb + Vdropb;
Vtbm = abs(Vtb);
Vtbp = angle(Vtb);
deltadb = Vtbp*180/pi;
Vtc = Efc + Vdropc;
Vtcm = abs(Vtc);
Vtcp = angle(Vtc);
deltadc = Vtcp*180/pi;
maa = Vtam*sqrt(3)/(Vdcm*0.612);
mab = Vtbm*sqrt(3)/(Vdcm*0.612);
mac = Vtcm*sqrt(3)/(Vdcm*0.612);

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
Focw = 1;
Fscw = 0;
Roc = 1e4;

%%
Vtab = Vta-Vtb;
Vtbc = Vtb-Vtc;
Vtca = Vtc-Vta;
Vtabm = abs(Vtab)
Vtbcm = abs(Vtbc)
Vtcam = abs(Vtca)
Vtabp = angle(Vtab)*180/pi
Vtbcp = angle(Vtbc)*180/pi
Vtcap = angle(Vtca)*180/pi



