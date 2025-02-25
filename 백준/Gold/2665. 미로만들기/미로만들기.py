# 미로만들기
from collections import deque
import sys
input = sys.stdin.readline
N = int(input())
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

arr = []
for i in range(N):
    arr.append(list(map(int, input().strip())))


def bfs():
    q = deque()
    q.append((0, 0))
    visited = [[-1] * N for _ in range(N)]
    visited[0][0] = 0
    while q:
        x, y = q.popleft()
        if x == N-1 and y == N-1:
            return visited[x][y]
        for k in range(4):
            nx = x + dx[k]
            ny = y + dy[k]
            if 0 <= nx < N and 0 <= ny < N and visited[nx][ny] == -1:
                if arr[nx][ny] == 1:
                    q.appendleft((nx, ny))
                    visited[nx][ny] = visited[x][y]
                else:
                    q.append((nx, ny))
                    visited[nx][ny] = visited[x][y] + 1


print(bfs())