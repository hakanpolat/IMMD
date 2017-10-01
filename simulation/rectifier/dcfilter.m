num = xlsread('lcfiltersimres.xlsx');

%%
ldata = 0:8;
cdata = 0:5;
for k = 1:length(cdata)
    vpp(k,:) = num((k-1)*length(ldata)+1:k*length(ldata),3);
    ipp(k,:) = num((k-1)*length(ldata)+1:k*length(ldata),4);
end

%%
figure;
%plot(ldata,vpp(1,:),'b-o','Linewidth',2);
%hold on;
plot(ldata,vpp(2,:),'r-o','Linewidth',2);
hold on;
plot(ldata,vpp(3,:),'k-o','Linewidth',2);
hold on;
plot(ldata,vpp(4,:),'m-o','Linewidth',2);
hold on;
plot(ldata,vpp(5,:),'g-o','Linewidth',2);
hold on;
plot(ldata,vpp(6,:),'y-o','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Inductance (mH)','FontSize',12,'FontWeight','Bold')
ylabel('Peak to peak DC link voltage ripple (%)','FontSize',12,'FontWeight','Bold')
legend('C=1mF','C=2mF','C=3mF','C=4mF','C=5mF');

%%
figure;
%plot(ldata,ipp(1,:),'b-o','Linewidth',2);
%hold on;
plot(ldata,ipp(2,:),'r-o','Linewidth',2);
hold on;
plot(ldata,ipp(3,:),'k-o','Linewidth',2);
hold on;
plot(ldata,ipp(4,:),'m-o','Linewidth',2);
hold on;
plot(ldata,ipp(5,:),'g-o','Linewidth',2);
hold on;
plot(ldata,ipp(6,:),'y-o','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Inductance (mH)','FontSize',12,'FontWeight','Bold')
ylabel('Peak to peak DC link voltage ripple (%)','FontSize',12,'FontWeight','Bold')
legend('C=1mF','C=2mF','C=3mF','C=4mF','C=5mF');
ylim([0 200])