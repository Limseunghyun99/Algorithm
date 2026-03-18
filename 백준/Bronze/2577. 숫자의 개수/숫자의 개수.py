numbers = [0]*10
a = int(input())
b = int(input())
c = int(input())
ans = a*b*c

while ans > 0:
    num = ans % 10
    numbers[num] += 1
    ans //= 10
    
for i in numbers:    print(i)