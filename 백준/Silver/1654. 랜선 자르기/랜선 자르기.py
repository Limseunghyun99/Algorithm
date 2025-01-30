K,N = map(int, input().split())
cables = []

for _ in range(K):    cables.append(int(input()))

start, end = 1, max(cables)
while(start<=end):
    mid = (start+end)//2
    cable_cnt = 0
    # 각 케이블을 mid 크기로 잘랐을때 총 몇개 만들 수 있는가
    for cable in cables:    cable_cnt+= cable//mid
    # 만들 수 있는 경우의 수가 목표치 보다 많은 경우, 중간값 이후 부분을 탐색
    if cable_cnt >= N:  start=mid+1
    # 개수가 모자란 경우 중간값 보다 작은 경우의 수들을 탐색
    else:   end = mid-1
print(end)