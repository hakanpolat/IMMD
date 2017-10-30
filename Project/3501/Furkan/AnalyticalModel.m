close all
clear all
clc
Vgs = -3:1:6;
Vds = -7:0.001:50;
K1 = 0.283;
b1 = 2.035;
c1 = 0.124;
d1 = 1.159;
e1 = -0.204;
m1 = 30.972;
n1 = -4.48;
K2 = 7.114;
b2 = 2.054;
c2 = 0.153;
for GateIndex = 1:10
    for i=1:((57/0.001)+1)
        GS = Vgs(GateIndex);
        DS = Vds(i);
        GD = GS - DS;
        if Vds(i)>0
            I(GateIndex,i) = K1*log(1+exp((GS-b1)/c1))*(m1+n1*GS)*DS/(1+(d1+e1*GS)*DS);
        else
            I(GateIndex,i) = -K2*log(1+exp((GD-b2)/c2))*(-DS/(1-DS));
        end
    end
end

hold all
for j=[1,2,6,9]
    plot(Vds, I(j,:),'Linewidth',2.0);
end
xlabel('Vds(V)');
ylabel('Ids(A)');
title('Ids vs Vds curves for different Vgs values');
hold off
legend ('Vgs = -3','Vgs = -2','Vgs = 2','Vgs = 5');