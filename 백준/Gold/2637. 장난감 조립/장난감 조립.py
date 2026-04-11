from collections import deque
import sys

input = sys.stdin.readline

N = int(input())
M = int(input())

graph = [[] for _ in range(N + 1)]
indegree = [0] * (N + 1)

for _ in range(M):
    X, Y, K = map(int, input().split())
    graph[Y].append((X, K))
    indegree[X] += 1

base = [False] * (N + 1)
for i in range(1, N + 1):
    if indegree[i] == 0:
        base[i] = True

dp = [[0] * (N + 1) for _ in range(N + 1)]
q = deque()

for i in range(1, N + 1):
    if base[i]:
        q.append(i)
        dp[i][i] = 1

while q:
    cur = q.popleft()

    for nxt, cnt in graph[cur]:
        for b in range(1, N + 1):
            dp[nxt][b] += dp[cur][b] * cnt

        indegree[nxt] -= 1
        if indegree[nxt] == 0:
            q.append(nxt)

for i in range(1, N + 1):
    if base[i] and dp[N][i] > 0:
        print(i, dp[N][i])