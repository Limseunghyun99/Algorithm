# Key Idea : Kruskal!, 이전 코드에서 edge정보를 추가해보자
import math

def find(parent, node):
    if parent[node] != node:    parent[node] = find(parent, parent[node])
    return parent[node]

def union (parent, a,b):
    a = find(parent, a)
    b = find(parent, b)
    if a < b : parent[b] = a
    else : parent[a] = b

N = int(input())
# init parent array
parent = [i for i in range(N+1)]

edges = []
# array for stars~
stars = [0]
for i in range(N):
    a,b = map(float, input().split())
    stars.append((a,b))

ans = 0

for i in range(1,N):
    for j in range(i+1,N+1):
        cost = math.sqrt((stars[i][0]-stars[j][0])**2 + (stars[i][1]-stars[j][1])**2)
        edges.append((cost,i,j))

edges.sort()

for edge in edges:
    cost, a, b = edge
    # 둘의 부모 노드가 같다면 사이클이 발생
    if find(parent, a) != find(parent, b):
        union(parent,a,b)
        ans += cost
# memo: 유효숫자 자르기 round(num, 자릿수)
print(round(ans,2))