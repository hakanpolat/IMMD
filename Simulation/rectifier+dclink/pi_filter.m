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
figure;
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
%% Vc2/Iin transfer function
R=45;
C1=10e-03;
C2=15e-06;
f=logspace(2,5,100000);
w=2*pi*f;
s=w*i;
figure;
for L=[1e-02 1e-03 1e-04 1e-05]
    t=(R)./((L*R*C1*C2*s.^3)+((C1*L)*s.^2)+((R*C2+R*C1)*s)+1);
    mag=20*log10(abs(t));
    semilogx(f,mag,'LineWidth',2);
    hold on
end
grid on
xlabel('Frequency (Hz)');
ylabel('Magnitude (dB)');
legend('10 mH','1 mH','100 uH','10 uH');
title('Vc2/Iin Magnitude Response of the Filter');

%% Vc1/Iin transfer function
R=45;
C1=10e-03;
C2=15e-06;
f=logspace(-5,9,100000);
w=2*pi*f;
s=w*i;
figure;
for L=[1e-02 1e-03 1e-04 1e-05]
    t=(R*L*C2*s.^2+L*s+R)./((L*R*C1*C2*s.^3)+((C1*L)*s.^2)+((R*C2+R*C1)*s)+1);
    mag=20*log10(abs(t));
    semilogx(f,mag,'LineWidth',2);
    hold on
end
grid on
xlabel('Frequency (Hz)');
ylabel('Magnitude (dB)');
legend('10 mH','1 mH','100 uH','10 uH');
title('Vc1/Iin Magnitude Response of the Filter');

%% Vc1/Iout transfer function
C1=10e-03;
C2=15e-06;
f=logspace(1,6,100000);
w=2*pi*f;
s=w*i;
figure;
for L=[1e-02 1e-03 1e-04 1e-05]
    t=(1)./(L*C1*C2^2*s.^3+s*C1*C2);
    mag=20*log10(abs(t));
    semilogx(f,mag,'LineWidth',2);
    hold on
end
grid on
xlabel('Frequency (Hz)');
ylabel('Magnitude (dB)');
legend('10 mH','1 mH','100 uH','10 uH','10 mH','1 mH','100 uH','10 uH');
title('Vc1/Iout Magnitude Response of the Filter');

%% Vc2/Iout transfer function
C1=10e-03;
C2=15e-06;
f=logspace(0,5,100000);
w=2*pi*f;
s=w*i;
figure;
for L=[1e-02 1e-03 1e-04 1e-05]
    t=(L*C1*s.^2+1)./(L*C1*C2*s.^3+(C1+C2)*s);
    mag=20*log10(abs(t));
    semilogx(f,mag,'LineWidth',2);
    hold on
end
grid on
xlabel('Frequency (Hz)');
ylabel('Magnitude (dB)');
legend('10 mH','1 mH','100 uH','10 uH');
title('Vc2/Iout Magnitude Response of the Filter');
%%
s = tf('s')
C1=10e-03;
C2=15e-06;
L=1e-03;
sys1= ((s^2*L*C1+1)/(s*C1))*((s^2*L*C1*C2+C2)/(s^2*L*C1*C2+C1+C2));
sys = (L^2*C1^2*C2*s^4+2*L*C1*C2*s^2+C2)/(L*C1^2*C2*s^3+(C1^2+C1*C2)*s);