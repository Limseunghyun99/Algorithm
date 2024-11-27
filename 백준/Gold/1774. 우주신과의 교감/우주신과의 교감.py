# Key Idea : Kruskal, Union-find algorithm
# distance -> 피타고라스 사용
import math

def find(parent, x):    
    if x!= parent[x]:   parent[x] = find(parent, parent[x])
    return  parent[x]

def union(parent, a,b):
    a = find(parent,a) 
    b = find(parent,b)
    if a <= b : parent[b] = a
    else:   parent[a] = b

N,M = map(int, input().split())
# union-find root list
parent = list(range(N+1))
# edge 정보
edges = [(0,0)]

for idx in range(N):
    a, b = map(int, input().split())
    edges.append((a,b))

for _ in range(M):
    a, b = map(int, input().split())
    union(parent, a, b)

# 거리 정보 리스트
possible = []
# 가능한 모든 노드 쌍들에 대해 거리 계산하여 저장
for i in range(1, len(edges)):
    for j in range(i+1, len(edges)):
        x1, y1 = edges[i][0], edges[i][1]
        x2, y2 = edges[j][0], edges[j][1]
        cost = math.sqrt((x1-x2)**2 + (y1-y2)**2)
        possible.append([cost, i, j])

# 거리 기준으로 정렬
possible.sort()
ans = 0

# x,y 쌍의 거리 정보 cost에 대해서 연산
for p in possible:
    cost, x, y = p[0], p[1], p[2]
    
    # 각 노드가 속한 집합이 다른 경우, 합치고 cost도 더한다
    if find(parent, x) != find(parent, y):
        union(parent, x, y)
        ans += cost
    
# 유효숫자 둘째 자리까지 출력
print("{:.2f}".format(ans))