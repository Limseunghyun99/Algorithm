DEBUG=0
# 입력, 편의를 위해 list로 받음
# ACAYKP -> ['A', 'C'] 이런식
s1 = list(input())
s2 = list(input())

if DEBUG:
    print(s1,s2)

# LCS를 저장할 2차원 리스트 초기화 (s1과 s2의 길이에 +1을 하여 각 0부터 시작할 수 있게 만듦)
lcs = [[0] * (len(s2) + 1) for _ in range(len(s1) + 1)]

# 첫 번째 문자열의 문자들을 순차적으로 탐색
for i in range(1, len(s1)+1):
    # 두 번째 문자열의 문자들을 순차적으로 탐색
    for j in range(1, len(s2)+1):
        # 만약 두 문자가 같다면 (현재 비교 중인 s1과 s2의 문자가 같을 경우)
        if s1[i-1] == s2[j-1]:
            # 이전의 대각선 값에서 +1 (두 문자열이 동일하므로 LCS 길이가 1 증가)
            lcs[i][j] = lcs[i-1][j-1] + 1
        else:
            # 두 문자가 다를 경우, 위쪽 값과 왼쪽 값 중 큰 값을 선택
            lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1])

# 2차원 리스트 lcs에서 가장 큰 값을 출력 (LCS의 최대 길이)
print(max(map(max, lcs)))