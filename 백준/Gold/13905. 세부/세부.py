import sys
input = sys.stdin.readline

n, m = map(int, input().split())
s, e = map(int, input().split())

edges = []
for _ in range(m):
    h1, h2, k = map(int, input().split())
    edges.append((k, h1, h2))

# 중량 큰 순서대로 정렬
edges.sort(reverse=True)

parent = list(range(n + 1))

def find(x):
    while parent[x] != x:
        parent[x] = parent[parent[x]]  # 경로 압축
        x = parent[x]
    return x

def union(a, b):
    ra = find(a)
    rb = find(b)
    if ra == rb:
        return
    if ra < rb:
        parent[rb] = ra
    else:
        parent[ra] = rb

answer = 0

for k, a, b in edges:
    union(a, b)
    if find(s) == find(e):
        answer = k
        break

print(answer)