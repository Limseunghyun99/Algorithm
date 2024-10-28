# dp[n] -> 2xn 직사각형의 경우의 수
dp = [0] * 1001
dp[1] = 1
dp[2] = 2

def tile(n):
    # 이미 연산된 경우의 수라면?
    # 저장된 값을 리턴
    if dp[n] != 0:
        return dp[n]
    # n = n-1 + n-2의 경우의 수
    # n-1 가장 오른쪽을 1x2로 채우는 경우
    # n-2 가장 오른쪽 두칸을 2x1 두개로 채우는 경우
    dp[n] = tile(n-1) + tile(n-2)
    return dp[n]
n = int(input())
ans = tile(n)
print(ans%10007)
