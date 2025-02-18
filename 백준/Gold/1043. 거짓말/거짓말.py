# 진실을 아는 애들과 같은 트리에 속하는지만 보면 되는거 아닌가?
def find(a):
    if a != parent[a]:  parent[a] = find(parent[a])
    return parent[a]

def union(a, b):
    a = find(a)
    b = find(b)

    if a < b:   parent[b] = a   
    else:   parent[a] = b

N, M = map(int, input().split())

# 킹갓 파이썬은 몇명인지 알바 아님
_, *true_list = map(int, input().split())
parent = [i for i in range(N+1)]

IMPO = 0

for i in true_list: union(IMPO, i)

# 파티 단위로 union
parties = []
for _ in range(M):
    cnt, *party = list(map(int, input().split()))
    parties.append(party)

    for i in range(cnt - 1):
        union(party[i], party[i+1])

cnt = 0
for party in parties:  
    if find(party[0]) == IMPO:  continue
    cnt += 1

print(cnt)