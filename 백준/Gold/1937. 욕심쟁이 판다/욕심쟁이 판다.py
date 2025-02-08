import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def dfs(x, y):
    temp = 1
    for i, j in zip(dx, dy):
        n_x, n_y = x + i, y + j
        if 0 <= n_x < n and 0 <= n_y < n:
            if graph[n_x][n_y] > graph[x][y]:
                if dp[n_x][n_y] != -1:
                    temp = max(temp, 1 + dp[n_x][n_y])
                else:
                    temp = max(temp, 1 + dfs(n_x, n_y))
    dp[x][y] = temp
    return dp[x][y]


n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
dp = [[-1] * n for _ in range(n)]

cnt = 0
for x in range(n):
    for y in range(n):
        cnt = max(cnt, dfs(x, y))

print(cnt)