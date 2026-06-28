def solution(n, t, m, timetable):
    # "HH:MM" -> 분 단위 정수
    def time_to_min(time_str):
        hour, minute = map(int, time_str.split(":"))
        return hour * 60 + minute

    # 분 단위 정수 -> "HH:MM"
    def min_to_time(minutes):
        hour = minutes // 60
        minute = minutes % 60
        return f"{hour:02d}:{minute:02d}"

    # 크루 도착 시간을 분 단위로 변환 후 정렬
    crew_times = []
    for time in timetable:
        crew_times.append(time_to_min(time))

    crew_times.sort()

    # 첫 셔틀 시간은 09:00
    bus_time = time_to_min("09:00")

    # 현재 태울 크루의 인덱스
    crew_idx = 0

    # 마지막 셔틀에 탄 크루들의 도착 시간 저장
    last_bus_crew = []

    # n번 셔틀 운행
    for bus_count in range(n):
        current_bus_time = bus_time + bus_count * t

        # 현재 셔틀에 탄 크루들
        current_bus_crew = []

        # 정원이 남아 있고,
        # 아직 대기 중인 크루가 있으며,
        # 그 크루가 현재 셔틀 시간 이하에 도착했다면 탑승
        while (
            len(current_bus_crew) < m
            and crew_idx < len(crew_times)
            and crew_times[crew_idx] <= current_bus_time
        ):
            current_bus_crew.append(crew_times[crew_idx])
            crew_idx += 1

        # 마지막 셔틀의 탑승자 정보를 저장
        if bus_count == n - 1:
            last_bus_crew = current_bus_crew
            last_bus_time = current_bus_time

    # 마지막 셔틀에 자리가 남는 경우
    if len(last_bus_crew) < m:
        answer = last_bus_time

    # 마지막 셔틀이 꽉 찬 경우
    else:
        # 마지막으로 탄 크루보다 1분 일찍 와야 함
        answer = last_bus_crew[-1] - 1

    return min_to_time(answer)