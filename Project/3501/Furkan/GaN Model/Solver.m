profile on
tic
tspan = [0 400e-9];
x0 = zeros(4,1);
[tout,xout] = ode45(@GaN, tspan, x0);
toc
profile off
profile viewer

figure;
hold all
grid on
plot(tout,xout(:,1),tout,xout(:,2),tout,xout(:,3),tout,xout(:,4),'Linewidth',2.0);
%xlim([0]);
ylim([-80 200]);
%xlim([0 400e-9]);
xlabel('Time');
ylabel('Voltage,Ampere');
title({'Ids, Vds, Ig, Vgs'})
legend ('Ids','Ig','Vgs','Vds','Location','best');
hold off

% [N,~]=size(tout);
% 
% for i=1:N
%     vgs = xout(i,3);
%     vds = xout(i,4);
%     vgd = vgs - vds;
% cur = 4.5057; % To be updated
% K = cur * 0.8 * (273/300)^(-2.7);
% x0 = 0.31 ;
% x1 = 0.255;
% slp = 2;
% if vds>=0
%             Ich(i) = K*log(1+exp(26*(vgs-1.7)/slp))*(vds)/(1+max((x0+x1*(vgs+4.1)),0.2)*vds);
% else
%             Ich(i) = -K*log(1+exp(26*(vgd-1.7)/slp))*(-vds)/(1+max((x0+x1*(vgd+6.1)),0.2)*(-vds));
% end
% end

