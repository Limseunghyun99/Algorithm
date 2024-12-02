# Key Idea : dijkstra 알고리즘
# 그래프 구성 후 최소 비용을 저장, 가는 길을 비교해서 최소 값인지 확인하면서 진행
import math
import heapq

N = int(input())
M = int(input())

# [a][b,weight] -> a->b 로 연결되며 weight만큼의 비용이 듦
graph = [[] for _ in range(N+1)]

for _ in range(M):
    s,e,cost = map(int,input().split())
    graph[s].append([e,cost])

start_node, end_node = map(int, input().split())

prev = [-1] * N
# 특정 노드 costs[N] = N노드까지의 최소 비용을 저장
costs = [math.inf] * (N+1)
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
print(costs[end_node])
