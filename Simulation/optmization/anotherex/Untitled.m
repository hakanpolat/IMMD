%%
% I. Setup the GA parameters
ff = inline('sum(x,2)'); % fitness function
maxit = 20; % maximum number of iterations (for stopping criteria)
maxcost = 500; % maximum allowable cost (for stopping criteria)
popsize = 6; % set population size
mutrate = 0.001; % set mutation rate
nbits = 5; % number of bits in each parameter
npar = 1; % number of parameters in each chromosome
Nt = nbits*npar; % total number of bits in a chromosome

%%
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

%%
% III. MAIN LOOP
while iga < maxit
    iga = iga+1; % increments generation counter
    % Choose mates
    M = ceil(popsize/2); % number of matings
    %ma = RandChooseN(probs,M); % mate #1
    %pa = RandChooseN(probs,M); % mate #2
    ma = datasample(pop,3); % mate #1
    pa = datasample(pop,3); % mate #2
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

%% VI. Displays the output as shown in Figure
day = clock;
disp(datestr(datenum(day(1),day(2),day(3),day(4),day(5),day(6)),0))
format short g
disp(['popsize=' num2str(popsize) 'mutrate=' num2str(mutrate) '# par=' num2str(npar)]);
disp(['#generations = ' num2str(iga) ' best cost = ' num2str(cost(1))]);
fprintf('best solution\n%s\n',mat2str(int8(pop(1,:))));
figure(1)
iters=0:length(maxc)-1;
plot(1:(iga+1),maxc,1:(iga+1),meanc);
xlabel('Generation');ylabel('Cost')

