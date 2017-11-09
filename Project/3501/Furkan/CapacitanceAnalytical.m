clear all;
%#codegen
Vds = 0:1:500;
Vds = abs(Vds);
%% Crss calculation
a1 = 1493;
b1 = -73.75;
c1 = 40.99;
a2 = 19.18;
b2 = 23.83;
c2 = 16.09;
a3 = 5.192e14;
b3 = 5.273e4;
c3 = 9064;
Crss = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2) + a3*exp(-((Vds-b3)./c3).^2);
Crss = Crss
%% Ciss Calculation
a = 31.75;
b = -0.09029;
c = 267.6;
d = -2.621e-5;
Ciss = a*exp(b*Vds) + c*exp(d.*Vds);
Ciss = Ciss
%% Coss Calculation
p1 = 7.622e-19;
p2 = -1.86e-15;
p3 = 1.918e-12;
p4 = -1.0846e-9;
p5 = 3.653e-7;
p6 = -7.428e-5;
p7 = 0.008737;
p8 = -0.5159;
p9 = 7.595;
p10 = 481.3;
Coss = p1*Vds.^9 + p2*Vds.^8 + p3*Vds.^7 + p4*Vds.^6 + p5*Vds.^5 + p6*Vds.^4 + ...
    p7*Vds.^3 + p8*Vds.^2 + p9*Vds + p10;
Coss = Coss
%% Outputs
Cgs = Ciss - Crss;
Cds = Coss - Crss;
Cgd = Crss;
%% Plots
hold on 
plot(Vds,Cgs);
plot(Vds,Cgd);
plot(Vds,Cds);
