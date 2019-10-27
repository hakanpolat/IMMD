clear
clc
%% Module 1
M1_PhaseA_Max_Inductance = 3.72e-3; %H
M1_PhaseB_Max_Inductance = 3.68e-3; %H
M1_PhaseC_Max_Inductance = 3.56e-3; %H

M1_PhaseA_Min_Inductance = 3.20e-3; %H
M1_PhaseB_Min_Inductance = 3.18e-3; %H
M1_PhaseC_Min_Inductance = 3.12e-3; %H

%% Module 2
M2_PhaseA_Max_Inductance = 3.51e-3; %H
M2_PhaseB_Max_Inductance = 3.43e-3; %H
M2_PhaseC_Max_Inductance = 3.62e-3; %H

M2_PhaseA_Min_Inductance = 3.05e-3; %H
M2_PhaseB_Min_Inductance = 2.94e-3; %H
M2_PhaseC_Min_Inductance = 3.07e-3; %H

%% Module 3
M3_PhaseA_Max_Inductance = 3.55e-3; %H
M3_PhaseB_Max_Inductance = 3.67e-3; %H
M3_PhaseC_Max_Inductance = 3.68e-3; %H

M3_PhaseA_Min_Inductance = 2.99e-3; %H
M3_PhaseB_Min_Inductance = 3.02e-3; %H
M3_PhaseC_Min_Inductance = 3.07e-3; %H
%% Module 4
M4_PhaseA_Max_Inductance = 3.58e-3; %H
M4_PhaseB_Max_Inductance = 3.64e-3; %H
M4_PhaseC_Max_Inductance = 3.62e-3; %H

M4_PhaseA_Min_Inductance = 2.98e-3; %H
M4_PhaseB_Min_Inductance = 3.12e-3; %H
M4_PhaseC_Min_Inductance = 3.12e-3; %H
%% Sum of maximum and minimums
Sum_Of_Maximum_Inductance = M1_PhaseA_Max_Inductance;
Sum_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance + M1_PhaseB_Max_Inductance;
Sum_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance + M1_PhaseC_Max_Inductance;
Sum_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance + M2_PhaseA_Max_Inductance;
Sum_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance + M2_PhaseB_Max_Inductance;
Sum_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance + M2_PhaseC_Max_Inductance;
Sum_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance + M3_PhaseA_Max_Inductance;
Sum_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance + M3_PhaseB_Max_Inductance;
Sum_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance + M3_PhaseC_Max_Inductance;
Sum_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance + M4_PhaseA_Max_Inductance;
Sum_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance + M4_PhaseB_Max_Inductance;
Sum_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance + M4_PhaseC_Max_Inductance;

Sum_Of_Minimum_Inductance = M1_PhaseA_Min_Inductance;
Sum_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance + M1_PhaseB_Min_Inductance;
Sum_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance + M1_PhaseC_Min_Inductance;
Sum_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance + M2_PhaseA_Min_Inductance;
Sum_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance + M2_PhaseB_Min_Inductance;
Sum_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance + M2_PhaseC_Min_Inductance;
Sum_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance + M3_PhaseA_Min_Inductance;
Sum_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance + M3_PhaseB_Min_Inductance;
Sum_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance + M3_PhaseC_Min_Inductance;
Sum_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance + M4_PhaseA_Min_Inductance;
Sum_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance + M4_PhaseB_Min_Inductance;
Sum_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance + M4_PhaseC_Min_Inductance;
%% Means
Mean_Of_Maximum_Inductance = Sum_Of_Maximum_Inductance/12;
Mean_Of_Minimum_Inductance = Sum_Of_Minimum_Inductance/12;

Lq_mean = Mean_Of_Maximum_Inductance;
Ld_mean = Mean_Of_Minimum_Inductance;
%%  Flux linkage calculation
% voltage rms induced in each phase at 600rpm
NumberOfPolePairs = 10;
M1_PhaseA_Erms = 79.3; %Vrms
M1_PhaseB_Erms = 79.3; %Vrms
M1_PhaseC_Erms = 79.8; %Vrms
M2_PhaseA_Erms = 79.5; %Vrms
M2_PhaseB_Erms = 79.0; %Vrms
M2_PhaseC_Erms = 80.6; %Vrms
M3_PhaseA_Erms = 81.1; %Vrms
M3_PhaseB_Erms = 81.6; %Vrms
M3_PhaseC_Erms = 81.8; %Vrms
M4_PhaseA_Erms = 81.9; %Vrms
M4_PhaseB_Erms = 80.0; %Vrms
M4_PhaseC_Erms = 80.1; %Vrms

Sum_Erms = M1_PhaseA_Erms;
Sum_Erms = Sum_Erms + M1_PhaseB_Erms;
Sum_Erms = Sum_Erms + M1_PhaseC_Erms;
Sum_Erms = Sum_Erms + M2_PhaseA_Erms;
Sum_Erms = Sum_Erms + M2_PhaseB_Erms;
Sum_Erms = Sum_Erms + M2_PhaseC_Erms;
Sum_Erms = Sum_Erms + M3_PhaseA_Erms;
Sum_Erms = Sum_Erms + M3_PhaseB_Erms;
Sum_Erms = Sum_Erms + M3_PhaseC_Erms;
Sum_Erms = Sum_Erms + M4_PhaseA_Erms;
Sum_Erms = Sum_Erms + M4_PhaseB_Erms;
Sum_Erms = Sum_Erms + M4_PhaseC_Erms;

Avg_Epeak = sqrt(2)*Sum_Erms/12;

FluxLinkagePeak = (Avg_Epeak/(600*2*pi/60))/NumberOfPolePairs;












