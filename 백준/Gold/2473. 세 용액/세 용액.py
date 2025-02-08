import sys
input = sys.stdin.readline

n = int(input())
lst = sorted(list(map(int, input().split())))

res = 30000000001 #임의의 max값
sol_candi = []

for i in range(n-2):
    refer = lst[i]
    l_p = i+1 #왼쪽 포인터
    r_p = n-1 #오른쪽 포인터
    while l_p < r_p:
        cur_sum = refer + lst[l_p] + lst[r_p]
        if abs(cur_sum) <= abs(res): #기준값보다 작으면
            sol_candi = [refer, lst[l_p], lst[r_p]] #세 용액 업데이트
            res = refer + lst[l_p] + lst[r_p] #결과값 업데이트
        if cur_sum < 0: l_p += 1
        elif cur_sum > 0:   r_p -= 1
        else:
            print(*sol_candi)
            exit()

print(*sol_candi)