# Key : 위상 정렬, 그런데 약간의 변형을 곁들인
# 상대 순위가 입력되었을땐 그 외의 순서들은 바뀌면 안됨
# 일관성이 없으면 IMPOSSIBLE -> 사이클 발생 의미?

import sys
from collections import deque

input = sys.stdin.readline
T = int(input())

for _ in range(T):
    N = int(input())

    # init graph & inDegree
    graph = [[] for _ in range(N+1)]
    # indegree[i] = i 노드에 진입 차수
    inDegree = [0]*(N+1)
    queue = deque()
    ans = []
    flag = False

    # 초기 팀 순위
    ranking = list(map(int, input().split()))
    
    # 상대적인 순위 비교, 마지막은 굳이 비교할 필요 없음
    # 연결 정보 저장
    for j in range(N-1):
        for k in range(j+1, N):
            # 이전 문제들과 동일, 연결 정보 파악
            graph[ranking[j]].append(ranking[k])
            inDegree[ranking[k]] += 1
    
    # 순위 변경 정보
    M = int(input())

    # 순위 변경 사항 적용
    for j in range(M):
        x, y = map(int, input().split())
        # 순위 변경이 가능한지를 의미하는 플래그
        flag = True

        # x->y 간선이 있다면 제거하고 y->x로 변경
        # 즉, x가 y에 앞서고 있다가 이제 y가 x를 앞서는 경우, 순위를 역전
        for k in graph[x]:
            # 이번에 비교하는 노드가 y라면, 제거
            if k == y:
                graph[x].remove(y)
                # 그래프 연결 정보 빼기
                inDegree[y] -= 1
                graph[y].append(x)
                inDegree[x] += 1
                flag = False
        if flag:
            graph[y].remove(x)
            inDegree[x] -= 1
            inDegree[y] +=1
            graph[x].append(y)
    # 아래 코드는 이전과 동일
    # 진입 차수가 0인 노드를 큐에 넣는다
    for idx in range(1, N+1):
        if inDegree[idx] == 0:  queue.append(idx)

    # 큐가 비어있다 == 답이 없다
    if not queue:
        print("IMPOSSIBLE")
        continue
    
    # 위상 정렬 수행, res = 정답을 찾을 수 있는가 
    res = True
    while queue:
        # 큐에 여러 노드가 동시에 들어가 있으면 순위를 확정할 수 없음
        if len(queue) > 1:
            res = False
            break
        tmp = queue.popleft()
        ans.append(tmp)
        for j in graph[tmp]:
            inDegree[j] -= 1
            if inDegree[j] == 0:    queue.append(j)
            elif inDegree[j] <0:
                res =False
                break
    if not res or len(ans) < N: print("IMPOSSIBLE")
    else:   print(*ans)