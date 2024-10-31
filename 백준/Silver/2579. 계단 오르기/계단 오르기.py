# Max num of stairs
MAX = 300+1
num = int(input())

# score of each stair
stairs=[0]*MAX
# max score of 0~N stairs
dp = [0]*MAX

for idx in range(1,num+1):
    stairs[idx] = int(input())

# Key Idea : 뒤에서 부터 생각하기
#   1) 한번에 1개 or 2개 계단 올라감
#   2) 연속된 3개의 계단을 밟아선 안된다
# → 마지막 계단을 기준으로 두 경우의 수로 나눌 수 있음
#   1. 직전 칸에서 올라왔는가
#   2. 전전칸에서 왔는가
dp[1] = stairs[1]
dp[2] = stairs[1] + stairs[2]
dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3])

# dp 점화식 계산
for i in range(4, num + 1):
    dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i])
    
print(dp[num])