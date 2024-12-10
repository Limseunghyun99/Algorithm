# Key Idea : KMP
# 이전 문제들과크게 다르지 않지만 고려할게 좀 더 많다

# LPS (Longest Prefix Suffix) 배열
# 접두/접미사가 동일한 최대 길이를 저장, 이후에 탐색 범위를 줄임

# KMP >> 이전에 쓰던것과 동일
# 순환문자열 >> 순환문자열 만들기 귀찮으넫 같은거 두개 붙여야지

# 확률 계산? >> 매칭된 패턴의 개수와 문자열의 길이로 계산
# 기약분수 >> 최대 공약수로 계산
from math import gcd

def kmp(pattern, text):
    # 패턴의 길이
    m = len(pattern)
    # LPS(Longest Prefix Suffix) 배열 생성 (패턴 내 반복 접두사-접미사 길이 저장)
    lps = [0] * m
    j = 0  # 패턴의 포인터 초기화

    # 1. LPS 배열 계산
    for i in range(1, m):
        while j > 0 and pattern[i] != pattern[j]:  # 현재 문자와 이전 접두사-접미사 비교
            j = lps[j - 1]  # 접두사-접미사 길이 감소
        if pattern[i] == pattern[j]:  # 현재 문자와 접두사 일치
            j += 1
            lps[i] = j  # LPS 값 저장

    # 문자열 매칭
    n = len(text)  # 텍스트의 길이
    j = 0  # 패턴 포인터 초기화
    match_count = 0  # 매칭 횟수 카운트

    # 2. 패턴과 텍스트 매칭
    for i in range(n):
        while j > 0 and text[i] != pattern[j]:  # 패턴 불일치 시 LPS 참고
            j = lps[j - 1]
        if text[i] == pattern[j]:  # 패턴과 텍스트의 현재 문자가 일치
            if j == m - 1:  # 패턴의 끝까지 매칭됨
                match_count += 1  # 매칭 횟수 증가
                j = lps[j]  # 다음 매칭 준비
            else:
                j += 1

    return match_count  # 매칭된 패턴의 개수 반환

# 입력 받기
L = int(input())  # 문자열 길이 입력
A = input().split()  # 패턴 문자열
B = input().split()  # 텍스트 문자열

# 문자열 B를 두 번 이어 붙여 회전 문자열 검색 가능하게 변환
B_extended = B + B[:-1]

# 매칭 횟수 계산
matches = kmp(A, B_extended)

# 기약 분수 계산 (매칭 횟수 / 문자열 길이)
divisor = gcd(matches, L)  # 최대공약수 계산
print(f"{matches // divisor}/{L // divisor}")  # 기약 분수 출력
