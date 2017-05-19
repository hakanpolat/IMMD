tic
clear edges;
clear next;
clear new_order;
%a= G(1:5,1:5);
%a = G;
a = flag_matrix;
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
prev = start;
new_order = start;
prev_index = 1;
ctr = 0;
while(1)
    ctr = ctr+1
    for j = 1:numel(prev)
        next(j) = edges(find(edges(:,2) == prev(j)),1)
    end
    if ctr == numel(edges(:,1))
        break;
    end
    add_elm = numel(next)
    new_order(prev_index+1:prev_index+add_elm) = next
    prev = next
    prev_index = prev_index + numel(prev)
end

%startindex = find(edges(:,2) == start);
%newnodes(1) = start
%newedges(1,:) = edges(startindex,:);

% ctr = 0;
% while(1)
%     ctr = ctr+1;
%     %nextvalue = newedges(ctr,1)
%     nextnode = edges(startindex,1);
%     
%     if(ctr == numedges)
%         break;
%     end
%     
%     
% end

toc
