%% Simulation base for RPG
Ts = 1e-5;

% Grid
Vphase = 400/sqrt(3); % V
Vline = 34.5e3; % V
fs = 50; % Hz

% Transformer
Vpri = 34.5e3; % V
Vsec = 400; % V
Sbase = 1.6e6; % VA
ftr = 50; % Hz
Rpri_pu = 0.0025; % pu
Rsec_pu = 0.0025; % pu
Lpri_pu = 0.025;
Lsec_pu = 0.025;

% Cable
%Zbase = Vsec^2/Sbase;
%Rcable = Zbase*0.01; % Ohms
%Xcable = Zbase*0.1; % Ohms
Rcable = 56.4e-3; % Ohms
Xcable = 22.5e-3; % Omhs
Lcable = Xcable/(2*pi*fs); % H

% Load-1 (Ayaslý)
Pload1 = 20e3; % W
Qload1 = 0e3; % VAr
Sload1 = sqrt(Pload1^2+Qload1^2); % VA
pfload1 = Pload1/Sload1;
Zload1 = Vphase^2/(Sload1/3); % Ohm
Rload1 = Zload1*pfload1; % Ohm
Xload1 = sqrt(Zload1^2-Rload1^2); % Ohm
Lload1 = Xload1/(2*pi*fs); % H

% Load-2 (Temiz alan)
Sload2_1 = 100e3; % VA
Sload2_2 = 20e3; % VA
pfload2 = 0.98;
Pload2_1 = Sload2_1*pfload2; % W
Pload2_2 = Sload2_2*pfload2; % W
Qload2_1 = sqrt(Sload2_1^2-Pload2_1^2); % VAr
Qload2_2 = sqrt(Sload2_2^2-Pload2_2^2); % VAr
Zload2_1 = Vphase^2/(Sload2_1/3); % Ohm
Rload2_1 = Zload2_1*pfload2; % Ohm
Lload2_1 = sqrt(Zload2_1^2-Rload2_1^2)/(2*pi*fs); % H
Zload2_2 = Vphase^2/(Sload2_2/3); % Ohm
Rload2_2 = Zload2_2*pfload2; % Ohm
Lload2_2 = sqrt(Zload2_2^2-Rload2_2^2)/(2*pi*fs); % H

% UPS-1
Qups1 = 6e3; % VAr

% UPS-2
Qups2 = 18e3; % VAr

% RPCU
%Qrpcu = 200e3; % VAr
rpcu_capacity = 120e3; % VAr
Qrpcu_each = rpcu_capacity/(3*12);
Zrpcu_each = Vphase^2/(Qrpcu_each);
Crpcu_each = 1/(2*pi*fs*Zrpcu_each);
% USER SELECTED
rpc_demand = 0e3; % VAr

rpcu_s = zeros(1,12);
scales = 0:10e3:11*10e3;
rpcu_s(:) = (rpc_demand>scales(:));

% Inverter
Vdc = 750; % V
fsw = 5e3; % Hz
Ls = 1e-3; % H
RLs = 10e-3; % Ohms
Xs = Ls*2*pi*fs; % Ohms
Ppv = 50e3; % W
Qpv = 5e3; % VAr
Spv = sqrt(Ppv^2+Qpv^2); % VA
pf = Ppv/Spv;
Idpv = Ppv/(3*Vphase);
Iqpv = Qpv/(3*Vphase);
Vc_mag = sqrt((Vphase-Iqpv*Xs)^2+(Idpv*Xs)^2);
ma = 2*sqrt(2)*Vc_mag/Vdc;
delta = atan((Idpv*Xs)/(Vphase-Iqpv*Xs));
delta_degree = delta*180/pi;

sim('simulation_base.slx');

%%
timeaxis = timeout;
Pload1_sim = activepowers(:,1);
Pload2_sim = activepowers(:,2);
Pline_sim = activepowers(:,4);
Qload1_sim = reactivepowers(:,1);
Qload2_sim = reactivepowers(:,2);
Qline_sim = reactivepowers(:,4);
V1_sim = voltages(:,1);
Vpcc_sim = voltages(:,2);
pfload1_sim = abs(powerfactors(:,1));
pfload2_sim = abs(powerfactors(:,2));
pfline_sim = abs(powerfactors(:,3));

%%
figure;
plot(timeaxis,Pload1_sim,'k-','LineWidth',2.0);
hold on;
plot(timeaxis,Pload2_sim,'b-','LineWidth',2.0);
hold on;
plot(timeaxis,Pline_sim,'r-','LineWidth',2.0);
hold off;
xlabel('Time (s)','Fontweight','Bold');
ylabel('Active Powers (kW)','Fontweight','Bold');
%title ('Photovoltaic Generation Profile','Fontweight','Bold');
grid on;
legend('Load-1','Load-2','Line');

%%
figure;
plot(timeaxis,Qload1_sim,'k-','LineWidth',2.0);
hold on;
plot(timeaxis,Qload2_sim,'b-','LineWidth',2.0);
hold on;
plot(timeaxis,Qline_sim,'r-','LineWidth',2.0);
hold off;
xlabel('Time (s)','Fontweight','Bold');
ylabel('Reactive Powers (kW)','Fontweight','Bold');
%title ('Photovoltaic Generation Profile','Fontweight','Bold');
grid on;
legend('Load-1','Load-2','Line');

%%
figure;
plot(timeaxis,V1_sim,'k-','LineWidth',2.0);
hold on;
plot(timeaxis,Vpcc_sim,'b-','LineWidth',2.0);
hold off;
xlabel('Time (s)','Fontweight','Bold');
ylabel('Voltages (V)','Fontweight','Bold');
%title ('Photovoltaic Generation Profile','Fontweight','Bold');
grid on;
ylim([200 250]);
legend('Load','PCC');

%%
figure;
plot(timeaxis,pfload1_sim,'k-','LineWidth',2.0);
hold on;
plot(timeaxis,pfload2_sim,'r-','LineWidth',2.0);
hold on;
plot(timeaxis,pfline_sim,'b-','LineWidth',2.0);
hold off;
xlabel('Time (s)','Fontweight','Bold');
ylabel('Power factors','Fontweight','Bold');
%title ('Photovoltaic Generation Profile','Fontweight','Bold');
grid on;
ylim([-0.1 1.1]);
legend('Load-1','Load-2','Line');


%%
% PV generation profile

hour = 1:24;
n = numel(hour);
pv_prod = zeros(1,numel(hour));
pv_peak = 0.7; % pu
pv_prod(6:18) = -pv_peak*cos(2*pi*(1/24)*hour(6:18));
figure;
plot(hour,pv_prod,'k-','LineWidth',2.0);
xlabel('Time (hours)','Fontweight','Bold');
ylabel('PV Generation (pu)','Fontweight','Bold');
title ('Photovoltaic Generation Profile','Fontweight','Bold');
grid on;
pv_prod';


%% OBSOLETE
% modulation index
ma = 0.66;
% switching frequency
fsw = 1e3; % Hz
% DC link voltage
Vdc = 700; % Volts
% DC Link capacitor
Cdc = 1e-3; % Farads
ESR = 1e-3; % Ohms
% Load
Sout = 20e3; % VA
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
Vll_rms = 400; % Volts
Iline = Sout/(Vll_rms*sqrt(3)); % Amps
pf = 0.8;
Zload = Vll_rms/(Iline*sqrt(3)); % Ohms
Rload = Zload*pf; % Ohms
Xload = sqrt(Zload^2-Rload^2); % Ohms
Lload = Xload/wout; % Henries

%%
% Solar panel side
Vdc = 750; % V
Rseries = 5; % Ohm
Pout = 50e3; % W
Rrefl = Vdc^2/Pout;
V1 = Vdc*(Rseries+Rrefl)/Rrefl; % V
Cdc = 5e-3; % F
ESR = 1e-3; % Ohms

%%
% PV trial
Vs = 400; % V
fs = 50; % Hz
Vdc = 750; % V
Ls = 1e-3; % H
fsw = 2e3; % Hz
Xs = 2*pi*fs*Ls; % Ohms
Ppv = 40e3; % W
Qpv = 30e3; % VAr
Spv = sqrt(Ppv^2+Qpv^2); % VA
Idpv = Ppv/(Vs);
Iqpv = Qpv/(Vs);
Vc_mag = sqrt((Vs-Iqpv*Xs)^2+(Xs*Idpv)^2); % V
ma = Vc_mag*sqrt(2)/Vdc
delta = atan(Idpv*Xs/(Vs-Iqpv*Xs))*180/pi

%delta = 5
%ma = 0.75

sim('pv_trial.slx')

