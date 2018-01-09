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
%title('2 series modules');