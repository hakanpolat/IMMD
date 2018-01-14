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
yaxis1(k) = param(1,16,k);
yaxis2(k) = param(2,16,k);
yaxis3(k) = param(3,16,(k));
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

