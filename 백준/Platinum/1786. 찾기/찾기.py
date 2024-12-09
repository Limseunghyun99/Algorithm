# Key Idea : KMP!
# Pattern 찾기
# index i,j 두개를 놓고 단어 하나 단위로 확인하면서 포인터 하나씩 이동


def make_pattern_index():
    # 패턴(P)의 접두사-접미사 테이블을 생성하는 함수 (KMP 알고리즘에서 사용)
    pi = [0 for i in range(0, len(P))]  # P의 길이만큼 0으로 초기화된 pi 배열 생성

    j = 0  # 접두사-접미사 매칭 포인터 초기화
    for i in range(1, len(P)):  # 패턴의 두 번째 문자부터 순회
        while j > 0 and P[i] != P[j]:  # 현재 문자와 매칭되지 않으면 이전 접두사로 이동
            j = pi[j - 1]  # 접두사 매칭 포인터를 이전 위치로 되돌림

        if (P[i] == P[j]):  # 현재 문자와 매칭되면
            j += 1  # 접두사 매칭 길이 증가
            pi[i] = j  # 현재 위치에 매칭 길이 저장
    return pi  # 접두사-접미사 테이블 반환


def solution(pi):
    # 문자열 T에서 패턴 P의 모든 매칭 시작 위치를 찾는 함수
    result = []  # 매칭 시작 위치를 저장할 리스트
    count = 0  # 매칭된 패턴의 개수를 카운트

    j = 0  # 패턴 매칭 포인터 초기화
    for i in range(0, len(T)):  # 텍스트의 모든 문자 순회
        while j > 0 and T[i] != P[j]:  # 현재 문자와 패턴이 매칭되지 않으면
            j = pi[j - 1]  # 접두사 테이블을 이용해 패턴 포인터 되돌림

        if T[i] == P[j]:  # 현재 문자와 패턴이 매칭되면
            if j == (len(P) - 1):  # 패턴의 끝까지 매칭된 경우
                result.append(i - len(P) + 2)  # 매칭 시작 위치를 result에 추가 (1-based index)
                count += 1  # 매칭 개수 증가
                j = pi[j]  # 접두사 테이블을 이용해 패턴 포인터 되돌림
            else:
                j += 1  # 패턴 매칭 포인터를 다음 문자로 이동

    print(count)  # 매칭된 패턴의 개수를 출력
    for element in result:  # 모든 매칭 시작 위치를 출력
        print(element)


T = input()  # 텍스트 입력
P = input()  # 패턴 입력
solution(make_pattern_index())  # 접두사-접미사 테이블 생성 후 패턴 매칭 수행