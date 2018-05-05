function carriervalue = carriergen(currenttime, Vmax, Vmin, fsw, phase)
%clc
%fsw = 1e3;
%Vmax = 1; Vmin = -1;
%phase = [0 50 90 180 230 360]';
%phase = [0 90]';

Vstep = 2*fsw*(Vmax-Vmin);
numphase = numel(phase);
carriervalue = zeros(1,numphase);
for k = 1:numphase
    times = currenttime - phase(k)/(360*fsw);
    direction = rem(ceil(2*times*fsw),2);
    timeinsector = rem(times,1/(2*fsw));
    if timeinsector == 0
        timeinsector = 1/(2*fsw);
    elseif timeinsector < 0
        timeinsector = 1/(2*fsw)+timeinsector;
    end
    if direction == 1
        carriervalue(k) = Vmin + Vstep*timeinsector;
    elseif direction == 0
        carriervalue(k) = Vmax - Vstep*timeinsector;
    else
        carriervalue(k) = Vmin + Vstep*timeinsector;
    end
end

%timeshift = phase/(360*fsw);
%times = currenttime*ones(1,numphase)-timeshift;
%direction = rem(ceil(2*times*fsw),2);
%timeinsector = rem(times,1/(2*fsw));
%carriervalue = zeros(1,numphase);
% for k = 1:numel(timeinsector)
%     if timeinsector(k) == 0
%         timeinsector(k) = 1/(2*fsw);
%     elseif timeinsector(k) < 0
%         timeinsector(k) = 1/(2*fsw)+timeinsector(k);
%     end
% end
% for k = 1:numphase
%     if direction(k) == 1
%         carriervalue(k) = Vmin + Vstep*timeinsector(k);
%     else
%         carriervalue(k) = Vmax - Vstep*timeinsector(k);
%     end
% end
%carriervalue
end

