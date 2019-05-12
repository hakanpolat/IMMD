% https://www.electronics-cooling.com/2001/08/simplified-formula-for-estimating-natural-convection-heat-transfer-coefficient-on-a-flat-plate/

%% SIMPLIFIED FORMULA FOR VERTICAL HEAT-SINK
index = [0.012:0.001:0.048]; % m
h_fin = zeros(37,1);
thermal_resistance = zeros(37,1); % C/W
y = 107e-3; % m - Length of fin (avg)
b = 3e-3; % m - Width of fin
A = b*y; % m2
Ploss_single = 4; % W
Num_fin = 12;
T_a = 273 + 25; % 
for i = 1:37
    C = 1.42;
    n = 0.25;
    L = index(i); 
    Surface_area = 2*(y+b)*L + A;
    power = Ploss_single*6/Num_fin;
    %T_s = (power/(C*A))^(1/(n+1)) * L^(n/(n+1))+T_a
    T_s = T_a + 30;
    h_fin(i) = C*((T_s-T_a)/L)^n;
    thermal_resistance(i) = 1/((h_fin(i)*Surface_area)*12);
end

figure;
hold all;
plot(1e2*index,h_fin,'r-','Linewidth',1);
ylabel('Conv','FontSize',14,'FontWeight','Bold')
yyaxis right
plot(1e2*index,thermal_resistance,'b-','Linewidth',1);
ylabel('Rth','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
xlabel('Fin height (cm)','FontSize',14,'FontWeight','Bold')
%xlim([-10 20]);
%legend({'Phase-A','Phase-B','Phase-C'},'Location','northeast');

%%
Ploss_single = 4; % W
b = 8.57E-3; %gap between adjacent plates
L = 5E-3; %m length of plate in vertical flow direction
%L = 107e-3; % m - Length of base (avg)
T_a = 273+25;%temperature of ambient air
C = 1.32;
n = 0.25;
A = 0.0105; % m^2 base area
%T_s = (Ploss_single*6/(C*A))^(1/(n+1)) * L^(n/(n+1)) + T_a
T_s = T_a + 20;
h_simple = C*((T_s-T_a)/L)^n
Rth = 1/(h_simple*A)

%%
Rth_juction_case = 0.5; % C/W
Rth_pcb = 3.39; % C/W
thermal_cond_tim = 5; % W/mK
area_tim = 15e-3*15e-3; % m^2
length_tim = 2e-3; % m
Rth_tim = length_tim/(thermal_cond_tim*area_tim); % C/W
Rth_path = Rth_tim + Rth_juction_case + Rth_pcb; % C/W
Ploss_single = 1:0.1:10; % W
Ploss_total = Ploss_single*6; % W
Tambient = 25; % C
Tjunction = 105; % C
Rth_heat_sink = (Tjunction - Tambient - Ploss_single*Rth_path)./(6*Ploss_single);
figure
hold all;
plot(Ploss_single,Rth_heat_sink,'b-','Linewidth',2);
set(gca,'FontSize',14);
xlabel('Single device loss (W)','FontSize',14,'FontWeight','Bold')
ylabel('Required R_{th-hs} (C/W)','FontSize',14,'FontWeight','Bold')

