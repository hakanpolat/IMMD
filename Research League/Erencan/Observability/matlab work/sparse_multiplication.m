clear all
clc
tic
n = 5;

ValueHT = [1 2 3 5 2 1 2 1 2];
CHT = [1 2 2 5 3 5 4 2 4 ];
TotalHT = [1 3 5 7 8 10];

ValueH = [3 2 1 3 5 2 1 3];
CH = [3 4 5 1 2 1 3 5];
TotalH = [1 2 4 5 6 9];
sayac = 0;

ValueG = [];
for i = 1:length(TotalHT)-1
    for j = 1:length(TotalHT)-1
    temp =0;
    
    nonzero = TotalHT(i+1)-TotalHT(i);    % Total Number of zero in a row
    
    for k = 1:nonzero
        
        
        a =CHT(TotalHT(i)+k-1); % This gives the nonzero columns
        
        % Now, we need to go to rows corresponding to these columns
        b = TotalH(a+1)-TotalH(a);
        for say = 1:b
            
            c = CH(TotalH(a)+say-1);  % Column number in the corresponding row
            
            if c == j
                temp = temp+ValueHT(TotalHT(i)+k-1)*ValueH(TotalH(a)+say-1);
                sayac = sayac+1;
                
            end
            
            
        end
        
        
    end
    ValueG  = horzcat(ValueG,temp);
    end
    
end

toc

