for Vds = 0:1:600
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
Coss1 = a1.*exp(-((Vds-b1)./c1).^2) + a2.*exp(-((Vds-b2)./c2).^2) + a3*exp(-((Vds-b3)./c3).^2)...
   + a4.*exp(-((Vds-b4)./c4).^2) +a5.*exp(-((Vds-b5)./c5).^2) +a6.*exp(-((Vds-b6)./c6).^2);
    k = Vds+1;
    EnergyOss(k) = 0.5*Coss1*1e-12*Vds^2;
end
plot(0:600,EnergyOss);
ylim([0 1e-5]);