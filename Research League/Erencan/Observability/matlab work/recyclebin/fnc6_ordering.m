tic
clear edges;
a= G(1:5,1:5);
%a = G;
n = numel(a(:,1));
nodes = 1:n;
edges = [0,0];
for k = 1:n
    mtrx = a(:,k)~=0;
    for l = k:n
        if mtrx(l) == 1 && l ~= k
            edges = [edges;k,l];
        end
    end
end
edges = edges(2:end,:);

flag = zeros(n,1);
for i = 1:n
    flag(i) = sum(sum(edges(:,:)==i));
end

numedges = numel(edges(:,1));
newnodes = zeros(n,1);
start = find(flag == min(flag));
%startindex = find(edges(:,2) == start);
newnodes(1) = start
%newedges(1,:) = edges(startindex,:);
ctr = 0;
while(1)
    ctr = ctr+1;
    %nextvalue = newedges(ctr,1)
    nextnode = edges(startindex,1);
    
    if(ctr == numedges)
        break;
    end
    
    
end

toc
