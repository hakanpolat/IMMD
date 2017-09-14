function SelChr = ev_select(Selef,Chrom,FitV,GGAP)


% SelChr = select('sus',Chrom,Fitv,1);

% Selection Function
if (nargin==3) %  No overlap -------------------
    if strcmp(Selef,'rws')
        % Roulette wheel selection method
        indices = rws(Fitv,length(Fitv));
        SelChr = Chrom(indices,:);
    elseif strcmp(Selef,'sus')
        % Stochastic unversal sampling selection
        indices = sus(FitV,length(FitV));
        SelChr = Chrom(indices,:);
    else
        error('Incorrect selection method');
    end
    
elseif (nargin==4) % With overlap -----------------------------
	% Indexes of new individuals
    if strcmp(Selef,'rws')
        indices = rws(Fitv,round(length(Fitv)*GGAP));
    elseif strcmp(Selef,'sus')
        indices = sus2(Fitv,round(length(Fitv)*GGAP));
    else
        error('Incorrect selection method');
    end
    if (GGAP < 1) % there is overlap
        % Members of the population to overlap
        oldpos = (1:length(Fitv))';
        for k = 1:length(Fitv)
            pos=round(rand*length(Fitv)+0.5);
            % exchange indexes
            oldpos([pos k]) = oldpos([k pos]);
        end
        oldpos = oldpos(1:round(length(Fitv)*GGAP));
        SelChr = Chrom;
        SelChr(oldpos,:)=Chrom(indices,:);
    else % more childs than parents
        SelChr = Chrom(indices,:);
    end
else
    error('Incorrect number of paramenters');
end

% Disorder the population.
[~,indi] = sort(rand(length(Fitv),1));
SelChr = SelChr(indi,:);

end



