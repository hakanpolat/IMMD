clear all
clc
ColumnG = [ 3 , 2 , 3 , 4 , 3 , 5 , 4] ;
ValueG= [3, 3, 1 , 2 , 2,3,3] ;
TotalG= [1, 1 , 2 , 5 , 7 ,8 ] ;

Columnzero = [] ;
Valuezero= [] ;
Totalzero= [1] ;
zerocounter = 0;
i = 1;

while i <=(numel(TotalG)-1)
    
    nonzeros = TotalG(i+1) - TotalG(i);
    
    Totalzero = [ Totalzero Totalzero(end)]
    
    if nonzeros == 0
        d = 1 ;
        Totalzero(end)=Totalzero(end)+1
        if zerocounter ~=0
            Valuezero = [Valuezero zerocounter]
            Columnzero = [Columnzero 1]
            
        end
        zerocounter = zerocounter +1;
    end
    
    for j = 1:nonzeros
        a = ColumnG(TotalG(i)+j-1);
        if TotalG(i)+j <= numel(ValueG)
        a2 = ColumnG(TotalG(i)+j);
        else 
            a2 = a;
        end
        
        if  a == i
            d = ValueG(TotalG(i)+j-1);
           
        end
        
        if (a < i && j == nonzeros ) || (a > i && j == 1 ) || (a < i && a2>i ) 
            %          (a < i && j == nonzeros ) || (a > i && j == 1 ) || (a < i && a2>i ) || (TotalG(i+1)-TotalG(i) == 0)
            
         
            d = 1;
            if zerocounter ~=0
            Valuezero = [Valuezero zerocounter]
            Columnzero = [Columnzero 1]
            Totalzero(end) = Totalzero(end)+1
            end 
            zerocounter = zerocounter +1;
          
        end
    end
    
    ValueB = ValueG;
    ColumnB = ColumnG;
    TotalB = TotalG;
    
    
    % Construction of a for Cholesky
    
    rowb = numel(TotalB)-1;
    ara = find(ColumnB ==i)
    for g = 1: numel(ara)
        if TotalB(2) TotalB(ColumnB(g))
            
 
            
        end
    
    i = i +1 ;
        
    end
end
    
    
    
    
    

