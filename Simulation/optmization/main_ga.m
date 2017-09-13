% Toolbox of MATLAB (ga function)

% ObjectiveFunction = @simple_fitness; % Fitness function
% nvars = 2;    % Number of variables
% LB = [0 0];   % Lower bound
% UB = [1 13];  % Upper bound
% ConstraintFunction = @simple_constraint; % Constraint function
% [x,fval] = ga(ObjectiveFunction,nvars,[],[],[],[],LB,UB, ...
%     ConstraintFunction);

%%
% Define data structure
clear gastr
lb = [0,0,1];
ub = [5,7,4];
gastr.bounds = [lb;ub];
gastr.objfun = 'simple_fitness';
gastr.Nvar = size(gastr.bounds,2);
gastr.maxgen = gastr.Nvar*20+10;
gastr.Nind = gastr.Nvar*50;
gastr.alfa = 0;
gastr.Pc = 0.9;
gastr.Pm = 0.1;
gastr.indinit = [];
disp(gastr);
% Call genetic algorithm function
myresult = gacode(gastr);

