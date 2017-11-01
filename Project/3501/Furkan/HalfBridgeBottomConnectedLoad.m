%% Initial Configurations
clear all;

%% Device Parameters
% K1 = 0.283;
% b1 = 2.035;
% c1 = 0.124;
% d1 = 1.159;
% e1 = -0.204;
% m1 = 30.972;
% n1 = -4.48;
% K2 = 7.114;
% b2 = 2.054;
% c2 = 0.153;

Cgd = 2e-12;
Cgs = 258e-12;
Cds = 63e-12;

Ls = 2e-9;
Ld = 7e-9;
Lg = 2e-9;

Rg = 1.5;
Rd = 25e-6;
Rs = 25e-6;

%% Circuit Parasitics
Ldc = 8e-9;
Lground = 10e-9;

%% Gate Driver
Ron = 12;
Roff = 2;
%% Source parameters
PulseAmplitude = 5;
fsw = 1000e3;
Vdc = 300;
% Quantities in below are in percent
Dtop = 49; % duty cycle of top
Dbot = 49; % duty cycle of bot
DelayTop = 0;
DelayBot = 50;


%% Load parameters
Rload = 10;
Lload = 1e-6;
%% Run Simulink
SampleTime = 0.5e-12;
model = 'HalfBridgeBottomConnectedLoa';
load_system(model);
StopTime = 1.7e-6;
set_param(model, 'StopTime','1.7e-6' )
sim(model);

%% Plots
Vgs = -3:1:6;
Vds = -7:0.1:320;
cur = 4.5057;
K = cur * 0.8 * (273/300)^(-2.7);
x0 = 0.31 ;
x1 = 0.255;
slp = 2;

for GateIndex = 1:10
    for i=1:((327/0.1)+1)
        GS = Vgs(GateIndex);
        DS = Vds(i);
        GD = GS - DS;
        if Vds(i)>0
            I(GateIndex,i) = K*log(1+exp(26*(GS-1.7)/slp))*(DS)/(1+max((x0+x1*(GS+4.1)),0.2)*DS);
        else
            I(GateIndex,i) = -K*log(1+exp(21*(GD-1.7)/slp))*(-DS)/(1+max((x0+x1*(GD+6.1)),0.2)*(-DS));
        end
    end
end

hold all
for j=[1,2,3,4,5,6,7,8,9]
    plot((Vds), I(j,:),'Linewidth',2.0);
end
xlabel('Vds(V)');
ylabel('Ids(A)');
title({'Ids vs Vds curves for different Vgs values for LT Spice equations','RED ARROW shows TURN OFF','BLUE ARROR shows TURN ON'})
legend ('Vgs = -3','Vgs = -2','Vgs = -1','Vgs = 0','Vgs = 1','Vgs = 2','Vgs = 3','Vgs = 4','Vgs = 5');

Isens = 2;
Vsens = 5;
Size = size(TopVoltageDS);

drawArrow = @(x,y,varargin) quiver( x(1),y(1),x(2)-x(1),y(2)-y(1),0, varargin{:} );
Period = 1/fsw;
% Turn OFF for Top Switch
    ToffSampleMid = Period/2/SampleTime + 1 ;
    MarginOff = Period/100/SampleTime;
    ToffSampleBegin = ToffSampleMid - MarginOff;
    ToffSampleEnd   = ToffSampleMid + MarginOff;
% Turn ON for Top Switch
    TonSampleMid = Period/SampleTime + 1 ;
    MarginOn = 1.5*Period/100/SampleTime;
    TonSampleBegin = TonSampleMid - MarginOn;
    TonSampleEnd   = TonSampleMid + MarginOn;%0.48*Period/SampleTime;   
    
% Turn OFF Plot
InitI = Vdc/Rload;
InitV = 0;
for j=ToffSampleBegin:ToffSampleEnd
    if abs(TopVoltageDS(j)-InitV) >= Vsens || abs(TopCurrentDS(j)-InitI) >= Isens
        X = [InitV TopVoltageDS(j)];
        Y = [InitI TopCurrentDS(j)];
        drawArrow(X,Y,'MaxHeadSize',20,'Color','r','LineWidth',2);
        InitV = TopVoltageDS(j);
        InitI = TopCurrentDS(j);
    end
end      
% Turn ON Plot
InitI = 0;
InitV = Vdc;
for j=TonSampleBegin:TonSampleEnd
    if abs(TopVoltageDS(j)-InitV) >= Vsens || abs(TopCurrentDS(j)-InitI) >= Isens
        X = [InitV TopVoltageDS(j)];
        Y = [InitI TopCurrentDS(j)];
        drawArrow(X,Y,'MaxHeadSize',20,'Color','b','LineWidth',2);
        InitV = TopVoltageDS(j);
        InitI = TopCurrentDS(j);
    end
end 
hold off
