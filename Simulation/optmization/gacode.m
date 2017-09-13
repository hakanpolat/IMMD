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

% Internal function definitions
gastr.Chrom = [];
gastr.ObjV = [];
gastr.xmin = [];
gastr.fxmin = inf;
gastr.xmingen = [];
gastr.fxmingen = [];
gastr.rf = (1:gastr.Nind)';
gastr.gen = 0;

gen = 0;
% create initial chromsomes
%gastr.Chrom = WRITE THIS FUNCTION
% create initial population
%gastr.indinit = WRITE THIS FUNCTION

if not(isempty(gastr.indinit))
    nind0 = size(gastr.indinit,1)
    posicion0=ceil(rand(1,nind0)*gastr.Nind)
    gastr.Chrom(posicion0,:) = gastr.indinit
end









outp = gastr;

%end