num_coins, total = map(int, input().split())
coins = list(range(num_coins))
cnt = 0

for idx in range(num_coins):
    coins[idx] = int(input())
    
coins.sort(reverse=True)    
for coin in range (num_coins):
    cnt += total//coins[coin]
    total %= coins[coin]
    if (total==0):
        break
print(cnt)