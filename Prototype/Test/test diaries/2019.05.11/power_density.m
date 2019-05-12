% Length
%L_fin = 23; % mm
L_fin = 10:1:50; % mm
L_base = 5; % mm
L_pad = 2; % mm
L_pcb = 1; % mm
L_cap = 21; % mm
L_total = L_base+L_cap+L_fin+L_pad+L_pcb; % mm
% Area
R_pcb = 133; % mm
A_pcb = pi*R_pcb^2/4; % mm^2
% Volume
V_drive_mm3 = A_pcb*L_total; % mm^3
V_drive = V_drive_mm3*1e-6; % lt
% Power density
P_drive = 2; % kW
PD_drive = P_drive./V_drive; % kW/lt

%%
figure;
plot(L_fin,PD_drive,'bx-','Linewidth',2);
xlabel('Fin height (mm)','FontSize',14,'FontWeight','Bold')
ylabel('Power density (kW/lt)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
