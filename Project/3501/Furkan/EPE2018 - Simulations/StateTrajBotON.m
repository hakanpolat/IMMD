%EPE - 2018 - GaN Plots
%% Static Calculator
Vgs_static = -10:1:6;
Vds_ch = -10:0.1:475;
cur = 4.5057; % To be updated
K = cur * 0.8 * ((125 - 25 + 273)/300)^(-2.7);
x0 = 0.31 ;
x1 = 0.255;
slp = 2;
    Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0135*(125 - 25))) / 295 + 1e-4;
    Rd = (3.6/4) * (0.95*0.82*(1 - (-0.0135*(125 - 25))) * 18.2 / 295) + 1e-4;

for GateIndex = 1:17    % Ids static = Ichan | Vds = Vch + Ich * (Rd + Rs)
    for i=1:((485/0.1)+1)
        GS = Vgs_static(GateIndex);
        DS = Vds_ch(i);
        GD = GS - DS;
        if Vds_ch(i)>0
            Ids_static(GateIndex,i) = K*log(1+exp(26*(GS-1.7)/slp))*(DS)/(1+max((x0+x1*(GS+4.1)),0.2)*DS);
            Vds_static(GateIndex,i) = Vds_ch(i) + 0*Ids_static(GateIndex,i)*(Rd + Rs);
        else
            Ids_static(GateIndex,i) = -K*log(1+exp(26*(GD-1.7)/slp))*(-DS)/(1+max((x0+x1*(GD+6.1)),0.2)*(-DS));
            Vds_static(GateIndex,i) = Vds_ch(i) + 0*Ids_static(GateIndex,i)*(Rd + Rs);
        end
    end
end
%% Dataset Configurations
SampleTime = 5e-13;
getElement(Model120A125C10and1ohm,'IdsB_I');
FIRSTCURRENT = ans.Values.Data;
getElement(Model120A125C10and1ohm,'VdsB_I');
FIRSTVOLTAGE = ans.Values.Data;
getElement(Model320A125C10and1ohm,'IdsB_I');
SECONDCURRENT = ans.Values.Data;
getElement(Model320A125C10and1ohm,'VdsB_I');
SECONDVOLTAGE = ans.Values.Data;
getElement(Model320A75C10and1ohmSOURCE,'IdsB_I');
THIRDCURRENT = ans.Values.Data;
getElement(Model320A75C10and1ohmSOURCE,'VdsB_I');
THIRDVOLTAGE = ans.Values.Data;
% First Data Set
FirstDataBeginIndex = 4.9e-7/SampleTime;
FirstDataEndIndex = 6e-7/SampleTime;
FirstDataCurrentBegin = FIRSTCURRENT(FirstDataBeginIndex);
FirstDataVoltageBegin = FIRSTVOLTAGE(FirstDataBeginIndex);

% Second Data Set
SecondDataBeginIndex = 4.9e-7/SampleTime;
SecondDataEndIndex = 6e-7/SampleTime;
SecondDataCurrentBegin = SECONDCURRENT(SecondDataBeginIndex);
SecondDataVoltageBegin = SECONDVOLTAGE(SecondDataBeginIndex);

% Third Data Set
ThirdDataBeginIndex = 4.9e-7/SampleTime;
ThirdDataEndIndex = 6e-7/SampleTime;
ThirdDataCurrentBegin = THIRDCURRENT(ThirdDataBeginIndex);
ThirdDataVoltageBegin = THIRDVOLTAGE(ThirdDataBeginIndex);
%% Plot Initial Configurations
drawArrow = @(x,y,varargin) quiver( x(1),y(1),x(2)-x(1),y(2)-y(1),0, varargin{:} );
f1 = figure('Name','Bot Switch Turn On','units','normalized','outerposition',[1/4 1/4 1/2 1/2]);
figure(f1);
hold all
grid on
% -10 -9 -8 -7 -6 -5 -4 -3 -2 -1  0  1  2  3  4  5  6
% 1    2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17
for j=[8,13,14,17]
    plot((Vds_static(j,:)), Ids_static(j,:),'Linewidth',2.0);
end
xlim([0 415]);
ylim([0 50]);
ax = gca;
ax.FontSize = 22;
ax.XTick = [0:100:400];
ax.YTick = [0:10:80];
grid off;
xlabel('V_c_h(V)','FontSize',22,'FontWeight','bold','Color','k');
ylabel('I_c_h(A)','FontSize',22,'FontWeight','bold','Color','k');
% title({'I_d_s vs V_d_s Curve of Top Switch During Turn ON'},'FontSize',22,'FontWeight','bold','Color','k')
legend ('Vgs = -3V','Vgs = 2V','Vgs = 3V','Vgs = 6V','Location','northeast');
hold off
%% State Trajector Plot
figure(f1);
hold all
% First State Trajectory
Isens = 0.5;
Vsens = 0.5;
for j=FirstDataBeginIndex:FirstDataEndIndex
    if abs(FIRSTVOLTAGE(j)-FirstDataVoltageBegin) >= Vsens || abs(FIRSTCURRENT(j)-FirstDataCurrentBegin) >= Isens
        X = [FirstDataVoltageBegin FIRSTVOLTAGE(j)];
        Y = [FirstDataCurrentBegin FIRSTCURRENT(j)];
%         drawArrow(X,Y,'MaxHeadSize',150,'Color','r','LineWidth',2);
        plot(X,Y,'Color','r','LineWidth',4);
        FirstDataVoltageBegin = FIRSTVOLTAGE(j);
        FirstDataCurrentBegin = FIRSTCURRENT(j);
    end
end 
    plot(FIRSTVOLTAGE(FirstDataBeginIndex),FIRSTCURRENT(FirstDataBeginIndex),'*','Linewidth',10.0,'Color','r');
    plot(FIRSTVOLTAGE(FirstDataEndIndex),FIRSTCURRENT(FirstDataEndIndex),'*','Linewidth',10.0,'Color','r');
% Second State Trajectory
Isens = 0.5;
Vsens = 0.5;
for j=SecondDataBeginIndex:SecondDataEndIndex
    if abs(SECONDVOLTAGE(j)-SecondDataVoltageBegin) >= Vsens || abs(SECONDCURRENT(j)-SecondDataCurrentBegin) >= Isens
        X = [SecondDataVoltageBegin SECONDVOLTAGE(j)];
        Y = [SecondDataCurrentBegin SECONDCURRENT(j)];
%         drawArrow(X,Y,'MaxHeadSize',150,'Color','r','LineWidth',2);
        plot(X,Y,'Color','k','LineWidth',4);
        SecondDataVoltageBegin = SECONDVOLTAGE(j);
        SecondDataCurrentBegin = SECONDCURRENT(j);
    end
end 
    plot(SECONDVOLTAGE(SecondDataBeginIndex),SECONDCURRENT(SecondDataBeginIndex),'*','Linewidth',10.0,'Color','k');
    plot(SECONDVOLTAGE(SecondDataEndIndex),SECONDCURRENT(SecondDataEndIndex),'*','Linewidth',10.0,'Color','k');
% Third State Trajectory
Isens = 0.5;
Vsens = 0.5;
for j=ThirdDataBeginIndex:ThirdDataEndIndex
    if abs(THIRDVOLTAGE(j)-ThirdDataVoltageBegin) >= Vsens || abs(THIRDCURRENT(j)-ThirdDataCurrentBegin) >= Isens
        X = [ThirdDataVoltageBegin THIRDVOLTAGE(j)];
        Y = [ThirdDataCurrentBegin THIRDCURRENT(j)];
%         drawArrow(X,Y,'MaxHeadSize',150,'Color','r','LineWidth',2);
        plot(X,Y,'Color','b','LineWidth',4);
        ThirdDataVoltageBegin = THIRDVOLTAGE(j);
        ThirdDataCurrentBegin = THIRDCURRENT(j);
    end
end 
    plot(THIRDVOLTAGE(ThirdDataBeginIndex),THIRDCURRENT(ThirdDataBeginIndex),'*','Linewidth',10.0,'Color','b');
    plot(THIRDVOLTAGE(ThirdDataEndIndex),THIRDCURRENT(ThirdDataEndIndex),'*','Linewidth',10.0,'Color','b');