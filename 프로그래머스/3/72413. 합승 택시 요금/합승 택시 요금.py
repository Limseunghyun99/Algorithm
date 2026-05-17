def solution(n, s, a, b, fares):
    INF = int(1e15)

    # dist[i][j] = i번 지점에서 j번 지점까지 가는 최소 요금
    # 지점 번호가 1번부터 n번까지이므로 n+1 크기로 생성
    dist = [[INF] * (n + 1) for _ in range(n + 1)]

    # 자기 자신으로 가는 비용은 0
    for i in range(1, n + 1):
        dist[i][i] = 0

    # fares에는 [출발지, 도착지, 요금] 형태로 들어 있음
    # 문제에서 택시 요금은 양방향이므로 둘 다 저장
    for c, d, f in fares:
        dist[c][d] = f
        dist[d][c] = f

    # k: 중간에 거쳐 가는 지점
    # i: 출발
    # j: 도착
    for k in range(1, n + 1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                # i에서 j로 바로 가는 것보다
                # i -> k -> j로 가는 것이 더 싸다면 갱신
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    answer = INF

    # x는 A와 B가 헤어지는 지점이라고 생각하면 됨
    # x == s이면 처음부터 따로 가는 경우
    # x == a 또는 x == b이면 한 명 목적지까지 같이 가는 경우도 포함됨
    for x in range(1, n + 1):
        total_cost = dist[s][x] + dist[x][a] + dist[x][b]
        answer = min(answer, total_cost)

    return answer