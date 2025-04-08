def check(txt, tl, part, pl):
    ret = 0
    for i in range(tl-pl+1):
        if txt[i:i+pl] == part:
            ret+=1
    return ret

B = int(input())
LPS = [input() for _ in range(B)]
HPS = [input() for _ in range(B)]

T = int(input())
for _ in range(T):
    sign = input()
    sl = len(sign)
    C = 0
    for LP in LPS:
        C += check(sign, sl, LP, len(LP))
    for HP in HPS:
        C -= check(sign, sl, HP, len(HP))

    if not C: print('GOOD')
    elif C > 0: print(f'HIGH {C}')
    else: print(f'LOW {-C}')