coins = [500, 100, 50, 10, 5, 1]
ans = 0

n = int(input())
r = 1000-n

for coin in coins:
    ans += r//coin
    r = r%coin
    
print(ans)