dice_result = list(map(int,input().split()))
dice_result.sort()
if (dice_result[0]==dice_result[1] & dice_result[0]==dice_result[2]):
    print(10000+dice_result[0]*1000)
elif (dice_result[0]==dice_result[1] or dice_result[1]==dice_result[2]):
    print(1000+dice_result[1]*100)
else:
    print(dice_result[2] * 100)