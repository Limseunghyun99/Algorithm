import sys
from itertools import combinations
input = sys.stdin.readline

n = int(input())
answer = []

# 최소 감소하는 수는 0, 최대 감소하는 수는 9876543210 
# 자릿수에 맞게 1부터 10까지 반복
for i in range(1, 11): 
    for pivot in combinations(range(10), i): 
         # 감소하는 수이므로 역순 정렬
        num = sorted(list(pivot), reverse=True)
        answer.append(int("".join(map(str, num))))
answer.sort() # 아 정렬 안해주니까 틀리네
        
print(answer[n] if len(answer) > n else -1)  # 감소하는 수가 있을 때와 없는 경우