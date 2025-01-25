# Key Idea : dp[N] = dp[n-2]+dp[n-3]
# 걍 피본데? 근데 memo 안쓰니까 시간초과과
import sys
input = sys.stdin.readline
dp = [0,1,1,1] + [0 for _ in range(97)]

def fn(N):
    if (dp[N]): return dp[N]
    else:
        dp[N] = fn(N-2) + fn(N-3)    
        return dp[N]

T = int(input())
for _ in range(T):  print(fn(int(input())))
