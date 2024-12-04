# Key Idea : 음수간선이 포함 되어 있음 -> bellman_ford 알고리즘 사용
# 이전 문제 (11657)과 다른점 : 최대 길이를 구해야 하니 -inf 로 초기화

import sys;
input = sys.stdin.readline
INF = int(1e9)

# 일부 변경 -> 리턴에서 그래프 값 업데이트 하는 형식
def bellman_ford(start_node):
    costs[start_node] = 0
    
    # i와 j 
    for i in range(1, N+1):
        for j in range(M):
            cur, next, weight = graph[j][0], graph[j][1], graph[j][2]
            # 현재 간선을 거치는게 다른 노드를 거치는 것보다 짧을 경우
            if costs[cur] != -INF and costs[next] < costs[cur] + weight:
                costs[next] = costs[cur] + weight
                route[next] = cur
                if i==N:    costs[next] = INF

N,M = map(int, input().split())

# [a][b,weight] -> a->b 로 연결되며 weight만큼의 비용이 듦
graph = []
costs = [-INF] * (N+1)
route = [0 for _ in range(N+1)]

for _ in range(M):
    a, b, w = map(int,input().split())
    graph.append([a,b,w])

bellman_ford(1)

ans = [N]
if costs[N] != INF:
    node = N

    while node != 1:
        node = route[node]
        ans.append(node)
    ans.reverse()
    print(*ans)
else:   print(-1)
