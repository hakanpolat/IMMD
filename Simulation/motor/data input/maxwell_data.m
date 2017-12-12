b = xlsread('akim.xlsx','akim','A3:A10');
a = [
0,0,0,0
0.01,0.275447948168559,-0.142054876749035,-0.133393071419524
0.02,0.54682236938209,-0.279517960867084,-0.267304408515006
0.03,0.815385609907236,-0.413610119042799,-0.401775490864437
0.04,1.08125486324198,-0.545184857793767,-0.536070005448212
0.05,1.34480905768689,-0.675091280635177,-0.669717777051718
0.06,1.60676741741085,-0.803410406110654,-0.803357011300197
0.07,1.86709121023381,-0.930172338544287,-0.936918871689525
];
c = xlsread('deneme.xlsx','Sheet1','A3:A10');

%%
%xlRange = 'A3:A10';
%sheet = 'akim';
%filename = 'akim.xlsx';
%A = str2num(cell2mat(importdata(filename,sheet,xlRange)))

impdata = importdata('deneme.xlsx');
mydata = impdata(2:3,1);
celldata = cell2mat(mydata);
sondata = str2num(celldata);

%%
timea = mydata3(:,1)/1000;
torq = mydata3(:,2);
figure;
plot(timea,torq,'b-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Motor output torque (Nm)','FontSize',12,'FontWeight','Bold')
xlim([0.09 0.1])
ylim([100 130])

%%
timea = mydata(:,1)/1000;
cura = mydata(:,2)/2;
curb = mydata(:,3)/2;
curc = mydata(:,4)/2;
figure;
plot(timea,cura,'b-','Linewidth',2);
hold on;
plot(timea,curb,'r-','Linewidth',2);
hold on;
plot(timea,curc,'k-','Linewidth',2);
hold off;
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Motor line currents (A)','FontSize',12,'FontWeight','Bold')
legend('Phase-A','Phase-B','Phase-C');
xlim([0.08 0.1])
%ylim([-20 30])

%%
timea = mydata2(:,1)/1000;
indvol = mydata2(:,2)/2;
figure;
plot(timea,indvol,'b-','Linewidth',2);
grid on;
set(gca,'FontSize',12);
xlabel('Time (s)','FontSize',12,'FontWeight','Bold')
ylabel('Motor phase induced voltage (V)','FontSize',12,'FontWeight','Bold')
xlim([0.08 0.1])
%ylim([-20 30])
