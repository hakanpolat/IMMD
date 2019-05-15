time = 110:10:210;
% 3. kademe data
GaN_inside  = [28.1,27.9,27.5,27.5,27.3,27.3,27.3,27.3,27.2,27.3,27.5];
Res_inside  = [28.2,28.2,27.9,28.0,27.8,28.0,27.7,27.5,27.4,27.6,27.6];
GaN_surface = [28.7,28.0,27.9,27.8,27.5,27.5,26.4,27.7,27.5,27.8,28.0];
Res_surface = [27.8,27.8,27.7,27.5,27.1,27.6,26.6,27.8,27.2,27.6,27.5];
GaN_top     = [28.7,28.2,28.0,27.5,28.0,27.3,27.2,27.3,27.5,27.1,27.2];
Res_top     = [27.8,27.8,27.6,27.0,27.6,27.1,27.5,27.0,27.1,26.8,26.7];
GaN_hottest = [30.4,29.4,29.4,28.7,29.5,29.2,29.0,28.4,29.0,28.9,28.9];
Res_hottest = [29.2,29.0,28.9,28.0,28.5,28.5,28.5,28.4,28.4,28.5,28.1];
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
xlim([110 210]);
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
xlim([110 210]);
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
xlim([110 210]);
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
xlim([110 210]);
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
xlim([110 210]);
legend({'Surface','Hottest','Top','Threshold'},'Location','best');
%%
power1 = 13.1;
power2 = 11.5;
power_curve = [15.4;
               power1*ones(7,1);...
               power2*ones(3,1)];

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
ylim([10 15]);
ylabel('Power input (W)','FontSize',14,'FontWeight','Bold')
xlabel('Time (minutes)','FontSize',14,'FontWeight','Bold')
set(gca,'FontSize',14);
xlim([110 210]);
legend({'Surface','Top','Threshold','Res Power'},'Location','best');
