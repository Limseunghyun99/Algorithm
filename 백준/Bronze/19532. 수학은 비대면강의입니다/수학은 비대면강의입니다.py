#Key : 딱히 제한 없는 브루트 포스 알고리즘 문제
a, b, c, d, e, f = map(int, input().split())

for i in range(-999, 1000):
    for j in range(-999, 1000):
        if (a*i) + (b*j) == c and (d*i) + (e*j) == f:    print(i,j)