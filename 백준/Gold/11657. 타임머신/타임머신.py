# Key Idea : 음수간선이 포함 되어 있음 -> bellman_ford 알고리즘 사용

import math

# 음수 순환이 있으면 True 리턴,
# 없으면 False 리턴
def bellman_ford(start_node):
    costs[start_node] = 0
    
    # i와 j 
    for i in range(1, N+1):
        for j in range(M):
            cur, next, weight = graph[j][0], graph[j][1], graph[j][2]
            # 현재 간선을 거치는게 다른 노드를 거치는 것보다 짧을 경우
            if costs[cur] != math.inf and costs[next] > costs[cur] + weight:
                costs[next] = costs[cur] + weight
                if i==N:    return True
    return False

N, M = map(int, input().split())
# [a][b,weight] -> a->b 로 연결되며 weight만큼의 비용이 듦
graph = []
costs = [math.inf] * (N+1)

for _ in range(M):
    a, b, w = map(int,input().split())
    graph.append([a,b,w])
    
is_negative_cycle = bellman_ford(1)

if is_negative_cycle:   print(-1)
else:
    for idx in range (2, N+1):
        if costs[idx] == math.inf:  print(-1)
        else:   print(costs[idx])