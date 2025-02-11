# Key Idea : 최단거리? 다익스트라

import heapq
import sys
input = sys.stdin.readline

N,E = map(int, input().split())

INF = int(1e9)
graph = [[]for _ in range(N+1)]

for _ in range(E):
    # s: start / e:end / l : 길의 수
    s,e,l = map(int, input().split())
    # 무방향 그래프기 때문에 서로를 연결해줌
    graph[s].append((e,l))
    graph[e].append((s,l))

def dijkstra(start,end):
    # 경로 초기화
    path = [INF] * (N+1)
    q = []
    heapq.heappush(q,(0,start))
    # 시작 지점 초기화
    path[start] = 0

    while q:
        length, current = heapq.heappop(q)
        # 이미 처리된 경로라면 무시
        if path[current] < length:  continue 

        for e,l in graph[current]:
            cost = length + l
            if cost < path[e]:
                path[e] = cost
                heapq.heappush(q,(cost,e))
    return path[end]

v1, v2 = map(int, input().split())
# 1에서 출발하여 v1, v2를 거쳐 N까지 가는 경우
p1 = dijkstra(1,v1) + dijkstra(v1,v2) + dijkstra(v2,N)
# 1에서 출발해서 v2, v1 을 거쳐 N까지 가는 경우 
p2 = dijkstra(1,v2) + dijkstra(v2,v1) + dijkstra(v1,N)

if p1 >= INF and p2 >= INF: print(-1)
else:   print(min(p1,p2))