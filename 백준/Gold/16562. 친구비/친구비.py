def find(node):
    if parent[node] != node:    parent[node] = find(parent[node])
    return parent[node]

def union (a,b):
    a = find(a)
    b = find(b)
    if friends[a] < friends[b] : parent[b] = a
    else : parent[a] = b

N, M, money = map(int, input().split())
# 친구별 cost
friends = [0] + list(map(int, input().split()))
#parent array, 단, 친구들 인덱스는 1부터 시작
parent = [idx for idx in range(N+1)]

for _ in range (M):
    a, b = map(int, input().split())
    union(a,b)

cnt = 0

for idx in range(1, N+1):
    if idx == find(idx):    cnt += friends[idx]

print(cnt if money >= cnt else 'Oh no')