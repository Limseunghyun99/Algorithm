N = int(input())
dp=[0]*10000001
dp[1], dp[2] = 1,2
for i in range(3,N+1):  dp[i] = (dp[i-2] + dp[i-1]) % 15746
print(dp[N])