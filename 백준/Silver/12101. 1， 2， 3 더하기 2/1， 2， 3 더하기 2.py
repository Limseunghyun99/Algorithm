# 꼼수
import sys
input = sys.stdin.readline

n,k = map(int,input().split())
save = {}
save[1] = ["1"]
save[2] = ["1+1","2"]
save[3] = ["1+2","1+1+1","2+1","3"]
for i in range(4,11):
    save[i] = []
    # N보다 1 작은수를 만드는 경우추가
    for j in save[i-1]:    save[i].append(j+"+1")
    # N보다 2 작은수를 만드는 경우추가
    for j in save[i-2]:    save[i].append(j+"+2")
    # N보다 3 작은수를 만드는 경우추가
    for j in save[i-3]:    save[i].append(j+"+3")            

if k <= len(save[n]):    print(sorted(save[n])[k-1])
else:    print(-1)