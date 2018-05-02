function [RMS,Phase] = fundamentalcomp(FunctionHarmonic, Ts, fout)

WindowCycle = 1;
SampleInWindow = WindowCycle/(Ts*fout);
FourierSeriesAk = 0;
FourierSeriesBk = 0;
FourierSeriesAo = 0;
for k = 1:SampleInWindow
    FourierSeriesAo = FourierSeriesAo+FunctionHarmonic(k);
    FourierSeriesAk = FourierSeriesAk+FunctionHarmonic(k)*...
        cos(double((k-1)*pi/(SampleInWindow/2)));
    FourierSeriesBk = FourierSeriesBk+FunctionHarmonic(k)*...
        sin(double((k-1)*pi/(SampleInWindow/2)));
end
DC = FourierSeriesAo/SampleInWindow;
CosValue = 2*FourierSeriesAk/SampleInWindow;
SinValue = 2*FourierSeriesBk/SampleInWindow;
FundamentalPeak = sqrt(CosValue.^2 + SinValue.^2);
RMS = FundamentalPeak/sqrt(2);
Phase = 180/pi*atan(CosValue/SinValue);


end