%% 
%classic bode plot
R=45;
C=15e-06;
s=tf('s');
for L=[1e-02 1e-03 1e-04 1e-05]
    sys= tf(R/(R*L*C*s^2+s*L+R));
    bode(sys);
    hold on
end
legend('10 mH','1 mH','100 uH','10 uH');
grid on
hold off
%%
%bode without input impedance
R=45;
C=15e-06;
f=linspace(100,100000,100000);
w=2*pi*f;
%L=1e-03;
for L=[1e-02 1e-03 1e-04 1e-05]
    t=R./(R*L*C*(w*i).^2+w*i*L+R);
    mag=20*log10(abs(t));
    semilogx(f,mag,'LineWidth',2);
    hold on
end
grid on
xlabel('Frequency (Hz)');
ylabel('Magnitude (dB)');
legend('10 mH','1 mH','100 uH','10 uH');
title('Magnitude Response of the Filter');
% t=R./(R*L*C*(w*i).^2+w*i*L+R);
% mag=20*log10(abs(t));
% 
% semilogx(w,mag);
% grid on
% xlabel('Frequency (rad/s)');
% ylabel('Magnitude (dB)');
%%
%bode with input impedance
R=45;
r=50e-03;
C1=10e-03;
C2=15e-06;
f=linspace(100,100000,100000);
w=2*pi*f;
s=w*i;
for L=[1e-02 1e-03 1e-04 1e-05]
    t=(R)./((L*R*r*C1*C2*s.^3)+((R*C2*L+r*C1*L)*s.^2)+((R*r*C2+L+R*r*C1)*s+(r+R)));
    mag=20*log10(abs(t));
    semilogx(f,mag,'LineWidth',2);
    hold on
end
grid on
xlabel('Frequency (Hz)');
ylabel('Magnitude (dB)');
legend('10 mH','1 mH','100 uH','10 uH');
title('Magnitude Response of the Filter');
