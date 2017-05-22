%function new_order = ordering(col,tot)
tic

tot = TotalG;
col = ColumnG;
n = numel(tot)-1;
nodes = 1:n;
edges = [];
for k = 1:n
    nonzero_places = 0;
    num_of_nonzero = tot(k+1)-tot(k);
    for l = 1:num_of_nonzero
        if col(tot(k)+l-1) > k
            edges = [edges;k,col(tot(k)+l-1)];
        end
    end
end

stored_zero = [];
for k = 1:n
    if any(col(:)==k)==0
        stored_zero = [stored_zero k];
    end
end

% discard the columns with full zero elements
new_order = stored_zero';

start = 1;
edges_mod = edges;
new_order = [new_order;start];
candidate = edges((edges(:,1)==start),2);
candidate = [candidate;edges((edges(:,2)==start),1)];
next = candidate;
new_order = [new_order;next];
edges_mod((edges(:,1)==start),:) = [];
temp = next;
next = [];
ctr = 0;
while(1)
    ctr = ctr+1;
    for k = 1:numel(temp)
        temp(k)
        candidate = edges_mod((edges_mod(:,2)==temp(k)),1);
        candidate = [candidate;edges_mod((edges_mod(:,1)==temp(k)),2)];
        for l = 1:numel(candidate)
            if any(candidate(l)==new_order)~=1
                next = [next;candidate(l)];
                new_order = [new_order;candidate(l)];
            end
        end
        edges_mod((edges_mod(:,2)==temp(k)),:) = [];
        edges_mod((edges_mod(:,1)==temp(k)),:) = [];
    end
    temp = next;
    next = [];
    if isempty(edges_mod) || numel(new_order) == n || ctr == 30 || isempty(temp)
        break;
    end
end
if isempty(edges_mod)==0
    new_order = [new_order;edges_mod(1,1)];
    continued = edges_mod(1,1);
end
ctr = 0;
next = continued;
temp = next;
next = [];
while(isempty(edges_mod)==0)
    ctr = ctr+1;
    for k = 1:numel(temp)
        temp(k)
        candidate = edges_mod((edges_mod(:,1)==temp(k)),2);
        candidate = [candidate;edges_mod((edges_mod(:,2)==temp(k)),1)];
        for l = 1:numel(candidate)
            if any(candidate(l)==new_order)~=1
                next = [next;candidate(l)];
                new_order = [new_order;candidate(l)];
            end
        end
        edges_mod((edges_mod(:,2)==temp(k)),:) = [];
        edges_mod((edges_mod(:,1)==temp(k)),:) = [];
    end
    temp = next;
    next = [];
    if isempty(edges_mod) || numel(new_order) == n || ctr == 30 || isempty(temp)
        break;
    end
end

new_order
numel(new_order)
toc
%end

% The most far away node is detected for staring point
% distance = zeros(n,1);
%
% for k = 1:n
%     level = 0;
%     counted = [k];
%     temp = [k];
%     while(1)
%         level = level+1
%         ctr = 0;
%         for m = 1:numel(temp)
%             for l = 1:numel(edges(:,1))
%                 if edges(l,1) == temp(m) && sum(any(counted~=edges(l,2)))==0
%                     counted = [counted;edges(l,2)]
%                     temp = [temp;edges(l,2)]
%                     ctr = ctr+1;
%                 end
%                 if edges(l,2) == temp(m) && sum(any(counted~=edges(l,1)))==0
%                     counted = [counted;edges(l,1)]
%                     temp = [temp;edges(l,1)]
%                     ctr = ctr+1;
%                 end
%
%             end
%             distance(k) = distance(k) + ctr*level
%         end
%         if numel(counted) >= n
%             break;
%         end
%     end
%
% end






%end


%
% for k = 1:n
%     level = 0;
%     counted = [k];
%     relations_old1 = [k];
%     relations_old2 = [k];
%     tot_rel_old = 1;
%     while(1)
%         level = level+1;
%         for m = 1:tot_rel_old
%             relations1 = edges(edges(:,1)==relations_old1(m),2)
%             relations2 = edges(edges(:,2)==relations_old2(m),1)
%             tot_rel = numel(relations1)+numel(relations2)
%             distance(k) = distance(k) + tot_rel*level;
%             relations_old1 = relations1;
%             relations_old2 = relations2;
%             counted = [counted;relations1];
%             tot_rel_old = tot_rel;
%         end
%     end
%     %distance(k) = distance(k) + 1;
%
% end
%
%
% end






%
% a = flag_matrix;
% n = numel(a(:,1));
% nodes = 1:n;
% edges = [0,0];
% for k = 1:n
%     mtrx = a(:,k)~=0;
%     for l = k:n
%         if mtrx(l) == 1 && l ~= k
%             edges = [edges;k,l];
%         end
%     end
% end
% edges = edges(2:end,:);
%
% flag = zeros(n,1);
% for i = 1:n
%     flag(i) = sum(sum(edges(:,:)==i));
% end
%
% numedges = numel(edges(:,1));
% newnodes = zeros(n,1);
% start = find(flag == min(flag));
% prev = start;
% new_order = start;
% prev_index = 1;
% ctr = 0;
% while(1)
%     ctr = ctr+1
%     for j = 1:numel(prev)
%         next(j) = edges(find(edges(:,2) == prev(j)),1)
%     end
%     if ctr == numel(edges(:,1))
%         break;
%     end
%     add_elm = numel(next)
%     new_order(prev_index+1:prev_index+add_elm) = next
%     prev = next
%     prev_index = prev_index + numel(prev)
% end




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

