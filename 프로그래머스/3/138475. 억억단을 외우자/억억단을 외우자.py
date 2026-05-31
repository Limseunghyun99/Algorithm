def solution(e, starts):
    # divisor_count[x] = 숫자 x의 약수 개수
    # 인덱스를 숫자 그대로 쓰기 위해 e + 1 크기로 만든다.
    divisor_count = [0] * (e + 1)

    # 1부터 e까지 각각의 수 i를 "약수"로 본다.
    # i의 배수들은 모두 i를 약수로 가지므로 +1 해준다.
    #
    # 예를 들어 i = 3이면
    # 3, 6, 9, 12, ... 는 모두 3을 약수로 가진다.
    for i in range(1, e + 1):
        for multiple in range(i, e + 1, i):
            divisor_count[multiple] += 1

    # answer_from[s] = s 이상 e 이하 중에서
    # 약수 개수가 가장 많은 수
    # 동점이면 더 작은 수
    answer_from = [0] * (e + 1)

    # 현재까지 본 범위에서 가장 좋은 숫자
    # 처음에는 e 하나만 본 상태라고 생각한다.
    best = e

    # e부터 1까지 거꾸로 내려오면서 답을 미리 구한다.
    for num in range(e, 0, -1):
        # num의 약수 개수가 현재 best의 약수 개수보다 많으면 num 선택
        #
        # 여기서 >= 를 쓰는 이유:
        # 약수 개수가 같을 때는 더 작은 수를 선택해야 한다.
        # 지금은 e에서 1 방향으로 내려오고 있으므로,
        # 현재 num은 기존 best보다 항상 작다.
        if divisor_count[num] >= divisor_count[best]:
            best = num

        # num 이상 e 이하에서의 정답은 best
        answer_from[num] = best

    # 각 starts의 원소 s에 대해 미리 구한 답을 꺼내면 된다.
    result = []

    for s in starts:
        result.append(answer_from[s])

    return result