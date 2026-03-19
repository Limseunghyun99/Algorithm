import heapq

# V 는 방문해야할 건물들 즉 vertex or node
# M 은 간선, 노드간의 연결선
# S 는 목적지 리스트인데 사실상 여기선 뭐 의미가 없음
V, M, S = map(int, input().split())
graph = [[] for _ in range(V+1)]

# 노드간의 연결 정보를 양방향 그래프로 만든다
for _ in range(M):
    u,v,w = map(int, input().split())
    graph[u].append((v,w))
    graph[v].append((u,w))

# 걍 받고 버려, 순간이동이 없었따면 의미가 있지만 지금은 없기에 그냥 의미가 없는 값들이 됨
_ = map(int,input().split())

# 프림 알고리즘, 시작점을 기준으로 최소 비용으로 트리를 확장해간다
# 사실 순간이동떄문에 걍 1부터 시작해도 상관 없음
def prim(start):
    visited = [False]*(V+1)
    pq = []

    # cost, vertex
    heapq.heappush(pq, (0, start))

    total_cost = 0

    while pq:
        cost, now = heapq.heappop(pq)
        if visited[now]:    continue
        visited[now] = True
        total_cost += cost

        for next_node, next_cost in graph[now]:
            if not visited[next_node]:
                heapq.heappush(pq, (next_cost, next_node))
    return total_cost

print(prim(S))


"""아래는 만약 순간이동기가 없는 조건이라면
import heapq, math

INF = math.inf

# N 는 방문해야할 건물들 즉 vertex or node
# M 은 간선, 노드간의 연결선
# S 는 목적지 리스트인데 사실상 여기선 뭐 의미가 없음
N, M, S = map(int, input().split())
graph = [[] for _ in range(N+1)]

# 노드간의 연결 정보를 양방향 그래프로 만든다
for _ in range(M):
    u,v,w = map(int, input().split())
    graph[u].append((v,w))
    graph[v].append((u,w))

# 걍 받고 버려, 순간이동이 없었따면 의미가 있지만 지금은 없기에 그냥 의미가 없는 값들이 됨
goals = map(int,input().split())

def dijkstra(start):
    dist = [INF] * (N+1)
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        cost, now = heapq.heappop(pq)
        if dist[now] < cost:    continue

        for nxt, w in graph[now]:
            new_cost = cost + w
            if new_cost < dist[now]:
                dist[now] = new_cost
                heapq.heappush(pq, (new_cost, nxt))
    return dist

ans = 0
cur = S
for target in goals:
    dist = dijkstra(cur)
    if dist[target] == INF:
        print(-1) # unreachable
        break
    answer += dist[target]
    cur = target
else:
    print(answer)
"""