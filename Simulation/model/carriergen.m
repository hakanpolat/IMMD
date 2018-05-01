function carriervalue = carriergen(currenttime, Vmax, Vmin, Tstep, fsw)

% Vmax = 1;
% Vmin = -1;
% Tstep = 1e-6;
% fsw = 10e3;
% currenttime = 100e-6;

Vstep = 2*fsw*(Vmax-Vmin);
direction = rem(ceil(2*currenttime*fsw),2);
timeinsector = rem(currenttime,1/(2*fsw));
if timeinsector == 0
    timeinsector = 1/(2*fsw);
end

if direction == 1
    carriervalue = Vmin + Vstep*timeinsector;
else
    carriervalue = Vmax - Vstep*timeinsector;
end

end

