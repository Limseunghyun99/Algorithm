# 필요한 모듈을 임포트
import sys
from heapq import heappush, heappop

# 유니온-파인드 알고리즘을 위한 부모 노드 찾기 함수
def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

# 유니온-파인드 알고리즘을 위한 두 노드 합치기 함수
def union(parent, rank, a, b):
    root_a = find(parent, a)
    root_b = find(parent, b)
    if root_a != root_b:
        if rank[root_a] > rank[root_b]:
            parent[root_b] = root_a
        elif rank[root_a] < rank[root_b]:
            parent[root_a] = root_b
        else:
            parent[root_b] = root_a
            rank[root_a] += 1

# 행성의 개수 입력받기
n = int(input().strip())

# 각 행성의 좌표를 저장할 리스트
planets = []

# 입력받은 좌표 데이터를 저장
for i in range(n):
    x, y, z = map(int, input().split())
    planets.append((x, y, z, i))

# 간선을 저장할 리스트
edges = []

# x좌표 기준으로 정렬 후 인접한 행성들 간의 최소 비용 간선 생성
planets.sort(key=lambda x: x[0])
for i in range(n - 1):
    cost = abs(planets[i][0] - planets[i + 1][0])
    heappush(edges, (cost, planets[i][3], planets[i + 1][3]))

# y좌표 기준으로 정렬 후 인접한 행성들 간의 최소 비용 간선 생성
planets.sort(key=lambda x: x[1])
for i in range(n - 1):
    cost = abs(planets[i][1] - planets[i + 1][1])
    heappush(edges, (cost, planets[i][3], planets[i + 1][3]))

# z좌표 기준으로 정렬 후 인접한 행성들 간의 최소 비용 간선 생성
planets.sort(key=lambda x: x[2])
for i in range(n - 1):
    cost = abs(planets[i][2] - planets[i + 1][2])
    heappush(edges, (cost, planets[i][3], planets[i + 1][3]))

# 유니온-파인드 초기화
parent = [i for i in range(n)]
rank = [0] * n

# 최소 스패닝 트리를 구성하며 최소 비용 계산
result = 0
count = 0
while edges and count < n - 1:
    cost, a, b = heappop(edges)
    if find(parent, a) != find(parent, b):
        union(parent, rank, a, b)
        result += cost
        count += 1

# 결과 출력
print(result)
