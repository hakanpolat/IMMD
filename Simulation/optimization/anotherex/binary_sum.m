clear all;
close all;
clc;
% I. Setup the GA parameters
ff = inline('sum(x,2)'); % fitness function
maxit = 200; % maximum number of iterations (for stopping criteria)
maxcost = 999999; % maximum allowable cost (for stopping criteria)
popsize = 100; % set population size
mutrate = 0.001; % set mutation rate
nbits = 20; % number of bits in each parameter
npar = 1; % number of parameters in each chromosome
Nt = nbits*npar; % total number of bits in a chromosome

% II. Create the initial population
iga = 0; % generation counter initialized
pop = round(rand(popsize,Nt)); % random population of 1’s and 0’s (100 x 20 matrix)
% Initialize cost and other items to set up the main loop
cost = feval(ff,pop); % calculates population cost using ff
[cost,ind] = sort(cost,'descend'); % max element in first entry
pop = pop(ind,:); % sorts population with max cost first
maxc(1) = max(cost); % minc contains min of population
meanc(1) = mean(cost); % meanc contains mean of population
probs = cost/sum(cost); % simple normalization for probabilities

% III. MAIN LOOP
while iga < maxit
    iga = iga+1; % increments generation counter
    % Choose mates
    M = ceil(popsize/2); % number of matings
    % roulette selection
    binedges = [0,cumsum(probs(:)')];
    roulette = zeros(1,M);
    for k = 1:M
        x1 = rand;
        counts = histcounts(x1,binedges);
        roulette(k) = find(counts==1);
    end
    ma = roulette;
    binedges = [0,cumsum(probs(:)')];
    roulette = zeros(1,M);
    for k = 1:M
        x1 = rand;
        counts = histcounts(x1,binedges);
        roulette(k) = find(counts==1);
    end
    pa = roulette;
    %ma = randperm(popsize,M); % mate #1
    %pa = randperm(popsize,M); % mate #2
    % ma and pa contain the indices of the chromosomes that will mate
    xp = ceil(rand(1,M)*(Nt-1)); % crossover point
    pop(1:2:popsize,:) = [pop(ma,1:xp(1)) pop(pa,xp(1)+1:Nt)]; % first offspring
    pop(2:2:popsize,:) = [pop(pa,1:xp(1)) pop(ma,xp(1)+1:Nt)]; % second offspring
    % Mutate the population
    nmut = ceil((popsize-1)*Nt*mutrate); % total number of mutations
    mrow = ceil(rand(1,nmut)*(popsize-1))+1; % row to mutate
    mcol = ceil(rand(1,nmut)*Nt); % column to mutate
    for ii=1:nmut
        pop(mrow(ii),mcol(ii)) = abs(pop(mrow(ii),mcol(ii))-1); % toggles bits
    end % ii
    
    % IV. The population is re-evaluated for cost
    cost = feval(ff,pop); % calculates population cost using fitness function
    [cost,ind] = sort(cost,'descend'); % maximum element in first entry
    pop = pop(ind,:); % sorts population with maximum cost first
    maxc(iga+1) = max(cost);
    meanc(iga+1) = mean(cost);
    probs = cost/sum(cost);
    
    % V. Stopping criteria
    if iga > maxit || cost(1) > maxcost
        break;
    end
end

% VI. Displays the output as shown in Figure
fprintf('\nGeneration number = %g.\n',iga);
fprintf('Best cost = %g.\n',cost(1));
fprintf('Best solution =.\n');
disp(pop(1,:))
figure(1)
iters=0:length(maxc)-1;
plot(1:(iga+1),maxc,1:(iga+1),meanc);
xlabel('Generation');ylabel('Cost')

