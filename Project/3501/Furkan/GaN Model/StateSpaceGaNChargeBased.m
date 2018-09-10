%% State Space Model of GaN
clear all;
close all;
%% GaN Parameters
Rgin = 1.5;
Lgin = 1e-9;
Rss = 1e-3;
Lss = 1e-9;
Ls = 0.9e-9;
Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0135*(25 - 25))) / 295;
Ld = 0.9e-9;
Rd = (3.6/8) * (0.95*0.82*(1 - (-0.0135*(25 - 25))) * 18.2 / 295);

%% Simulation Parameters
TimeStep = 5e-13; %Time Steps
StopTime = 600e-9; %Stop Time
% Allocation
t = (0 : TimeStep : StopTime);
x1 = zeros(size(t)); %Ids
x2 = zeros(size(t)); %Vd
x3 = zeros(size(t)); %Vdin
x4 = zeros(size(t)); %Vsin
x5 = zeros(size(t)); %Vgin
x6 = zeros(size(t)); %Vss
x7 = zeros(size(t)); %Ig
x8 = zeros(size(t)); %Ich
x9 = zeros(size(t)); %Cgd
x10 = zeros(size(t));%Cgs
x11 = zeros(size(t));%Cds
x12 = zeros(size(t));%Qgd
x13 = zeros(size(t));%Qgs
x14 = zeros(size(t));%Qds
u1 = zeros(size(t)); %Vgss

%% Input Definition
u1(t>=50e-9) = 6;
x2(t>=0e-9) = 2;
u1(t>=200e-9) = -3;
% x2(t>=200e-9) = 0;
x3 = x2;
[x8(1),x9(1),x10(1),x11(1)] = NumericCalc(x5(1),x3(1));
x12(1) = x9(1) * (x5(1) - x3(1));
x13(1) = x10(1) * x5(1);
x14(1) = x11(1) * x3(1);
[m,n] = size(t);
% Dx10 = 0; Dx11 = 0;
% x9(2) = x9(1);
% x10(2) = x10(1);
% x11(2) = x11(1);
for k = 2:n-1
    
    VgsTemp = x13(k-1)/x10(k-1);
    VdsTemp = x14(k-1)/x11(k-1);
    [x8(k), x9(k), x10(k), x11(k)] = NumericCalc(VgsTemp,VdsTemp);
%     x9(k) = 2e-12;
%     x10(k) = 258e-12;
%     x11(k) = 63e-12;
    Dx1 = TimeStep * ((x2(k-1) - x1(k-1)*(Rs+Rd) - x14(k-1)/x11(k))/(Ls + Ld));
    Dx7 = TimeStep * ((u1(k) - x13(k-1)/x10(k))/(Lgin + Lss) - (Rgin + Rss)/(Lgin + Lss)*x7(k-1));
    Dx12 = TimeStep * ((x7(k-1)/x10(k) - x1(k-1)/x11(k) + x8(k)/x11(k)) / (1/x10(k) + 1/x9(k) + 1/x11(k)));
    Dx13 = TimeStep * (x7(k-1) - (x7(k-1)/x10(k) + x8(k)/x11(k) - x1(k-1)/x11(k))/(1/x11(k) + 1/x10(k) + 1/x9(k)) );
%     Dx14 = TimeStep * (x1(k-1) - x8(k) + (x7(k-1)/x10(k) - x1(k-1)/x11(k))/(1/x10(k) + 1/x9(k) + 1/x11(k)));
%     Dx14 = TimeStep * ((x11(k)*x7(k-1)/x10(k)) - (x11(k)*Dx12/TimeStep/x10(k)) - (x11(k)*(x7(k-1)/x10(k) + x8(k)/x11(k) - x1(k-1)/x11(k))/(1/x11(k) + 1/x10(k) + 1/x9(k))/x9(k)));
%   [Dx9,Dx10,Dx11] = CapacitanceDerivative(x10(k-1),Dx10,x11(k-1),Dx11,x13(k-1),Dx13/TimeStep,x14(k-1),Dx14/TimeStep);
    
    x1(k) = x1(k-1) + Dx1;
    x7(k) = x7(k-1) + Dx7;
%     x9(k) = x9(k-1) + Dx9;
%     x10(k) = x10(k-1) + Dx10;
%     x11(k) = x11(k-1) + Dx11;
    x12(k) = x12(k-1) + Dx12;
    x13(k) = x13(k-1) + Dx13;
%     x14(k) = x14(k-1) + Dx14;
    x14(k) = x11(k) * (x13(k)/x10(k) - x12(k)/x9(k));
    
end




figure;
hold all
grid on
plot(t,x1,t,x2,t,u1,'Linewidth',2.0);
%xlim([0]);
ylim([-110 450]);
xlabel('Time');
ylabel('Voltage,Ampere');
title({'Ids, Vds, Vgs OUT'})
legend ('Ids','Vds','Vgs','Location','best');
hold off

figure;
hold all
grid on
plot(t,x8,t,x14./x11,t,x13./x10,'Linewidth',2.0);
%xlim([0]);
ylim([-110 450]);
xlabel('Time');
ylabel('Voltage,Ampere');
title({'Ich, Vds, Vgs IN'})
legend ('Ich','Vds','Vgs','Location','best');
hold off


figure;
hold all
grid on
plot(t,x9,t,x10,t,x11,'Linewidth',2.0);
%xlim([0]);
ylim([-2e-9 2e-9]);
xlabel('Time');
ylabel('Capacitance');
title({'Cgd, Cgs, Cds IN'})
legend ('Cgd','Cgs','Cds','Location','best');
hold off

figure;
hold all
grid on
plot(t,x12,t,x13,t,x14,'Linewidth',2.0);
%xlim([0]);
ylim([-1e-9 20e-9]);
xlabel('Time');
ylabel('Charge');
title({'Qgd, Qgs, Qds IN'})
legend ('Qgd','Qgs','Qds','Location','best');
hold off

figure;
hold all
grid on
plot(t,x12./x9,t,x13./x10,t,x14./x11,t,x7,'Linewidth',2.0);
%xlim([0]);
ylim([-20 20]);
xlabel('Time');
ylabel('Voltages');
title({'Vgd, Vgs, Vds IN'})
legend ('Vgd','Vgs','Vds','Ig','Location','best');
hold off

