function carriervalue = carriergen(currenttime, Vmax, Vmin, fsw, phase)

%Vmax = 1; Vmin = -1;
%phase = [0 50 90 180 230 360]';
%currenttime = 440e-6;
timeshift = phase/(360*fsw);
times = timeshift+currenttime;
Vstep = 2*fsw*(Vmax-Vmin);
direction = rem(ceil(2*times*fsw),2);
timeinsector = rem(times,1/(2*fsw));

for k = 1:numel(timeinsector)
    if timeinsector(k) == 0
        timeinsector(k) = 1/(2*fsw);
    end
end
if direction == 1
    carriervalue = Vmin + Vstep*timeinsector;
else
    carriervalue = Vmax - Vstep*timeinsector;
end

end

