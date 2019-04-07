%% Aspect ratio plots

%% Aspect ratio, Core mass, number of modules
figure;
plot(ar_xaxis,ar_np_miron(1,:),'b -','Linewidth',3);
hold on
plot(ar_xaxis,ar_np_miron(2,:),'k -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_np_miron(3,:),'r -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_np_miron(4,:),'g -','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel');
title('w = 2, ns = 2');
xlabel('Aspect ratio','FontSize',16,'FontWeight','Bold')
ylabel('Core iron mass (kg)','FontSize',16,'FontWeight','Bold')
%ylim([5 10]);


%% Aspect ratio, Motor efficiency, number of modules
figure;
plot(ar_xaxis,ar_np_effm(1,:),'b -','Linewidth',2);
hold on
plot(ar_xaxis,ar_np_effm(2,:),'k o','Linewidth',2);
hold on;
plot(ar_xaxis,ar_np_effm(3,:),'r *','Linewidth',2);
hold on;
plot(ar_xaxis,ar_np_effm(4,:),'g --','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel');
title('w = 2, ns = 2');
xlabel('Aspect ratio','FontSize',16,'FontWeight','Bold')
ylabel('Motor efficiency (%)','FontSize',16,'FontWeight','Bold')
%ylim([5 10]);

%% Aspect ratio, Copper mass, number of modules
figure;
plot(ar_xaxis,ar_np_mcopper(1,:),'b -','Linewidth',3);
hold on
plot(ar_xaxis,ar_np_mcopper(2,:),'k -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_np_mcopper(3,:),'r -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_np_mcopper(4,:),'g -','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel');
title('w = 2, ns = 2');
xlabel('Aspect ratio','FontSize',16,'FontWeight','Bold')
ylabel('Winding copper mass (kg)','FontSize',16,'FontWeight','Bold')
%ylim([5 10]);

%% Aspect ratio, Magnet mass, number of modules
figure;
plot(ar_xaxis,ar_np_mmagnet(1,:),'b -','Linewidth',3);
hold on
plot(ar_xaxis,ar_np_mmagnet(2,:),'k -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_np_mmagnet(3,:),'r -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_np_mmagnet(4,:),'g -','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel');
title('w = 2, ns = 2');
xlabel('Aspect ratio','FontSize',16,'FontWeight','Bold')
ylabel('Magnet mass (kg)','FontSize',16,'FontWeight','Bold')
%ylim([5 10]);

%% Aspect ratio, Power density, number of modules
figure;
plot(ar_xaxis,ar_np_PDv(1,:),'b -','Linewidth',2);
hold on
plot(ar_xaxis,ar_np_PDv(2,:),'k o','Linewidth',2);
hold on;
plot(ar_xaxis,ar_np_PDv(3,:),'r *','Linewidth',2);
hold on;
plot(ar_xaxis,ar_np_PDv(4,:),'g --','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel');
title('w = 2, ns = 2');
xlabel('Aspect ratio','FontSize',16,'FontWeight','Bold')
ylabel('Power density (kW/lt)','FontSize',16,'FontWeight','Bold')
%ylim([5 10]);


%% Aspect ratio, Core mass, number of slots
figure;
plot(ar_xaxis,ar_Qs_miron(1,:),'b -','Linewidth',3);
hold on
plot(ar_xaxis,ar_Qs_miron(2,:),'k -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_Qs_miron(3,:),'r -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_Qs_miron(4,:),'g -','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
legend('Qs=12','Qs=24','Qs=36','Qs=48');
%legend('1 parallel','2 parallel','3 parallel','4 parallel');
title('ns = 2, np = 1');
xlabel('Aspect ratio','FontSize',16,'FontWeight','Bold')
ylabel('Core iron mass (kg)','FontSize',16,'FontWeight','Bold')
%ylim([5 10]);


%% Aspect ratio, Motor efficiency, number of slots
figure;
plot(ar_xaxis,ar_Qs_effm(1,:),'b -','Linewidth',3);
hold on
plot(ar_xaxis,ar_Qs_effm(2,:),'k -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_Qs_effm(3,:),'r -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_Qs_effm(4,:),'g -','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
legend('Qs=12','Qs=24','Qs=36','Qs=48');
%legend('1 parallel','2 parallel','3 parallel','4 parallel');
title('ns = 2, np = 1');
xlabel('Aspect ratio','FontSize',16,'FontWeight','Bold')
ylabel('Motor efficiency (%)','FontSize',16,'FontWeight','Bold')
%ylim([5 10]);

%% Aspect ratio, Copper mass, number of slots
figure;
plot(ar_xaxis,ar_Qs_mcopper(1,:),'b -','Linewidth',3);
hold on
plot(ar_xaxis,ar_Qs_mcopper(2,:),'k -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_Qs_mcopper(3,:),'r -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_Qs_mcopper(4,:),'g -','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
legend('Qs=12','Qs=24','Qs=36','Qs=48');
%legend('1 parallel','2 parallel','3 parallel','4 parallel');
title('ns = 2, np = 1');
xlabel('Aspect ratio','FontSize',16,'FontWeight','Bold')
ylabel('Winding copper mass (kg)','FontSize',16,'FontWeight','Bold')
%ylim([5 10]);

%% Aspect ratio, Magnet mass, number of slots
figure;
plot(ar_xaxis,ar_Qs_mmagnet(1,:),'b -','Linewidth',3);
hold on
plot(ar_xaxis,ar_Qs_mmagnet(2,:),'k -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_Qs_mmagnet(3,:),'r -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_Qs_mmagnet(4,:),'g -','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
legend('Qs=12','Qs=24','Qs=36','Qs=48');
%legend('1 parallel','2 parallel','3 parallel','4 parallel');
title('ns = 2, np = 1');
xlabel('Aspect ratio','FontSize',16,'FontWeight','Bold')
ylabel('Magnet mass (kg)','FontSize',16,'FontWeight','Bold')
%ylim([5 10]);

%% Aspect ratio, Power density, number of slots
figure;
plot(ar_xaxis,ar_Qs_PDv(1,:),'b -','Linewidth',3);
hold on
plot(ar_xaxis,ar_Qs_PDv(2,:),'k -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_Qs_PDv(3,:),'r -','Linewidth',3);
hold on;
plot(ar_xaxis,ar_Qs_PDv(4,:),'g -','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
legend('Qs=12','Qs=24','Qs=36','Qs=48');
%legend('1 parallel','2 parallel','3 parallel','4 parallel');
title('ns = 2, np = 1');
xlabel('Aspect ratio','FontSize',16,'FontWeight','Bold')
ylabel('Power density (kW/lt)','FontSize',16,'FontWeight','Bold')
%ylim([5 10]);



%% Modulation index plots

%% Modulation index, Drive efficiency, number of parallel modules
figure;
plot(ma_xaxis,ma_np_effdr(1,:),'bx-','Linewidth',2);
hold on
plot(ma_xaxis,ma_np_effdr(2,:),'ro-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_effdr(3,:),'k*-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_effdr(4,:),'g--','Linewidth',3);
hold on;
plot(ma_xaxis,ma_np_effdr(5,:),'m^-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_effdr(6,:),'c+-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','southeast');
title('ns = 2, fsw = 40kHz');
xlabel('Modulation index','FontSize',16,'FontWeight','Bold')
ylabel('Drive efficiency (%)','FontSize',16,'FontWeight','Bold')
ylim([94 100]);
xlim([0.48 1.02]);


%% Modulation index, Capacitance requirement, number of parallel modules
figure;
plot(ma_xaxis,ma_np_Cdcreq(1,:),'bx-','Linewidth',2);
hold on
plot(ma_xaxis,ma_np_Cdcreq(2,:),'ro-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_Cdcreq(3,:),'k*-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_Cdcreq(4,:),'g--','Linewidth',3);
hold on;
plot(ma_xaxis,ma_np_Cdcreq(5,:),'m^-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_Cdcreq(6,:),'c+-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','Best');
title('ns = 2, fsw = 40kHz');
xlabel('Modulation index','FontSize',16,'FontWeight','Bold')
ylabel('Capacitance requirement (uF)','FontSize',16,'FontWeight','Bold')
ylim([0 200]);
xlim([0.48 1.02]);


%% Modulation index, DC link current ripple, number of parallel modules
figure;
plot(ma_xaxis,ma_np_Icrms(1,:),'bx-','Linewidth',2);
hold on
plot(ma_xaxis,ma_np_Icrms(2,:),'ro-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_Icrms(3,:),'k*-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_Icrms(4,:),'g--','Linewidth',3);
hold on;
plot(ma_xaxis,ma_np_Icrms(5,:),'m^-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_Icrms(6,:),'c+-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','Best');
title('ns = 2, fsw = 40kHz');
xlabel('Modulation index','FontSize',16,'FontWeight','Bold')
ylabel('DC link rms ripple current (A)','FontSize',16,'FontWeight','Bold')
ylim([0 22]);
xlim([0.48 1.02]);



%% Modulation index, Motor efficiency, number of parallel modules
figure;
plot(ma_xaxis,ma_np_effm(1,:),'bx-','Linewidth',2);
hold on
plot(ma_xaxis,ma_np_effm(2,:),'ro-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_effm(3,:),'k*-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_effm(4,:),'g--','Linewidth',3);
hold on;
plot(ma_xaxis,ma_np_effm(5,:),'m^-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_effm(6,:),'c+-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','Best');
title('ns = 2, fsw = 40kHz');
xlabel('Modulation index','FontSize',16,'FontWeight','Bold')
ylabel('Motor efficiency (%)','FontSize',16,'FontWeight','Bold')
ylim([95 100]);
xlim([0.48 1.02]);


%% Modulation index, Power density, number of parallel modules
figure;
%plot(ma_xaxis,ma_np_PDv(1,:),'bx-','Linewidth',2);
%hold on
plot(ma_xaxis,ma_np_PDv(2,:),'rx-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_PDv(3,:),'kx-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_PDv(4,:),'gx-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_PDv(5,:),'mx-','Linewidth',2);
hold on;
plot(ma_xaxis,ma_np_PDv(6,:),'cx-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','Best');
title('ns = 2, fsw = 40kHz');
xlabel('Modulation index','FontSize',16,'FontWeight','Bold')
ylabel('Power density (kW/lt)','FontSize',16,'FontWeight','Bold')
%ylim([95 100]);
xlim([0.48 1.02]);


%% Switching frequency, Drive efficiency, number of parallel modules
figure;
plot(fsw_xaxis,fsw_np_effdr(1,:),'bx-','Linewidth',2);
hold on
plot(fsw_xaxis,fsw_np_effdr(2,:),'ro-','Linewidth',2);
hold on;
plot(fsw_xaxis,fsw_np_effdr(3,:),'k*-','Linewidth',2);
hold on;
plot(fsw_xaxis,fsw_np_effdr(4,:),'g--','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_effdr(5,:),'m+-','Linewidth',2);
hold on;
plot(fsw_xaxis,fsw_np_effdr(6,:),'c^-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','southeast');
title('ns = 2, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',16,'FontWeight','Bold')
ylabel('Drive efficiency (%)','FontSize',16,'FontWeight','Bold')
ylim([97 100]);
xlim([-4 220]);
%% Switching frequency, Capacitance requirement, number of parallel modules
figure;
plot(fsw_xaxis,fsw_np_Cdcreq(1,:),'bx-','Linewidth',2);
hold on
plot(fsw_xaxis,fsw_np_Cdcreq(2,:),'ro-','Linewidth',2);
hold on;
plot(fsw_xaxis,fsw_np_Cdcreq(3,:),'k*-','Linewidth',2);
hold on;
plot(fsw_xaxis,fsw_np_Cdcreq(4,:),'g--','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Cdcreq(5,:),'m+-','Linewidth',2);
hold on;
plot(fsw_xaxis,fsw_np_Cdcreq(6,:),'c^-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','northeast');
title('ns = 2, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',16,'FontWeight','Bold')
ylabel('Required capacitance (uF)','FontSize',16,'FontWeight','Bold')
%ylim([97 100]);
xlim([-4 120]);
%% Switching frequency, Power density, number of parallel modules
figure;
%plot(fsw_xaxis,fsw_np_PDv(1,:),'bx-','Linewidth',2);
%hold on
plot(fsw_xaxis,fsw_np_PDv(2,:),'rx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_PDv(3,:),'kx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_PDv(4,:),'gx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_PDv(5,:),'mx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_PDv(6,:),'cx-','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','southeast');
title('ns = 2, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',16,'FontWeight','Bold')
ylabel('Power density (kW/lt)','FontSize',16,'FontWeight','Bold')
ylim([0.4 1]);
xlim([-4 220]);


%% Switching frequency, Volume, number of parallel modules
figure;
plot(fsw_xaxis,fsw_np_Volcap(1,:),'bx-','Linewidth',2);
hold on
plot(fsw_xaxis,fsw_np_Volcap(2,:),'rx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Volcap(3,:),'kx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Volcap(4,:),'gx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Volcap(5,:),'mx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Volcap(6,:),'cx-','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','southeast');
title('ns = 2, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',16,'FontWeight','Bold')
ylabel('Effective capacitor volume (lt)','FontSize',16,'FontWeight','Bold')
%ylim([97 100]);
xlim([-4 220]);


%% Switching frequency, Volume, number of parallel modules
figure;
%plot(fsw_xaxis,fsw_np_Volhs(1,:),'bx-','Linewidth',2);
%hold on
plot(fsw_xaxis,fsw_np_Volhs(2,:),'rx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Volhs(3,:),'kx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Volhs(4,:),'gx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Volhs(5,:),'mx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Volhs(6,:),'cx-','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','southeast');
title('ns = 2, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',16,'FontWeight','Bold')
ylabel('Effective heat sink volume (lt)','FontSize',16,'FontWeight','Bold')
%ylim([97 100]);
xlim([-4 220]);


%% Switching frequency, Volume, number of parallel modules
% drive total volume (silindir)
figure;
plot(fsw_xaxis,fsw_np_Voldr(1,:),'bx-','Linewidth',2);
hold on
plot(fsw_xaxis,fsw_np_Voldr(2,:),'rx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Voldr(3,:),'kx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Voldr(4,:),'gx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Voldr(5,:),'mx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Voldr(6,:),'cx-','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','southeast');
title('ns = 2, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',16,'FontWeight','Bold')
ylabel('Total drive volume (lt)','FontSize',16,'FontWeight','Bold')
ylim([0 5]);
xlim([-4 220]);


%% Switching frequency, Volume, number of parallel modules
% heat sink total volume (silindir)
figure;
%plot(fsw_xaxis,fsw_np_Vhs(1,:),'bx-','Linewidth',2);
%hold on
plot(fsw_xaxis,fsw_np_Vhs(2,:),'rx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Vhs(3,:),'kx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Vhs(4,:),'gx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Vhs(5,:),'mx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Vhs(6,:),'cx-','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','southeast');
title('ns = 2, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',16,'FontWeight','Bold')
ylabel('Total heat sink volume (lt)','FontSize',16,'FontWeight','Bold')
ylim([0 5]);
xlim([-4 220]);


%% Switching frequency, Total Volume, number of parallel modules
% Total volume (silindir)
figure;
%plot(fsw_xaxis,fsw_np_Vhs(1,:),'bx-','Linewidth',2);
%hold on
plot(fsw_xaxis,fsw_np_Vhs(2,:) + fsw_np_Voldr(2,:),'rx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Vhs(3,:) + fsw_np_Voldr(3,:),'kx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Vhs(4,:) + fsw_np_Voldr(4,:),'gx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Vhs(5,:) + fsw_np_Voldr(5,:),'mx-','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_Vhs(6,:) + fsw_np_Voldr(6,:),'cx-','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','southeast');
title('ns = 2, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',16,'FontWeight','Bold')
ylabel('Total volume (lt)','FontSize',16,'FontWeight','Bold')
ylim([0 8]);
xlim([-4 220]);

%% Number of series modules, Capacitance requirement, number of parallel modules
figure;
plot(np_xaxis,np_ns_Cdcreq(1,:),'bx-','Linewidth',2);
hold on
plot(np_xaxis,np_ns_Cdcreq(2,:),'ro-','Linewidth',2);
hold on;
plot(np_xaxis,np_ns_Cdcreq(3,:),'k--','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
legend('2 series','3 series','4 series','Location','northeast');
title('fsw = 40kHz, ma = 0.9');
xlabel('Number of parallel connected modules','FontSize',16,'FontWeight','Bold')
ylabel('Capacitance requirement (uF)','FontSize',16,'FontWeight','Bold')
ylim([0 420]);
xlim([0 9]);


%% Number of series modules, Power density, number of parallel modules
figure;
plot(np_xaxis,np_ns_PDv(1,:),'bx-','Linewidth',2);
hold on
plot(np_xaxis,np_ns_PDv(2,:),'ro-','Linewidth',2);
hold on;
plot(np_xaxis,np_ns_PDv(3,:),'k--','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
legend('2 series','3 series','4 series','Location','southeast');
title('fsw = 40kHz, ma = 0.9');
xlabel('Number of parallel connected modules','FontSize',16,'FontWeight','Bold')
ylabel('Power density (lt)','FontSize',16,'FontWeight','Bold')
%ylim([0 420]);
xlim([0 9]);



%% Number of series modules, Power density, number of parallel modules
figure;
plot(np_xaxis,np_ns_effdr(1,:),'bx-','Linewidth',2);
hold on
plot(np_xaxis,np_ns_effdr(2,:),'rx-','Linewidth',3);
hold on;
plot(np_xaxis,np_ns_effdr(3,:),'kx-','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
legend('2 series','3 series','4 series','Location','southeast');
title('fsw = 40kHz, ma = 0.9');
xlabel('Number of parallel connected modules','FontSize',16,'FontWeight','Bold')
ylabel('Drive efficiency (%)','FontSize',16,'FontWeight','Bold')
ylim([94 100]);
xlim([0 9]);



%% Switching frequency, Volume, drive, heatsink, total

fsw_np_Voldr(3,3) = (fsw_np_Voldr(3,2)+fsw_np_Voldr(3,4))/2;
fsw_np_Voldr(3,3) = (fsw_np_Voldr(3,2)+fsw_np_Voldr(3,4))/2;


figure;
plot(fsw_xaxis,fsw_np_Vhs(3,:),'rx-','Linewidth',2);
hold on;
plot(fsw_xaxis,fsw_np_Voldr(3,:),'ko-','Linewidth',2);
hold on;
plot(fsw_xaxis,(fsw_np_Vhs(3,:)+fsw_np_Voldr(3,:))/1,'b--','Linewidth',3);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('Heat sink','Drive','Total','Location','southwest');
title('ns = 2, np = 3, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',16,'FontWeight','Bold')
ylabel('Volume (lt)','FontSize',16,'FontWeight','Bold')
ylim([0 7]);
xlim([0 210]);



%% Switching frequency, Power density, number of parallel modules
fsw_np_PDv(3,3) = (fsw_np_PDv(3,2)+fsw_np_PDv(3,4))/2;
fsw_np_PDv(4,3) = (fsw_np_PDv(4,2)+fsw_np_PDv(4,4))/2;
fsw_np_PDv(5,3) = (fsw_np_PDv(5,2)+fsw_np_PDv(5,4))/2;
fsw_np_PDv(2,8) = (fsw_np_PDv(2,7)+fsw_np_PDv(2,10))/2;
fsw_np_PDv(2,9) = (fsw_np_PDv(2,8)+fsw_np_PDv(2,12))/2;


figure;
%plot(fsw_xaxis,fsw_np_PDv(1,:),'bx-','Linewidth',2);
%hold on
plot(fsw_xaxis,fsw_np_PDv(2,:),'rx-','Linewidth',2);
hold on;
plot(fsw_xaxis,fsw_np_PDv(3,:),'ko-','Linewidth',2);
hold on;
plot(fsw_xaxis,fsw_np_PDv(4,:),'g--','Linewidth',3);
hold on;
plot(fsw_xaxis,fsw_np_PDv(5,:),'m^-','Linewidth',2);
hold on;
plot(fsw_xaxis,fsw_np_PDv(6,:),'c+-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('2 parallel','3 parallel','4 parallel',...
    '5 parallel','6 parallel','Location','southeast');
title('ns = 2, ma = 0.9');
xlabel('Switching frequency (kHz)','FontSize',16,'FontWeight','Bold')
ylabel('Power density (kW/lt)','FontSize',16,'FontWeight','Bold')
ylim([0.4 1]);
xlim([-4 220]);



%% Aspect ratio, Magnet mass, number of modules
figure;
plot(ar_xaxis,ar_np_cost(1,:),'g -','Linewidth',2);
hold on
plot(ar_xaxis,ar_np_cost(2,:),'k o','Linewidth',2);
hold on;
plot(ar_xaxis,ar_np_cost(3,:),'r *','Linewidth',2);
hold on;
plot(ar_xaxis,ar_np_cost(4,:),'b --','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',16);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
legend('1 parallel','2 parallel','3 parallel','4 parallel');
title('w = 2, ns = 2');
xlabel('Aspect ratio','FontSize',16,'FontWeight','Bold')
ylabel('Motor active material cost ($)','FontSize',16,'FontWeight','Bold')
%ylim([5 10]);

%% BELOW ARE OLD
%%
figure;
%subplot(3,1,1)
plot(xaxis,param(1,:,1),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,2),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,param(1,:,3),'ro-','Linewidth',1.5);
hold on;
plot(xaxis,param(2,:,1),'go-','Linewidth',1.5);
hold on;
plot(xaxis,param(3,:,2),'co-','Linewidth',1.5);
hold on;
plot(xaxis,param(4,:,1),'mo-','Linewidth',1.5);
%hold on;
%plot(xaxis,param(1,:,7),'bx-','Linewidth',1.5);
%hold on;
%plot(xaxis,param(1,:,8),'kx','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
legend('2s-1p','2s2p','2s3p','3s1p','3s2p','4s1p')
title('2 series modules, ma = 0.9');
xlabel('Modulation index','FontSize',12,'FontWeight','Bold')
ylabel('Capacitance requirement (uF)','FontSize',12,'FontWeight','Bold')
%ylim([94 100]);

%%
figure;
xaxis = (1:8);
for k = 1:8
yaxis1(k) = param(1,4,k);
yaxis2(k) = param(2,4,k);
yaxis3(k) = param(3,4,k);
end
%subplot(3,1,1)
plot(xaxis,yaxis1,'bo-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis2,'ko-','Linewidth',1.5);
hold on;
plot(xaxis,yaxis3,'ro-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
legend('2series','3series','4series')
title('fsw = 40kHz, ma = 0.9');
xlabel('Number of parallel connected modules','FontSize',12,'FontWeight','Bold')
ylabel('Capacitance requirement (uF)','FontSize',12,'FontWeight','Bold')
%ylim([94 100]);

%%
figure;
plot(xaxis,param1(1,:,2),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param2(1,:,2),'ko-','Linewidth',1.5);
hold on;
plot(xaxis,param3(1,:,2),'ro-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Aspect ratio','FontSize',12,'FontWeight','Bold')
ylabel('Active material mass (kgt)','FontSize',12,'FontWeight','Bold')
%xlim([0.0995 0.1]);
%ylim([95 100]);
%ylim([0 400]);
%legend('1parallel','2parallel','3parallel','4parallel','5parallel','6parallel');
legend('Copper','Magnet','Iron');


%%
figure;
%subplot(3,1,1)
plot(xaxis,param1(1,:,1),'bo-','Linewidth',1.5);
hold on;
plot(xaxis,param2(1,:,1),'ko-','Linewidth',1.5);
% hold on;
% plot(xaxis,param(1,:,3),'ro-','Linewidth',1.5);
% hold on;
% plot(xaxis,param(1,:,4),'go-','Linewidth',1.5);
% hold on;
% plot(xaxis,param(1,:,5),'co-','Linewidth',1.5);
% hold on;
% plot(xaxis,param(1,:,6),'mo-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
%xlabel('Switching frequency (kHz)','FontSize',12,'FontWeight','Bold')
xlabel('Aspect ratio','FontSize',12,'FontWeight','Bold')
%xlabel('Modulation index','FontSize',12,'FontWeight','Bold')
%ylabel('Drive efficiency (%)','FontSize',12,'FontWeight','Bold')
%ylabel('Capacitance requirement (uF)','FontSize',12,'FontWeight','Bold')
%ylabel('Total capacitor volume (cm^3)','FontSize',12,'FontWeight','Bold')
%ylabel('DC bus ripple current requirement (Arms)','FontSize',12,'FontWeight','Bold')
%xlim([0.0995 0.1]);
%ylim([95 100]);
%ylim([0 400]);
%legend('1parallel','2parallel','3parallel','4parallel','5parallel','6parallel');
legend('Axial length','Bore diameter');
%title('2 series modules');

%%
% interleaving effect
intv = [1,0.40,0.20,0.19,0.17,0.09,0.07,0.05];
intc = [1,0.76,0.36,0.30,0.26,0.23,0.2,0.15];
xaxis = 1:8;
figure;
plot(xaxis,intv,'bx-','Linewidth',1.5);
hold on;
plot(xaxis,intc,'kx-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Number of parallel connected modules','FontSize',12,'FontWeight','Bold')
ylabel('Normalized ripple','FontSize',12,'FontWeight','Bold')
xlim([0 9]);
ylim([0 1.05]);
legend('Ripple voltage','Ripple current');

