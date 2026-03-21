N = int(input())

as_is = list(map(int, input().split()))
to_be = list(map(int, input().split()))

diff = [to_be[i] - as_is[i] for i in range(N)]

ans = abs(diff[0])

for i in range(1, N):
    # 이전과 부호가 다르면 지금 구간은 새로 시작
    if diff[i] * diff[i - 1] <= 0:
        ans += abs(diff[i])
    else:
        # 같은 부호면 더 커진 만큼만 추가
        if abs(diff[i]) > abs(diff[i - 1]):
            ans += abs(diff[i]) - abs(diff[i - 1])

print(ans)