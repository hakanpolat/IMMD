function [ColumnG,ValueG,TotalG] = matrix_multiplication(colHT,valHT,totHT,colH,valH,totH)
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

