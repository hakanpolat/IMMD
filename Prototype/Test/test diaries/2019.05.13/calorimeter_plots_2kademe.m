time = 210:10:370;
% 3. kademe data
GaN_inside  = [27.5,27.2,26.7,26.8,26.6,26.7,26.8,26.9,26.7,0,0,26.4,26.6,26.5,26.7,26.7,26.7];
Res_inside  = [27.6,27.6,27.1,27.2,27.0,27.1,27.2,26.9,27.2,0,0,26.8,27.1,27.0,27.2,27.1,27.3];
GaN_surface = [28.0,26.5,27.4,27.4,27.2,27.1,27.2,27.3,27.5,0,0,27.2,27.2,27.1,27.1,26.3,26.7];
Res_surface = [27.5,26.1,27.1,26.9,27.0,27.2,27.0,27.5,27.4,0,0,27.4,27.2,26.9,27.2,26.1,26.7];
GaN_top     = [27.2,27.2,27.3,27.3,27.1,27.0,27.1,27.2,27.3,0,0,27.2,27.0,26.9,27.2,26.1,26.6];
Res_top     = [26.7,27.0,27.2,27.2,26.8,26.8,26.8,26.9,27.0,0,0,27.0,26.6,26.3,26.8,26.2,26.4];
GaN_hottest = [28.9,28.9,28.5,28.6,28.5,28.4,28.5,28.5,28.2,0,0,28.5,28.1,28.3,29.0,27.7,28.5];
Res_hottest = [28.1,28.1,28.0,28.0,28.0,28.0,28.0,28.2,27.9,0,0,28.2,28.2,28.2,28.4,27.4,28.2];
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
xlim([210 370]);
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
xlim([210 370]);
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
xlim([210 370]);
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
xlim([210 370]);
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
xlim([210 370]);
legend({'Surface','Hottest','Top','Threshold'},'Location','best');
%%
power1 = 8;
power2 = 8.9;
power3 = 10.2;
power_curve = [11.5;
               power1*ones(8,1);...
               power2*ones(5,1);...
               power3*ones(3,1)];

%%
figure;
hold all;
yyaxis left
plot(time,-diff_surface,'bx-','Linewidth',2);
plot(time,-diff_top,'ko-','Linewidth',2);
plot(time,zeros(1,numel(time)),'g--','Linewidth',2);
ylim([-2 2]);
ylabel('Temperature difference (^\circC)','FontSize',14,'FontWeight','Bold')
yyaxis right
plot(time,power_curve,'r+-','Linewidth',2);
ylim([6 12]);
ylabel('Power input (W)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
xlim([210 370]);
legend({'Surface','Top','Threshold','Res Power'},'Location','best');
