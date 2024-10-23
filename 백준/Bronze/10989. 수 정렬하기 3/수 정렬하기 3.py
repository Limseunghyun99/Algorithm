import sys

n = int(sys.stdin.readline())
# 숫자 최대치 + 1
# Counting Sort 사용
num_list = [0] * 10001

# 숫자 입력 받기
# 각 숫자별 카운트 구하기
for _ in range(n):
    num_list[int(sys.stdin.readline())] += 1

for i in range(10001):
    if num_list[i] != 0:
        for j in range(num_list[i]):
            print(i)