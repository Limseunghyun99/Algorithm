num = int(input())
lst = []
for _ in range (num):
    x, y  = map(int, input().split())
    lst.append((x,y))
lst.sort()

for position in lst:
    print(position[0], position[1])