def solution(s):
    # 문자열을 공백 기준으로 분리하여 정수로 변환
    numbers = list(map(int, s.split()))
    # 최소값과 최대값 찾기
    min_val = min(numbers)
    max_val = max(numbers)
    # 결과 문자열 생성
    return f"{min_val} {max_val}"
