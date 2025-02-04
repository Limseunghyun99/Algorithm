MAX = 1000001
N = int(input())
P = [0] + list(map(int, input().split()))
dp = [MAX]*(N+1)
dp[0] = 0

for i in range(N+1):
    for j in range(i+1):
        dp[i] = min(dp[i], dp[i-j]+P[j])

print(dp[-1])