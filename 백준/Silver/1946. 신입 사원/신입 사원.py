T = int(input())

for _ in range(T):
    ans = 1
    rank = 0
    
    N = int(input())
    TC = []
    for idx in range(N):
        s,e = map(int,input().split())
        TC.append((s,e))
    TC = sorted(TC, key=lambda TC:(TC[0], -TC[1]))
    
    for idx in range(1, len(TC)):
        if TC[idx][1] < TC[rank][1]:
            rank = idx
            ans += 1
    print(ans)
            