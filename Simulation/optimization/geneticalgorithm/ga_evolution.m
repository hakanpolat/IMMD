function gastr = ga_evolution(gastr)
Chrom = gastr.Chrom;
Objv = inf(gastr.Nind,1);
for i = 1:gastr.Nind
    if isempty(gastr.ObjvfunPar)
        Objv(i) = feval(gastr.Objvfun,Chrom(i,:));
    else
        Objv(i) = feval(gastr.Objvfun,Chrom(i,:),gastr.ObjfunPar);
    end
end
gastr.Objv = Objv;

% Best individual of the generation
[v,p] = min(gastr.Objv);
if v <= gastr.fxmin
    gastr.xmin = Chrom(p,:);
    gastr.fxmin = v;
end

% Next generation

% Ranking
[~,pos] = sort(Objv);
FitV(pos) = flipud(gastr.rf);
FitV = FitV';

% Selection
% Stochastic Universal Sampling (SUS)
SelCh = ev_select('sus',Chrom,FitV,1);

% CROSSOVER ---------------------------------------------------
% Uniform crossover.
SelCh = lxov(SelCh,gastr.Pc,gastr.alfa);

% MUTATION ------------------------------------------------
Chrom = mutbga(SelCh,gastr.FieldD,[gastr.Pm 1]);

% Reinsert the best individual
Chrom(round(gastr.NIND/2),:) = gastr.xmin;
gastr.Chrom = Chrom;

% Optional additional task required by user
gaiteration(gastr)

end