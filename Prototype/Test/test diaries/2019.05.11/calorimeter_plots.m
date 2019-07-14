time = 15:15:285;
time_top = 150:15:285;
time_hottest = 60:15:285;
GaN_inside = [27.3,27.7,27.7,27.5,27.5,27.2,27.5,27.5,27.5,27.9,27.7,27.8,27.6,27.6,27.4,27.5,27.2,27.5,27.3];
Res_inside = [27.8,28.5,28.3,28.3,28.6,28.0,28.1,28.8,28.6,28.4,28.3,28.2,28.5,28.5,28.7,28.2,28.1,28.1,28.0];
GaN_surface = [26.4,27.2,27.2,27.4,25.6,27.2,27.0,26.7,27.0,26.9,27.3,26.9,27.3,27.4,27.1,27.2,26.9,27.3,25.7];
Res_surface = [27.0,27.2,27.2,27.4,25.6,26.2,27.0,27.2,27.9,27.4,27.8,27.6,27.4,27.3,27.6,26.8,25.9,26.8,25.4];
GaN_top = [26.6,26.7,25.8,27.0,26.9,26.4,25.7,25.5,27.0,26.0];
Res_top = [27.1,27.2,26.2,27.2,26.9,26.8,25.3,25.5,26.6,25.5];
GaN_hottest = [27.5,28.6,28.9,28.5,28.7,28.7,29.2,29.2,29.7,29.2,29.7,29.7,29.2,29.3,29.6,28.0];
Res_hottest = [27.6,28.0,27.5,27.9,28.4,28.6,29.1,29.3,29.4,28.7,28.8,29.3,28.6,28.2,28.8,26.9];

diff_inside = GaN_inside - Res_inside;
diff_surface = GaN_surface - Res_surface;
diff_top = GaN_top - Res_top;
diff_hottest = GaN_hottest - Res_hottest;

%%
figure;
%subplot(3,1,1);
hold all;
plot(time,GaN_inside,'r-','Linewidth',2);
plot(time,Res_inside,'b-','Linewidth',2);
ylabel('Temperature ($^\circ$C)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
ylim([20 30]);
xlim([0 300]);
legend({'GaN inside','Res inside'},'Location','best');
%%
figure;
%subplot(3,1,1);
hold all;
plot(time,GaN_surface,'r-','Linewidth',2);
plot(time,Res_surface,'b-','Linewidth',2);
ylabel('Temperature ($^\circ$C)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
ylim([20 30]);
xlim([0 300]);
legend({'GaN surface','Res surface'},'Location','best');
%%
figure;
%subplot(3,1,1);
hold all;
plot(time_hottest,GaN_hottest,'r-','Linewidth',2);
plot(time_hottest,Res_hottest,'b-','Linewidth',2);
ylabel('Temperature ($^\circ$C)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
ylim([20 30]);
xlim([0 300]);
legend({'GaN hottest','Res hottest'},'Location','best');
%%
figure;
%subplot(3,1,1);
hold all;
plot(time_top,GaN_top,'r-','Linewidth',2);
plot(time_top,Res_top,'b-','Linewidth',2);
ylabel('Temperature ($^\circ$C)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
ylim([20 30]);
xlim([0 300]);
legend({'GaN top','Res top'},'Location','best');
%%
figure;
%subplot(3,1,1);
hold all;
%plot(time,diff_inside,'ro-','Linewidth',2);
plot(time,diff_surface,'bx-','Linewidth',2);
plot(time_hottest,diff_hottest,'k+-','Linewidth',2);
plot(time_top,diff_top,'ro-','Linewidth',2);
plot(time,zeros(1,numel(time)),'g--','Linewidth',2);
%grid on;
ylabel('Temperature Difference (^\circC)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
ylim([-2.5 2.5]);
xlim([0 300]);
legend({'Surface','Hottest','Top','Threshold'},'Location','best');
%%
power1 = 26.22;
power2 = 30.26;
power3 = 27.80;
power4 = 24.60;
power_curve = [power1*ones(7,1);...
               power2*ones(4,1);...
               power3*ones(4,1);...
               power4*ones(4,1)];

%%
figure;
hold all;
yyaxis left
plot(time,-diff_surface,'bx-','Linewidth',2);
plot(time_top,-diff_top,'ko-','Linewidth',2);
%plot(time,zeros(1,numel(time)),'g--','Linewidth',2);
ylim([-2.5 2.5]);
ylabel('Temperature difference (^\circC)','FontSize',14,'FontWeight','Bold')
yyaxis right
plot(time,power_curve,'r+-','Linewidth',2);
ylim([20 34]);
ylabel('Power input (W)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
xlim([0 300]);
legend({'Temperature difference in box front surfaces',...
    'Temperature difference in box top surfaces',...
    'Resistance Power Input'},'Location','best');

%%
power_modify1 = (power_curve'-24)
power_modify2 = (power_curve'-25)
power_modify3 = (power_curve'-26)
power_modify4 = (power_curve'-27)
power_modify5 = (power_curve'-28)
figure;
hold all;
plot(time,-diff_surface./power_modify1,'bx-','Linewidth',2);
plot(time,-diff_surface./power_modify2,'ro-','Linewidth',2);
plot(time,-diff_surface./power_modify3,'k+-','Linewidth',2);
plot(time,-diff_surface./power_modify4,'g^-','Linewidth',2);
plot(time,-diff_surface./power_modify5,'m--','Linewidth',2);
%ylim([-2.5 2.5]);
ylabel('Power input (W)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
xlim([0 300]);
legend({'24W','25W','26W','27W','28W'},'Location','best');


%%

% Konferans: 
% https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=5544503
% https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=6699623
% https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=6634469
% https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=6185790
% https://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=8170556
% 
