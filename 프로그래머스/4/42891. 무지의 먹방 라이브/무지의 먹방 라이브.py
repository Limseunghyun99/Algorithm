def solution(food_times, k):
    # 모든 음식을 다 먹을 수 있는 경우
    if sum(food_times) <= k:
        return -1

    # (음식 시간, 음식 번호) 형태로 저장
    foods = []
    for i, time in enumerate(food_times):
        foods.append((time, i + 1))

    # 음식 시간이 적은 순서대로 정렬
    foods.sort()

    n = len(food_times)

    # 이전까지 모든 음식에서 공통으로 먹은 시간
    previous_time = 0

    # 시간이 적은 음식부터 확인
    for i, (time, food_number) in enumerate(foods):
        # 현재 음식이 없어지기 위해 추가로 먹어야 하는 시간
        diff = time - previous_time

        # 이미 같은 시간대에서 처리된 음식이면 넘어감
        if diff == 0:
            continue

        # 아직 남아 있는 음식 개수
        remaining_food_count = n - i

        # 남은 음식들을 diff초씩 모두 먹는 데 필요한 총 시간
        spend = diff * remaining_food_count

        # k초 안에 이 구간을 통째로 먹을 수 있다면
        if k >= spend:
            k -= spend
            previous_time = time

        # 이 구간을 다 먹기 전에 네트워크 장애가 발생한다면
        else:
            # 아직 남은 음식들을 음식 번호 순서대로 정렬
            remaining_foods = sorted(foods[i:], key=lambda x: x[1])

            # 남은 음식 중 k번째 위치의 음식 번호가 정답
            return remaining_foods[k % remaining_food_count][1]