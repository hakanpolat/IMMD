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

%% Simulation Parameters
TimeStep = 1e-11; %Time Steps
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
u1 = zeros(size(t)); %Vg
u2 = zeros(size(t)); %dVg/dt

%% Input Definition
u1(t>=50e-9) = 6; 
u2 = diff(u1)/TimeStep;
x2(t>=0) = 1;
x3 = x2;

[m,n] = size(t);
for k=2:n-1
    
    if k ~= 0
        [x8(k),x9(k),x10(k),x11(k)] = NumericCalc(x5(k-1),x4(k-1),x3(k-1));
    else 
        [x8(k),x9(k),x10(k),x11(k)] = NumericCalc(x5(k),x4(k),x3(k));
    end
    u1(k) = x6(k-1) + u1(k);
    Dx1 = TimeStep * (x2(k-1)/Ld - x3(k-1)/Ld - Rd*x1(k-1)/Ld);
    Dx4 = TimeStep * (x1(k-1)*Rs + x2(k-1)*Ls/Ld - x3(k-1)*Ls/Ld - Ls*Rd*x1(k-1)/Ld);
    
    CoeffA = 1/(x10(k)^2*(x9(k)+x11(k)) + x11(k)^2*(x9(k)+x10(k)) + 2*x9(k)*x10(k)*x11(k));
    CoeffB = (Dx4/TimeStep*(x10(k) + x11(k)) - x7(k-1))*(x9(k)*x10(k) + x11(k)*x10(k)  +x9(k)*x11(k) );
   
    Dx3 = TimeStep * (1/CoeffA * (x10(k)*(x1(k-1) - x8(k))*(x10(k) + x11(k)) + x7(k-1)*x10(k)*x11(k) + CoeffB));
    Dx5 = TimeStep * (1/CoeffA * (x11(k)*(x8(k) - x1(k-1))*(x10(k) + x11(k)) - x7(k-1)*x11(k)^2 + CoeffB));
    Dx6 = TimeStep * (-Lss/Lgin*u2(k) + Lss/Lgin * Dx5/TimeStep + (Rgin*Lss/Lgin - Rss)*(u1(k)/Lgin - x5(k-1)/Lgin - x7(k-1)*Rgin/Lgin) + Dx4/TimeStep);
    Dx7 = TimeStep * (-x6(k-1)/Lss + x4(k-1)/Lss - x7(k-1)*Rss/Lss);
   
    x1(k) = x1(k-1) + Dx1;
    x3(k) = x3(k-1) + Dx3;
    x4(k) = x4(k-1) + Dx4;
    x5(k) = x5(k-1) + Dx5;
    x6(k) = x6(k-1) + Dx6;
    x7(k) = x7(k-1) + Dx7;
end

figure;
hold all
grid on
plot(t,x1,t,x2,t,u1-x6,'Linewidth',2.0);
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
plot(t,x8,t,x3-x4,t,x5-x4,'Linewidth',2.0);
%xlim([0]);
ylim([-110 110]);
xlabel('Time');
ylabel('Voltage,Ampere');
title({'Ids, Vds, Vgs IN'})
legend ('Ids','Vds','Vgs','Location','best');
hold off




