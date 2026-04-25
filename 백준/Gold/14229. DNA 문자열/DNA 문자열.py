import sys
from itertools import product

input = sys.stdin.readline

S = input().strip()

dna = ['A', 'C', 'G', 'T']

for length in range(1, 7):
    included = set()

    # S 안에 있는 길이 length 부분 문자열들을 set에 저장
    for i in range(len(S) - length + 1):
        included.add(S[i:i + length])

    # 길이 length로 만들 수 있는 모든 DNA 문자열 확인
    for candidate in product(dna, repeat=length):
        word = ''.join(candidate)

        # S에 없는 문자열이면 정답
        if word not in included:
            print(word)
            sys.exit()