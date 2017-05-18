clear all 
clc
tic

% Important Variables :
% ValueA,CA,TotalA
% ValueH,CH,TotalH
% ValueG,CG,TotalG

% IEEE CDF data

% Data import
fid = fopen('ieee_cdf.dat');

% Bus Data
Line_String_Complete = fgetl(fid);
Line_String_Complete = fgetl(fid);
Line_String_Numeric = Line_String_Complete(41:46);
No_of_Buses =str2num(Line_String_Numeric);

while strcmp(Line_String_Complete(1:4),'-999')==0
    Line_String_Complete = fgetl(fid);
end
counter =0;

% Line Data
Line_String_Complete = fgetl(fid);
Line_String_Numeric = Line_String_Complete(41:46);
No_of_Branches = str2num(Line_String_Numeric);

ValueA= ones(1,2*No_of_Branches);
CA= zeros(1,2*No_of_Branches);
totalA = ones(1,No_of_Branches+1);

Line_String_Complete = fgetl(fid);
while strcmp(Line_String_Complete(1:4),'-999')==0
    
    Line_String_Numeric = Line_String_Complete(1:4);
    Line_String_Numeric2 = Line_String_Complete(6:9);
    if strcmp(Line_String_Complete(1:4),'-999')==0
        counter = counter+1;
    end
    
    ValueA(2*counter)= -1;
    CA(2*counter-1)= str2double(Line_String_Numeric);
    CA(2*counter)= str2double(Line_String_Numeric2);
    totalA(counter+1) = totalA(counter) + 2;
    
    Line_String_Complete = fgetl(fid);
end

fclose(fid);



% Measurement data
% Data import

fid = fopen('measure.dat');
Line_String_Complete = fgetl(fid);
Line_String_Numeric = str2double(Line_String_Complete);

for i = 1: Line_String_Numeric+1
    Line_String_Complete = fgetl(fid);
end
%The numeric gives the number of power injections
Line_String_Numeric = str2double(Line_String_Complete);



CH = [];
ValueH = [];
TotalH = 1;
for i= 1:Line_String_Numeric
    
    Line_String_Complete = fgetl(fid);
    Line_String_Numeric = str2double(Line_String_Complete(1,1:4));
    temp = find(CA==Line_String_Numeric);
    j = length(temp);  % Bu asl?nda N , -1 , -1 deki N de?eri
    
    Totaltemp = j+1;
    Valuetemp = ones(1,j+1)*-1;
    CHtemp = zeros(1,j+1);
    CHtemp(1,j+1)= Line_String_Numeric;
    for counter = 1:j
      if mod(temp(counter),2)==0
      CHtemp(counter)=  CA(temp(counter)-1);
      else 
      CHtemp(counter)=  CA(temp(counter)+1);
      end
    end
    
    CHtemp = sort(CHtemp);
    Valuetemp(find(CHtemp==Line_String_Numeric))=j;
    
    CH = horzcat(CH,CHtemp);
    ValueH = horzcat(ValueH,Valuetemp);
    TotalH = horzcat(TotalH,Totaltemp);
    
    
end

% Correcting TotalH value
    for counter = 2:length(TotalH)
        TotalH(counter)= TotalH(counter)+TotalH(counter-1);
    end
    
% Now, we should also include power flow measurements to H matrix



 Line_String_Complete = fgetl(fid);
 Line_String_Numeric = str2double(Line_String_Complete(1,1:4));
 
for i = 1: Line_String_Numeric
    Line_String_Complete = fgetl(fid);
end

 Line_String_Complete = fgetl(fid);
 Line_String_Numeric = str2double(Line_String_Complete(1,1:4));
 
 
 Valuetemp = ones(1,2);
 Ctemp = zeros(1,2);
 Totaltemp = 2;
 
for i = 1: Line_String_Numeric
    
    Line_String_Complete = fgetl(fid);
    Line_String_Numeric = str2double(Line_String_Complete(1,1:5));
    Line_String_Numeric2 = str2double(Line_String_Complete(1,6:10));
    
    Valuetemp(1,2)= -1;
    ValueH = horzcat(ValueH,Valuetemp);
    
    Ctemp(1,1)=Line_String_Numeric;
    Ctemp(1,2)=Line_String_Numeric2;
    
    CH =horzcat(CH,Ctemp);
    
    Totaltemp = TotalH(end)+2;
    TotalH = horzcat(TotalH,Totaltemp);
    
end


%======================END OF THE DATA READ=======================

% UNTIL NOW; A AND H MATRICES ARE STORED WHILE DATA READ 

% BU PARÇAYI JACOBIAN TRANSPOSE ICIN KULLANDIM AMA SONRADAN MATRIX
% TRANSPOSE KODU YAZDIM SOLDA VAR BU KOD.(ONCE CONSTRUCT EDIP TRANSPOSE
% ALIP SONRA RESTORE ETMISTIM AMA BOYLE YAPMAK BAYA SACMAYDI KABUL EDIYORUM

% Reconstruction part in order to take the transpose

cons_matrix = 0;
ctr = 0;
row_num = numel(TotalH)-1;

index = 1;

while(1)
    ctr = ctr + 1;
    current_row = ctr;
    row_elnum = TotalH(ctr+1)-TotalH(ctr);
    for k = 1:row_elnum
        col_index = CH(index);
        cons_matrix(current_row,col_index) = ValueH(index);
        index = index+1;
    end
    if ctr == row_num
        break;
    end
end

HT = cons_matrix';


% This function implements sparse storage of any given matrix with
% Gustavson's method

given_matrix = HT;
% given_matrix = H;
%given_matrix = A;

size_row = numel(given_matrix(:,1));
size_column = numel(given_matrix(1,:));

ctr1 = 0;
ctr2 = 0;
TotalHT = zeros(1,size_row);
TotalHT(1) = 1;
CHT = 0;
ValueHT = 0;


for i = 1:size_row
    for j = 1:size_column
        value = given_matrix(i,j);
        if value ~= 0
            ctr2 = ctr2 + 1;
            ctr1 = ctr1 + 1;
            CHT(ctr1) = j;
            ValueHT(ctr1) = value;
        end
    end
    TotalHT(i+1) = TotalHT(i) + ctr2;
    ctr2 = 0;
end


% ======================================



% BURASI SPARSE MULTIPLICATION KISMI. YINE SOLDA VAR BU KOD.

% E?ER ÇARPIM 0 GEL?RSE BREAK EDILCEK O KISMI EKLEMEDIM.

% TotalG missing ! 

%Bir de check edersen süper olur çal???yor mu düzgün diye

 % Until now, no gain matrix exists ! 
 ValueG = [];
 CG = [];
 TotalG = [];
for i = 1:length(TotalHT)-1
    temp =0;
    for j = 1:length(TotalHT)-1
    
    
    nonzero = TotalHT(i+1)-TotalHT(i);    % Total Number of zero in a row
    
    for k = 1:nonzero
        
        
        a =CHT(TotalHT(i)+k-1); % This gives the nonzero columns
        
        % Now, we need to go to rows corresponding to these columns
        b = TotalH(a+1)-TotalH(a);
        for say = 1:b
            
            c = CH(TotalH(a)+say-1);  %Column number in the corresponding row
            
            if c == i
                temp = temp+ValueHT(TotalHT(i)+k-1)*ValueH(TotalH(a)+say-1);

                
            end
            
            
        end
        
        
    end
    Ctemp = j;
    CG  = horzcat(CG,Ctemp);
    ValueG  = horzcat(ValueG,temp);
    end
    
    
end

 
toc