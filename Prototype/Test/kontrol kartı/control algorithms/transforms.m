
clear all;
close all;
clc;

fsw = 10000; % Hz
Ts = 1/fsw;
ffund = 50;
Tfund = 1/ffund;
vmag = 0.9;
tfinal = 0.1;
t = 0:Ts:tfinal;
num = numel(t);
loopfinal = tfinal/Ts;
volta = vmag*sin(2*pi*ffund*t);
voltb = vmag*sin(2*pi*ffund*t-2*pi/3);
voltc = vmag*sin(2*pi*ffund*t+2*pi/3);
voltalfa = zeros(1,num);
voltbeta = zeros(1,num);
voltzero = zeros(1,num);
voltanew = zeros(1,num);
voltbnew = zeros(1,num);
voltcnew = zeros(1,num);
voltd = zeros(1,num);
voltq = zeros(1,num);
voltalfanew = zeros(1,num);
voltbetanew = zeros(1,num);
theta = t*2*pi/Tfund;

%%

% Clarke
for k = 1:loopfinal
   voltalfa(k) = (2/3)*(volta(k)) - (1/3)*(voltb(k) + voltc(k));
   voltbeta(k) = (1/sqrt(3))*(voltb(k) - voltc(k));
   voltzero(k) = (1/3)*(volta(k) + voltb(k) + voltc(k));
end

figure;
hold all;
plot(t,volta,'r-','Linewidth',1);
plot(t,voltb,'b-','Linewidth',1);
plot(t,voltc,'k-','Linewidth',1);
plot(t,voltalfa,'m*-','Linewidth',1);
plot(t,voltbeta,'g*-','Linewidth',1);
plot(t,voltzero,'c*-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 0.04]);
legend('Phase-A','Phase-B','Phase-C','Valfa','Vbeta','Vzero');

%%

% Inverse Clarke
for k = 1:loopfinal
    voltanew(k) = voltalfa(k);   
    voltbnew(k) = (-voltalfa(k)+sqrt(3)*voltbeta(k))/2;
    voltcnew(k) = (-voltalfa(k)-sqrt(3)*voltbeta(k))/2;
end

figure;
hold all;
plot(t,volta,'r-','Linewidth',1);
plot(t,voltb,'b-','Linewidth',1);
plot(t,voltc,'k-','Linewidth',1);
plot(t,voltanew,'m*-','Linewidth',2);
plot(t,voltbnew,'g*-','Linewidth',2);
plot(t,voltcnew,'c*-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 0.04]);
legend('Phase-A','Phase-B','Phase-C','Phase-Anew','Phase-Bnew','Phase-Cnew');

%%

% Park
for k = 1:loopfinal
    voltd(k) = voltalfa(k)*cos(theta(k)) + voltbeta(k)*sin(theta(k));   
    voltq(k) = voltalfa(k)*sin(theta(k)) - voltbeta(k)*cos(theta(k));   
end

figure;
hold all;
plot(t,volta,'r-','Linewidth',1);
plot(t,voltb,'b-','Linewidth',1);
plot(t,voltc,'k-','Linewidth',1);
plot(t,voltd,'m*-','Linewidth',2);
plot(t,voltq,'g*-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 0.04]);
legend('Phase-A','Phase-B','Phase-C','Vd','Vq');

%%

% Inverse Park
for k = 1:loopfinal
    voltalfanew(k) = voltd(k)*cos(theta(k)) + voltq(k)*sin(theta(k));   
    voltbetanew(k) = -voltq(k)*cos(theta(k)) + voltd(k)*sin(theta(k));   
end

figure;
hold all;
plot(t,voltalfanew,'r-','Linewidth',1);
plot(t,voltbetanew,'b-','Linewidth',1);
plot(t,voltalfa,'k*-','Linewidth',1);
plot(t,voltbeta,'m*-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 0.04]);
legend('AlfaNew','BetaNew','Alfa','Beta');


