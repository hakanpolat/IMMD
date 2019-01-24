timeaxis1 = e008;
Vds1 = VarName2;
timeaxis2 = e1;
Vds2 = VarName1;
timeaxis3 = e2;
Vds3 = VarName3;
timeaxis4 = e3;
Vds4 = VarName4;

% Vds1: 250V, 8.4A, Top, Turn-off
% Vds2: 275V, 9.4A, Top, Turn-off
% Vds3: 275V, 11.5A, Bottom, Turn-off
% Vds4: 300V, 12.6A, Bottom, Turn-off


%%
figure;
hold all;
plot(timeaxis1*1e9,Vds1,'r-','Linewidth',2);
%plot(timeaxis2*1e9,Vds2,'r-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vds (Volts)','FontSize',12,'FontWeight','Bold')
xlim([-20 100]);
ylim([-50 500]);
% legend('250V, 8.4A, Top, Turn-off','275V, 9.4A, Top, Turn-off');


%%
figure;
hold all;
plot(timeaxis3*1e9,Vds3,'k-','Linewidth',2);
plot(timeaxis4*1e9,Vds4,'r-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vds (Volts)','FontSize',12,'FontWeight','Bold')
xlim([-20 100]);
ylim([-50 500]);
legend('275V, 11.5A, Bottom, Turn-off','300V, 12.6A, Bottom, Turn-off');

%%
figure;
hold all;
plot(timeaxis3*1e9,Vds3,'k-','Linewidth',2);
plot(timeaxis2*1e9,Vds2,'r-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (ns)','FontSize',12,'FontWeight','Bold')
ylabel('Vds (Volts)','FontSize',12,'FontWeight','Bold')
xlim([-20 100]);
ylim([-50 500]);
legend('275V, 11.5A, Bottom, Turn-off','275V, 9.4A, Top, Turn-off');


%%
% DPT data excel

mydata = [
25	35.82	34.3	4.24	0.66	40.4	50.1	59.3	14	2.45	7.71	3.76	2.054347826
50	79.1	74.9	5.31	1.78	87.2	106	127	14	5.50	7.24	3.82	1.895238095
75	101.7	92.85	8.70	1.28	139.3	167	200	14	8.93	6.80	3.70	1.839393939
100	126.8	118	6.94	1.29	192.6	227	274	14	12.43	6.55	3.78	1.731914894
125	159.5	137	14.11	0.86	250.8	275	332	14	14.79	5.49	3.86	1.424561404
150	189.4	205	-8.24	3.93	298.5	324	391	14	17.21	5.37	3.89	1.380597015
175	209.5	234	-11.69	4.21	328.9	373	449	14	19.57	6.14	3.88	1.580263158
200	231.6	254	-9.67	3.86	342.9	416	500	14	21.43	7.33	3.92	1.870238095
225	251.8	265	-5.24	2.86	354.1	454	533	14	22.00	8.13	3.59	2.264556962
250	275.3	270	1.93	1.43	371.6	489	584	14	23.86	8.90	3.98	2.235789474
275	298	299	-0.34	1.71	385.1	517	614	14	24.21	9.45	4.01	2.359793814
];

mydata2 = [ 
1.50	44.2	63.3	40.4
2.8	93	70.4	87.2
4	153	88	139.3
5	209	100	192.6
6	263	111	250.8
6.9	311	116	298.5
7.6	350	119	328.9
8.8	376	122	342.9
9.8	379	125	354.1
10.5	385	132	371.6
11.5	401	135	385.1
];

% mydata3 = [
% 60   62.5 1.9 62.7
% 84.3 83
% 95   107
% 97.3 117.6
% 106  122
% 119  122
% 142  139
% 147  139
% 155  147
% ];

Lloop = 14; % nH

Vdc = mydata(:,1);
Vds_top_measure = mydata(:,2);
Vds_top_sim = mydata(:,3);

Vds_bottom_measure1 = mydata(:,6);
Vds_bottom_sim_out = mydata(:,7);
Vds_bottom_sim_in = mydata(:,8);

Iload2 = mydata2(:,1);

Vds_bottom_measure2 = mydata2(:,2);

%%
figure;
hold all;
plot(Vdc,Vds_top_measure,'ko-','Linewidth',2);
plot(Vdc,Vds_top_sim,'ro-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('DC Link Voltage (Volts)','FontSize',12,'FontWeight','Bold')
ylabel('Vds peak (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 300]);
ylim([0 400]);
legend('Top-Measurement','Top-simulation');

%%
figure;
hold all;
plot(Vdc,Vds_bottom_measure1,'ko-','Linewidth',2);
plot(Vdc,Vds_bottom_measure2,'mo-','Linewidth',2);
plot(Vdc,Vds_bottom_sim_out,'ro-','Linewidth',2);
plot(Vdc,Vds_bottom_sim_in,'bo-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('DC Link Voltage (Volts)','FontSize',12,'FontWeight','Bold')
ylabel('Vds peak (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 300]);
ylim([0 700]);
legend('Bottom-Measurement (uzak)','Bottom-Measurement (yakin)',...
    'Bottom-simulation (uzak)','Bottom-simulation (Vds)');

%%
figure;
hold all;
plot(Vdc,Vds_bottom_measure1,'ko-','Linewidth',2);
plot(Vdc,Vds_bottom_measure2,'bo-','Linewidth',2);
plot(Vdc,Vds_top_measure,'ro-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('DC Link Voltage (Volts)','FontSize',12,'FontWeight','Bold')
ylabel('Vds peak (Volts)','FontSize',12,'FontWeight','Bold')
xlim([0 300]);
ylim([0 500]);
legend('Bottom-Measurement (uzak)','Bottom-Measurement (yakin)',...
    'Top-measurement');
