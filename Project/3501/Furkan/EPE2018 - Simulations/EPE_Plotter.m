%EPE - 2018 - GaN Plots
%% Static Calculator
Vgs_static = -10:1:6;
Vds_ch = 0:0.1:475;
cur = 4.5057;           % To be updated
K = cur * 0.8 * (273/300)^(-2.7);
x0 = 0.31 ;
x1 = 0.255;
slp = 2;
for GateIndex = 1:17    % Ids static = Ichan | Vds = Vch + Ich * (Rd + Rs)
    for i=1:((475/0.1)+1)
        GS = Vgs_static(GateIndex);
        DS = Vds_ch(i);
        GD = GS - DS;
        if Vds_ch(i)>0
            Ids_static(GateIndex,i) = K*log(1+exp(26*(GS-1.7)/slp))*(DS)/(1+max((x0+x1*(GS+4.1)),0.2)*DS);
            Vds_static(GateIndex,i) = Vds_ch(i) + Ids_static(GateIndex,i)*(Rd + Rs);
        else
            Ids_static(GateIndex,i) = -K*log(1+exp(21*(GD-1.7)/slp))*(-DS)/(1+max((x0+x1*(GD+6.1)),0.2)*(-DS));
            Vds_static(GateIndex,i) = Vds_ch(i) + Ids_static(GateIndex,i)*(Rd + Rs);
        end
    end
end
%% Dataset Configurations
% First Data Set
FirstDataBeginIndex = 1;
FirstDataEndIndex = 1;
FirstDataCurrentBegin = FIRSTCURRENT(FirstDataBeginIndex);
FirstDataVoltageBegin = FIRSTVOLTAGE(FirstDataBeginIndex);

% Second Data Set
SecondDataBeginIndex = 1;
SecondDataEndIndex = 1;
SecondDataCurrentBegin = SECONDCURRENT(SecondDataBeginIndex);
SecondDataVoltageBegin = SECONDVOLTAGE(SecondDataBeginIndex);

% Third Data Set
ThirdDataBeginIndex = 1;
ThirdDataEndIndex = 1;
ThirdDataCurrentBegin = THIRDCURRENT(ThirdDataBeginIndex);
ThirdDataVoltageBegin = THIRDVOLTAGE(ThirdDataBeginIndex);
%% Plot Initial Configurations
f1 = figure('Name','Top Switch Turn On','units','normalized','outerposition',[0 0 1 1]);
figure(f1);
hold all
grid on
for j=[8,13,14,17]
    plot((Vds_static(j,:)), Ids_static(j,:),'Linewidth',2.0);
end
xlim([0 415]);
ylim([0 60]);
xlabel('V_d_s(V)');
ylabel('I_d_s(A)');
title({'I_d_s vs V_d_s Curve of Top Switch During Turn ON'})
legend ('Vgs = -3','Vgs = 2','Vgs = 3','Vgs = 6','Location','northeast');
hold off
%% State Trajector Plot
figure(f1);
hold all
% First State Trajectory
Isens = 2;
Vsens = 2;
for j=FirstDataBeginIndex:FirstDataEndIndex
    if abs(FIRSTVOLTAGE(j)-FirstDataVoltageBegin) >= Vsens || abs(FIRSTCURRENT(j)-FirstDataCurrentBegin) >= Isens
        X = [FirstDataVoltageBegin FIRSTVOLTAGE(j)];
        Y = [FirstDataCurrentBegin FIRSTCURRENT(j)];
        drawArrow(X,Y,'MaxHeadSize',150,'Color','r','LineWidth',2);
        FirstDataVoltageBegin = FIRSTVOLTAGE(j);
        FirstDataCurrentBegin = FIRSTCURRENT(j);
    end
end 
    plot(FIRSTVOLTAGE(FirstDataBeginIndex),FIRSTCURRENT(FirstDataBeginIndex),'*','Linewidth',10.0);
    plot(FIRSTVOLTAGE(FirstDataEndIndex),FIRSTCURRENT(FirstDataEndIndex),'*','Linewidth',10.0);
% Second State Trajectory
Isens = 2;
Vsens = 2;
for j=SecondDataBeginIndex:SecondDataEndIndex
    if abs(SECONDVOLTAGE(j)-SecondDataVoltageBegin) >= Vsens || abs(SECONDCURRENT(j)-SecondDataCurrentBegin) >= Isens
        X = [SecondDataVoltageBegin SECONDVOLTAGE(j)];
        Y = [SecondDataCurrentBegin SECONDCURRENT(j)];
        drawArrow(X,Y,'MaxHeadSize',150,'Color','r','LineWidth',2);
        SecondDataVoltageBegin = SECONDVOLTAGE(j);
        SecondDataCurrentBegin = SECONDCURRENT(j);
    end
end 
    plot(SECONDVOLTAGE(SecondDataBeginIndex),SECONDCURRENT(SecondDataBeginIndex),'*','Linewidth',10.0);
    plot(SECONDVOLTAGE(SecondDataEndIndex),SECONDCURRENT(SecondDataEndIndex),'*','Linewidth',10.0);
% Third State Trajectory
Isens = 2;
Vsens = 2;
for j=ThirdDataBeginIndex:ThirdDataEndIndex
    if abs(THIRDVOLTAGE(j)-ThirdDataVoltageBegin) >= Vsens || abs(THIRDCURRENT(j)-ThirdDataCurrentBegin) >= Isens
        X = [ThirdDataVoltageBegin THIRDVOLTAGE(j)];
        Y = [ThirdDataCurrentBegin THIRDCURRENT(j)];
        drawArrow(X,Y,'MaxHeadSize',150,'Color','r','LineWidth',2);
        ThirdDataVoltageBegin = THIRDVOLTAGE(j);
        ThirdDataCurrentBegin = THIRDCURRENT(j);
    end
end 
    plot(THIRDVOLTAGE(ThirdDataBeginIndex),THIRDCURRENT(ThirdDataBeginIndex),'*','Linewidth',10.0);
    plot(THIRDVOLTAGE(ThirdDataEndIndex),THIRDCURRENT(ThirdDataEndIndex),'*','Linewidth',10.0);