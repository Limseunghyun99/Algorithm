nums = list(map(int, input().split()))
ans = 0

for i in range(len(nums)):
    ans += nums[i] * nums[i]
print(ans % 10)