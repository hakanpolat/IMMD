%% Functions
function [Ich,Cgd,Cgs,Cds] = NumericCalc(x5,x4,x3) %Vgin,Vdin,Vsin
Vgs = x5-x4;
Vds = x4-x3;
Vgd = x5-x4;
cur = 4.5057; % To be updated
K = cur * 0.8 * (273/300)^(-2.7);
x0 = 0.31 ;
x1 = 0.255;
slp = 2;
if Vds>0
            Ich = K*log(1+exp(26*(Vgs-1.7)/slp))*(Vds)/(1+max((x0+x1*(Vgs+4.1)),0.2)*Vds);
else
            Ich = -K*log(1+exp(26*(Vgd-1.7)/slp))*(-Vds)/(1+max((x0+x1*(Vgd+6.1)),0.2)*(Vds));
end

Vds = abs(Vds);
%% Crss calculation
       a1 =   2.519e+14;
       b1 =      -345.7;
       c1 =       63.76;
       a2 =       27.99;
       b2 =       12.86;
       c2 =       18.29;
       a3 =       8.666;
       b3 =       33.93;
       c3 =       9.161;
       a4 =       1.502;
       b4 =       125.5;
       c4 =       121.9;
       a5 =      0.6563;
       b5 =         500;
       c5 =       34.57;
       a6 =        1.98;
       b6 =       408.2;
       c6 =       134.7;
Crss = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2) + a3*exp(-((Vds-b3)./c3).^2)...
   + a4.*exp(-((Vds-b4)./c4).^2) +a5.*exp(-((Vds-b5)./c5).^2) +a6.*exp(-((Vds-b6)./c6).^2);
Crss = Crss*1e-12;
%% Ciss Calculation
%        a1 =        1167;
%        b1 =      -115.8;
%        c1 =       60.96;
%        a2 =       269.7;
%        b2 =       -5402;
%        c2 =   4.243e+04;
%        a3 =        3.61;
%        b3 =       238.5;
%        c3 =       2.507;
%        a4 =       1.036;
%        b4 =       175.8;
%        c4 =       16.81;
%        a5 =       1.571;
%        b5 =         263;
%        c5 =       3.586;
%        a6 =      -1.174;
%        b6 =       238.2;
%        c6 =       25.85;
       a1 =        267.6;
       b1 =      2.007;
       c1 =       0.4734;
       a2 =       240.1;
       b2 =       3.049;
       c2 =      1.104;
       a3 =        -1336;
       b3 =       7.803;
       c3 =       9.331;
       a4 =       -250.6;
       b4 =       7.082;
       c4 =       1.715;
       a5 =       -2352;
       b5 =         11.25;
       c5 =       3.184;
       a6 =      8.572e13;
       b6 =       340.6;
       c6 =       67.72;
Ciss = a1.*exp(-((Vgs-b1)./c1).^2) + a2.*exp(-((Vgs-b2)./c2).^2) + a3*exp(-((Vgs-b3)./c3).^2)...
   + a4.*exp(-((Vgs-b4)./c4).^2) +a5.*exp(-((Vgs-b5)./c5).^2) +a6.*exp(-((Vgs-b6)./c6).^2);
Ciss = Ciss*1e-12;
%% Coss Calculation
       a1 =         328;
       b1 =       -8.43;
       c1 =       30.26;
       a2 =       115.8;
       b2 =        42.2;
       c2 =       7.341;
       a3 =       45.83;
       b3 =       59.01;
       c3 =       6.099;
       a4 =       183.1;
       b4 =        28.6;
       c4 =       16.39;
       a5 =       69.29;
       b5 =       154.4;
       c5 =        1511;
       a6 =       125.6;
       b6 =       22.68;
       c6 =       119.6;
Coss = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2) + a3*exp(-((Vds-b3)./c3).^2)...
   + a4.*exp(-((Vds-b4)./c4).^2) +a5.*exp(-((Vds-b5)./c5).^2) +a6.*exp(-((Vds-b6)./c6).^2);
Coss = Coss*1e-12;
%% Outputs
Cgs = Ciss - Crss;
Cds = Coss - Crss;
Cgd = Crss;

end