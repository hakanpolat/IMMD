%% Numerical data

Vdc = 25:25:275;

%% Phase A

phA_loadB_bot = [
40.4
87.2
139.3
192.6
250.8
298.5
328.9
342.9
354.1
371.6
385.1 ];

phA_loadB_top = [
35.82
79.1
101.7
126.8
159.5
189.4
209.5
231.6
251.8
275.3
298 ];

phA_loadT_bot = [
33.6
64.6
95.9
120
152
185
209
232
253
278
300 ];

phA_loadT_top = [
41.6
82.6
143.5
207
255
288
311
325
343
353
362 ];


figure;
hold all;
plot(Vdc,phA_loadB_bot,'ko-','Linewidth',2);
plot(Vdc,phA_loadB_top,'bo-','Linewidth',2);
plot(Vdc,phA_loadT_bot,'ro-','Linewidth',2);
plot(Vdc,phA_loadT_top,'mo-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('DC Link Voltage (Volts)','FontSize',12,'FontWeight','Bold')
ylabel('Vds peak (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 300]);
ylim([0 500]);
legend('Phase A, Load on Bottom, Bottom switch',...
    'Phase A, Load on Bottom, Top switch',...
    'Phase A, Load on Top, Bottom switch',...
    'Phase A, Load on Top, Top switch');

%% Phase B

phB_loadB_bot = [
44.20
89.50
150.50
212.00
260%
317.00
358%
384.00
391.00
398.00
413.00 ];


phB_loadB_top = [
42%
62.50
98%
121.00
154%
183.00
207%
230.00
255%
283.00
303.00 ];


phB_loadT_bot = [
31%
62.90
97%
123.70
150%
179.20
205%
229.10
250%
273.00
302.00 ];


phB_loadT_top = [
42%
85.70
146%
200.00
260%
300.00
335%
371.00
400%
425.00
436.00 ];

figure;
hold all;
plot(Vdc,phB_loadB_bot,'ko-','Linewidth',2);
plot(Vdc,phB_loadB_top,'bo-','Linewidth',2);
plot(Vdc,phB_loadT_bot,'ro-','Linewidth',2);
plot(Vdc,phB_loadT_top,'mo-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('DC Link Voltage (Volts)','FontSize',12,'FontWeight','Bold')
ylabel('Vds peak (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 300]);
ylim([0 500]);
legend('Phase B, Load on Bottom, Bottom switch',...
    'Phase B, Load on Bottom, Top switch',...
    'Phase B, Load on Top, Bottom switch',...
    'Phase B, Load on Top, Top switch');


%% Phase C

Vdc2 = 25:25:200;

phC_loadT_top = [
40.50
81.00
137%
195.50
252%
293.00
318%
338.00 ];

figure;
hold all;
plot(Vdc2,phC_loadT_top,'ko-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('DC Link Voltage (Volts)','FontSize',12,'FontWeight','Bold')
ylabel('Vds peak (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 300]);
ylim([0 500]);
legend('Phase C, Load on Top, Top switch');


%% Altogether

figure;
hold all;
plot(Vdc,phA_loadB_bot,'ro-','Linewidth',2);
%plot(Vdc,phA_loadT_top,'bo-','Linewidth',2);
plot(Vdc,phB_loadB_bot,'kx-','Linewidth',2);
%plot(Vdc,phB_loadT_top,'mx-','Linewidth',2);
%plot(Vdc2,phC_loadT_top,'g+-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('DC Link Voltage (Volts)','FontSize',12,'FontWeight','Bold')
ylabel('Vds peak (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 300]);
ylim([0 500]);
% legend('Phase A, Load on Bottom, Bottom switch',...
%     'Phase A, Load on Top, Top switch',...
%     'Phase B, Load on Bottom, Bottom switch',...
%     'Phase B, Load on Top, Top switch',...
%     'Phase C, Load on Top, Top switch');
legend('Phase A', 'Phase B');



