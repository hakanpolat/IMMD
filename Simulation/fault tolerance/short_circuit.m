% Calculation of short circuit current and/or required inductance

Ephm = 81; % Vrms (phase voltage)
Nr = 600; % rpm
p = 20;
fs = Nr*p/120; % Hz
Rs = 0.277; % Ohms
La = 0.78e-3; % H (IMMD)
Llk = 2.87e-3; % H (IMMD)
Ls = La + Llk; % H (IMMD)
Xs = 2*pi*fs*Ls; % Ohms
Zsc = sqrt(Rs^2+Xs^2); % Ohms
Isc = Ephm/Zsc;

Iphm = 8.5; % Arms
Iscreq = Iphm; % Arms
Zscreq = Ephm/Iscreq; % Ohms
Xscreq = sqrt(Zscreq^2-Rs^2); % Ohms
Lscreq = Xscreq/(2*pi*fs); % H

Vtm = sqrt(Ephm^2+(Xs*Iphm)^2)
pf = Ephm/Vtm;
delta = 180/pi*acos(pf);
Vtm2 = sqrt(Ephm^2+(Xscreq*Iphm)^2)
pf2 = Ephm/Vtm2;
delta2 = 180/pi*acos(pf2);

%%
% analysis of SC current with speed
Ls = 3.66e-3; % H
R = 300e-3; % Ohms
Nr = 0:600; % rpm
wr = Nr*2*pi/60; % rad/sec
p = 20;
fs = p*Nr/120; % Hz
Efn = 80; % V
Nrn = 600; % rpm
Efw = Efn/Nrn; % V/rpm
Ef = Efw*Nr; % V
Zsc = sqrt(R^2+(2*pi*fs*Ls).^2);
Isc = Ef./Zsc;


figure;
plot(Nr,Isc,'b-','Linewidth',2.5);
hold on;
plot(Nr,Ef,'r-','Linewidth',2.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Motor speed (rpm)','FontSize',12,'FontWeight','Bold');
%ylabel('Motor speed (rpm)','FontSize',12,'FontWeight','Bold');
legend('Short circuit current','Induced voltage');


%%
% Some torque calculation
Qs = 24;
p = 20;
Bgp = 0.9; % T
Ip = 8*sqrt(2); % A
Dis = 180; % mm
La = 135; % mm
Ag = (pi*Dis)*La/p*1e-6; % m^2 - air gap area
nl = 2; % layer
nc = 40; % turns per coil
Kw = 0.933; % winding factor
cosphi = 0.972; % power factor

T = (1/4*pi)*Kw*nl*nc*Qs*Bgp*Ip*Ag*cosphi

