function [ColumnC,ValueC,TotalC] = matrix_sub(ColumnA,ValueA,TotalA,ColumnB,ValueB,TotalB)
% ColumnA = [ 1 ,3 , 2, 3,4, 1,2 ];
% ValueA = [ 11 ,10, 9, -2 , 7 , 1 ,5];
% TotalA = [ 1, 3, 6, 6 ,8 ];
% ColumnB = [ 1,2,2,4,3,4,1];
% ValueB = [ 3,2,5,4,7,-1,3];
% TotalB = [ 1,3,5,7,8];

ColumnC = [];
ValueC= [];
TotalC= [1];

row1 = numel(TotalA)-1;
row2 = numel(TotalB)-1;

el1 = numel(ValueA);
el2 = numel(ValueB);

if row1 ~= row2
    disp('Matrix sizes should be matched ! ')
end

% Bu kod kare matrise göre yaz?lm??t?r !
% E?er kare olmayan matris için i?lem yap?lacaksa ikinci for döngüsü
% Column say?s?na kadar saymal?d?r.
for i = 1:row1  %row1
    
%     nonzeroA = TotalA(i+1)-TotalA(i); % Nonzeros in the corresponding row of A
%     nonzeroB = TotalB(i+1)-TotalB(i); % Nonzeros in the corresponding row of B
    
    tempA = ColumnA(TotalA(i):TotalA(i+1)-1);
    tempB = ColumnB(TotalB(i):TotalB(i+1)-1);
    
    common1 = intersect(tempA,tempB);   % Value bu kadar i?lemle yap?lacak
    column =horzcat(tempA,tempB);
    column = unique(column);
    column = sort(column);
    column2 = column;
   
    
    for j = 1:numel(column)
        if   ismember(column(j),common1) ==0
            
            if ismember(column(j),tempA)==1
                sira = find(tempA ==column(j));
                sira = TotalA(i)+ sira-1;
                ValueC = [ValueC ValueA(sira)];
            end
            if ismember(column(j),tempB)==1
                sira = find(tempB ==column(j));
                sira = TotalB(i)+ sira-1;
                ValueC = [ValueC -ValueB(sira)];
            end
            
        end
        if   ismember(column(j),common1) ==1
            sira = find(tempA ==column(j));
            sira = TotalA(i)+ sira-1;
            sira2 = find(tempB ==column(j));
            sira2 = TotalB(i)+ sira2-1;
            result = ValueA(sira)-ValueB(sira2);
            ValueC = [ValueC result];
            
            if result == 0
                
                ValueC(end) = [] ;
                silincek = find(column2==column(j));
                column2(silincek)= [];

            end
            
            
            
        end
        
        
    end
    ColumnC = [ColumnC column2];
    TotalC = [TotalC numel(column2)+TotalC(end)];
end
end