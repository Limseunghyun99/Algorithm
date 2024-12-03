import heapq
import sys
input = sys.stdin.readline

V, E = map(int, input().split())
start = int(input())
graph = [[] for _ in range(V+1)]

# 그래프 정보 저장
for _ in range(E):
    u, v, w = map(int, input().split())
    
    graph[u].append((v, w))

# 다익스트라 알고리즘
def dijkstra(start):
    distances = [float("inf")]*(V+1)
    distances[start] = 0
    q = []
    # 힙은 새 기준이 될, 방문했던 인접 노드들 중 그 노드까지의 최단 거리가 가장 짧은 것을 먼저 방문하기 위해 씀
    heapq.heappush(q, (distances[start], start))
    
    while q:
        cnt_distance, node = heapq.heappop(q)
        
        # BFS처럼 수행하기에, 한 level에서 특정 인접 노드에 대한 정보가 중복될 수 있음
        # 만약 (2, 4)가 이미 distances에 있는데, (2, 7)을 힙에서 뽑았다면,
        # 최단거리인 4를 활용하는게 맞으므로 (2, 7)은 그냥 넘어간다.
        if distances[node] < cnt_distance:
            continue
        
        # 인접 노드들 중에 최단거리 갱신이 되는 노드들은 갱신해주고, 갱신 안했으면
        # 그냥 힙에 안넣고 넘어가면 됨. 이미 더 짧은 최단거리가 존재하고 있다는 것은
        # 다른 경로로 이 노드를 방문하는 경우가 존재한다는 것이므로 그 경우에서
        # 어차피 처리해줄 것이기 때문
        for adjacency_node, distance in graph[node]:
            cal_distance = distances[node] + distance
            
            if cal_distance < distances[adjacency_node]:
                distances[adjacency_node] = cal_distance
                heapq.heappush(q, (cal_distance, adjacency_node))
                
    return distances

result = dijkstra(start)

for i in range(1, len(result)):
    print("INF" if result[i] == float("inf") else result[i])