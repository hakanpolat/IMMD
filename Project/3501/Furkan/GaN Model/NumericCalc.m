%% Functions
function [Ich,Cgd,Cgs,Cds] = NumericCalc(Vgs,Vds) %Vgin,Vdin,Vsin
% Vgs = x5-x4;
% Vds = x4-x3;
% Vgd = x5-x4;
Vgd = Vgs - Vds;
cur = 4.5057; % To be updated
K = cur * 0.8 * (273/300)^(-2.7);
x0 = 0.31 ;
x1 = 0.255;
slp = 2;
if Vds>=0
            Ich = K*log(1+exp(26*(Vgs-1.7)/slp))*(Vds)/(1+max((x0+x1*(Vgs+4.1)),0.2)*Vds);
else
            Ich = -K*log(1+exp(26*(Vgd-1.7)/slp))*(-Vds)/(1+max((x0+x1*(Vgd+6.1)),0.2)*(-Vds));
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
% if Vds <= 48.88
%        a1 =   7.326e+14;
%        b1 =      -285.3;
%        c1 =       51.06;
%        a2 =       -81.13;
%        b2 =       10.82;
%        c2 =       17.02;
%        a3 =       113;
%        b3 =       9.47;
%        c3 =       20.77;
%        Crss = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2) + a3*exp(-((Vds-b3)./c3).^2);
% else
%        a1 =   114.5;
%        b1 =      -54.95;
%        c1 =       44.09;
%        a2 =       1.647;
%        b2 =       496.9;
%        c2 =       3.006e7;
%        a3 =       -13.84;
%        b3 =       359.4;
%        c3 =       156.4;
%        
%        a5 =      13.9;
%        b5 =      364.4;
%        c5 =      153.7;
% Crss = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2) + a3*exp(-((Vds-b3)./c3).^2)...
%     +a5.*exp(-((Vds-b5)./c5).^2);
% end
% if Crss<1
%     Crss = 1;
% end
Crss = Crss*1e-12;
%% Ciss Calculation
%        a1 =        230.4;
%        b1 =      1.899;
%        c1 =       0.3985;
%        a2 =       223.4;
%        b2 =       2.729;
%        c2 =      0.9208;
%        a3 =       219.6;
%        b3 =       4.408;
%        c3 =       10.35;
%        a4 =       206.1;
%        b4 =       4.207;
%        c4 =       1.794;
%        a5 =       166;
%        b5 =       -12.04;
%        c5 =       10.33;
%        a6 =      -134.9;
%        b6 =      8.683;
%        c6 =      1.862;
%        a7 =      434.9;
%        b7 =      8.993;
%        c7 =      3.737;
% Ciss = a1.*exp(-((Vgs-b1)./c1).^2) + a2.*exp(-((Vgs-b2)./c2).^2) + a3*exp(-((Vgs-b3)./c3).^2)...
%    + a4.*exp(-((Vgs-b4)./c4).^2) +a5.*exp(-((Vgs-b5)./c5).^2) +a6.*exp(-((Vgs-b6)./c6).^2)+a7.*exp(-((Vgs-b7)./c7).^2);
if Vgs <= 2.16
       a1 =      404.1;
       b1 =      2.013;
       c1 =      0.5109;
       a2 =      6.187e16;
       b2 =      3116;
       c2 =      540.5;
       Ciss = a1.*exp(-((Vgs-b1)./c1).^2) + a2.*exp(-((Vgs-b2)./c2).^2);
else
       a1 =      281.4;
       b1 =      -3.004;
       c1 =      6.079;
       a2 =      524.1;
       b2 =      -2593;
       c2 =      8843;
       Ciss = a1.*exp(-((Vgs-b1)./c1).^2) + a2.*exp(-((Vgs-b2)./c2).^2);
end
if Ciss<180
    Ciss = 180;
end
Ciss = Ciss*1e-12;

%% Coss Calculation
%        a1 =         328;
%        b1 =       -8.43;
%        c1 =       30.26;
%        a2 =       115.8;
%        b2 =        42.2;
%        c2 =       7.341;
%        a3 =       45.83;
%        b3 =       59.01;
%        c3 =       6.099;
%        a4 =       183.1;
%        b4 =        28.6;
%        c4 =       16.39;
%        a5 =       69.29;
%        b5 =       154.4;
%        c5 =        1511;
%        a6 =       125.6;
%        b6 =       22.68;
%        c6 =       119.6;
% Coss = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2) + a3*exp(-((Vds-b3)./c3).^2)...
%    + a4.*exp(-((Vds-b4)./c4).^2) +a5.*exp(-((Vds-b5)./c5).^2) +a6.*exp(-((Vds-b6)./c6).^2);

if Vds <= 34.9
    Coss = -1.472*Vds + 492;
elseif Vds <= 69.57
       a1 =       -98.59;
       b1 =       51.35;
       c1 =       6.451;
       a2 =       451.4;
       b2 =       31.64;
       c2 =       37.52;
 
Coss = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2);
else
       a1 =       95.6;
       b1 =       58.5;
       c1 =       88.28;
       a2 =       1.31e16;
       b2 =       -1.231e5;
       c2 =       2.152e4;
 
Coss = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2);            
end
if Coss<60
    Coss = 60;
end
Coss = Coss*1e-12;
%% Outputs
Cgs = Ciss - Crss;
Cds = Coss - Crss;
Cgd = Crss;

end