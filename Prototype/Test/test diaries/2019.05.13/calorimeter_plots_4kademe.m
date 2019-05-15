time = 0:10:110;
% 4. kademe data
GaN_inside  = [23.9,25.1,26.0,26.6,27.1,27.1,27.4,27.5,27.8,28.0,28.1,28.1];
Res_inside  = [23.6,25.8,26.4,27.0,27.8,27.7,28.2,28.2,29.0,28.6,28.1,28.2];
GaN_surface = [25.4,26.7,27.2,26.4,27.8,28.1,27.8,28.1,28.1,28.2,28.9,28.7];
Res_surface = [25.4,26.0,27.1,25.8,27.7,28.2,27.8,28.4,28.8,27.8,28.2,27.8];
GaN_top     = [25.4,24.9,27.2,26.2,27.8,28.0,26.7,28.2,27.7,28.4,28.6,28.7];
Res_top     = [25.4,25.0,27.4,26.1,27.7,27.7,26.6,28.2,27.8,27.9,28.0,27.8];
GaN_hottest = [25.4,27.5,28.5,28.0,28.1,28.7,29.9,30.0,30.0,30.0,30.0,30.4];
Res_hottest = [25.4,27.2,28.3,27.6,27.5,28.5,29.0,29.2,29.6,30.1,29.0,29.2];
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
ylim([20 35]);
xlim([0 110]);
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
ylim([20 35]);
xlim([0 110]);
legend({'GaN surface','Res surface'},'Location','best');
%%
figure;
%subplot(3,1,1);
hold all;
plot(time,GaN_hottest,'r-','Linewidth',2);
plot(time,Res_hottest,'b-','Linewidth',2);
ylabel('Temperature ($^\circ$C)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
ylim([20 35]);
xlim([0 110]);
legend({'GaN hottest','Res hottest'},'Location','best');
%%
figure;
%subplot(3,1,1);
hold all;
plot(time,GaN_top,'r-','Linewidth',2);
plot(time,Res_top,'b-','Linewidth',2);
ylabel('Temperature ($^\circ$C)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
ylim([20 35]);
xlim([0 110]);
legend({'GaN top','Res top'},'Location','best');
%%
figure;
hold all;
plot(time,diff_surface,'bx-','Linewidth',2);
plot(time,diff_hottest,'k+-','Linewidth',2);
plot(time,diff_top,'ro-','Linewidth',2);
plot(time,zeros(1,numel(time)),'g--','Linewidth',2);
ylabel('Temperature Difference (^\circC)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
ylim([-2 2]);
xlim([0 110]);
legend({'Surface','Hottest','Top','Threshold'},'Location','best');
%%
power1 = 17.5;
power2 = 19.4;
power3 = 15.4;
power_curve = [0;
               power1*ones(5,1);...
               power2*ones(3,1);...
               power3*ones(3,1)];

%%
figure;
hold all;
yyaxis left
plot(time,-diff_surface,'bx-','Linewidth',2);
plot(time,-diff_top,'ko-','Linewidth',2);
plot(time,zeros(1,numel(time)),'g--','Linewidth',2);
ylim([-2.5 2.5]);
ylabel('Temperature difference (^\circC)','FontSize',14,'FontWeight','Bold')
yyaxis right
plot(time,power_curve,'r+-','Linewidth',2);
ylim([13 22]);
ylabel('Power input (W)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
xlim([0 110]);
legend({'Surface','Top','Threshold','Res Power'},'Location','best');

%%
power_modify1 = (power_curve'-15);
power_modify2 = (power_curve'-16);
power_modify3 = (power_curve'-17);
power_modify4 = (power_curve'-18);
power_modify5 = (power_curve'-19);
power_modify6 = (power_curve'-20);
figure;
hold all;
plot(time,-diff_surface./power_modify1,'bx-','Linewidth',2);
plot(time,-diff_surface./power_modify2,'ro-','Linewidth',2);
plot(time,-diff_surface./power_modify3,'k+-','Linewidth',2);
plot(time,-diff_surface./power_modify4,'g^-','Linewidth',2);
plot(time,-diff_surface./power_modify5,'m--','Linewidth',2);
plot(time,-diff_surface./power_modify6,'c--','Linewidth',2);
%ylim([-2.5 2.5]);
ylabel('Power input (W)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
xlim([0 110]);
legend({'15W','16W','17W','18W','19W','20W'},'Location','best');


