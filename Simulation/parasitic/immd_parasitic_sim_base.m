Ts = 1e-6; % sec
Tfinal = 0.15; % sec
Ripth = 0.1; % sec
fsw = 10e3; % Hz
Vmodule = 270; % V
Pmodule = 2e3/0.94;
m = 3;
np = 1;
ns = 1;
n = ns*np;
Pout = Pmodule*n; % W
Vdc = Vmodule*ns; % Volts
Ef = 85*ns; % Volts
Ls = 3.5e-3/n; % Henries
Rs = 1e-3/n; % Ohms
fout = 50; % Hz
wout = 2*pi*fout; % rad/sec
Is = Pmodule/(Ef*m); % amps
Xs = wout*Ls; % Ohms
Vdrop = Is*Xs; % Volts
Vt = sqrt(Ef^2+Vdrop^2); % Volts
ma = Vt*sqrt(3)/(Vmodule*0.612);
delta = acos(Ef/Vt); % radians
deltad = delta*180/pi; % degrees
pf = cos(delta);
phase = [0 90 0 90];

% Input is current
Rin = 10;
Vin = Vdc + Rin*(Pout/Vdc);
%Cdc = 40e-6;

Vmaxs = Vmodule/2;
Vmins = Vmodule*2;

Idcrms1 = np*Is*sqrt( 2*ma*(sqrt(3)/(4*pi) +...
    pf^2*(sqrt(3)/pi-9*ma/16)) ) % Amps

Vdcrip = 1;
intv = 1;
Cdcreq1 = intv*np*ns*(ma*Is/(16*fsw*Vdcrip))*...
    sqrt( (6 - (96*sqrt(3)*ma)/(5*pi) +...
    (9*ma^2/2) )*pf^2 + (8*sqrt(3)*ma)/(5*pi) ); % Farads

Cdc = Cdcreq1;
Cdc = round(Cdc*1e6)/1e6


%%
deltav = 0.1:0.1:10;
Cdc = 1e6*ma*0.9575*Is./(16*fsw*deltav);

figure;
plot(deltav,Cdc,'b-','Linewidth',2);
grid on;
set(gca,'FontSize',12);


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

xlim([0.1 0.11])
% ylim([500 600])
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

