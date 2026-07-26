def solution(sales, links):
    n = len(sales)
    children = [[] for _ in range(n)]

    for leader, member in links:
        # 인덱스랑 직원 번호 맞춰주기
        leader -= 1
        member -= 1
        children[leader].append(member)

    order = []
    stack = [0]  # 0번 인덱스가 직원번호 1번 CEO

    while stack:
        current = stack.pop()
        order.append(current)

        for child in children[current]:
            stack.append(child)

    # u가 참석하지 않을 때 u의 하위 조직을 만족시키는 최소 비용
    dp_not_attend = [0] * n

    # u가 참석할 때 u의 하위 조직을 만족시키는 최소 비용
    dp_attend = [0] * n

    INF = float("inf")

    for employee in reversed(order):
        # 비용 == 참석자의 매출액
        dp_attend[employee] = sales[employee]

        # 말단 직원
        if not children[employee]:
            continue

        base_cost = 0
        min_extra_cost = INF

        for child in children[employee]:
            # 하위조직이 참석하거나 불참하는 경우 비교
            child_min_cost = min(
                dp_not_attend[child],
                dp_attend[child]
            )

            base_cost += child_min_cost

            # 현재 자식을 반드시 참석시키기 위해 필요한 추가 비용
            extra_cost = dp_attend[child] - child_min_cost

            min_extra_cost = min(
                min_extra_cost,
                extra_cost
            )

        # 현재 직원이 참석하는 경의 수
        dp_attend[employee] += base_cost

        # 현재 직원이 불참하는 경우
        # 직속 팀원 중 최소 한 명은 반드시 참석해야 합니다.
        #
        # 이미 어떤 자식의 참석 상태가 더 저렴했다면
        # extra_cost가 0이 됩니다.
        dp_not_attend[employee] = (
            base_cost + min_extra_cost
        )

    return min(dp_not_attend[0], dp_attend[0])