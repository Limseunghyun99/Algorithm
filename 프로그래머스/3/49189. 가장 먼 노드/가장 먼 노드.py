import heapq

def solution(n, edge):
    edges = [[] for _ in range(n)]
    for a,b in edge:
        # connect each ways
        edges[a-1].append(b-1)
        edges[b-1].append(a-1)
    visited = [False] * (n)
    q = []
    heapq.heappush(q,(0,0))
    visited[0] = True
    dist, cnt = 0,0
    while q:
        tmp = heapq.heappop(q)
        if dist < tmp[0]:
            dist = tmp[0]
            cnt = 1
        else:   cnt+=1
        
        for cur in edges[tmp[1]]:
            if not visited[cur]:
                visited[cur] = True
                heapq.heappush(q, (tmp[0]+1,cur))
    return cnt