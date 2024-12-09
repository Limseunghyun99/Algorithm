# Key Idea : KMP!
# 이전 문제의 접근 방식과 동일하다

# 입력된 문자열(패턴)의 접두사와 접미사가 겹치는 길이를 테이블 형태로 저장.
# table[i]는 패턴의 첫 i+1 문자에서 접두사와 접미사가 겹치는 최대 길이를 나타냄.
def KMP(pattern):
    # 패턴의 접두사-접미사 테이블 (Partial Match Table)을 생성하는 함수
    i = 0  # 접두사 매칭 포인터 초기화
    table = [0] * len(pattern)  # 패턴 길이만큼 0으로 초기화된 테이블 생성
    for j in range(1, len(pattern)):  # 패턴의 두 번째 문자부터 순회
        while i > 0 and pattern[i] != pattern[j]:  # 현재 문자와 매칭되지 않으면
            i = table[i - 1]  # 이전 접두사 위치로 되돌림
        if pattern[i] == pattern[j]:  # 현재 문자와 매칭되면
            i += 1  # 접두사 매칭 길이 증가
            table[j] = i  # 현재 위치에 매칭 길이 저장
    return table  # 접두사-접미사 테이블 반환

l = int(input())  
s = input()  

# 입력 문자열에 대한 접두사-접미사 테이블 생성
table = KMP(s)

# 반복 부분을 제외한 문자열의 최소 길이를 출력
# l (전체 문자열 길이) - table[l-1] (가장 긴 접두사-접미사 매칭 길이)
print(l - table[l - 1])
