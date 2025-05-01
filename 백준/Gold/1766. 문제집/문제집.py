# Key Idea : 위상 정렬! 
# 기준 1) 문제들끼리 먼저 풀면 좋은 순서를 지키자
# 기준 2) 가능하면 쉬운 문제부터 풀어야 한다
# 가능하면 쉬운 문제 -> 우선순위 큐 사용

import sys
import heapq
input = sys.stdin.readline

# N: 문제수, M: 간선
N,M = map(int, input().split())

graph = [[] for _ in range(N+1)]
# indegree[i] = i 노드에 진입 차수
inDegree = [0]*(N+1)
queue = []
ans = []

for _ in range(M):
    x,y = map(int,input().split())
    # seq[x] 는 y 보다 선행 되어야 함
    # 노드간의 순서 관계라고 생각하면 됨
    graph[x].append(y)
    # y문제를 풀기 위해 먼저 풀어야 하는 문제들
    # 즉, 진입 차수가 하나 늘었음
    inDegree[y] += 1

# 진입 차수가 0인 노드를 queue에 넣는다
# 단 이때, 쉬운 문제를 우선 풀어야 하니 먼저 넣는다
for idx in range (1, N+1):
    if inDegree[idx] == 0:  heapq.heappush(queue, idx)

# queue에 저장된 노드 = 진입차수가 0인 문제들 중 가장 번호가 작은 문제
# 현재 문제랑 연결된 문제들의 진입 차수를 1씩 줄인다
# 이후 진입 차수가 다시 0이 된 노드를 찾아서 진행한다
while queue:
    tmp = heapq.heappop(queue)
    ans.append(tmp)
    for idx in graph[tmp]:
        inDegree[idx] -= 1
        if inDegree[idx] == 0:  heapq.heappush(queue, idx)

print(*ans)