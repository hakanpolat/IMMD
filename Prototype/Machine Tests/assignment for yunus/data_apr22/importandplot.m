clc; close all; clear all;

va = load('C1load30000000.dat');
vb = load('C2load30000000.dat');
vc = load('C3load30000000.dat');
ia = load('C4load30000003.dat');
ib = load('C4load30000001.dat');
ic = load('C4load30000002.dat');

va = va(1:199951,:);
time = va(:,1);

figure;
yyaxis left
plot(time,va(:,2),'r--','LineWidth',1);
hold on;
plot(time,vb(:,2),'k--','LineWidth',1);
hold on;
plot(time,vc(:,2),'b--','LineWidth',1);
hold on;
ylabel('Voltage (V)');
ylim([-150 150]);
yyaxis right
plot(time,ia(:,2),'r-','LineWidth',2);
hold on;
plot(time,ib(:,2),'k-','LineWidth',2);
hold on;
plot(time,ic(:,2),'b-','LineWidth',2);
grid minor;
legend('V_a','V_b','V_c','I_a','I_b','I_c');
xlabel('Time (s)');
ylabel('Current (A)');
ylim([-15 15]);
title('2 Modules Half-Loaded');

m1 = va(:,2);
m2 = vb(:,2);
m3 = vc(:,2);
m4 = ia(:,2);
m5 = ib(:,2);
m6 = ic(:,2);

time = time - time(1);

rms1 = rms(m1);
rms2 = rms(m2);
rms3 = rms(m3);
rms4 = rms(m4);
rms5 = rms(m5);
rms6 = rms(m6);

figure;
harmonik1 = harmonik(va);
figure;
harmonik2 = harmonik(vb);
figure;
harmonik3 = harmonik(vc);
figure;
harmonik4 = harmonik(mod4(1:249992,:));