%% Plot
f1 = figure('Name','Experimental Results','units','normalized','outerposition',[0 0 1 1]);
%% Bot Turn OFF
%f1 = figure('Name','Bottom Switch Turn OFF Graph');
%figure(f1);
    ha(1) = subplot(2,2,1)
    hold all
    grid on
    ax = gca;
    title('Experimental Results of Bottom Switch Turn Off Graph','FontSize',12,'FontWeight','bold','Color','k');
    xlabel('Time Axis(sec)','FontSize',12,'FontWeight','bold','Color','k');
    ylabel('Results','FontSize',12,'FontWeight','bold','Color','k');
    ax.FontSize = 12;
%     ax.YTick = [0:20:120];
%     xlim([0 5.1])
    SampleRange = 12499;
    SampleMid = 12500;
    SampleBeg = SampleMid - SampleRange;
    SampleEnd = SampleMid + SampleRange;
    plot( (SampleBeg:SampleEnd)/5e9 , 0.1*TopONVdsBot(SampleBeg:SampleEnd,2),'LineWidth',3.0);
    plot( (SampleBeg:SampleEnd)/5e9 , BotOFFVgsBot(SampleBeg:SampleEnd,2),'LineWidth',3.0);    
    plot( (SampleBeg:SampleEnd)/5e9 , 7.811/0.3625*BotOFFV25m(SampleBeg:SampleEnd,2),'LineWidth',3.0);    
    plot( (SampleBeg:SampleEnd)/5e9 , 10*BotOFFIload(SampleBeg:SampleEnd,2),'LineWidth',3.0);  
    legend('Vds(V)','Vgs(V)','Ids(A)','ILoad(A)','Location','Best');
    hold off
    %saveas(f1, 'I_{DS} vs V_{DS} Graph for Different Temperatures @ V_{gs} = 6V.jpg');
%% Bot Turn ON    
% f2 = figure('Name','Bottom Switch Turn ON Graph');
% figure(f2);
    hb(1) = subplot(2,2,2)
    hold all
    grid on
    ax = gca;
    title('Experimental Results of Bottom Switch Turn On Graph','FontSize',12,'FontWeight','bold','Color','k');
    xlabel('Time Axis(sec)','FontSize',12,'FontWeight','bold','Color','k');
    ylabel('Results','FontSize',12,'FontWeight','bold','Color','k');
    ax.FontSize = 12;
%     ax.YTick = [0:20:120];
%     xlim([0 5.1])
    SampleRange = 12499;
    SampleMid = 12500;
    SampleBeg = SampleMid - SampleRange;
    SampleEnd = SampleMid + SampleRange;
    plot( (SampleBeg:SampleEnd)/5e9 , 0.1*TopOFFVdsBot(SampleBeg:SampleEnd,2),'LineWidth',3.0);
    plot( (SampleBeg:SampleEnd)/5e9 , BotONVgsBot(SampleBeg:SampleEnd,2),'LineWidth',3.0);    
    plot( (SampleBeg:SampleEnd)/5e9 , 7.811/0.3625*BotONV25m(SampleBeg:SampleEnd,2),'LineWidth',3.0);
    plot( (SampleBeg:SampleEnd)/5e9 , 10*BotONIload(SampleBeg:SampleEnd,2),'LineWidth',3.0);  
    legend('Vds(V)','Vgs(V)','Ids(A)','ILoad(A)','Location','Best');
    hold off
    %saveas(f1, 'I_{DS} vs V_{DS} Graph for Different Temperatures @ V_{gs} = 6V.jpg');   
%% Top Turn OFF
% f3 = figure('Name','Top Switch Turn OFF Graph');
% figure(f3);
    hb(2) = subplot(2,2,4)  
    hold all
    grid on
    ax = gca;
    title('Experimental Results of Top Switch Turn Off Graph','FontSize',12,'FontWeight','bold','Color','k');
    xlabel('Time Axis(sec)','FontSize',12,'FontWeight','bold','Color','k');
    ylabel('Results','FontSize',12,'FontWeight','bold','Color','k');
    ax.FontSize = 12;
%     ax.YTick = [0:20:120];
%     xlim([0 5.1])
    SampleRange = 12499;
    SampleMid = 12500;
    SampleBeg = SampleMid - SampleRange;
    SampleEnd = SampleMid + SampleRange;
    plot( (SampleBeg:SampleEnd)/5e9 , 0.1*TopOFFVdsTop(SampleBeg:SampleEnd,2),'LineWidth',3.0);
    plot( (SampleBeg:SampleEnd)/5e9 , TopOFFVgsTop(SampleBeg:SampleEnd,2),'LineWidth',3.0);    
    plot( (SampleBeg:SampleEnd)/5e9 , TopOFFIdsTop(SampleBeg:SampleEnd,2),'LineWidth',3.0);
    plot( (SampleBeg:SampleEnd)/5e9 , 10*BotONIload(SampleBeg:SampleEnd,2),'LineWidth',3.0);  
    legend('Vds(V)','Vgs(V)','Ids(A)','ILoad(A)','Location','Best');
    hold off
    %saveas(f1, 'I_{DS} vs V_{DS} Graph for Different Temperatures @ V_{gs} = 6V.jpg');
%% Top Turn ON
% f4 = figure('Name','Top Switch Turn ON Graph');
% figure(f4);
    ha(2) = subplot(2,2,3)
    hold all
    grid on
    ax = gca;
    title('Experimental Results of Top Switch Turn On Graph','FontSize',12,'FontWeight','bold','Color','k');
    xlabel('Time Axis(sec)','FontSize',12,'FontWeight','bold','Color','k');
    ylabel('Results','FontSize',12,'FontWeight','bold','Color','k');
    ax.FontSize = 12;
%     ax.YTick = [0:20:120];
%     xlim([0 5.1])
    SampleRange = 12499;
    SampleMid = 12500;
    SampleBeg = SampleMid - SampleRange;
    SampleEnd = SampleMid + SampleRange;
    plot( (SampleBeg:SampleEnd)/5e9 , 0.1*TopONVdsTop(SampleBeg:SampleEnd,2),'LineWidth',3.0);
    plot( (SampleBeg:SampleEnd)/5e9 , TopONVgsTop(SampleBeg:SampleEnd,2),'LineWidth',3.0);    
    plot( (SampleBeg:SampleEnd)/5e9 , TopONIdsTop(SampleBeg:SampleEnd,2),'LineWidth',3.0);
    plot( (SampleBeg:SampleEnd)/5e9 , 10*BotOFFIload(SampleBeg:SampleEnd,2),'LineWidth',3.0);  
    legend('Vds(V)','Vgs(V)','Ids(A)','ILoad(A)','Location','Best');
    hold off
    %saveas(f1, 'I_{DS} vs V_{DS} Graph for Different Temperatures @ V_{gs} = 6V.jpg'); 
%% Dock Figures
    linkaxes(ha, 'x');
    linkaxes(hb, 'x');
% h = [f1,f2,f3,f4];
% set(h,'WindowStyle','Docked');