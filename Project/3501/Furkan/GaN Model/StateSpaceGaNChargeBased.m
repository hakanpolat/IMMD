%% State Space Model of GaN
clear all;
%% GaN Parameters
Rgin = 1.5;
Lgin = 1e-9;
Rss = 1e-3;
Lss = 1e-9;
Ls = 0.9e-9;
Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0135*(25 - 25))) / 295;
Ld = 0.9e-9;
Rd = (3.6/8) * (0.95*0.82*(1 - (-0.0135*(25 - 25))) * 18.2 / 295);
Cgs = 100e-9;
Cds = 100e-9;

%% Simulation Parameters
TimeStep = 1e-12; %Time Steps
StopTime = 200e-9; %Stop Time
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
x2(t>=0) = 1;
x3 = x2;
x10(1) = Cgs;
x11(1) = Cds;
[m,n] = size(t);
for k=2:n-1
    
    if k ~= 0
        [x8(k),x9(k),x10(k),x11(k)] = NumericCalc(x13(k)/x10(k-1),x14(k)/x11(k-1));
    else 
        [x8(k),x9(k),x10(k),x11(k)] = NumericCalc(x13(k)/x10(k-1),x14(k)/x11(k-1));
    end

end

Dx1 = TimeStep * ((x2(k-1) - x1(k-1)*(Rs+Rd) - x14(k-1)/x11(k))/(Ls + Ld));
Dx7 = TimeStep * ((u1(k) - x13(k-1)/x10(k))/(Lgin + Lss) - (Rgin + Rss)/(Lgin + Lss)*x7(k-1));
Dx12 = TimeStep * ((x7(k-1)/x10(k) - x1(k-1)/x11(k) + x8(k)/x11(k)) / (1/x10(k) + 1/x9(k) + 1/x11(k)));
Dx13 = TimeStep * (x7(k-1) + (x1(k-1)/x11(k) - x7(k-1)/x10(k) - x8(k)/x11(k) ) / (1/x10(k) + 1/x9(k) + 1/x11(k)));
Dx14 = TimeStep * (x1(k-1) - x8(k) + (x7(k-1)/x10(k) - x1(k-1)/x11(k))/(1/x10(k) + 1/x9(k) + 1/x11(k)));

x1(k) = x1(k-1) + Dx1;
x7(k) = x7(k-1) + Dx7;
x12(k) = x12(k-1) + Dx12;
x13(k) = x13(k-1) + Dx13;
x14(k) = x14(k-1) + Dx14;



figure;
hold all
grid on
plot(t,x1,t,x2,t,u1,'Linewidth',2.0);
%xlim([0]);
ylim([-110 110]);
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
ylim([-110 110]);
xlabel('Time');
ylabel('Voltage,Ampere');
title({'Ids, Vds, Vgs IN'})
legend ('Ids','Vds','Vgs','Location','best');
hold off




