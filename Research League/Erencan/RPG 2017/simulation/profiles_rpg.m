%%
% PV generation profile
clear all;
clc;
hour = 1:24;
n = numel(hour);
minute = 1:n*60;
nn = numel(minute);
pv_prod1 = zeros(1,nn);
pv_prod2 = zeros(1,nn);
ayasli1p = zeros(1,nn);
ayasli2p = zeros(1,nn);
ayasli1q = zeros(1,nn);
ayasli2q = zeros(1,nn);
upsq = zeros(1,nn);
qdemand = zeros(1,nn);
pccp1 = zeros(1,nn);
pccp2 = zeros(1,nn);
pccq = zeros(1,nn);
pv_s1 = zeros(1,nn);
pv_s2 = zeros(1,nn);
pv_pf1 = zeros(1,nn);
pv_pf2 = zeros(1,nn);
pv_peak = 50; % kW
pv_peak_prod1 = 0.9*pv_peak; % kW
pv_peak_prod2 = 0.5*pv_peak; % kW
for k = 1:nn
    kalan = minute(k)/60;
    kalanint = floor(kalan);
    if (kalanint >= 6) && (kalanint < 18)
        pv_prod1(k) = -pv_peak_prod1*cos(2*pi*(1/nn)*minute(k)); % kVA
        pv_prod2(k) = -pv_peak_prod2*cos(2*pi*(1/nn)*minute(k)); % kVA
    end
    ayasli1p(k) = 20; % kW
    ayasli1q(k) = 0; % kVAr
    upsq(k) = 24; % kVAr
    if (kalanint < 7) || (kalanint == 9) ||...
            (kalanint > 10 && kalanint < 13) || ...
            (kalanint > 14 && kalanint < 17) ||...
            (kalanint == 18) || (kalanint > 20)
        ayasli2p(k) = 0;
        ayasli2q(k) = 0;
    else
        ayasli2p(k) = 60*0.98; % kW
        ayasli2q(k) = 60*0.199; % kW
    end
    %houraxis(k) = kalanint;
    qdemand(k) = upsq(k)-ayasli1q(k)-ayasli2q(k);
    pv_s1(k) = sqrt(qdemand(k)^2+pv_prod1(k)^2);
    pv_s2(k) = sqrt(qdemand(k)^2+pv_prod2(k)^2);
    pv_pf1(k) = pv_prod1(k)/pv_s1(k);
    pv_pf2(k) = pv_prod2(k)/pv_s2(k);
    pccp1(k) = ayasli1p(k) + ayasli2p(k) - pv_prod1(k);
    pccp2(k) = ayasli1p(k) + ayasli2p(k) - pv_prod2(k);
    pccq(k) = upsq(k) - ayasli2q(k) - ayasli1q(k);
end

%%
figure;
plot(minute/60,pv_prod1,'b--','LineWidth',2.0);
hold on;
plot(minute/60,pv_prod2,'k-','LineWidth',2.0);
hold on;
plot(minute/60,ayasli2p+ayasli1p,'k--','LineWidth',2.0);
hold on;
plot(minute/60,ayasli2q+ayasli1q,'b-','LineWidth',2.0);
hold on;
plot(minute/60,upsq,'r-','LineWidth',2.0);
hold off;
xlabel('Time (hours)','Fontweight','Bold');
ylabel('PV Generation, Load and UPS','Fontweight','Bold','Fontsize',16);
%title ('Photovoltaic Generation and Load Profile','Fontweight','Bold');
legend('PV Gen (summer) - kW','PV Gen (winter) - kW','Load P - kW','Load Q - kVAr','UPS Q - kVAr');
grid on;
ylim([-1 100]);
set(gca,'fontsize',14)

%%
figure;
plot(minute/60,qdemand,'b-','LineWidth',2.0);
hold on;
plot(minute/60,pv_s1,'r-','LineWidth',2.0);
hold on;
plot(minute/60,pv_s2,'k-','LineWidth',2.0);
hold off;
xlabel('Time (hours)','Fontweight','Bold','Fontsize',16 );
ylabel('Reactive Power Demand and Apparent Powers','Fontweight','Bold','Fontsize',16);
legend('Reactive Power Demand','PV Apparent Power (summer) - kVA','PV Apparent Power (winter) - kVA');
grid on;
ylim([-1 70]);
set(gca,'fontsize',14)

%%
figure;
plot(minute/60,pccp1,'b-','LineWidth',2.0);
hold on;
plot(minute/60,pccp2,'r-','LineWidth',2.0);
hold on;
plot(minute/60,pccq,'k-','LineWidth',2.0);
hold off;
ylabel('PCC Active and Reactive Powers','Fontweight','Bold','Fontsize',16);
xlabel('Time (hours)','Fontweight','Bold','Fontsize',16 );
legend('PCC Active Power (Summer) - kW','PCC Active Power (winter) - kW','PCC Reactive Power - kVAr');
grid on;
set(gca,'fontsize',14)
ylim([-40 140]);

%%
Spcc1 = sqrt(pccp1.^2+pccq.^2);
Spcc2 = sqrt(pccp2.^2+pccq.^2);
pf1 = pccp1./Spcc1;
pf2 = pccp2./Spcc2;

figure;
plot(minute/60,pf1,'b-','LineWidth',2.0);
hold on;
plot(minute/60,pf2,'k-','LineWidth',2.0);
hold off;
xlabel('Time (hours)','Fontweight','Bold','Fontsize',16);
legend('PCC power factor (Summer)','PCC power factor (winter)');
grid on;
set(gca,'fontsize',14)
ylim([-1 1.5]);

%%
pqratio1 = abs(pccq)./abs(pccp1);
pqratio2 = abs(pccq)./abs(pccp2);

figure;
plot(minute/60,pqratio1,'b-','LineWidth',2.0);
hold on;
plot(minute/60,pqratio2,'k-','LineWidth',2.0);
hold off;
xlabel('Time (hours)','Fontweight','Bold');
%legend('PCC power factor (Summer)','PCC power factor (winter)');
grid on;
ylim([0 10]);

