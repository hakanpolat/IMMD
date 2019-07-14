
timeaxis = vdc.time;
vdc_single_withESL = vdc.signals(1).values;

%%

timeaxis = vdc.time;
vdc_single_withoutESL = vdc.signals(1).values;

%%
figure;
hold all;
plot(timeaxis,vdc_single_withESL,'b-','Linewidth',1);
plot(timeaxis,vdc_single_withoutESL,'r-','Linewidth',1);
set(gca,'FontSize',14);
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([0.35 0.4]);
ylim([250 290]);
legend({'With ESL and ESR','Without ESL and ESR'},'Location','best');
