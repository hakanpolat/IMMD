close all
clear all
clc
Vgs = -3:1:6;
Vds = -7:0.001:5;
% K1 = 0.283;
% b1 = 2.035;
% c1 = 0.124;
% d1 = 1.159;
% e1 = -0.204;
% m1 = 30.972;
% n1 = -4.48;
% K2 = 7.114;
% b2 = 2.054;
% c2 = 0.153;
% cur = 4.5057;
% K = cur * 0.8 * (273/300)^(-2.7);
% x0 = 0.31 ;
% x1 = 0.255;
% slp = 2;
% Rd = 3.6*0.95*0.82*18.2*0.25/295;
% Rs = 3.6*0.238*0.82/295;
Vth = 1.7;
%% Reverse Model
cur = 4.5057;
K = cur * 0.8 * (273/300)^(-2.7);
x0 = 0.31 ;
x1 = 0.255;
slp = 2;
%% Forward Model
m1 = 11.5;
m2 = 0.21/2;
m3 = -3e-4;
m4 = (1e-5+1e-4)/2;
m5 = m1;
m6 = m2;
m7 = m3;
m8 = m4;
m9 = 1.45;
m10 = 0.8;
m11 = 12;
m12 = 1;
m13 = 0.3;
m14 = -5.5;
m15 = 5.5;
m16 = 0.105;
m17 = 1;
m18 = 1;
beta = 5.5;
lambda = 9e-5;


for GateIndex = 1:10
    for i=1:((12/0.001)+1)
        GS = Vgs(GateIndex);
        DS = Vds(i);
        GD = GS - DS;
%         if Vds(i)>0
%             I(GateIndex,i) = K1*log(1+exp((GS-b1)/c1))*(m1+n1*GS)*DS/(1+(d1+e1*GS)*DS);
%         else
%             I(GateIndex,i) = -K2*log(1+exp((GD-b2)/c2))*(-DS/(1-DS));
%         end
        if DS>0
            f1 = (1+m1*GS+m2*GS^2+m3*GS^3+m4*GS^4)/(1+m5*GS+m6*GS^2+m7*GS^3+m8*GS^4);
            f2 = m9*max(m10-m11*exp(-m12*GS),0);
            f3 = 1 - m13*exp(-(DS-m14)^2/(2*m15^2));
            f4 = m16*((-atan(m17*(GS-DS))+pi/2)/(pi)) + m18;
            if DS<(GS-Vth) && GS>=Vth %Ohmic Region
                I(GateIndex,i) = beta*DS*(2*(GS-Vth)-DS)*(1+lambda*DS)*f1*f2*f3*f4;
            elseif DS>=(GS-Vth) && GS >= Vth %Saturation
                I(GateIndex,i) = beta*(GS-Vth)^2*(1+lambda*DS)*f1*f2*f3*f4;
            elseif GS<Vth %CutOff
                I(GateIndex,i) = 0;
            end
        else
            I(GateIndex,i) = -K*log(1+exp(21*(GD-1.7)/slp))*(-DS)/(1+max((x0+x1*(GD+6.1)),0.2)*(-DS));
        end  
    end
end

hold all

for j=[1,2,3,4,5,6,7,8,9]
    plot((Vds), I(j,:),'Linewidth',2.0);
end
plot(4.3,60,'*');
xlabel('Vds(V)');
ylabel('Ids(A)');
title('Ids vs Vds curves for different Vgs values for LT Spice equations');
legend ('Vgs = -3','Vgs = -2','Vgs = -1','Vgs = 0','Vgs = 1','Vgs = 2','Vgs = 3','Vgs = 4','Vgs = 5');