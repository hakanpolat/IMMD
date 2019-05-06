%% Ploss vs Tempfplot = figure;
bar(Pout*1e-3,Ploss,'stacked','BarWidth',0.6);
ylim([0 20]);
xlim([0.2 2.2]);
ax = gca;
set(findobj(gcf,'type','axes'),'FontName','Arial','FontSize',12,'LineWidth', 1);
ax.XTick = [0 0.4 0.8 1.2 1.6 2];
ax.YTick = [0 4 8 12 16 20];
legend('Conduction Loss','Switching Loss','Location','northwest')
xlabel('Output Power (kW)','FontSize',12);
ylabel('Transistor Loss (W)','FontSize',12);