%% Plots
fsw = 1e6;
Period = 1/fsw;
Vgs = -10:1:6;
Vds = 0:0.1:475;
cur = 4.5057;
K = cur * 0.8 * (273/300)^(-2.7);
x0 = 0.31 ;
x1 = 0.255;
slp = 2;
f1 = figure('Name','Top Switch Turn On','units','normalized','outerposition',[0 0 1 1]);
f2 = figure('Name','Top Switch Turn Off','units','normalized','outerposition',[0 0 1 1]);
f3 = figure('Name','Bottom Switch Turn On','units','normalized','outerposition',[0 0 1 1]);
f4 = figure('Name','Bottom Switch Turn Off','units','normalized','outerposition',[0 0 1 1]);
Vds2 = 0;
for GateIndex = 1:17
    for i=1:((475/0.1)+1)
        GS = Vgs(GateIndex);
        DS = Vds(i);
        DS = DS - 0.9*0.95*0.82*18.2/295 - 3.6*0.238*0.82/295;
        GD = GS - DS;
        if Vds(i)>0
            I_top(GateIndex,i) = K*log(1+exp(26*(GS-1.7)/slp))*(DS)/(1+max((x0+x1*(GS+4.1)),0.2)*DS);
            Vds2(GateIndex,i) = Vds(i) + I_top(GateIndex,i)*(0.9*0.95*0.82*18.2/295 + 3.6*0.238*0.82/295);
        else
            I_top(GateIndex,i) = -K*log(1+exp(21*(GD-1.7)/slp))*(-DS)/(1+max((x0+x1*(GD+6.1)),0.2)*(-DS));
            Vds2(GateIndex,i) = Vds(i) + I_top(GateIndex,i)*(0.9*0.95*0.82*18.2/295 + 3.6*0.238*0.82/295);
        end
        
    end
end

figure(f1);
hold all
grid minor
for j=[8,13,14,17]
    plot((Vds2(j,:)), I_top(j,:),'Linewidth',2.0);
    %plot((Vds),  I_top(j,:),'Linewidth',2.0);
end
xlim([0 415]);
ylim([0 60]);
xlabel('V(V)');
ylabel('I(A)');
title({'State Trajectory for Top Switch During Turn ON','Red Ch, Blue DS'})
legend ('Vgs = -3','Vgs = 2','Vgs = 3','Vgs = 6','Location','northeast');
hold off

figure(f2);
hold all
grid minor
for j=[8,13,14,17]
    plot((Vds2(j,:)),  I_top(j,:),'Linewidth',2.0);
end
xlim([0 465]);
ylim([0 50]);
xlabel('V(V)');
ylabel('I(A)');
title({'State Trajectory for Top Switch During Turn OFF','Red Ch, Blue DS'})
legend ('Vgs = -3','Vgs = 2','Vgs = 3','Vgs = 6','Location','northeast');
hold off





drawArrow = @(x,y,varargin) quiver( x(1),y(1),x(2)-x(1),y(2)-y(1),0, varargin{:} );
Period = 1/fsw;
% Turn OFF for Top Switch
    ToffSampleMid = 2.5*Period/SampleTime + 1 ;
    MarginOff = round(1*Period/100/SampleTime);
    ToffSampleBegin = ToffSampleMid - MarginOff ;
    ToffSampleEnd   = ToffSampleMid + MarginOff ;
    DurationTopOFF = ToffSampleEnd - ToffSampleBegin;
% Turn ON for Top Switch
    TonSampleMid = 2*Period/SampleTime + 1 ;
    MarginOn = round(2*Period/100/SampleTime);
    TonSampleBegin = TonSampleMid ;
    TonSampleEnd   = TonSampleMid + MarginOn + 12000;%0.48*Period/SampleTime;   
    DurationTopON = TonSampleEnd - TonSampleBegin; 
%Top Switch Plot
% 
% Turn OFF Plot
%         InitI = TopCurrentDS(ToffSampleBegin);
%         InitV = TopVoltageDS(ToffSampleBegin);
%         EnergyTopOFF = 0;
%         TopOFFVI = zeros(1,2);
%         figure(f2)
%         hold all
%         for j=ToffSampleBegin:ToffSampleEnd
%             if abs(TopVoltageDS(j)-InitV) >= Vsens || abs(TopCurrentDS(j)-InitI) >= Isens
%                 X = [InitV TopVoltageDS(j)];
%                 Y = [InitI TopCurrentDS(j)];
%                 drawArrow(X,Y,'MaxHeadSize',150,'Color','b','LineWidth',2);
%                 InitV = TopVoltageDS(j);
%                 InitI = TopCurrentDS(j);
%             end
%             EnergyTopOFF = abs(TopVoltageDS(j) * TopCurrentDS(j)) * SampleTime + EnergyTopOFF;
%             TopOFFVI(j+1-ToffSampleBegin,:) = [TopVoltageDS(j),TopCurrentDS(j)];
%             EnergyTOFinst(j+1-ToffSampleBegin) = EnergyTopOFF;
%         end 
%         PowerTopOFF = EnergyTopOFF / Period;
%             plot(TopVoltageDS(ToffSampleBegin),TopCurrentDS(ToffSampleBegin),'*','Linewidth',10.0);
%             plot(TopVoltageDS(ToffSampleEnd),TopCurrentDS(ToffSampleEnd),'*','Linewidth',10.0);
%         hold off
% 


InitI = TopChCons(ToffSampleBegin);
InitV = TopVoltDSCons(ToffSampleBegin);
figure(f2)
Isens = 4;
Vsens = 4;
hold all
for j=ToffSampleBegin:ToffSampleEnd
    if abs(TopVoltDSCons(j)-InitV) >= Vsens || abs(TopChCons(j)-InitI) >= Isens
        X = [InitV TopVoltDSCons(j)];
        Y = [InitI TopChCons(j)];
        drawArrow(X,Y,'MaxHeadSize',150,'Color','r','LineWidth',2);
        InitV = TopVoltDSCons(j);
        InitI = TopChCons(j);
    end
end 
    plot(TopVoltDSCons(ToffSampleBegin),TopChCons(ToffSampleBegin),'*','Linewidth',10.0);
    plot(TopVoltDSCons(ToffSampleEnd),TopChCons(ToffSampleEnd),'*','Linewidth',10.0);
hold off    

InitI = TopDSCurrCons(ToffSampleBegin);
InitV = TopVoltDSCons(ToffSampleBegin);
figure(f2)
Isens = 4;
Vsens = 4;
hold all
for j=ToffSampleBegin:ToffSampleEnd
    if abs(TopVoltDSCons(j)-InitV) >= Vsens || abs(TopDSCurrCons(j)-InitI) >= Isens
        X = [InitV TopVoltDSCons(j)];
        Y = [InitI TopDSCurrCons(j)];
        drawArrow(X,Y,'MaxHeadSize',150,'Color','b','LineWidth',2);
        InitV = TopVoltDSCons(j);
        InitI = TopDSCurrCons(j);
    end
end 
hold off   

% Turn ON Plot
Isens = 5;
Vsens = 5;
% Drain-Source Current PLOT
%         InitI = TopCurrentDS(TonSampleBegin);
%         InitV = TopVoltageDS(TonSampleBegin);
%         EnergyTopON = 0;
%         TopONVI = zeros(1,2);
%         figure(f1)
%         hold all
%         for j=TonSampleBegin:TonSampleEnd
%             if abs(TopVoltageDS(j)-InitV) >= Vsens || abs(TopCurrentDS(j)-InitI) >= Isens
%                 X = [InitV TopVoltageDS(j)];
%                 Y = [InitI TopCurrentDS(j)];
%                 drawArrow(X,Y,'MaxHeadSize',150,'Color','b','LineWidth',2);
%                 InitV = TopVoltageDS(j);
%                 InitI = TopCurrentDS(j);
%             end
%             EnergyTopON = abs(TopVoltageDS(j) * TopCurrentDS(j)) * SampleTime + EnergyTopON;
%             TopONVI(j+1-TonSampleBegin,:) = [TopVoltageDS(j),TopCurrentDS(j)];
%             EnergyTONinst(j+1-TonSampleBegin) = EnergyTopON;
%         end 
%         PowerTopON = EnergyTopON / Period;
%             plot(TopVoltageDS(TonSampleBegin),TopCurrentDS(TonSampleBegin),'*','Linewidth',10.0);
%             plot(TopVoltageDS(TonSampleEnd),TopCurrentDS(TonSampleEnd),'*','Linewidth',10.0);
%         hold off;

InitI = TopChCons(TonSampleBegin);
InitV = TopVoltDSCons(TonSampleBegin);
figure(f1)
hold all
for j=TonSampleBegin:TonSampleEnd
    if abs(TopVoltDSCons(j)-InitV) >= Vsens || abs(TopChCons(j)-InitI) >= Isens
        X = [InitV TopVoltDSCons(j)];
        Y = [InitI TopChCons(j)];
        drawArrow(X,Y,'MaxHeadSize',1000,'Color','r','LineWidth',2);
        InitV = TopVoltDSCons(j);
        InitI = TopChCons(j);
    end
    if InitV<20
        Vsens = 0.5;
        Isens = 0.5;
    elseif InitV<5
        Vsens = 0.1;
        Isens = 0.1;
    end
       
end 
    plot(TopVoltDSCons(TonSampleBegin),TopChCons(TonSampleBegin),'*','Linewidth',10.0);
    plot(TopVoltDSCons(TonSampleEnd),TopChCons(TonSampleEnd),'*','Linewidth',10.0);

hold off;
InitI = TopDSCurrCons(TonSampleBegin);
InitV = TopVoltDSCons(TonSampleBegin);
figure(f1)
hold all
for j=TonSampleBegin:TonSampleEnd
    if abs(TopVoltDSCons(j)-InitV) >= Vsens || abs(TopDSCurrCons(j)-InitI) >= Isens
        X = [InitV TopVoltDSCons(j)];
        Y = [InitI TopDSCurrCons(j)];
        drawArrow(X,Y,'MaxHeadSize',1000,'Color','b','LineWidth',2);
        InitV = TopVoltDSCons(j);
        InitI = TopDSCurrCons(j);
    end
    if InitV<20
        Vsens = 0.5;
        Isens = 0.5;
    elseif InitV<5
        Vsens = 0.1;
        Isens = 0.1;
    end
       
end 



%Bot Switch Plot
Isens = 1;
Vsens = 0.5;
% Turn OFF for Bottom Switch
    ToffSampleMid = 2*Period/SampleTime + 1 ;
    MarginOff = round(Period/100/SampleTime);
    ToffSampleBegin = ToffSampleMid - MarginOff;
    ToffSampleEnd   = ToffSampleMid + MarginOff + 10000;
    DurationBotOFF = ToffSampleEnd - ToffSampleBegin;
% Turn ON for Bottom Switch
    TonSampleMid = 2.5*Period/SampleTime + 1 ;
    MarginOn = round(2.5*Period/100/SampleTime);
    TonSampleBegin = TonSampleMid - MarginOn;
    TonSampleEnd   = TonSampleMid + MarginOn;%0.48*Period/SampleTime;  
    DurationBotON = TonSampleEnd - TonSampleBegin;
Vds = -15:0.1:420;
Vds2 = 0;
for GateIndex = 1:17
    for i=1:((435/0.1)+1)
        GS = Vgs(GateIndex);
        DS = Vds(i);
        GD = GS - DS;
        if Vds(i)>0
            I_bottom(GateIndex,i) = K*log(1+exp(26*(GS-1.7)/slp))*(DS)/(1+max((x0+x1*(GS+4.1)),0.2)*DS);
        else
            I_bottom(GateIndex,i) = -K*log(1+exp(21*(GD-1.7)/slp))*(-DS)/(1+max((x0+x1*(GD+6.1)),0.2)*(-DS));
        end
        Vds2(GateIndex,i) = Vds(i) + I_bottom(GateIndex,i)*(0.9*0.95*0.82*18.2/295 + 3.6*0.238*0.82/295);
    end
end


figure(f3);
hold all
grid minor
for j=[1,5,8,14,17]
    plot((Vds2(j,:)),  I_bottom(j,:),'Linewidth',2.0);
end
xlim([-25 420]);
ylim([-50 5]);
xlabel('V(V)');
ylabel('I(A)');
title({'State Trajectory for Bottom Switch during Turn ON','Red Ch, Blue DS'})
legend ('Vgs = -10','Vgs = -6','Vgs = -3','Vgs = 3','Vgs = 6','Location','southeast');
hold off

figure(f4);
hold all
grid minor
for j=[5,8,11,14,17]
   plot((Vds2(j,:)),  I_bottom(j,:),'Linewidth',2.0);
end
xlim([-10 420]);
ylim([-30 5]);
xlabel('V(V)');
ylabel('I(A)');
title({'State Trajectory for Bottom Switch during Turn OFF','Red Ch, Blue DS'})
legend ('Vgs = -6','Vgs = -3','Vgs = 0','Vgs = 3','Vgs = 6','Location','southeast');
hold off

% Turn ON Plot
% Drain-Source Current Plot
%         InitI = BotCurrentDS(TonSampleBegin);
%         InitV = BotVoltageDS(TonSampleBegin);
%         EnergyBotON = 0;
%         BotONVI = zeros(1,2);
%         figure(f3)
%         hold all
%         for j=TonSampleBegin:TonSampleEnd
%             if abs(BotVoltageDS(j)-InitV) >= Vsens || abs(BotCurrentDS(j)-InitI) >= Isens
%                 X = [InitV BotVoltageDS(j)];
%                 Y = [InitI BotCurrentDS(j)];
%                 drawArrow(X,Y,'MaxHeadSize',20,'Color','b','LineWidth',2);
%                 InitV = BotVoltageDS(j);
%                 InitI = BotCurrentDS(j);
%             end
%             EnergyBotON = abs(BotVoltageDS(j) * BotCurrentDS(j)) * SampleTime + EnergyBotON;
%             BotONVI(j+1-TonSampleBegin,:) = [BotVoltageDS(j),BotCurrentDS(j)];
%             EnergyBONinst(j+1-TonSampleBegin) = EnergyBotON;
%         end      
%         PowerBotON = EnergyBotON / Period;
%         plot(BotVoltageDS(TonSampleBegin),BotCurrentDS(TonSampleBegin),'*','Linewidth',10.0);
%         plot(BotVoltageDS(TonSampleEnd),BotCurrentDS(TonSampleEnd),'*','Linewidth',10.0);
%         hold off

InitI = BotChCons(TonSampleBegin);
InitV = BotVoltDSCons(TonSampleBegin);
figure(f3)
hold all
for j=TonSampleBegin:(TonSampleEnd-20000)
    if abs(BotVoltDSCons(j)-InitV) >= Vsens || abs(BotChCons(j)-InitI) >= Isens
        X = [InitV BotVoltDSCons(j)];
        Y = [InitI BotChCons(j)];
        drawArrow(X,Y,'MaxHeadSize',20,'Color','r','LineWidth',2);
        InitV = BotVoltDSCons(j);
        InitI = BotChCons(j);
    end
end 
    plot(BotVoltDSCons(TonSampleBegin),BotChCons(TonSampleBegin),'*','Linewidth',10.0);
    plot(BotVoltDSCons(TonSampleEnd),BotChCons(TonSampleEnd),'*','Linewidth',10.0);

hold off
InitI = BotDSCurrCons(TonSampleBegin);
InitV = BotVoltDSCons(TonSampleBegin);
figure(f3)
hold all
for j=TonSampleBegin:(TonSampleEnd-20000)
    if abs(BotVoltDSCons(j)-InitV) >= Vsens || abs(BotDSCurrCons(j)-InitI) >= Isens
        X = [InitV BotVoltDSCons(j)];
        Y = [InitI BotDSCurrCons(j)];
        drawArrow(X,Y,'MaxHeadSize',20,'Color','b','LineWidth',2);
        InitV = BotVoltDSCons(j);
        InitI = BotDSCurrCons(j);
    end
end 
    
% Turn OFF Plot
% Drain Source Current Plot
%         InitI = BotCurrentDS(ToffSampleBegin);
%         InitV = BotVoltageDS(ToffSampleBegin);
%         EnergyBotOFF = 0;
%         BotOFFVI = zeros(1,2);
%         figure(f4)
%         hold all
%         for j=ToffSampleBegin:ToffSampleEnd
%             if abs(BotVoltageDS(j)-InitV) >= Vsens || abs(BotCurrentDS(j)-InitI) >= Isens
%                 X = [InitV BotVoltageDS(j)];
%                 Y = [InitI BotCurrentDS(j)];
%                 drawArrow(X,Y,'MaxHeadSize',20,'Color','b','LineWidth',2);
%                 InitV = BotVoltageDS(j);
%                 InitI = BotCurrentDS(j);
%             end
%             EnergyBotOFF = abs(BotVoltageDS(j) * BotCurrentDS(j)) * SampleTime + EnergyBotOFF;
%             BotOFFVI(j+1-ToffSampleBegin,:) = [BotVoltageDS(j),BotCurrentDS(j)];
%             EnergyBOFinst(j+1-ToffSampleBegin) = EnergyBotOFF;
%         end
%         PowerBotOFF = EnergyBotOFF / Period;
%         plot(BotVoltageDS(ToffSampleBegin),BotCurrentDS(ToffSampleBegin),'*','Linewidth',10.0);
%         plot(BotVoltageDS(ToffSampleEnd),BotCurrentDS(ToffSampleEnd),'*','Linewidth',10.0);
%         hold off
Isens = 1;
Vsens = 1;
InitI = BotChCons(ToffSampleBegin);
InitV = BotVoltDSCons(ToffSampleBegin);
figure(f4)
hold all
for j=ToffSampleBegin:(ToffSampleEnd)
    if abs(BotVoltDSCons(j)-InitV) >= Vsens || abs(BotChCons(j)-InitI) >= Isens
        X = [InitV BotVoltDSCons(j)];
        Y = [InitI BotChCons(j)];
        drawArrow(X,Y,'MaxHeadSize',1000,'Color','r','LineWidth',2);
        InitV = BotVoltDSCons(j);
        InitI = BotChCons(j);
    end
end
plot(BotVoltDSCons(ToffSampleBegin),BotChCons(ToffSampleBegin),'*','Linewidth',10.0);
plot(BotVoltDSCons(ToffSampleEnd),BotChCons(ToffSampleEnd),'*','Linewidth',10.0);

InitI = BotDSCurrCons(ToffSampleBegin);
InitV = BotVoltDSCons(ToffSampleBegin);
figure(f4)
hold all
for j=ToffSampleBegin:(ToffSampleEnd)
    if abs(BotVoltDSCons(j)-InitV) >= Vsens || abs(BotDSCurrCons(j)-InitI) >= Isens
        X = [InitV BotVoltDSCons(j)];
        Y = [InitI BotDSCurrCons(j)];
        drawArrow(X,Y,'MaxHeadSize',1000,'Color','b','LineWidth',2);
        InitV = BotVoltDSCons(j);
        InitI = BotDSCurrCons(j);
    end
end
hold off