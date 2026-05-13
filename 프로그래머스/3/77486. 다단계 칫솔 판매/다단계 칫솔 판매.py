def solution(enroll, referral, seller, amount):
    n = len(enroll)

    # 이름 -> 인덱스
    name_to_idx = {name: i for i, name in enumerate(enroll)}

    # 각 사람의 추천인 인덱스
    # 추천인이 "-"이면 center이므로 -1로 표시
    parent = [-1] * n
    for i in range(n):
        if referral[i] != "-":
            parent[i] = name_to_idx[referral[i]]

    answer = [0] * n

    # 판매 기록을 하나씩 처리
    for name, cnt in zip(seller, amount):
        idx = name_to_idx[name]
        money = cnt * 100

        while idx != -1 and money > 0:
            give = money // 10      # 추천인에게 줄 10%
            keep = money - give     # 현재 사람이 가질 금액

            answer[idx] += keep

            # 줄 돈이 0원이면 더 이상 위로 분배하지 않음
            if give == 0:
                break

            money = give
            idx = parent[idx]

    return answer