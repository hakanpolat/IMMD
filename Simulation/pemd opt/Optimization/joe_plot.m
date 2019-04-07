%% Interleaving
for i = 1:8
    [intc(i),intv(i)] = interleaving_effect(i,1);
end

%%
figure;
hold all;
plot(1:8,intv,'b x-','Linewidth',2);
plot(1:8,intc,'k o-','Linewidth',2);
grid on;
set(gca,'FontSize',16);
legend('Ripple voltage','Ripple current');
xlabel('Number of parallel connected modules','FontSize',16,'FontWeight','Bold')
ylabel('Normalized ripple','FontSize',16,'FontWeight','Bold')
xlim([0 9]);
ylim([0 1.1]);