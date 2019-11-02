%%
% 2-parallel modules
% No parasitics
% Balanced load
% Infinite bus


%%
figure;
hold all;
plot(timeaxis,Vdc1withoutint,'b-','Linewidth',1);
plot(timeaxis,Vdc1withint,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([0.049 0.05]);
ylim([260 280]);
legend({'Without interleaving','With interleaving'},'Location','best');
title('Vdc');

%%
figure;
hold all;
plot(timeaxis,Idc1withint,'r-','Linewidth',1);
plot(timeaxis,Idc2withint,'b-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([0.049 0.05]);
%ylim([260 280]);
legend({'Idc1','Idc2'},'Location','best');
title('Idc-With interleaving');
