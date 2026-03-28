N = int(input())
arr = list(map(int,input().split()))

arr.sort()
total = [0] * (N+1)

# print(*arr)
for i in range(1,N+1):
    total[i] += total[i-1]+arr[i-1]
    
print(sum(total))
