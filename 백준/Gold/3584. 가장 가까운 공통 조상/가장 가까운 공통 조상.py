T = int(input())
for _ in range(T):
    N = int(input())
    parent = [0] * (N+1)
    # 부모 정보
    for _ in range(N-1):
        i,j = map(int, input().split())
        parent[j] = i
    
    a, b = map(int, input().split())
    parent_a, parent_b = [a], [b]

    # 조상까지 쭉 타고 올라감
    while parent[a] != a:
        parent_a.append(parent[a])
        a = parent[a]
    while parent[b] != b:
        parent_b.append(parent[b])
        b = parent[b]

    depth_a = len(parent_a)-1
    depth_b = len(parent_b)-1
    # 루트부터 내려오면서 가장 가까운 조상 찾기
    while parent_a[depth_a] == parent_b[depth_b]: 
        depth_a -= 1
        depth_b -= 1

    #print("###############")
    print(parent_a[depth_a+1])