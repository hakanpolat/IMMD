L_fin = [0.012:0.001:0.060]; % m
%L_fin = 0.024; % m
num = numel(L_fin);
h_base = zeros(1,num);
h_fin = zeros(1,num);
Rth_base = zeros(1,num); % C/W
Rth_fin = zeros(1,num); % C/W
Rth_hs = zeros(1,num); % C/W

y = 107e-3; % m - Length of fin (avg)
bfin = 3e-3; % m - Width of fin
A = bfin*y; % m2
Ploss_single = 4; % W
Num_fin = 12;
T_a = 25; % C 
C_fin = 1.42;
n = 0.25;
A_fin = 2*(y+bfin)*L_fin + A;
%A_fin2 = y*L_fin*2 + y*bfin + bfin*L_fin*2
power = Ploss_single*6/Num_fin;
T_s = T_a + 60;
h_fin = C_fin*((T_s-T_a)./L_fin).^n
Rth_fin = 1./(h_fin.*A_fin*Num_fin)

bbase = 8.57e-3; %gap between adjacent plates
L_base = 7E-3; %m length of plate in vertical flow direction
C_base = 0.59;
n = 0.25;
A_base = 0.0105; % m^2 base area
h_base = C_base*((T_s-T_a)./L_base)^n
Rth_base = 1./(h_base.*A_base)

Rth_hs = (Rth_base*Rth_fin)./(Rth_base+Rth_fin)

%%
figure;
hold all;
yyaxis left
plot(L_fin*1e2,h_fin,'r-','Linewidth',2);
%plot(L_fin*1e2,h_base,'m--','Linewidth',2);
ylabel('Convection coefficienct (W/m^2.^\circC)','FontSize',14,'FontWeight','Bold')
yyaxis right
plot(L_fin*1e2,Rth_fin,'b+-','Linewidth',2);
%plot(L_fin*1e2,Rth_base,'g-','Linewidth',2);
plot(L_fin*1e2,Rth_hs,'k--','Linewidth',2);
ylabel('Thermal Resistance (^\circC/W)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
xlabel('Fin Height (cm)','FontSize',14,'FontWeight','Bold')
legend('h_{fin}','R_{th-fin}','R_{th-hs}');


%%
figure;
hold all;
yyaxis left
plot(L_fin*1e2,h_fin,'r-','Linewidth',2);
plot(L_fin*1e2,h_base,'m--','Linewidth',2);
ylabel('Convection Coefficient','FontSize',14,'FontWeight','Bold')
yyaxis right
plot(L_fin*1e2,Rth_fin,'b-','Linewidth',2);
%plot(L_fin*1e2,Rth_base,'g-','Linewidth',2);
%plot(L_fin*1e2,Rth_hs,'k--','Linewidth',2);
ylabel('Thermal Resistance (C/W)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
xlabel('fin height (cm)','FontSize',14,'FontWeight','Bold')
legend('h_{fin}','h_{base}','R_{th-fin}','R_{th-base}','R_{th-Total}');


%%
Rth_juction_case = 0.5; % C/W
Rth_pcb = 3.39; % C/W
thermal_cond_tim = 5; % W/mK
area_tim = 17e-3*14e-3; % m^2
length_tim = 2e-3; % m
Rth_tim = length_tim/(thermal_cond_tim*area_tim); % C/W
Rth_path = Rth_tim + Rth_juction_case + Rth_pcb; % C/W
Ploss_single = 2:0.1:8; % W
%Ploss_single = 4;
Ploss_total = Ploss_single*6; % W
Tambient = 40; % C
Tjunction = 140; % C
Rth_heat_sink = (Tjunction - Tambient - Ploss_single*Rth_path)./(6*Ploss_single)

figure
hold all;
plot(Ploss_single,Rth_heat_sink,'b-','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Single device loss (W)','FontSize',14,'FontWeight','Bold')
ylabel('Required R_{th-hs} (C/W)','FontSize',14,'FontWeight','Bold')

