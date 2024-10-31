import sys
input = sys.stdin.readline
 
num = int(input())
arr = list(map(int, input().split()))

# dp[i] = arr[i] 를 마지막 값으로 가지는 가장 긴 증가 부분 수열
dp = [1 for i in range(num)]
 
# Key Idea : if arr[n] > arr[n-1]
# DP[n] = DP[0]~DP[n-1]까지의 수 중 가장 큰 경우의수 + 1
# 자기보다 아래에 있는 숫자들을 돌면서 가장 큰 수 + 1
for i in range(1, num):
    for j in range(i):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i], dp[j]+1)
 
print(max(dp))