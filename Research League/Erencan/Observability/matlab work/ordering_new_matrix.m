% construction of the re-ordered matrix with Gustavson's method

%edges
%new_order
%ColumnG
%ValueG
%TotalG

n = numel(TotalG)-1;
TotalGnew = [1];
ColumnGnew = [];
ValueGnew = [];
ctr = 0;
for k = 1:6
    old_order_index = new_order(k)
    old_order_relation = edges(edges(:,1)==old_order_index,2);
    old_order_relation = [old_order_relation;edges(edges(:,2)==old_order_index,1)]
    temp = numel(old_order_relation)
    if temp~=0
        sub_index = 
        Value_newG(ctr) = ValueG()
    end
    inside_counter = 0
    for l = 1:temp
        new_order_relation = find(new_order==old_order_relation(l))
        ctr = ctr+1
        inside_counter = inside_counter+1
        %ColumnGnew(next_iter) = new_order_relation;
        %ValueGnew(next_iter) = ValueG()
    end
    
%     ctr = 0;
%     while(1)
%         ctr = ctr+1;
%         edges(:,1)==old_order_index
%         if ctr == 10
%             break;
%         end
%     end
end
