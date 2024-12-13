flag = True
while(flag):
    nums = list(map(int,input().split()))
    nums.sort()
    if nums.count(0) == 3: break
    if (nums[0]**2 + nums[1]**2 == nums[2]**2):   print("right")
    else:   print("wrong")