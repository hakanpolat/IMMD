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
end
qdemand = upsq-ayasli1q-ayasli2q;
pv_s1 = sqrt(qdemand.^2+pv_prod1.^2);
pv_s2 = sqrt(qdemand.^2+pv_prod2.^2);
pv_pf1 = pv_prod1/pv_s1;
pv_pf2 = pv_prod2/pv_s2;
pccp1 = ayasli1p + ayasli2p - pv_prod1;
pccp2 = ayasli1p + ayasli2p - pv_prod2;
pccq = upsq - ayasli2q - ayasli1q;
pqratio1 = abs(pccq)./abs(pccp1);
pqratio2 = abs(pccq)./abs(pccp2);

% Loss calculation
Vline = 400; % V
Vdc = 750; % V
D = Vline/(0.612*Vdc); % modulation depth
fsw = 5e3; % Hz, switching frequency
Vce_p = Vdc; % V, peak voltage
Ploss1 = zeros(1,nn);
Ploss2 = zeros(1,nn);
losten1 = zeros(1,nn);
losten2 = zeros(1,nn);
lost_energy1 = 0;
lost_energy2 = 0;
lost_reactive = 0;
lost_reactive1 = 0;
lost_reactive2 = 0;
lostq = zeros(1,nn);
lostq1 = zeros(1,nn);
lostq2 = zeros(1,nn);



%%
% Case 1: Conventional

lost_energy1 = 0;
lost_energy2 = 0;
lost_reactive = 0;
lost_reactive1 = 0;
lost_reactive2 = 0;

for k = 1:nn
    
    % Operation parameters
    App_power = pv_prod1(k)*1e3; % VA
    Iphase = App_power/(Vline*sqrt(3)); % A
    pf = 1;
    Icp = Iphase*sqrt(2); % A, peak current
    Iep = Iphase*sqrt(2); % A, peak current
    Irr = Iep; % A, peak reverse recovery current
    
    % Datasheet parameters
    Vce_sat = 9.091*1e-3*Icp+1.073; % V, @102 A peak, 125 C
    Eon = (0.05*Icp+1)*1e-3; % J, @600V
    Eon = Eon*Vdc/600; % J, @750V
    Eoff = (0.1*Icp+3)*1e-3; % J, @600V
    Eoff = Eoff*Vdc/600; % J, @750V
    Err = 0.1*Iep*1e-3; % J, @600V
    Err = Err*Vdc/600; % J, @750V
    Vec = 0.01*Iep+1.05; % V
    %trr = 150e-9; % s, @600V
    %trr = trr*Vdc/600; % s, @750V
    
    % Loss calculation
    Psc = Icp*Vce_sat*(1/8+D*pf/(3*pi)); % W
    Pdc = Iep*Vec*(1/8-D*pf/(3*pi)); % W
    Pss = (Eon+Eoff)*fsw*(1/pi); % W
    %Pds = (1/8)*Irr*trr*Vce_p*fsw; % W
    Pds = (Err)*fsw*(1/pi); % W
    Plos = Psc+Pdc+Pss+Pds; % W
    Ploss1(k) = Plos*6+add_loss; % W
    lost_energy1 = lost_energy1+Ploss1(k)/60;
    losten1(k) = lost_energy1;
    
    lost_reactive = lost_reactive + qdemand(k)*1e3/60;
    lostq(k) = lost_reactive;
    
    if pqratio1(k) >= 0.2
        lost_reactive1 = lost_reactive1 + qdemand(k)*1e3/60;
        lostq1(k) = lost_reactive1;
    else
        lostq1(k) = lost_reactive1;
    end
    
end

lost_reactive = 0;
for k = 1:nn
    
    % Operation parameters
    App_power = pv_prod2(k)*1e3; % VA
    Iphase = App_power/(Vline*sqrt(3)); % A
    pf = 1;
    Icp = Iphase*sqrt(2); % A, peak current
    Iep = Iphase*sqrt(2); % A, peak current
    Irr = Iep; % A, peak reverse recovery current
    
    % Datasheet parameters
    Vce_sat = 9.091*1e-3*Icp+1.073; % V, @102 A peak, 125 C
    Eon = (0.05*Icp+1)*1e-3; % J, @600V
    Eon = Eon*Vdc/600; % J, @750V
    Eoff = (0.1*Icp+3)*1e-3; % J, @600V
    Eoff = Eoff*Vdc/600; % J, @750V
    Err = 0.1*Iep*1e-3; % J, @600V
    Err = Err*Vdc/600; % J, @750V
    Vec = 0.01*Iep+1.05; % V
    %trr = 150e-9; % s, @600V
    %trr = trr*Vdc/600; % s, @750V
    
    % Loss calculation
    Psc = Icp*Vce_sat*(1/8+D*pf/(3*pi)); % W
    Pdc = Iep*Vec*(1/8-D*pf/(3*pi)); % W
    Pss = (Eon+Eoff)*fsw*(1/pi); % W
    %Pds = (1/8)*Irr*trr*Vce_p*fsw; % W
    Pds = (Err)*fsw*(1/pi); % W
    Plos = Psc+Pdc+Pss+Pds; % W
    Ploss2(k) = Plos*6; % W
    lost_energy2 = lost_energy2+Ploss2(k)/60;
    losten2(k) = lost_energy2;

    lost_reactive = lost_reactive + qdemand(k)*1e3/60;
    lostq(k) = lost_reactive;
    
    if pqratio2(k) >= 0.2
        lost_reactive2 = lost_reactive2 + qdemand(k)*1e3/60;
        lostq2(k) = lost_reactive2;
    else
        lostq2(k) = lost_reactive2;
    end

end

figure;
plot(minute/60,losten1*1e-3,'b--','LineWidth',2.0);
hold on;
plot(minute/60,Ploss1*5*1e-3,'b-','LineWidth',2.0);
hold on;
plot(minute/60,losten2*1e-3,'k--','LineWidth',2.0);
hold on;
plot(minute/60,Ploss2*5*1e-3,'k-','LineWidth',2.0);
hold on;
plot(minute/60,lostq*1e-5,'r--','LineWidth',2.0);
hold on;
plot(minute/60,lostq1*1e-5,'r-','LineWidth',2.0);
hold on;
plot(minute/60,lostq2*1e-5,'g-','LineWidth',2.0);
hold off;
xlabel('Time (hours)','Fontweight','Bold','Fontsize',14);
ylabel('Power loss, lost energy and reactive power charge','Fontweight','Bold','Fontsize',16);
legend('Energy lost (kWh) - summer','P loss X5 (kW) - summer',...
    'Energy lost (kWh) - winter','P loss X5 (kW) - winter',...
    'Q injection x0.01 (kVArh)',...
    'Q charged x0.01 (kVArh) - summer',...
    'Q charged x0.01 (kVArh) - winter');
grid on;
set(gca,'fontsize',14)
% Penalty
tl_kwh = 0.23;
tl_kVarh = 0.11;
year_p = 1e-3*(losten1(end)*365/2+losten2(end)*365/2); %kWh
year_cost_p = year_p*tl_kwh; % TL
year_q = 1e-3*(lostq1(end)*365/2+lostq2(end)*365/2); %kVARh
year_cost_q = year_q*tl_kVarh; % TL





%%
% Case 2: No size increase


lost_energy1 = 0;
lost_energy2 = 0;
lost_reactive = 0;
lost_reactive1 = 0;
lost_reactive2 = 0;



for k = 1:nn
    
    % Operation parameters
    App_power = pv_s1(k)*1e3; % VA
    if App_power >= 50e3
        %fprintf('Gotcha % g\n',k);
        add_loss = App_power-50e3;
        App_power = 50e3;
    else
        add_loss = 0;
    end
    Iphase = App_power/(Vline*sqrt(3)); % A
    pf = pv_prod1(k)/pv_s1(k);
    Icp = Iphase*sqrt(2); % A, peak current
    Iep = Iphase*sqrt(2); % A, peak current
    Irr = Iep; % A, peak reverse recovery current
    
    % Datasheet parameters
    Vce_sat = 9.091*1e-3*Icp+1.073; % V, @102 A peak, 125 C
    Eon = (0.05*Icp+1)*1e-3; % J, @600V
    Eon = Eon*Vdc/600; % J, @750V
    Eoff = (0.1*Icp+3)*1e-3; % J, @600V
    Eoff = Eoff*Vdc/600; % J, @750V
    Err = 0.1*Iep*1e-3; % J, @600V
    Err = Err*Vdc/600; % J, @750V
    Vec = 0.01*Iep+1.05; % V
    %trr = 150e-9; % s, @600V
    %trr = trr*Vdc/600; % s, @750V
    
    % Loss calculation
    Psc = Icp*Vce_sat*(1/8+D*pf/(3*pi)); % W
    Pdc = Iep*Vec*(1/8-D*pf/(3*pi)); % W
    Pss = (Eon+Eoff)*fsw*(1/pi); % W
    %Pds = (1/8)*Irr*trr*Vce_p*fsw; % W
    Pds = (Err)*fsw*(1/pi); % W
    Plos = Psc+Pdc+Pss+Pds; % W
    Ploss1(k) = Plos*6+add_loss; % W
    lost_energy1 = lost_energy1+Ploss1(k)/60;
    losten1(k) = lost_energy1;
    
%     lost_reactive = lost_reactive + qdemand(k)*1e3/60;
%     lostq(k) = lost_reactive;
%     
%     if pqratio1(k) >= 0.2
%         lost_reactive1 = lost_reactive1 + qdemand(k)*1e3/60;
%         lostq1(k) = lost_reactive1;
%     else
%         lostq1(k) = lost_reactive1;
%     end
    
end

% lost_reactive = 0;
for k = 1:nn
    
    % Operation parameters
    App_power = pv_s2(k)*1e3; % VA
    if App_power >= 50e3
        fprintf('Gotcha % g\n',k);
    end
    Iphase = App_power/(Vline*sqrt(3)); % A
    pf = pv_prod2(k)/pv_s2(k);
    Icp = Iphase*sqrt(2); % A, peak current
    Iep = Iphase*sqrt(2); % A, peak current
    Irr = Iep; % A, peak reverse recovery current
    
    % Datasheet parameters
    Vce_sat = 9.091*1e-3*Icp+1.073; % V, @102 A peak, 125 C
    Eon = (0.05*Icp+1)*1e-3; % J, @600V
    Eon = Eon*Vdc/600; % J, @750V
    Eoff = (0.1*Icp+3)*1e-3; % J, @600V
    Eoff = Eoff*Vdc/600; % J, @750V
    Err = 0.1*Iep*1e-3; % J, @600V
    Err = Err*Vdc/600; % J, @750V
    Vec = 0.01*Iep+1.05; % V
    %trr = 150e-9; % s, @600V
    %trr = trr*Vdc/600; % s, @750V
    
    % Loss calculation
    Psc = Icp*Vce_sat*(1/8+D*pf/(3*pi)); % W
    Pdc = Iep*Vec*(1/8-D*pf/(3*pi)); % W
    Pss = (Eon+Eoff)*fsw*(1/pi); % W
    %Pds = (1/8)*Irr*trr*Vce_p*fsw; % W
    Pds = (Err)*fsw*(1/pi); % W
    Plos = Psc+Pdc+Pss+Pds; % W
    Ploss2(k) = Plos*6; % W
    lost_energy2 = lost_energy2+Ploss2(k)/60;
    losten2(k) = lost_energy2;

%     lost_reactive = lost_reactive + qdemand(k)*1e3/60;
%     lostq(k) = lost_reactive;
%     
%     if pqratio2(k) >= 0.2
%         lost_reactive2 = lost_reactive2 + qdemand(k)*1e3/60;
%         lostq2(k) = lost_reactive2;
%     else
%         lostq2(k) = lost_reactive2;
%     end

end

figure;
plot(minute/60,losten1*1e-3,'b--','LineWidth',2.0);
hold on;
plot(minute/60,Ploss1*5*1e-3,'b-','LineWidth',2.0);
hold on;
plot(minute/60,losten2*1e-3,'k--','LineWidth',2.0);
hold on;
plot(minute/60,Ploss2*5*1e-3,'k-','LineWidth',2.0);
% hold on;
% plot(minute/60,lostq*1e-2,'r--','LineWidth',2.0);
% hold on;
% plot(minute/60,lostq1*1e-2,'r-','LineWidth',2.0);
% hold on;
% plot(minute/60,lostq2*1e-2,'g-','LineWidth',2.0);
hold off;
xlabel('Time (hours)','Fontweight','Bold','Fontsize',14);
legend('Energy lost (Wh) - summer','P loss X10 (W) - summer',...
    'Energy lost (Wh) - winter','P loss X10 (W) - winter',...
    'Q injection x0.01 (VArh)',...
    'Q charged x0.2 (VArh) - summer',...
    'Q charged x0.2 (VArh) - winter');
grid on;
set(gca,'fontsize',14)
% Penalty
tl_kwh = 0.23;
tl_kVarh = 0.11;
year_p = 1e-3*(losten1(end)*365/2+losten2(end)*365/2); %kWh
year_cost_p = year_p*tl_kwh; % TL
year_q = 1e-3*(lostq1(end)*365/2+lostq2(end)*365/2); %kVARh
year_cost_q = year_q*tl_kVarh; % TL







%%
% Case 3: Size increase

% Loss calculation
Vline = 400; % V
Vdc = 750; % V
D = Vline/(0.612*Vdc); % modulation depth
fsw = 5e3; % Hz, switching frequency
Vce_p = Vdc; % V, peak voltage
Ploss1 = zeros(1,nn);
Ploss2 = zeros(1,nn);
losten1 = zeros(1,nn);
losten2 = zeros(1,nn);
lost_energy1 = 0;
lost_energy2 = 0;

for k = 1:nn
    
    % Operation parameters
    App_power = pv_s1(k)*1e3; % VA
    Iphase = App_power/(Vline*sqrt(3)); % A
    pf = pv_prod1(k)/pv_s1(k);
    Icp = Iphase*sqrt(2); % A, peak current
    Iep = Iphase*sqrt(2); % A, peak current
    Irr = Iep; % A, peak reverse recovery current
    
    % Datasheet parameters
    Vce_sat = 6.76*1e-3*Icp+1.08; % V, @102 A peak, 125 C
    Eon = (0.025*Icp+1)*1e-3; % J, @600V
    Eon = Eon*Vdc/600; % J, @750V
    Eoff = (0.13333*Icp+0.66667)*1e-3; % J, @600V
    Eoff = Eoff*Vdc/600; % J, @750V
    Err = (0.1*Iep+1)*1e-3; % J, @600V
    Err = Err*Vdc/600; % J, @750V
    Vec = 0.0125*Iep+0.75; % V
    %trr = 150e-9; % s, @600V
    %trr = trr*Vdc/600; % s, @750V
    
    % Loss calculation
    Psc = Icp*Vce_sat*(1/8+D*pf/(3*pi)); % W
    Pdc = Iep*Vec*(1/8-D*pf/(3*pi)); % W
    Pss = (Eon+Eoff)*fsw*(1/pi); % W
    %Pds = (1/8)*Irr*trr*Vce_p*fsw; % W
    Pds = (Err)*fsw*(1/pi); % W
    Plos = Psc+Pdc+Pss+Pds; % W
    Ploss1(k) = Plos*6+add_loss; % W
    lost_energy1 = lost_energy1+Ploss1(k)/60;
    losten1(k) = lost_energy1;
    
%     lost_reactive = lost_reactive + qdemand(k)*1e3;
%     lostq(k) = lost_reactive;
%     
%     if pqratio1(k) >= 0.2
%         lost_reactive1 = lost_reactive1 + qdemand(k)*1e3;
%         lostq1(k) = lost_reactive1;
%     else
%         lostq1(k) = lost_reactive1;
%     end
    
end

lost_reactive = 0;
for k = 1:nn
    
    % Operation parameters
    App_power = pv_s2(k)*1e3; % VA
    Iphase = App_power/(Vline*sqrt(3)); % A
    pf = pv_prod2(k)/pv_s2(k);
    Icp = Iphase*sqrt(2); % A, peak current
    Iep = Iphase*sqrt(2); % A, peak current
    Irr = Iep; % A, peak reverse recovery current
    
    % Datasheet parameters
    Vce_sat = 6.76*1e-3*Icp+1.08; % V, @102 A peak, 125 C
    Eon = (0.025*Icp+1)*1e-3; % J, @600V
    Eon = Eon*Vdc/600; % J, @750V
    Eoff = (0.13333*Icp+0.66667)*1e-3; % J, @600V
    Eoff = Eoff*Vdc/600; % J, @750V
    Err = (0.1*Iep+1)*1e-3; % J, @600V
    Err = Err*Vdc/600; % J, @750V
    Vec = 0.0125*Iep+0.75; % V
    %trr = 150e-9; % s, @600V
    %trr = trr*Vdc/600; % s, @750V
    
    % Loss calculation
    Psc = Icp*Vce_sat*(1/8+D*pf/(3*pi)); % W
    Pdc = Iep*Vec*(1/8-D*pf/(3*pi)); % W
    Pss = (Eon+Eoff)*fsw*(1/pi); % W
    %Pds = (1/8)*Irr*trr*Vce_p*fsw; % W
    Pds = (Err)*fsw*(1/pi); % W
    Plos = Psc+Pdc+Pss+Pds; % W
    Ploss2(k) = Plos*6; % W
    lost_energy2 = lost_energy2+Ploss2(k)/60;
    losten2(k) = lost_energy2;

%     lost_reactive = lost_reactive + qdemand(k)*1e3;
%     lostq(k) = lost_reactive;
%     
%     if pqratio2(k) >= 0.2
%         lost_reactive2 = lost_reactive2 + qdemand(k)*1e3;
%         lostq2(k) = lost_reactive2;
%     else
%         lostq2(k) = lost_reactive2;
%     end

end

figure;
plot(minute/60,losten1,'b--','LineWidth',2.0);
hold on;
plot(minute/60,Ploss1*5,'b-','LineWidth',2.0);
hold on;
plot(minute/60,losten2,'k--','LineWidth',2.0);
hold on;
plot(minute/60,Ploss2*5,'k-','LineWidth',2.0);
hold off;
xlabel('Time (hours)','Fontweight','Bold');
legend('Energy lost (Wh) - summer','Power loss X10 (W) - summer',...
    'Energy lost (Wh) - winter','Power loss X10 (W) - winter');
grid on;



%%
% Penalty
tl_kwh = 0.23;
tl_kVarh = 0.11;
year_p = 1e-3*(losten1(end)*365/2+losten2(end)*365/2) %kWh
year_cost_p = year_p*tl_kwh % TL
year_q = 1e-3*(lostq1(end)*365/2+lostq2(end)*365/2) %kVARh
year_cost_q = year_q*tl_kVarh % TL


