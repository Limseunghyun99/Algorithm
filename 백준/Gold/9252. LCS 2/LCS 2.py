import sys
input = sys.stdin.readline

# 두 문자열을 입력받아 각각 리스트 A와 B에 저장합니다.
# 줄바꿈 문자 제거
A = [""] + list(input().rstrip())  # 문자열 A에 빈 문자열을 추가하여 인덱스를 1부터 시작
B = [""] + list(input().rstrip())  # 문자열 B에 빈 문자열을 추가하여 인덱스를 1부터 시작

# LCS 테이블 초기화, A와 B의 각 위치에서의 LCS를 저장하기 위한 2차원 리스트
LCS = [[""] * len(B) for _ in range(len(A))]

# LCS 테이블을 채워나가는 과정
for i in range(1, len(A)):
    for j in range(1, len(B)):
        if A[i] == B[j]:  # A와 B의 현재 문자가 같으면
            LCS[i][j] = LCS[i-1][j-1] + A[i]  # 대각선 왼쪽 위에서 내려오며 현재 문자 추가
        else:
            # A와 B의 현재 문자가 다르면, 윗줄이나 왼쪽 중 더 긴 LCS를 선택
            if len(LCS[i-1][j]) >= len(LCS[i][j-1]):
                LCS[i][j] = LCS[i-1][j]  # 윗줄의 LCS 선택
            else:
                LCS[i][j] = LCS[i][j-1]  # 왼쪽의 LCS 선택

# 최종 결과는 LCS 테이블의 마지막 요소에 있음
result = LCS[-1][-1]
# 최장 공통 부분 수열의 길이와 문자열을 출력
print(len(result), result, sep="\n")
