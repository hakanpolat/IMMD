function Chrom = init_population(Nvar,Nind,bounds)
aux = rand(Nind,Nvar);
m = [-1 1]*bounds;
ublb = ones(Nind,1)*m;
lb = ones(Nind,1)*bounds(1,:);
Chrom = ublb.*aux+lb;
end
