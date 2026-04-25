import sys
from collections import deque

input = sys.stdin.readline

# N: 행 개수, M: 열 개수
N, M = map(int, input().split())

# 수영장 높이 정보 입력
pool = [list(map(int, input().strip())) for _ in range(N)]

# 상하좌우 이동
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

answer = 0

# 물 높이를 1부터 9까지 확인
# h보다 낮은 칸은 h 높이까지 물이 찰 수 있는 후보
for h in range(1, 10):
    visited = [[False] * M for _ in range(N)]

    for i in range(N):
        for j in range(M):

            # 이미 방문했거나, 현재 물 높이 이상인 땅이면 스킵
            if visited[i][j] or pool[i][j] >= h:
                continue

            q = deque()
            q.append((i, j))
            visited[i][j] = True

            # 현재 연결 영역에 포함된 칸 수
            count = 1

            # 이 영역이 바깥으로 물이 새는지 여부
            leak = False

            while q:
                x, y = q.popleft()

                # 가장자리에 닿으면 물이 밖으로 빠질 수 있음
                if x == 0 or x == N - 1 or y == 0 or y == M - 1:
                    leak = True

                for d in range(4):
                    nx = x + dx[d]
                    ny = y + dy[d]

                    if 0 <= nx < N and 0 <= ny < M:
                        if not visited[nx][ny] and pool[nx][ny] < h:
                            visited[nx][ny] = True
                            q.append((nx, ny))
                            count += 1

            # 바깥으로 연결되지 않은 영역이면
            # 현재 높이 h에서 물 1층을 채울 수 있음
            if not leak:
                answer += count

print(answer)