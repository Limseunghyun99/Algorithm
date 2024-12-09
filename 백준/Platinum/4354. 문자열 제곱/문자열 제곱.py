# Key Idea : KMP, 반복되는 문자열 찾는건 동일!
# 제곱이라짐만 결국 등장 횟수를 출력 하는 문제
# 아 웨 입력이 안받아지냐ㅑㅑ -> 해결!

def KMP(sentence):
    # 문자열이 몇 번 반복되는지 계산하는 함수
    l = len(sentence)  # 문자열의 길이 저장
    for idx in range(1, (l // 2) + 1):  # 가능한 패턴 길이 탐색 (최대 문자열 길이의 절반까지)
        if l % idx == 0:  # 패턴 길이가 문자열 길이를 나누어떨어질 경우만 검사
            word = sentence[0:idx]  # 패턴 추출 (문자열의 앞 idx 문자)
            cnt = int(l / idx)  # 패턴이 몇 번 반복되는지 계산
            if word * cnt == sentence:  # 패턴을 cnt 번 반복했을 때 원래 문자열과 동일한지 확인
                return cnt  # 반복 횟수 반환
    return 1  # 반복되는 패턴이 없으면 1 반환 (전체 문자열이 하나의 단위)

while True:
    a = input()  # 문자열 입력
    if a == ".":  # "." 입력 시 종료
        break
    print(KMP(a))  # 문자열의 반복 횟수를 계산하여 출력