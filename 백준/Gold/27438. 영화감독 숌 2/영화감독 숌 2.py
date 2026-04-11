import sys
sys.setrecursionlimit(10**6)
n = int(sys.stdin.readline())

# N 범위, 걍 넉넉히 100정도
MAX_DIGIT = 100
# 돌면서 dp 에 저장
# dp[남은 자리수][현재 연속된 6의 개수(0~2)][이미 666 포함 여부(0/1)]
dp = [[[-1] * 2 for _ in range(3)] for _ in range(MAX_DIGIT + 1)]


def get_count(rem, conti, already):
    # conti가 3 이상이면 666
    if conti >= 3:
        already = 1
        conti = 2  # dp 인덱스 보호용, 이미 already=1이면 conti는 의미 없음
    # 이미 666이 포함된 상태라면 남은 자리는 아무거나 가능 *건너 뛰기
    if already:        return 10 ** rem
    if rem == 0:        return 0

    if dp[rem][conti][already] != -1:        return dp[rem][conti][already]

    res = 0
    for digit in range(10):
        next_conti = conti + 1 if digit == 6 else 0
        next_already = already
        if next_conti >= 3:
            next_already = 1
            next_conti = 2
        res += get_count(rem - 1, next_conti, next_already)

    dp[rem][conti][already] = res
    return res


ans_digits = [0] * (MAX_DIGIT + 1)
conti = 0
already = 0

# 가장 높은 자리부터 답을 구성
for pos in range(MAX_DIGIT, 0, -1):
    for digit in range(10):
        next_conti = conti + 1 if digit == 6 else 0
        next_already = already
        if next_conti >= 3:
            next_already = 1
            next_conti = 2

        cnt = get_count(pos - 1, next_conti, next_already)

        if n <= cnt:
            ans_digits[pos] = digit
            conti = next_conti
            already = next_already
            break
        else:
            n -= cnt

# 숫자로 변환
answer = 0
for pos in range(MAX_DIGIT, 0, -1):
    answer = answer * 10 + ans_digits[pos]

print(answer)