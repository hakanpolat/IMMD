%function outp = gacode(gastr)

%Nvar = phenotype
%Nind = population size
%gastr = genetic algorithm input data structure
%gastr.bounds = [LB;UB]
%gastr.objfun = 'costFunction'
%gastr.Nvar = Nvar % phenotype
%gastr.maxgen = gastr.Nvar*20+10 % maximum number of generations
%gastr.Nind = gastr.Nvar*50 % population size
%gastr.alfa = 0  % linear crossover
%gastr.Pc = 0.9 % crossover probability
%gastr.Pm = 0.1 % Mutation probability
%gastr.indinit = [] % Initialized members of the initial population

% Define data structure
%clear gastr
clear all
lb = [0,0];
ub = [5,7];
gastr.bounds = [lb;ub];
gastr.Objvfun = 'objective_func';
gastr.Nvar = size(gastr.bounds,2);
%gastr.maxgen = gastr.Nvar*20+10;
gastr.maxgen = gastr.Nvar*2+10;
%gastr.Nind = gastr.Nvar*50;
gastr.Nind = gastr.Nvar*5;
gastr.alfa = 0;
gastr.Pc = 0.9;
gastr.Pm = 0.1;
gastr.indinit = [];
disp(gastr);

% Internal function definitions
gastr.Chrom = [];
gastr.Objv = [];
gastr.xmin = [];
gastr.fxmin = inf;
gastr.xmingen = [];
gastr.fxmingen = [];
gastr.ObjvfunPar = [];
gastr.rf = (1:gastr.Nind)';
gastr.gen = 0;

genctr = 0;
% create initial population
gastr.Chrom = init_population(gastr.Nvar,gastr.Nind,gastr.bounds);
if not(isempty(gastr.indinit))
    nind0 = size(gastr.indinit,1);
    position0 = ceil(rand(1,nind0)*gastr.Nind);
    gastr.Chrom(position0,:) = gastr.indinit;
end

%%
while (gastr.gen < gastr.maxgen)
    genctr = genctr + 1;
    gastr.gen = genctr;
    gastr = gaevolution(gastr);
    gastr.xmingen(genctr+1,:) = gastr.xmin;
    gastr.fxmingen(genctr+1,:) = gastr.fxmin;
    %genctr = genctr + 1;
end








%outp = gastr;
%end