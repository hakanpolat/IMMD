function [ColumnG,ValueG,TotalG] = matrix_multiplication(colHT,valHT,totHT,colH,valH,totH)

%ValueHT = [1 2 3 5 2 1 2 1 2];
%CHT = [1 2 2 5 3 5 4 2 4 ];
%TotalHT = [1 3 5 7 8 10];

%ValueH = [3 2 1 3 5 2 1 3];
%CH = [3 4 5 1 2 1 3 5];
%TotalH = [1 2 4 5 6 9];

sayac = 0;
ColumnG = [];
ValueG = [];
TotalG = 1;
for i = 1:length(totHT)-1
    for j = 1:length(totHT)-1
        temp =0;
        nonzero = totHT(i+1)-totHT(i);    % Total Number of zero in a row
        for k = 1:nonzero
            a =colHT(totHT(i)+k-1); % This gives the nonzero columns
            % Now, we need to go to rows corresponding to these columns
            b = totH(a+1)-totH(a);
            for say = 1:b
                c = colH(totH(a)+say-1);  % Column number in the corresponding row
                if c == j
                    temp = temp+valHT(totHT(i)+k-1)*valH(totH(a)+say-1);
                    sayac = sayac+1;
                end
            end
        end
        if temp ~= 0
            ValueG  = [ValueG temp];
            ColumnG = [ColumnG j];
        end
        if j == length(totHT)-1
            TotalG = [TotalG length(ColumnG)+1];
        end
    end
    
end


end

