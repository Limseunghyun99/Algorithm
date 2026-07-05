from collections import deque

def solution(h, grid, panels, seqs):
    n = len(grid)
    m = len(grid[0])
    k = len(panels)

    INF = 10**18

    # 엘리베이터 위치 찾기
    elevator = None
    for r in range(n):
        for c in range(m):
            if grid[r][c] == '@':
                elevator = (r, c)

    er, ec = elevator

    # 패널 위치 0-index 변환
    # floors[i], positions[i]는 i번 패널의 층과 좌표
    floors = []
    positions = []

    for f, r, c in panels:
        floors.append(f - 1)
        positions.append((r - 1, c - 1))

    # 2D BFS
    def bfs(start_r, start_c):
        dist = [[-1] * m for _ in range(n)]
        q = deque()

        dist[start_r][start_c] = 0
        q.append((start_r, start_c))

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while q:
            r, c = q.popleft()

            for dr, dc in directions:
                nr = r + dr
                nc = c + dc

                if nr < 0 or nr >= n or nc < 0 or nc >= m:
                    continue

                if grid[nr][nc] == '#':
                    continue

                if dist[nr][nc] != -1:
                    continue

                dist[nr][nc] = dist[r][c] + 1
                q.append((nr, nc))

        return dist

    # 각 패널에서의 2D 거리
    panel_bfs = []
    for r, c in positions:
        panel_bfs.append(bfs(r, c))

    # 엘리베이터에서의 2D 거리
    elevator_bfs = bfs(er, ec)

    # 패널 간 이동 거리 계산
    move_dist = [[INF] * k for _ in range(k)]

    for i in range(k):
        fi = floors[i]
        ri, ci = positions[i]

        for j in range(k):
            if i == j:
                move_dist[i][j] = 0
                continue

            fj = floors[j]
            rj, cj = positions[j]

            # 같은 층이면 직접 2D BFS 거리
            if fi == fj:
                d = panel_bfs[i][rj][cj]
                move_dist[i][j] = d

            # 다른 층이면 반드시 엘리베이터 경유
            else:
                to_elevator = panel_bfs[i][er][ec]
                from_elevator = elevator_bfs[rj][cj]
                floor_move = abs(fi - fj)

                move_dist[i][j] = to_elevator + floor_move + from_elevator

    # 각 패널의 선행 조건을 비트마스크로 저장
    prereq = [0] * k

    for a, b in seqs:
        a -= 1
        b -= 1
        prereq[b] |= 1 << a

    # 시작 위치는 1번 패널
    start_pos = 0

    # 1번 패널을 시작하자마자 활성화할 수 있는지 확인
    if prereq[0] == 0:
        start_mask = 1 << 0
    else:
        start_mask = 0

    full_mask = (1 << k) - 1

    # dp[mask][last] = 현재 활성화 상태가 mask이고,
    # last번 패널 위치에 있을 때의 최소 시간
    dp = [[INF] * k for _ in range(1 << k)]
    dp[start_mask][start_pos] = 0

    for mask in range(1 << k):
        for last in range(k):
            if dp[mask][last] == INF:
                continue

            # 다음에 활성화할 패널 선택
            for nxt in range(k):
                # 이미 활성화된 패널이면 패스
                if mask & (1 << nxt):
                    continue

                # 선행 조건이 아직 충족되지 않았으면 패스
                if prereq[nxt] & ~mask:
                    continue

                new_mask = mask | (1 << nxt)
                new_cost = dp[mask][last] + move_dist[last][nxt]

                if new_cost < dp[new_mask][nxt]:
                    dp[new_mask][nxt] = new_cost

    return min(dp[full_mask])