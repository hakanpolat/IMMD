%% Data Configurations
fc = 10e6;
Wn = (2/25000000)*fc;
filt = fir1(20,Wn,'low',kaiser(21,3));
BotONIloadF = filter(Hlp2,BotONIload);
BotOFFIloadF = filter(Hlp2,BotOFFIload);
% BotONIloadF = BotONIload;
% BotOFFIloadF = BotOFFIload;
BotONV25mF = filter(Hlp2,BotONV25m);
BotOFFV25mF = filter(Hlp2,BotOFFV25m);
% BotONV25mF = BotONV25m;
% BotOFFV25mF = BotOFFV25m;

BotOFFIdsBot = 7.408/0.304 * BotOFFV25mF;
BotONIdsBot = 7.408/0.304 * BotONV25mF;

TopONVdsTop = 100 - (BotOFFVdsBot + BotOFFV25mF);
TopOFFVdsTop = 100 - (BotONVdsBot + BotONV25mF);

TopONIdsTop = BotOFFIdsBot - 10*BotOFFIloadF;
TopOFFIdsTop = BotONIdsBot - 10*BotONIloadF;
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
%     ylim([-20 20])
    SampleRange = 12499;
    SampleMid = 12500;
    SampleBeg = SampleMid - SampleRange;
    SampleEnd = SampleMid + SampleRange;
    plot( (SampleBeg:SampleEnd)/5e9 , 0.1*BotOFFVdsBot(SampleBeg:SampleEnd),'LineWidth',3.0);
    plot( (SampleBeg:SampleEnd)/5e9 , BotOFFVgsBot(SampleBeg:SampleEnd),'LineWidth',3.0);    
    plot( (SampleBeg:SampleEnd)/5e9 , BotOFFIdsBot(SampleBeg:SampleEnd),'LineWidth',1.0);    
    plot( (SampleBeg:SampleEnd)/5e9 , 10*BotOFFIloadF(SampleBeg:SampleEnd),'LineWidth',3.0);  
    legend('Vds(V)','Vgs(V)','Ids(A)','IloadF(A)','Location','Best');
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
%     ylim([-20 20])
    SampleRange = 12499;
    SampleMid = 12500;
    SampleBeg = SampleMid - SampleRange;
    SampleEnd = SampleMid + SampleRange;
    plot( (SampleBeg:SampleEnd)/5e9 , 0.1*BotONVdsBot(SampleBeg:SampleEnd),'LineWidth',3.0);
    plot( (SampleBeg:SampleEnd)/5e9 , BotONVgsBot(SampleBeg:SampleEnd),'LineWidth',3.0);    
    plot( (SampleBeg:SampleEnd)/5e9 , BotONIdsBot(SampleBeg:SampleEnd),'LineWidth',1.0);
    plot( (SampleBeg:SampleEnd)/5e9 , 10*BotONIloadF(SampleBeg:SampleEnd),'LineWidth',3.0);  
    legend('Vds(V)','Vgs(V)','Ids(A)','IloadF(A)','Location','Best');
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
%     ylim([-20 20])
    SampleRange = 12499;
    SampleMid = 12500;
    SampleBeg = SampleMid - SampleRange;
    SampleEnd = SampleMid + SampleRange;
    plot( (SampleBeg:SampleEnd)/5e9 , 0.1*TopOFFVdsTop(SampleBeg:SampleEnd),'LineWidth',3.0);
    plot( (SampleBeg:SampleEnd)/5e9 , TopOFFVgsTop(SampleBeg:SampleEnd),'LineWidth',3.0);    
    plot( (SampleBeg:SampleEnd)/5e9 , TopOFFIdsTop(SampleBeg:SampleEnd),'LineWidth',1.0);
    plot( (SampleBeg:SampleEnd)/5e9 , 10*BotONIloadF(SampleBeg:SampleEnd),'LineWidth',3.0); 
%     plot( (SampleBeg:SampleEnd)/5e9 , 0.1*TopOFFVdsBot(SampleBeg:SampleEnd),'LineWidth',3.0);
%     plot( (SampleBeg:SampleEnd)/5e9 , TopOFFVgs(SampleBeg:SampleEnd),'LineWidth',3.0);    
%     plot( (SampleBeg:SampleEnd)/5e9 , 7.811/0.3625*TopOFFV25mF(SampleBeg:SampleEnd),'LineWidth',3.0);
%     plot( (SampleBeg:SampleEnd)/5e9 , 10*TopOFFIloadF(SampleBeg:SampleEnd),'LineWidth',3.0);  
    legend('Vds(V)','Vgs(V)','Ids(A)','IloadF(A)','Location','Best');
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
%     ylim([-20 20])
    SampleRange = 12499;
    SampleMid = 12500;
    SampleBeg = SampleMid - SampleRange;
    SampleEnd = SampleMid + SampleRange;
    plot( (SampleBeg:SampleEnd)/5e9 , 0.1*TopONVdsTop(SampleBeg:SampleEnd),'LineWidth',3.0);
    plot( (SampleBeg:SampleEnd)/5e9 , TopONVgsTop(SampleBeg:SampleEnd),'LineWidth',3.0);    
    plot( (SampleBeg:SampleEnd)/5e9 , TopONIdsTop(SampleBeg:SampleEnd),'LineWidth',1.0);
    plot( (SampleBeg:SampleEnd)/5e9 , 10*BotOFFIloadF(SampleBeg:SampleEnd),'LineWidth',3.0);  
    legend('Vds(V)','Vgs(V)','Ids(A)','IloadF(A)','Location','Best');
    hold off
    %saveas(f1, 'I_{DS} vs V_{DS} Graph for Different Temperatures @ V_{gs} = 6V.jpg'); 
%% Dock Figures
    linkaxes(ha, 'x');
    linkaxes(hb, 'x');
% h = [f1,f2,f3,f4];
% set(h,'WindowStyle','Docked');