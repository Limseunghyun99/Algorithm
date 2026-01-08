#해결해야 하는 문제 : fibo(0), fibo(1) 이 얼마나 호출되는지
# 재귀함수 특성상 모든 함수 호출의 끝에는 0,1이 있으니 트리의 리프 노드 갯수를 구하는 것과 다르지 않음

# 아 근데 fibo(0), fibo(1) 이 동일하게 나오는게 아니라 dp로 점화식으로 풀어야되네
import sys
input = sys.stdin.readline

t = int(input())

# dp[n] = (fibo(0) 호출 횟수, fibo(1) 호출 횟수)
dp = [(0, 0)] * 41
dp[0] = (1, 0)
dp[1] = (0, 1)

for i in range(2, 41):
    dp[i] = (
        dp[i-1][0] + dp[i-2][0],
        dp[i-1][1] + dp[i-2][1]
    )

for _ in range(t):
    n = int(input())
    print(dp[n][0], dp[n][1])