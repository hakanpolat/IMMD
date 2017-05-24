clear all
clc
ColumnG = [ 3 , 2 , 3 , 4 , 3 , 5 , 4] ;
ValueG= [3, 3, 1 , 2 , 2,3,3] ;
TotalG= [1, 1 , 2 , 5 , 7 ,8 ] ;

Columnzero = [] ;
Valuezero= [] ;
Totalzero= 1 ;
zerocounter = 0;

ValueB = ValueG;
ColumnB = ColumnG;
TotalB = TotalG;


for i = 1: numel(TotalG)-1
    
    elb = numel(TotalB)-1;
    
    
    % Tek eleman kald?ysa ve o eleman nonzero ise
    if elb==1 && ValueB(1) ~=0   % If it has at least two rows ! If not it will give error !
        
        d = ValueB(1);
        disp('mal1')
        
    end
    
    % Tek eleman kald?ysa ve o eleman zero ise
    if elb==1 && ValueB(1) ==0   % If it has at least two rows ! If not it will give error !
        
        d = 1;
        disp('mal2')
        zerocounter = zerocounter +1 ;
        
        
    end
    
    % En az iki eleman kald?ysa
    if elb>1 && TotalB(2)- TotalB(1) ~=0 % If it has at least two rows ! If not it will give error !
        if ColumnB(1) == i
            d = ValueB(1);
            disp('mal3')
            
        end
        if ColumnB(1) ~= i
            d = 1;
            disp('mal4')
            
        end
        
        
    end
    
    
    
    % ?ki rowun silinmesi
    
    if elb>1
        
        silinecek = TotalB(2)-TotalB(1);
        
        
        
        if silinecek ~=0
            for j = 1:silinecek
                
                TotalB=  TotalB - silinecek * eye(1,numel(TotalB));
                TotalB(1) = [];
                
            end
            
            
        end
    end
    
    if elb ==1 
        
        TotalB(1) = [] ;
    end
    
end

