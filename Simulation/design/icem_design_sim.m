% Design and Simulation with IGBT

Ts = 1e-6; % sec
Tfinal = 0.1; % sec
Ripth = 0.08; % sec
fsw = 10e3; % Hz
Vdc = 540; % Volts
Pout = 8e3/0.94; % W
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


Idcrms1 = Is*sqrt( 2*ma*(sqrt(3)/(4*pi) +...
    pf^2*(sqrt(3)/pi-9*ma/16)) ); % Amps

Vdcrip = 1;
Cdcreq1 = ns*(ma*Is/(16*fsw*Vdcrip))*...
    sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
    (9*ma^2/2) )*pf^2 + (8*sqrt(3)*ma)/(5*pi) ); % Farads


%%
% Design and Simulation with GaN

Ts = 1e-6; % sec
Tfinal = 0.2; % sec
Ripth = 0.05; % sec
fsw = 1e3; % Hz
Vdc = 540; % Volts
Pout = 8e3/0.94; % W
m = 3;
np = 2;
ns = 2;
n = ns*np;
Ef = 155/ns; % Volts
Ls = 13.8e-3/n; % Henries
Rs = 1e-3/n; % Ohms
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
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

Idcrms1 = np*Is*sqrt( 2*ma*(sqrt(3)/(4*pi) +...
    pf^2*(sqrt(3)/pi-9*ma/16)) ); % Amps

Vdcrip = 1;
intv = 0.48;
Cdcreq1 = intv*np*ns*(ma*Is/(16*fsw*Vdcrip))*...
    sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
    (9*ma^2/2) )*pf^2 + (8*sqrt(3)*ma)/(5*pi) ); % Farads

Cdc = Cdcreq1;
Cdc = round(Cdc*1e5)/1e5;

%%
% Selected GaNs
% Transphorm: TPH3205WSB, 35A, 650V, 60 mOhm, Cascode
% GaN Systems: GS66508B, 30A, 650V, 50 mOhm, E-mode

%%
% 1st device
% TPH3205WSB
% Loss analysis
clear Psc;
clear Pdc;
clear Pds;
clear Pss;

fsw = 0;
while(fsw<100e3)
    fsw = fsw+10e3
    %fsw = 100e3; % Hz
    Icp = Iphase*sqrt(2);
    Iep = Iphase*sqrt(2);
    
    Vceo = 0; % V
    Ro = 93.8*1e-3; % Ohms
    Vdo = 0.6; % V
    Rd = (8-5.4)/(88-60); % Ohms
    Vnom = 400; % V
    Inom = 22; % A
    Eon = 1/6*(Inom*Vnom*(36+7.6)*1e-9); % J
    Eoff = 1/6*(Inom*Vnom*(40+8.6)*1e-9); % J
    Err = 1/6*(Inom*Vnom*(40)*1e-9); % J
    
    % Loss calculation
    Psc = Vceo*Icp/(2*pi) + Ro*Icp^2/8 + ma*pf*Vceo*Icp/8 + ma*pf*Ro*Icp^2/(3*pi); % W
    Pdc = Vdo*Iep/(2*pi) + Rd*Iep^2/8 - ma*pf*Vdo*Iep/8 - ma*pf*Rd*Iep^2/(3*pi); % W
    Pss = (Eon+Eoff)*fsw*Vdcm*Icp/(pi*Vnom*Inom); % W
    Pds = Err*fsw*Vdcm*Icp/(pi*Vnom*Inom) % W
    
    Ploss1 = Psc+Pdc+Pss+Pds; % W
    Ploss = Ploss1*6; % W
    efficiency = 100*Pdrout/(Ploss+Pdrout); % percent

end


%% Plots from simulations

figure;
plot(timearray,Vdctot,'b-','Linewidth',2);
hold on;
plot(timearray,Vdcmod1*2,'r-','Linewidth',2);
hold on;
plot(timearray,Vdcmod2*2,'k-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('DC Link Voltage (Volts)','FontSize',12,'FontWeight','Bold')
legend('Total DC link voltage','DC link voltage of module-1',...
    'DC link voltage of module-2');

%xlim([0.03 0.04])
ylim([500 600])
% xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
% ylabel('DC link voltage (V)','FontSize',12,'FontWeight','Bold')
% legend('without interleaving','with interleaving');


%%
figure;
plot(timearray,Vdcmod1,'b-','Linewidth',2);
hold on;
plot(timearray,Vdcmod2,'r-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
legend('DC link voltage of module-1','DC link voltage of module-2',...
    'FontSize',14,'FontWeight','Bold');

xlim([0.0448 0.045]);
ylim([268 273]);


%%

figure;
plot(timearray,Vdctotalwithoutint,'b-','Linewidth',2);
hold on;
plot(timearray,Vdctotalwithint,'r-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
legend('Without interleaving','With interleaving','FontSize',14,'FontWeight','Bold');

xlim([0.049 0.0492]);
ylim([536 546]);


%%

figure;
plot(timearray,Idctotalwithoutint,'b-','Linewidth',2);
hold on;
plot(timearray,Idctotalwithint,'r-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link Current (Amps)','FontSize',14,'FontWeight','Bold')
legend('Without interleaving','With interleaving','FontSize',14,'FontWeight','Bold');

xlim([0.049 0.0491]);
ylim([-2 40]);


%%
timearray = timeaxis;
Idcmod1 = Idcmodule1;
Idcmod2 = Idcmodule2;
figure;
plot(timearray,Idcmod1,'r-','Linewidth',2);
hold on;
plot(timearray,Idcmod2,'b-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link Current (Amps)','FontSize',14,'FontWeight','Bold')
legend('DC link current of module-1',...
    'DC link current of module-2','FontSize',14,'FontWeight','Bold');

xlim([0.049 0.0491]);
ylim([-2 20]);


%%

figure;
plot(timearray,Vlineab,'b-','Linewidth',2);
grid on;
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('Line-to-line voltage (Volts)','FontSize',14,'FontWeight','Bold')

xlim([0.036 0.06]);
%ylim([536 546]);

%%

figure;
plot(timearray,Ilinea,'r-','Linewidth',2);
grid on;
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('Line current (Amps)','FontSize',14,'FontWeight','Bold')

xlim([0.036 0.06]);
%ylim([536 546]);
%%

figure;
plot(timearray,Vdctotalwithoutint,'b-','Linewidth',2);
hold on;
plot(timearray,Vdctotalwithint,'r-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('DC Link Voltage (Volts)','FontSize',14,'FontWeight','Bold')
legend('Without interleaving','With interleaving','FontSize',14,'FontWeight','Bold');

xlim([0.049 0.0492]);
ylim([536 546]);

%% Data storage
Idctotalwithint = Idctot;
Vdctotalwithint = Vdctot;
Idcmodule1 = Idcmod1;
Idcmodule2 = Idcmod2;
Vdcmodule1 = Vdcmod1;
Vdcmodule2 = Vdcmod2;
Vlinetoline = Vlineab;
Ilinecurrent = Ilinea;
timeaxis = timearray;
save('icemdata.mat','Idctotalwithint','Vdctotalwithint','Idcmodule1',...
    'Idcmodule2','Vdcmodule1','Vdcmodule2','Vlinetoline','Ilinecurrent',...
    'timeaxis');


%%
Idctotalwithoutint = Idctot;
Vdctotalwithoutint = Vdctot;
save('icemdata.mat','Idctotalwithoutint',...
    'Vdctotalwithoutint','-append');

