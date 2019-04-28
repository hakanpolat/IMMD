figure;
hold all;
plot(e007*1e9,VarName2,'b-','Linewidth',1);
plot(e1*1e9,VarName1,'r-','Linewidth',1);
plot(e2*1e9,VarName3,'g-','Linewidth',1);
plot(e3*1e9,VarName4,'k-','Linewidth',1);
plot(e007*1e9,1.7*ones(1,numel(e007)),'m--','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vgs (Volts)','FontSize',12,'FontWeight','Bold')
xlim([1200 1300]);
legend('75V-Nocap','125V-Nocap','75V-Yescap','125V-Yescap','Threshold');
%%
figure;
hold all;
plot(e007*1e9,VarName2,'g-','Linewidth',1);
plot(e1*1e9,VarName1,'k-','Linewidth',1);
plot(e2*1e9,VarName3,'b-','Linewidth',1);
plot(e3*1e9,VarName4,'r-','Linewidth',1);
plot(e4*1e9,VarName5,'m-','Linewidth',1);
plot(e007*1e9,1.7*ones(1,numel(e007)),'k--','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vgs (Volts)','FontSize',12,'FontWeight','Bold')
xlim([1220 1260]);
legend('25V','75V','100V','125V','150V','Threshold');
