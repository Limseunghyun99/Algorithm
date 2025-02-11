# Key Idea : 다익스트라
import heapq
import sys
input = sys.stdin.readline

V,E,P = map(int, input().split())

INF = int(1e9)
graph = [[]for _ in range(V+1)]


for _ in range(E):
    a,b,c = map(int, input().split())
    # 양방향 그래프
    graph[a].append((b,c))
    graph[b].append((a,c))

def dijkstra(start):
    dist = [INF]*(V+1)
    q = []
    heapq.heappush(q,(0,start))
    # 시작지점의 거리를 0으로 초기화
    dist[start] = 0
    while(q):
        cost, curr = heapq.heappop(q)
        for next,c in graph[curr]:
            total_cost = cost + c
            if total_cost < dist[next]:
                dist[next] = total_cost
                heapq.heappush(q,[total_cost,next])
    return dist

# 1 -> V vs 1-> P + p->V
if dijkstra(1)[V] == dijkstra(1)[P] + dijkstra(P)[V]:    print("SAVE HIM")
else : print("GOOD BYE")