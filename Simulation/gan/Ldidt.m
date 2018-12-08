fileID = fopen('data.txt','r');
formatSpec = '%f %f\n';
A = fscanf(fileID,formatSpec);
fclose(fileID);

fileID = fopen('data2.txt','r');
B = fscanf(fileID,formatSpec);
fclose(fileID);

fileID = fopen('data3.txt','r');
C = fscanf(fileID,formatSpec);
fclose(fileID);

fileID = fopen('data4.txt','r');
D = fscanf(fileID,formatSpec);
fclose(fileID);

for k = 1:numel(A)/2
   time(k) = A(k*2-1);
   current(k) = A(k*2);
   voltage(k) = B(k*2);
   Vdsbot(k) = C(k*2);
   cekilen(k) = D(k*2);
end

Vdc = 220;
Lloop = 40e-9;
didt = diff(current)./diff(time);
didt(numel(current)) = 0;
Vdstop = Vdc - Vdsbot - Lloop*didt; 

%%
figure;
hold all;
plot(time,current,'b-','Linewidth',1);
plot(time,didt*1e-9,'k-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Signal','FontSize',12,'FontWeight','Bold')
xlim([0.401e-4 0.4015e-4]);


%%
figure;
hold all;
plot(time,voltage,'r-','Linewidth',1);
plot(time,Vdstop,'b-','Linewidth',1);
plot(time,cekilen,'k-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Signal','FontSize',12,'FontWeight','Bold')
xlim([0.401e-4 0.4015e-4]);
legend('Actual Vds','Calculated on MATLAB','Calculated on LTSpice');

%%
figure;
hold all;
plot(current,'b-','Linewidth',1);
plot(diff(time)*1e10,'k-','Linewidth',1);
grid on;
set(gca,'FontSize',12);
%xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
%ylabel('Signal','FontSize',12,'FontWeight','Bold')
xlim([2.44*1e4 2.46*1e4]);

