# Key Idea, Union-find algorithm
# 입력된 적군 위치끼리 연결되는지 판단 -> 연결되면 하나의 셋으로 연결
import sys
sys.setrecursionlimit(10**5)
input = sys.stdin.readline

def find(node):
    if parent[node] != node:    parent[node] = find(parent[node])
    return parent[node]

def union (a,b):
    a = find(a)
    b = find(b)
    if a < b : parent[b] = a
    else : parent[a] = b

T = int(input())

for _ in range(T):
    # Num of enemies
    N = int(input())
    # Init parent list for union-find
    parent = [i for i in range(N)]
    enemies = [list(map(int, input().split())) for _ in range(N)]

    # location of enemy
    for idx in range (N):
        x,y,r = enemies[idx]
        # 이후의 지점들과 연결되어 있는가
        for j in range(idx+1, N):
            x_1,y_1,r_1 = enemies[j]
            # 피타고라스 공식, 원형이기에 대각선 연결 여부를 봐야함
            if (((x-x_1)**2 + (y-y_1)**2) <= (r+r_1)**2): union(idx,j)
        # 중복 제거
    num_groups = set()
    for i in range(N):
        X = find(i)
        if X not in num_groups: num_groups.add(X)

    print(len(num_groups))