%% Kollmorgen frameless motor data

% Data information
% 1. Prated: Watts
% 2. pole
% 3. Nrated: rpm
% 4. Cont. Tstall: Nm
% 5. Peak Tstall: Nm
% 6. Tconstant: Nm/Arms
% 7. Econstant: Vrms/kRPM
% 8. Length: mm
% 9. Dos: mm
% 10. Dis: mm
% 11. Dir: mm
% 12. Slot number

motor_data2 = [
5025,10,3100,21.8,76.1,2.19,133,100.74,139.956,86.19,65.012;
5160,10,4800,21.7,76.6,1.59,96.2,100.74,139.956,86.19,65.012;
5400,10,2800,25.6,92.3,2.44,147,125.60,139.956,86.19,65.012;
5750,10,3400,25.9,93.0,2.01,121,125.60,139.956,86.19,65.012;
5200,10,2100,30.7,119,3.08,186,69.04,189.956,115.9,85.018;
5750,10,2650,30.2,119,2.48,150,69.04,189.956,115.9,85.018;
6655,10,1950,43.7,170,3.35,202,69.04,189.956,115.9,85.018;
7200,10,2350,43.5,171,2.98,180,69.04,189.956,115.9,85.018;
7270,10,1700,54.6,218,3.96,240,69.04,189.956,115.9,85.018;
6985,38,885,108,243,6.79,411,100.48,229.85,152.49,105.05;
8350,38,720,154,393,8.50,514,150.09,229.85,152.49,105.05;
5460,46,1000,102,197,6.08,368,36.37,331.46,224.16,155.01;
5460,46,1000,102,197,3.04,184,36.37,331.46,224.16,155.01;
8250,46,520,205,390,12.2,738,70.36,331.46,224.16,155.01;
6600,46,940,209,390,6.57,397,70.36,331.46,224.16,155.01;
7780,38,830,172,498,8.24,498,50.71,361.11,300.92,225.04;
7780,38,830,172,498,6.59,399,50.71,361.11,300.92,225.04
];

for k = 1:numel(motor_data2(:,1))
    if motor_data2(k,2) == 10
        motor_data2(k,12) = 12;
    elseif motor_data2(k,2) == 38
        motor_data2(k,12) = 36;
    elseif motor_data2(k,2) == 46
        motor_data2(k,12) = 36;
    else
        motor_data2(k,12) = 0;
    end
end
        
motor_data = motor_data2(12,:);
motor_data = motor_data2;

% Motor information
% Kollmorgen,KBM-3503A 
% Kollmorgen,KBM-3503B 
% Kollmorgen,KBM-3504A 
% Kollmorgen,KBM-3504B 
% Kollmorgen,KBM-4501A 
% Kollmorgen,KBM-4501B 
% Kollmorgen,KBM-4502A 
% Kollmorgen,KBM-4502B 
% Kollmorgen,KBM-4503A 
% Kollmorgen,KBM-6002A 
% Kollmorgen,KBM-6003A 
% Kollmorgen,KBM-8800A 
% Kollmorgen,KBM-8800C 
% Kollmorgen,KBM-8801A 
% Kollmorgen,KBM-8801B 
% Kollmorgen,KBM-11800A 
% Kollmorgen,KBM-11800B 


%% General Inputs
% motor catalog (Kollmorgen, KBM(S)-88X00-X, B)
%%
% http://productpage.3dpublisher.net/3dproductpage/Qsvalidlogin.asp?GUID=1249850940083&name=KBM(S)-88&isCate=true
%%
% http://www.kollmorgen.com/en-us/products/motors/direct-drive/kbm-series-frameless/_literature/kbm-selection-guide-en-us_revg/
Prated = 5.46e3; % Watts
Nrated = 1000; % rpm
Tstall_cont = 102; % Nm
Icont = 20.5; % Amps
Tstall_peak = 145; % Nm
Ipeak = 48.3; % amps
torque_sens = 5.06; % Nm/Arms
back_emfc = 306; % Vrms/kRPM
motor_cons = 6.10; % Nm/sqrt(Watt)
res_ltol = 0.46; % Omhs
induct = 4.5; % mH
inertia = 5.26e-2; % kgm^2
friction_static = 1.08; % Nm
Tcogging_pp = 0.81; % Nm
friction_viscous = 0.385; % Nm/kRPM
Rth = 0.305; % C/W
pole_number = 46;
slot_number = 36;
length = 36.37; % mm
Do_stator = 331.46; % mm
Di_stator = 224.16; % mm
Di_rotor = 155.02; % mm

