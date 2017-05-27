clear all
clc
ColumnG = [ 3 , 2 , 3 , 4 , 3 , 5 , 4] ;
ValueG= [3, 3, 1 , 2 , 2,3,3] ;
TotalG= [1, 1 , 2 , 5 , 7 ,8 ] ;
tic

Columnzero = [] ;
Valuezero= [] ;
Totalzero= [1] ;
zerocounter = 0;
i = 1;


Valuea= [] ;
Columna = [] ;
Totala= [1] ;

    ValueB = ValueG;
    ColumnB = ColumnG;
    TotalB = TotalG;
while i <= 2
    
    
    nonzeros = TotalG(i+1) - TotalG(i);
    
    Totalzero = [ Totalzero Totalzero(end)];
    
    if nonzeros == 0  % && zerocounter ~=0
        d = 1 ;
        
        if zerocounter ~=0
            Totalzero(end)=Totalzero(end)+1
            Valuezero = [Valuezero zerocounter];
            Columnzero = [Columnzero 1];

            
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
            Valuezero = [Valuezero zerocounter];
            Columnzero = [Columnzero 1];
            Totalzero(end) = Totalzero(end)+1;
            end 
            zerocounter = zerocounter +1;
          
        end
    end
    

    
    
    % Construction of a for Cholesky
    
    rowb = numel(TotalB)-1;
    ara = find(ColumnB ==i);
    for g = 1: numel(ara)
        if ColumnB(g) ~=1
            Valuea = [Valuea ValueB(g)];
            Columna = [Columna 1];
            Totala = [Totala Totala(end)+1];
                 
        end

        % ?lk rowu sil
silin = TotalB(2)-Total(1);
for i =1:silin
ValueB(i) = [];
ColumnB(i) = = [];

end



for k =1:numel(TotalB)
    TotalB(k) = TotalB(k)-silin;
end

TotalB(1) = [];

% S?ra ilk columnu silmede :
 
c1 = find(ColumnB == 1)

for k = 1:numel(c1)
    
    
end
    
    



[ColumnaT,ValueaT,TotalaT] = matrix_transpose(Columna,Valuea,Totala);
[ColumnaaT,ValueaaT,TotalaaT]=matrix_multiplication(Columna,Valuea,Totala,ColumnaT,ValueaT,TotalaT,numel(TotalG)-1-i);
ValueaaT = ValueaaT / d ;
[ColumnB, ValueB,TotalB] = matrix_sub(ColumnB,ValueB,TotalB,ColumnaaT,ValueaaT,TotalaaT);
  
            Valuea = [];
            Columna = [];
            Totala = [];   
            
    
        
    end
    i = i +1 ;
end
    
    toc 
    
    
    

