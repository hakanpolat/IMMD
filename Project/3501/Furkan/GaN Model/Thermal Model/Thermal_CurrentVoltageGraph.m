%% Initial Configurations
clear all;
close all;

%% Loop
cur = 4.5057;
x0 = 0.31 ;
x1 = 0.255;
slp = 2;
Vgs = [2,3,4,5,6];
Vds = 0:0.1:5;
Temp = 25:25:150;
for TempIndex = 1:6
    K = cur * 0.8 * ((Temp(TempIndex) - 25 + 273)/300)^(-2.7);
    for GateIndex = 1:5
        for DSIndex = 1:51
            Vgd = Vgs(GateIndex) - Vds(DSIndex);
            if Vds(DSIndex) > 0
                Ids(TempIndex,GateIndex,DSIndex) = K*log(1+exp(26*(Vgs(GateIndex)-1.7)/slp))*(Vds(DSIndex))/(1+max((x0+x1*(Vgs(GateIndex)+4.1)),0.2)*Vds(DSIndex));
            else
                Ids(TempIndex,GateIndex,DSIndex) = -K*log(1+exp(26*(Vgd-1.7)/slp))*(-Vds(DSIndex))/(1+max((x0+x1*(Vgd+6.1)),0.2)*(-Vds(DSIndex)));
            end
        end
    end
end

for TempIndex = 1:6
    Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0135*(Temp(TempIndex) - 25))) / 295 + 1e-4;
    Rd = (3.6/4) * (0.95*0.82*(1 - (-0.0135*(Temp(TempIndex) - 25))) * 18.2 / 295) + 1e-4;
    for GateIndex = 1:5
        for DSIndex = 1:51
            Vds_modified(TempIndex,GateIndex,DSIndex) = Ids(TempIndex,GateIndex,DSIndex) * (Rs + Rd) + Vds(DSIndex);
        end
    end
end
%Ids is a three dimensional array which is encoded as I[Temperature,GateSourceVoltage,DrainSourceVoltage]

%% Plot
f1 = figure('Name','I_{DS} vs V_{DS} Graph for Different Temperatures at V_{gs} = 6V');
f2 = figure('Name','I_{DS} vs V_{DS} Graph at T_j = 25{\circ}');
f3 = figure('Name','I_{DS} vs V_{DS} Graph @ T_j = 150{\circ}'); 
% Vgs = [2,3,4,5,6];
% Vds = 0:5;
% Temp = 25:25:150;
figure(f1);
    hold all
    grid on
    ax = gca;
    title('I_{DS} vs V_{DS} Graph for Different Temperatures @ V_{gs} = 6V','FontSize',12,'FontWeight','bold','Color','k');
    xlabel('V_{DS}(V)','FontSize',12,'FontWeight','bold','Color','k');
    ylabel('I_{DS}(A)','FontSize',12,'FontWeight','bold','Color','k');
    ax.FontSize = 12;
    ax.XTick = [0:1:5];
    ax.YTick = [0:20:120];
    xlim([0 5])
    for TempIndex = 1:6
    Ids_dummy(:) = Ids(TempIndex,5,:);
    Vds_dummy(:) = Vds_modified(TempIndex,5,:);
    plot( Vds_dummy , Ids_dummy,'LineWidth',3.0);
    clear Ids_dummy;
    clear Vds_dummy;
    end
    legend('25{\circ}','50{\circ}','75{\circ}','100{\circ}','125{\circ}','150{\circ}','Location','NorthWest');
    hold off
    saveas(f1, 'I_{DS} vs V_{DS} Graph for Different Temperatures @ V_{gs} = 6V.jpg');
figure(f2);
    hold all
    grid on
    ax = gca;
    title('I_{DS} vs V_{DS} Graph @ T_j = 25{\circ}','FontSize',12,'FontWeight','bold','Color','k');
    xlabel('V_{DS}(V)','FontSize',12,'FontWeight','bold','Color','k');
    ylabel('I_{DS}(A)','FontSize',12,'FontWeight','bold','Color','k');
    ax.FontSize = 12;
    ax.XTick = [0:1:5];
    ax.YTick = [0:10:80];
    xlim([0 5])
    for GateIndex = 1:5
    Ids_dummy(:) = Ids(1,GateIndex,:);
    Vds_dummy(:) = Vds_modified(1,GateIndex,:);
    plot(Vds_dummy , Ids_dummy,'LineWidth',3.0);
    clear Ids_dummy;
    clear Vds_dummy;
    end
    legend('2V','3V','4V','5V','6V','Location','NorthWest');
    hold off
    saveas(f2, 'I_{DS} vs V_{DS} Graph @ T_j = 25.jpg');
figure(f3);
    hold all
    grid on
    ax = gca;
    title('I_{DS} vs V_{DS} Graph @ T_j = 150{\circ}','FontSize',12,'FontWeight','bold','Color','k');
    xlabel('V_{DS}(V)','FontSize',12,'FontWeight','bold','Color','k');
    ylabel('I_{DS}(A)','FontSize',12,'FontWeight','bold','Color','k');
    ax.FontSize = 12;
    ax.XTick = [0:1:5];
    ax.YTick = [0:5:30];
    xlim([0 5])
    for GateIndex = 1:5
    Ids_dummy(:) = Ids(6,GateIndex,:);
    Vds_dummy(:) = Vds_modified(6,GateIndex,:);
    plot(Vds_dummy , Ids_dummy,'LineWidth',3.0);
    clear Ids_dummy;
    clear Vds_dummy;
    end
    legend('2V','3V','4V','5V','6V','Location','NorthWest');
    hold off
    saveas(f3, 'I_{DS} vs V_{DS} Graph @ T_j =150.jpg');
    
 %% Loop Reverse
clear Vds_modified; clear Vds; clear Vgs; clear Ids;
cur = 4.5057;
x0 = 0.31 ;
x1 = 0.255;
slp = 2;
Vgs = [-2,0,6];
Vds = -10:0.1:0;

    K = cur * 0.8 * ((25 - 25 + 273)/300)^(-2.7);
    for GateIndex = 1:3
        for DSIndex = 1:101
            Vgd = Vgs(GateIndex) - Vds(DSIndex);
            if Vds(DSIndex) > 0
                Ids(GateIndex,DSIndex) = K*log(1+exp(26*(Vgs(GateIndex)-1.7)/slp))*(Vds(DSIndex))/(1+max((x0+x1*(Vgs(GateIndex)+4.1)),0.2)*Vds(DSIndex));
            else
                Ids(GateIndex,DSIndex) = -K*log(1+exp(26*(Vgd-1.7)/slp))*(-Vds(DSIndex))/(1+max((x0+x1*(Vgd+6.1)),0.2)*(-Vds(DSIndex)));
            end
        end
    end



    Rs = 3.6 * 0.238 * 0.82 * (1 - (-0.0135*(25 - 25))) / 295 + 1e-4;
    Rd = (3.6/4) * (0.95*0.82*(1 - (-0.0135*(25 - 25))) * 18.2 / 295) + 1e-4;
    for GateIndex = 1:3
        for DSIndex = 1:101
            Vds_modified(GateIndex,DSIndex) = Ids(GateIndex,DSIndex) * (Rs + Rd) + Vds(DSIndex);
        end
    end

 %% Reverse Plot
 f4 = figure('Name','I_{SD} vs V_{SD} Graph at T_{j}  25');
    figure(f4);
    hold all
    grid on
    ax = gca;
    
    title('I_{SD} vs V_{SD} Graph at T_{j} = 25{\circ}','FontSize',12,'FontWeight','bold','Color','k');
    xlabel('V_{SD}(V)','FontSize',12,'FontWeight','bold','Color','k');
    ylabel('I_{SD}(A)','FontSize',12,'FontWeight','bold','Color','k');
    ax.FontSize = 12;
    ax.XTick = [0:2:10];
    ax.YTick = [0:20:120];
    xlim([0 10])
    for GateIndex = 1:3
    Ids_dummy(:) = Ids(GateIndex,:);
    Vds_dummy(:) = Vds_modified(GateIndex,:);
    plot(-Vds_dummy , -Ids_dummy,'LineWidth',3.0);
    clear Ids_dummy;
    clear Vds_dummy;
    end
    legend('-2V','0V','6V','Location','NorthWest');
    hold off
    saveas(f4, 'I_{SD} vs V_{SD} Graph for Different GS Voltages @ 25C.jpg');