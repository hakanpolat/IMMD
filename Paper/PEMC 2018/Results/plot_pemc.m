%%
timea = 0:Sampling_time:stop_time;
figure;
plot(timea,voltec,'b -','Linewidth',1.5);
% hold on
% plot(ar_xaxis,ar_np_miron(2,:),'k -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(3,:),'r -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(4,:),'g -','Linewidth',3);
% hold off;
%grid on;
set(gca,'FontSize',14);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
%legend('1 parallel','2 parallel','3 parallel','4 parallel');
%title('w = 2, ns = 2');
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([0.297 0.317]);

figure;
plot(timea,akim,'b -','Linewidth',1.5);
% hold on
% plot(ar_xaxis,ar_np_miron(2,:),'k -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(3,:),'r -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(4,:),'g -','Linewidth',3);
% hold off;
%grid on;
set(gca,'FontSize',14);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
%legend('1 parallel','2 parallel','3 parallel','4 parallel');
%title('w = 2, ns = 2');
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',14,'FontWeight','Bold')
xlim([0.3 0.32]);

%%
%%
timea = 0:Sampling_time:stop_time;
figure;
plot(timea,Vdc_total,'b -','Linewidth',1.5);
% hold on
% plot(ar_xaxis,ar_np_miron(2,:),'k -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(3,:),'r -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(4,:),'g -','Linewidth',3);
% hold off;
%grid on;
set(gca,'FontSize',14);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
%legend('1 parallel','2 parallel','3 parallel','4 parallel');
%title('w = 2, ns = 2');
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('Voltage (Volts)','FontSize',14,'FontWeight','Bold')
xlim([0.297 0.317]);

figure;
plot(timea,Idc_total,'b -','Linewidth',1.5);
% hold on
% plot(ar_xaxis,ar_np_miron(2,:),'k -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(3,:),'r -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(4,:),'g -','Linewidth',3);
% hold off;
%grid on;
set(gca,'FontSize',14);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
%legend('1 parallel','2 parallel','3 parallel','4 parallel');
%title('w = 2, ns = 2');
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',14,'FontWeight','Bold')
xlim([0.3 0.32]);

%%
timea = 0:Sampling_time:stop_time;
figure;
plot(timea,DCLINK_current,'b -','Linewidth',1.5);
% hold on
% plot(ar_xaxis,ar_np_miron(2,:),'k -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(3,:),'r -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(4,:),'g -','Linewidth',3);
% hold off;
%grid on;
set(gca,'FontSize',14);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
%legend('1 parallel','2 parallel','3 parallel','4 parallel');
%title('w = 2, ns = 2');
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',14,'FontWeight','Bold')
xlim([0.3 0.32]);

%%
figure;
plot(timea,DCLINK_voltage,'b -','Linewidth',1.5);
% hold on
% plot(ar_xaxis,ar_np_miron(2,:),'k -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(3,:),'r -','Linewidth',3);
% hold on;
% plot(ar_xaxis,ar_np_miron(4,:),'g -','Linewidth',3);
% hold off;
%grid on;
set(gca,'FontSize',14);
%legend('Qs=12','Qs=18','Qs=24','Qs=30','Qs=36','Qs=42','Qs=48');
%legend('1 parallel','2 parallel','3 parallel','4 parallel');
%title('w = 2, ns = 2');
xlabel('Time (s)','FontSize',14,'FontWeight','Bold')
ylabel('Current (Amps)','FontSize',14,'FontWeight','Bold')
xlim([0.48 0.5]);
ylim([538.5 541.5])