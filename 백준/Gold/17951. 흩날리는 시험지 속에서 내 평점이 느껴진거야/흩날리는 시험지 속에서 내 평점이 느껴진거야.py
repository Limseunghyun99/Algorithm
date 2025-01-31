N,K = map(int, input().split())
scores = list(map(int,input().split()))

l,r = 1, (10 ** 5 * 20) + 1
ans = 0

while (l<=r):
    pivot = (l+r)//2
    cnt = 0
    tmp = 0
    for score in scores:
        tmp += score
        # 현재 목표 점수를 넘긴 경우
        if tmp >= pivot:  
            cnt+=1
            tmp = 0
    if cnt <K:  r = pivot -1
    else:
        ans = pivot
        l = pivot+1
        
print(ans)