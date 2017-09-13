%min f(x) = 100 * (x1^2 - x2) ^2 + (1 - x1)^2;
%x1*x2 + x1 - x2 + 1.5 <=0, (nonlinear constraint)
%10 - x1*x2 <=0,            (nonlinear constraint)
%0 <= x1 <= 1, and          (bound)
%0 <= x2 <= 13              (bound)
% %%
% function y = simple_fitness(x)
% y = 100 * (x(1)^2 - x(2)) ^2 + (1 - x(1))^2;
% %%
% function [c, ceq] = simple_constraint(x)
% c = [1.5 + x(1)*x(2) + x(1) - x(2);
% -x(1)*x(2) + 10];
% ceq = [];
%%
ObjectiveFunction = @simple_fitness;
nvars = 2;    % Number of variables
LB = [0 0];   % Lower bound
UB = [1 13];  % Upper bound
ConstraintFunction = @simple_constraint;
[x,fval] = ga(ObjectiveFunction,nvars,[],[],[],[],LB,UB, ...
    ConstraintFunction)
%%
%x = 0.8122   12.3104
%fval = 1.3574e+04
