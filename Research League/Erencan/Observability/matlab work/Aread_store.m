clear all 
clc
tic
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
    ValueH = horzcat(ValueH,Valuetemp)
    
    Ctemp(1,1)=Line_String_Numeric;
    Ctemp(1,2)=Line_String_Numeric2;
    
    CH =horzcat(CH,Ctemp);
    
    Totaltemp = TotalH(end)+2
    TotalH = horzcat(TotalH,Totaltemp);
    
end 
 
 
toc