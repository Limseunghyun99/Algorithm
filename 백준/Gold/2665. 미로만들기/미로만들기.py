from collections import deque
N = int(input())
dx = [0,1,0,-1]
dy = [1,0,-1,0]

arr = []
for _ in range(N):    arr.append(list(map(int, input().strip())))

def bfs():
    q = deque()
    q.append((0,0))
    # NxN
    visited = [[-1] * N for _ in range(N)]

    visited[0][0]=0
    while q:
        x,y = q.popleft()
        if x == N-1 and y == N-1:   return visited[x][y]
        for k in range(4):
            cur_x = x+dx[k]
            cur_y = y + dy[k]

            # 좌표가 유효하고 아직 방문 안했다면
            if 0<=cur_x<N and 0<=cur_y <N and visited[cur_x][cur_y] == -1:
                # 흰방
                if arr[cur_x][cur_y] == 1:
                    q.appendleft((cur_x,cur_y))
                    visited[cur_x][cur_y] = visited[x][y]
                # 검은방방
                else:
                    q.append((cur_x,cur_y))
                    visited[cur_x][cur_y] = visited[x][y] +1

print(bfs())