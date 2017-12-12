function SelChr = ev_select(Selef,Chrom,FitV,GGAP)

% Indexes of new individuals
if strcmp(Selef,'rws')
    indices = rws(FitV,round(length(FitV)*GGAP));
elseif strcmp(Selef,'sus')
    indices = sus(FitV,round(length(FitV)*GGAP));
end

SelChr = Chrom(indices,:);

% Disorder the population.
[~,indi] = sort(rand(length(FitV),1));
SelChr = SelChr(indi,:);

    function NewChrIx = sus(FitV,Nsel)
        suma = sum(FitV);
        % Position of the roulette pointers
        j = 0;
        sumfit = 0;
        paso = suma/Nsel; % distance between pointers
        flecha = rand*paso; % offset of the first pointer
        NewChrIx(Nsel,1) = 0;
        for i = 1:Nsel
            sumfit = sumfit + FitV(i);
            while (sumfit >= flecha)
                j = j+1;
                NewChrIx(j) = i;
                flecha = flecha + paso;
            end
        end
        
    end

end


