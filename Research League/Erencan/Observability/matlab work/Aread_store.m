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
toc


% Measurement data
% Data import
tic
fid = fopen('measure.dat');
Line_String_Complete = fgetl(fid);
Line_String_Numeric = str2double(Line_String_Complete);

for i = 1: Line_String_Numeric+1
    Line_String_Complete = fgetl(fid);
end
%The numeric gives the number of power injections
Line_String_Numeric = str2double(Line_String_Complete);
for i = 1: Line_String_Numeric+1
    Line_String_Complete = fgetl(fid);
end


CH = [];
for i= 1:Line_String_Numeric
    
    Line_String_Complete = fgetl(fid);
    Line_String_Numeric = str2double(Line_String_Complete(1,1:4));
    temp = find(CA==Line_String_Numeric)
    j = length(temp)  % Bu asl?nda N , -1 , -1 deki N de?eri
    
    Valuetemp = ones(1,j+1)*-1;
    Ctemp = zeros(1,j+1);
    
    for counter = 1:j
      if mod(temp(counter),2)==0
      CHtemp(counter)=  CA(temp(counter)-1)
      else 
      CHtemp(counter)=  CA(temp(counter)+1) 
      end
    end
    
    CH = horzcat(CH,CHtemp);
%     end
    
    
%     ValueH_temp = ones(length(temp)+1)*(-19;
    
%     CH
%     ValueH
%     CH
%     TotalH
    
end
toc