import sys
N = int(input())
# (a,b) 입력
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

# Memo
dp = [[0]*(N) for _ in range(N)]

# start : 시작점
# term : 간격,
# term=1 : (1,2)
# term=2 : (1,2), (1,3), (2,3) 조합의 연산량을 구하고 dp에 저장
for term in range(1, N):
    for start in range(N):  # 첫행렬 : i, 끝행렬: i+term
        if start + term == N:  # 범위를 벗어나면 무시
            break
        ### 여기 위까지는 범위 지정 (1,2)(1,3)(1,4)####
        ### 아래는 divde & Conquer 파트 ####
        dp[start][start+term] = int(1e9)  # 지금 계산할 첫행렬과 끝행렬, 1e9 -> 10만, 충분히 큰수
        # 지금 조건을 기준으로 문제를 쪼갠다
        # (start:term) -> (start:t)(t+1:term)
        # 그럼 이때 연산량 = Left행 x Left열 x Right 열
        #  arr[start][0] * arr[t][1] * arr[start+term][1]
        # 이미 저장된 값과 비교 
        for t in range(start, start+term):
            dp[start][start+term] = min(dp[start][start+term],dp[start][t]+dp[t+1][start+term] + arr[start][0] * arr[t][1] * arr[start+term][1])
print(dp[0][N-1])