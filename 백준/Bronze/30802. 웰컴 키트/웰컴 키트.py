N = int(input())
shirts = list(map(int, input().split()))
T,P =map(int, input().split())

N_T= 0

for shirt in shirts:
    if shirt%T ==0:    N_T += shirt//T
    else : N_T += shirt//T + 1
print(N_T)
print(N//P, N%P)
