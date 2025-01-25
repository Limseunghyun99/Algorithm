# Key Idea : 모든 부분 탐색? BFS or DP ?
# 작은 연산이 최적해의 일부가 아니고 경우의 수를 구하는게 아니니까 DP는 아닌듯
# BFS로 간다 deque사용

# 시간 : O(nxm)
# 공간 : O(nxm)
from collections import deque

n,m = map(int, input().split())
graph = []
cnt = 0
ans = 0
dx = [-1,1,0,0]
dy = [0,0,-1,1]

for _ in range(n):    graph.append(list(map(int, input().split())))

def bfs(x,y):
    q = deque()
    q.append((x,y))
    # 시작점 초기화
    graph[x][y] = 0
    # 넓이
    area = 1

    while q:
        x, y = q.popleft()
        for idx in range(4):
            nx= x+dx[idx]
            ny= y+dy[idx]

            # 값이 범주 안에 있는지 확인
            if 0<=nx<n and 0<=ny<m and graph[nx][ny] == 1:
                # 방문을 했으면 그 위치는 지워도 무관함
                graph[nx][ny] = 0
                q.append((nx,ny))
                area += 1
    return area

for x in range(n):
    for y in range(m):
        if graph[x][y]:
            cnt += 1
            ans = max(bfs(x,y), ans)

print(cnt)
print(ans)