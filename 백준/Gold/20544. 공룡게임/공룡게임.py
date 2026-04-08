MOD = 1_000_000_007

N = int(input())

# b[n]: 0과 1만 사용해서 만들 수 있는 길이 n의 유효한 맵 수
b = [0] * (max(3, N + 1))
b[0] = 1
b[1] = 1
b[2] = 2

for i in range(3, N + 1):
    b[i] = (b[i - 1] + b[i - 2] + b[i - 3]) % MOD

# a[n]: 높이 2가 적어도 하나 포함된 길이 n의 유효한 맵 수
a = [0] * (max(4, N + 1))
a[1] = 0
if N >= 2:
    a[2] = 1
if N >= 3:
    a[3] = 4

for i in range(4, N + 1):
    a[i] = (
        a[i - 1]
        + 2 * a[i - 2]
        + 3 * a[i - 3]
        + b[i - 2]
        + 2 * b[i - 3]
    ) % MOD

print(a[N] % MOD)