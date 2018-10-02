function [TopV,BotV]= PulseTimer(timeArray,fsw,SampleTime)
VpulseMax = 6;
VpulseMin = -3;
Dtop = 49; % duty cycle of top
Dbot = 49; % duty cycle of bot
DelayTop = 50;
DelayBot = 50;

[~,n] = size(timeArray);
TopV = zeros(size(timeArray));
BotV = zeros(size(timeArray));

for time = 1:n
    PseudoTime = mod(SampleTime*time,1/fsw); 
    if (PseudoTime >= 0 && PseudoTime < (Dbot/100)/fsw) %bottom on top off dead time öncesi
        TopV(time) = VpulseMin;
        BotV(time) = VpulseMax;
    elseif (PseudoTime >= ((Dbot/100)/fsw) && PseudoTime < ((1-DelayBot/100)/fsw))%bottom off oldu top off zaten dead time
        TopV(time) = VpulseMin;
        BotV(time) = VpulseMin;
    elseif PseudoTime >= ((DelayTop/100)/fsw) && PseudoTime < ((0.5 + Dtop/100)/fsw) %top on bottom off dead time öncesi
        TopV(time) = VpulseMax;
        BotV(time) = VpulseMin;
    else
        TopV(time) = VpulseMin;
        BotV(time) = VpulseMin; 
    end
end