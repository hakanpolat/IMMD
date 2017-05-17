clear all
clc

ValueH = [3 2 1 3 5 2 1 3];
CH = [3 4 5 1 2 1 3 5];
TotalH = [1 2 4 5 6 9];

%Row Number
row = numel(TotalH)-1;
column = max(CH); % If a column is zero at most right, this is wrong !

TotalT=1;
ValueT = [];
CT =  [];

for i = 1:column
    temp = find(CH==i);
    Totaltemp = TotalT(end)+numel(temp);
    TotalT = horzcat(TotalT,Totaltemp);
    
    
    for j = 1:numel(temp)
        Valuetemp(j) = ValueH(temp(j));
        Ctemp = zeros(1,numel(temp));
        for f = 1:row
            if (temp(j)>=TotalH(f) && temp(j)<TotalH(f+1))
                Ctemp=f
                CT = horzcat(CT,Ctemp);
            end
        end   
        
    end
        
    ValueT = horzcat(ValueT,Valuetemp);
    Valuetemp = [];
end
