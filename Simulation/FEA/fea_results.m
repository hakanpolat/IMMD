num = xlsread('torque_varied.xlsx');

time_axis(1,:) = double(num(2:end,1));
offset = 15:5:75;
for k = 1:numel(offset)
    torque(k,:) = num(2:end,k+1);
end

for k = 1:numel(offset)
    max_value(k) = max(torque(k,4800:5000));
    min_value(k) = min(torque(k,4800:5000));
    ripple(k) = max_value(k) - min_value(k);
end

figure;
plot(offset,ripple,'b-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Offset (mm)','FontSize',12,'FontWeight','Bold')
ylabel('Torque Ripple (Nm)','FontSize',12,'FontWeight','Bold')
%legend('15mm','20mm','25mm','30mm','35mm','40mm','45mm','50mm');
%xlim([48 50])
%ylim([-20 30])


%%
clear all;
num = xlsread('cogging_torque_varied_offset.xlsx');
time_axis(1,:) = double(num(2:end,1));
offset = 0:5:70;
for k = 1:numel(offset)
    cogging_torque(k,:) = num(2:end,k+1);
end

%%
figure;
plot(time_axis,cogging_torque(1,:),'b-','Linewidth',2);
hold all;
% plot(time_axis,torque(9,:),'r-','Linewidth',2);
% plot(time_axis,torque(11,:),'k-','Linewidth',2);
% plot(time_axis,torque(10,:),'g-','Linewidth',2);
% plot(time_axis,torque(13,:),'m-','Linewidth',2);
% plot(time_axis,torque(12,:),'y-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ms)','FontSize',12,'FontWeight','Bold')
ylabel('Motor Torque (Nm)','FontSize',12,'FontWeight','Bold')
legend('15mm','20mm','25mm','30mm','35mm','40mm','45mm','50mm');
%xlim([48 50])
%ylim([-20 30])
