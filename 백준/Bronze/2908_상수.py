a,b = map(int, input().split())

flipped_a = (a//100)+(a//10%10*10)+(a%10*100)
flipped_b = (b//100)+(b//10%10*10)+(b%10*100)

print(flipped_a if flipped_a>flipped_b else flipped_b)