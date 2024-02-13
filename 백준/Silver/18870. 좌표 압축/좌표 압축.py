num = int(input())
lst = list(map(int, input().split()))
sorted_list = list(set(lst))
sorted_list.sort()

num_dict = {}
for idx in range(len(sorted_list)):
    num_dict[sorted_list[idx]] = idx

for i in lst:
    print(num_dict[i], end=' ')