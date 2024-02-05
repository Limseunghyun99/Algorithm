N, M = map(int, input().split())

basket = list(range(1,N+1))
# check basket
# print(basket)

for _ in range (M):
    a, b = map(int, input().split())
    basket[a-1], basket[b-1] =basket[b-1], basket[a-1]
    # print(basket)

for i in range (N):
    print(basket[i], end=' ')