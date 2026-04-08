import sys
sys.setrecursionlimit(200000)
input = sys.stdin.readline

N, S, D = map(int, input().split())

graph = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

answer = 0

def dfs(cur, parent):
    """
    cur를 루트로 하는 서브트리에서
    cur -> 가장 먼 리프까지의 거리 반환
    """
    global answer

    max_depth = 0
    is_leaf = True

    for nxt in graph[cur]:
        if nxt == parent:
            continue
        is_leaf = False

        child_depth = dfs(nxt, cur) + 1
        max_depth = max(max_depth, child_depth)

        # 이 자식 방향으로는 D보다 먼 리프가 있으므로 직접 가야 함
        if child_depth > D:
            answer += 2

    return max_depth

dfs(S, 0)
print(answer)