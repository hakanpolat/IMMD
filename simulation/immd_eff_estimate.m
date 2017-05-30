%%
% Suppose an IGBT is selected
% Infineon SKB15N60HS IGBT + Diode, 600V, 27A
% http://www.infineon.com/cms/en/product/power/igbt/igbt-discrete/discrete-igbt-with-anti-parallel-diode/SKB15N60HS/productType.html?productType=ff80808112ab681d0112ab6e35f41850

clear Psc;
clear Pdc;
clear Pds;
clear Pss;
fsw = 1e3:1e3:20e3; % Hz
for k = 1:numel(fsw)
    % Datasheet values
    Vce_sat = 2.3; % V, @ A peak
    Eon = 0.45e-3; % J, @ 400V
    Eon = Eon*Vdc_module/400; % J, @270V
    Eoff = 0.275e-3; % J, @400V
    Eoff = Eoff*Vdc_module/400; % J, @270V
    % Err = 8e-3; % J, @400V
    % Err = Err*Vdc_module/600; % J, @270V
    Vec = 1.25; % V
    trr = 184e-9; % s, @400V
    trr = trr*Vdc_module/400; % s, @270V
    Irr = 18; % A, @400V
    Irr = Irr*Vdc_module/400; % A, @270V
    
    % Loss calculation
    Psc(k) = Icp*Vce_sat*(1/8+ma*pf/(3*pi)); % W
    Pdc(k) = Iep*Vec*(1/8-ma*pf/(3*pi)); % W
    Pss(k) = (Eon+Eoff)*fsw(k)*(1/pi); % W
    Pds(k) = (1/8)*Irr*trr*Vce_p*fsw(k); % W
    %Pds = (Err)*fsw*(1/pi); % W
    Ploss1 = Psc(k)+Pdc(k)+Pss(k)+Pds(k); % W
    Ploss = Ploss1*6; % W
    efficiency1(k) = 100*Pout_inv_module/(Ploss+Pout_inv_module); % percent
    fprintf('Efficiency value with GaN with %gkHz is %g %%\n',fsw(k),efficiency1(k));
end

figure;
plot(fsw*1e-3,Psc,'bo-','Linewidth',1.5);
hold on;
plot(fsw*1e-3,Pss,'ro-','Linewidth',1.5);
hold on;
plot(fsw*1e-3,Pdc,'ko-','Linewidth',1.5);
hold on;
plot(fsw*1e-3,Pds,'mo-','Linewidth',1.5);
hold on;
grid on;
set(gca,'FontSize',12);
xlabel('switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
%ylabel('DC Link RMS Current (A)','FontSize',12,'FontWeight','Bold')

figure;
plot(fsw*1e-3,efficiency1,'bo-','Linewidth',1.5);
grid on;
set(gca,'FontSize',12);
xlabel('switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
%ylabel('DC Link RMS Current (A)','FontSize',12,'FontWeight','Bold')

%%
% Suppose a GaN is selected
% Transphorm TPH3212PS GaN FET, 650V, 26.5A
% http://www.transphormusa.com/product/tph3212ps/
clear Psc;
clear Pdc;
clear Pds;
clear Pss;
%fsw = 10e3:1e3:100e3; % Hz
fsw = 40e3;
%for k = 1:numel(fsw)
% Datasheet values
Rds_onB = 72e-3; % Ohms, @25C, @17A, @8V Vgs
Tj = 125; % C
Rds_on = Rds_onB*(Tj/125+0.8); % Ohms
% It is assumed that, Rds_on is not affected by current amplitude up to 80A
% This assumption is based on datasheet graph (Ids vs Vds)
VsdB = 0.5; % V
Vsd = Iep*0.09163+VsdB; % V
% The following time values should be normalized
tdon = 24e-9; % s,VDS=400V, ID = 18A, 25C
tdoff = 55.5e-9; % s,VDS=400V, ID = 18A, 25C
tr = 7.5e-9; % s,VDS=400V, ID = 18A, 25C
tf = 5e-9; % s,VDS=400V, ID = 18A, 25C
trr = 35e-9; % s,VDS=400V, ID = 18A, 1000A/ms, 25C
ton = tdon+tr; % s
toff = tdoff+tf; % s
Eon = Vdc_module*Icp*ton/6; % J
Eoff = Vdc_module*Icp*toff/6; % J
% Irr value was not present in the datasheet. Peak value is taken
Irr = Iep; % A

% Loss calculation
Psc(k) = Rds_on*Icp^2*(1/8+ma*pf/(3*pi)); % W
Pdc(k) = Iep*Vsd*(1/8-ma*pf/(3*pi)); % W
Pss(k) = (Eon+Eoff)*fsw(k)*(1/pi); % W
Pds(k) = (1/8)*Irr*trr*Vce_p*fsw(k); % W

Ploss1 = Psc(k)+Pdc(k)+Pss(k)+Pds(k); % W
Ploss = Ploss1*6; % W
efficiency2(k) = 100*Pout_inv_module./(Ploss+Pout_inv_module); % percent
fprintf('Efficiency value with GaN with %gkHz is %g %%\n',fsw(k),efficiency2(k));
%end

% figure;
% plot(fsw*1e-3,Psc,'bo-','Linewidth',1.5);
% hold on;
% plot(fsw*1e-3,Pss,'ro-','Linewidth',1.5);
% hold on;
% plot(fsw*1e-3,Pdc,'ko-','Linewidth',1.5);
% hold on;
% plot(fsw*1e-3,Pds,'mo-','Linewidth',1.5);
% hold on;
% grid on;
% set(gca,'FontSize',12);
% xlabel('switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
% %ylabel('DC Link RMS Current (A)','FontSize',12,'FontWeight','Bold')
% 
% figure;
% plot(fsw*1e-3,efficiency2,'bo-','Linewidth',1.5);
% grid on;
% set(gca,'FontSize',12);
% xlabel('switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
% %ylabel('DC Link RMS Current (A)','FontSize',12,'FontWeight','Bold')
