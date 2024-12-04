# Key Idea : 위상정렬!, 단 이번에는 딜레이 개념이 들어갔다
# 딜레이 -> target에 연결되어 있는 (inDegree에 물린 노드들의 딜레이 중 가장 긴 값)
# 반복 연산이 많으니 DP를 활용해보자

import sys
from collections import deque
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N,K = map(int, input().split())
    
    # Algorithm을 위해 필요한 list 선언
    seq = [[] for _ in range(N+1)]
    inDegree = [0 for _ in range(N+1)]
    dp = [0 for _ in range(N+1)]

    # delay[i] = i번째 건물의 delay
    # 문제의 index가 1을 기준으로 동작하기 때문에 편의상 0을 추가
    delays = [0]+list(map(int,input().split()))
    # x->y 순서가 유지 되어야 함
    for _ in range (K): 
        x,y = map(int,input().split())
        # seq[x] 를 짓고 y를 지어야함
        # 노드간의 순서 관계라고 생각하면 됨
        seq[x].append(y)
        # y건물을 짓기 위해 필요한 건물
        # 즉, 진입 차수가 하나 늘었음
        inDegree[y] += 1
    goal = int(input())

    queue= deque()
    for idx in range(1,N+1):
        # 진입 차수가 0인 애들은 큐에 넣어준다
        if inDegree[idx]==0:    
            queue.append(idx)
            # idx 까지 건설하는데 까지의 딜레이를 저장
            dp[idx] = delays[idx]
    
    while queue:
        tmp = queue.popleft()
        for idx in seq[tmp]:
            inDegree[idx] -= 1
            # 건물을 짓기까지 필요한 시간 = 이전에 지어야 하는 건물들의 딜레이 중 가장 긴 시간
            dp[idx] = max(dp[tmp] + delays[idx], dp[idx])
            if inDegree[idx] == 0:  queue.append(idx)
    # 연산된 결과 중 목적지 까지의 최대 비용 (건물 짓기 위해 필요한 딜레이)
    print(dp[goal])
    

