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
cur = 0.4685890625;
K = cur * 0.8 * ((25-25+273)/300)^(-2.7);
x0 = 0.31 ;
x1 = 0.255;
slp = 1;
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
        if Vds(i)>0
            I(GateIndex,i) = K*log(1+exp(26*(GS-1.7)/slp))*(DS)/(1+max((x0+x1*(GS+4.1)),2)*DS);
        else
            I(GateIndex,i) = -K*log(1+exp(21*(GD-1.7)/slp))*(-DS)/(1+max((x0+x1*(GD+6.1)),2)*-DS);
        end
    end
end

hold all
for j=[4,5,6,7,8,9]
    plot(Vds, I(j,:),'Linewidth',2.0);
end
xlabel('Vds(V)');
ylabel('Ids(A)');
title('Ids vs Vds curves for different Vgs values for LT Spice equations');
hold off
legend ('Vgs = 0','Vgs = 1','Vgs = 2','Vgs = 3','Vgs = 4','Vgs = 5');