# Key Idea : 다익스트라, 함수 재사용을 위해 dijkstra함수로 분리
# 이전 1916,1753과 동일한 문제
import heapq, math

def dijkstra(start_node):
    costs = [math.inf] * (N+1)
    costs[start_node] = 0
    heap = []

    heapq.heappush(heap, [0,start_node])
    while heap:
        cur_cost, cur_v = heapq.heappop(heap)
        # 이미 더 빠르게 도달할 수 있는 방법이 있다면 패스
        if costs[cur_v] < cur_cost: continue
        # 만약 지금 방법이 더 빠르다면
        for next_v, next_cost in graph[cur_v]:
            # 현재 노드에서 다음 노드로 넘어가는 비용이
            # 다음 노드의 최소 비용보다 높다면 굳이 이 길을 갈 이유가 없음
            sum_cost = cur_cost + next_cost
            if sum_cost >= costs[next_v]:   continue
            
            # 만약 현재까지의 값 (sum_cost)이 다음 노드에 대한 비용을 업데이트한다
            costs[next_v] = sum_cost
            # 여태까지 파악된 길, 교수님 교안으로는 초록색으로 표시된 집합
            heapq.heappush(heap, [sum_cost, next_v])
    return costs

N, M, X = map(int, input().split())

# [a][b,weight] -> a->b 로 연결되며 weight만큼의 비용이 듦
graph = [[] for _ in range (N+1)]

for _ in range(M):
    a, b, cost = map(int,input().split())
    graph[a].append([b,cost])

ans = dijkstra(X)
ans[0]=0

for idx in range(1, N+1):
    if idx !=X:
        res = dijkstra(idx)
        ans[idx] += res[X]

print(max(ans))