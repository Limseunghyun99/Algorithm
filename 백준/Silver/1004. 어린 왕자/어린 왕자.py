# 좌표 평면으로 표현하고 x,y 기준으로 원너비 계산하고

import sys
input = sys.stdin.readline

def inside(x, y, cx, cy, r):
    # 거리의 제곱 <= 반지름^2 이면 내부/경계
    # (문제에서 점이 경계 위에 있는 입력은 없다고 했지만, <= 로 둬도 안전)
    dx = x - cx
    dy = y - cy
    return dx*dx + dy*dy < r*r  # 경계 제외 조건을 그대로 반영하려면 '<'

t = int(input())
for _ in range(t):
    x1, y1, x2, y2 = map(int, input().split())
    n = int(input())
    ans = 0
    for _ in range(n):
        cx, cy, r = map(int, input().split())
        s_in = inside(x1, y1, cx, cy, r)
        e_in = inside(x2, y2, cx, cy, r)
        if s_in ^ e_in:
            ans += 1
    print(ans)
