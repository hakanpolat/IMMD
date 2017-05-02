% Arbitrary matrix

arb = [7,0,0,0,4,0,0;...
       0,5,2,0,0,6,0;...
       0,8,3,0,9,1,0;...
       0,0,0,10,0,0,6;...
       8,0,0,9,4,0,0;...
       0,3,0,0,0,7,12;...
       4,0,10,0,8,0,11];

% arb = [0,16,0,340,74;...
%     7,0,0,0,-51;...
%     0,44,0,-14,23];


%%
% This function implements sparse storage of any given matrix with
% Gustavson's method

given_matrix = arb;
%given_matrix = H;
%given_matrix = A;

size_row = numel(given_matrix(:,1));
size_column = numel(given_matrix(1,:));

ctr1 = 0;
ctr2 = 0;
vect_total = zeros(1,size_row);
vect_total(1) = 1;
vect_column = 0;
vect_value = 0;

for i = 1:size_row
    for j = 1:size_column
        value = given_matrix(i,j);
        if value ~= 0
            ctr2 = ctr2 + 1;
            ctr1 = ctr1 + 1;
            vect_column(ctr1) = j;
            vect_value(ctr1) = value;
        end
    end
    vect_total(i+1) = vect_total(i) + ctr2;
    ctr2 = 0;
end


%%
% This function implements sparse storage of any given matrix with
% Knutt's method

%given_matrix = arb;
given_matrix = H;
%given_matrix = A;

size_row = numel(given_matrix(:,1));
size_column = numel(given_matrix(1,:));

ctr1 = 0;
ctr2 = 0;

vect_C = 0;
vect_V = 0;
vect_BeginR = zeros(1,size_row);
vect_NextR = 0;
prev = 0;

for i = 1:size_row
    for j = 1:size_column
        value = given_matrix(i,j);
        if value ~= 0
            ctr2 = ctr2 + 1;
            ctr1 = ctr1 + 1;
            if prev ~= i
                vect_BeginR(i) = ctr1;
            end
            if ctr1 ~= 1
                if prev ~= i
                    vect_NextR(ctr1-1) = -1;
                elseif prev == i
                    vect_NextR(ctr1-1) = ctr1;
                end
            end
            vect_C(ctr1) = j;
            vect_V(ctr1) = value;
            prev = i;
        end
    end
    ctr2 = 0;
end

vect_NextR(numel(vect_V)) = -1;

% One should note that, these algorithms cannot work with a continuously
% feeding data. They can be used to store a given MATRIX stored in MATLAB
% environment.
