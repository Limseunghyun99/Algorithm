# 간선 길이의 합 최소화? MST
# weighted인가 -> yes
# d음수가 있는가 -> No
# kruskal 드가자
INF = float('inf')


def solution(n, costs):
    answer = 0
    graph = [[] for _ in range(n)]
    dist = [INF]*n
    dist[0] = 0
    
    visited = [False]*n
    
    for edge in costs:
        a,b,c = edge
        graph[a].append((b, c))
        graph[b].append((a, c))
        
    for _ in range(n):
        fin_idx = None
        tmp = INF
        for i in range(n):
            if dist[i] < tmp and visited[i] == False:
                tmp = dist[i]
                fin_idx = i
        
        visited[fin_idx] = True
        answer += dist[fin_idx]
        
        for adj_node, w in graph[fin_idx]:
            if visited[adj_node] == False:
                dist[adj_node] = min(dist[adj_node], w)
        
    answer = sum(dist)
    return answer