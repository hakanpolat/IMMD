%%
%filename = 'Irmspercdata.xlsx';
Irms_perc = xlsread('Irmspercdata.xlsx');
phase_shift = 0:5:74*5;

%%
fig=figure;
% plot(phase_shift,Irms_perc(1,:),'ko-','Linewidth',1.5);
% hold on;
plot(phase_shift,Irms_perc(2,:),'r -','Linewidth',1.5);
hold on;
plot(phase_shift,Irms_perc(3,:),'b -','Linewidth',1.5);
hold on;
plot(phase_shift,Irms_perc(4,:),'m -','Linewidth',1.5);
hold on;
plot(phase_shift,Irms_perc(5,:),'g -','Linewidth',1.5);
hold on;
plot(phase_shift,Irms_perc(6,:),'y -','Linewidth',1.5);
hold on;
plot(phase_shift,Irms_perc(7,:),'k -','Linewidth',1.5);
hold on;
plot(phase_shift,Irms_perc(8,:),'r -','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Phase shift (degrees)','FontSize',12,'FontWeight','Bold')
ylabel('DC Link Capacitor RMS Current (%)','FontSize',12,'FontWeight','Bold')
legend('2 Modules','3 Modules','4 Modules','5 Modules','6 Modules','7 Modules','8 Modules');
print(fig,'varyingmodule','-dpng')
%ylim([0 80]);
xlim([0 360]);