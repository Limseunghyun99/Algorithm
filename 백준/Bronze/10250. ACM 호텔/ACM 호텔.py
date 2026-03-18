T = int(input())

for _ in range(T):
    H,W,N = map(int, input().split())
    if(N%H==0):
        floor = H
        N_room = N//H
    else:
        floor = N%H
        N_room = N//H+1

    print(str(floor)+str(N_room).zfill(2))