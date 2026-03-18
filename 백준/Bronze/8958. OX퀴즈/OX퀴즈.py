T= int(input())

for _ in range(T):
    cnt =1
    total =0
    tmp = input()
    for c in range(len(tmp)):
        if tmp[c] == 'O': 
            total += cnt
            cnt += 1
        else:
            cnt=1
    print(total)