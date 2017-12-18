clear all;
Vgs = -6:1:6;
Vds = -10:0.1:15;
cur = 4.5057;
K = cur * 0.8 * (273/300)^(-2.7);
x0 = 0.31 ;
x1 = 0.255;
slp = 2;


Vds2 = 0;
for GateIndex = 1:13
    for i=1:((25/0.1)+1)
        GS = Vgs(GateIndex);
        DS = Vds(i);
        DS = DS - 0.9*0.95*0.82*18.2/295 - 3.6*0.238*0.82/295;
        GD = GS - DS;
        if Vds(i)>0
            I_top(GateIndex,i) = K*log(1+exp(26*(GS-1.7)/slp))*(DS)/(1+max((x0+x1*(GS+4.1)),0.2)*DS);
        else
            I_top(GateIndex,i) = -K*log(1+exp(21*(GD-1.7)/slp))*(-DS)/(1+max((x0+x1*(GD+6.1)),0.2)*(-DS));
        end
        Vds2(GateIndex,i) = Vds(i) + I_top(GateIndex,i)*(0.9*0.95*0.82*18.2/295 + 3.6*0.238*0.82/295);
    end
end

