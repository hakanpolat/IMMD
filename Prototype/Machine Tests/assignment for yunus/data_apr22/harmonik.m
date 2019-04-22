function answer = harmonik(signal)

Fs = 1/abs(signal(1,1)-signal(2,1)) ;
T = 1/Fs; k = 10;
L = (signal(end,1) - signal(1,1))/T; L = k*L;
time = (0:L-1)*T;
S = signal(:,2);
S = S(1:199950,:);
window = hann(L/k);
Y = fft(S.*window,L);
% Y = fft(S,L);
P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f = Fs*(0:(L/2))/L;

answer = plot(f,P1,'k','LineWidth',1.5);
xlim([0 500]);
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')
grid on;

end