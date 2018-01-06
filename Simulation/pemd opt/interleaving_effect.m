module = 1:8;
percmin = [53,35,21,16,11,11,10,10];

%expfit(percmin)

degfit = 5;
P = polyfit(module,percmin,degfit);
curfcn = zeros(1,numel(module));
for k = 1:degfit+1
    curfcn = P(k)*module.^(degfit+1-k)+curfcn;
end

figure;
plot(module,percmin,'bo-','Linewidth',1.5);
hold on;
plot(module,curfcn,'ro-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Number of nodules','FontSize',12,'FontWeight','Bold')
ylabel('Minimum ripple rms current (% of DC)','FontSize',12,'FontWeight','Bold')
ylim([0,60]);
legend('Actual','Estimated');

curfcn2 = curfcn/curfcn(1);
percmin2 = percmin/percmin(1);
figure;
plot(module,percmin2,'bo-','Linewidth',1.5);
hold on;
plot(module,curfcn2,'ro-','Linewidth',1.5);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Number of nodules','FontSize',12,'FontWeight','Bold')
ylabel('Minimum ripple rms current (% of DC)','FontSize',12,'FontWeight','Bold')
ylim([0,1.1]);
legend('Actual','Estimated');