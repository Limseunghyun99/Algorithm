def find(node):
    # 자기 자신이 루트라면
    if node == root[node]: return node
    else:
        # 엄마 모셔와
        tmp = find(root[node])
        root[node] = tmp
        return root[node]

def union(node_a, node_b):
    root_a = find(node_a)
    root_b = find(node_b)

    if root_a != root_b:
        root[root_b] = root_a
        size[root_a] += size[root_b]

T = int(input())

for _ in range(T):
    # 각 노드의 root가 누구인지 저장
    root = dict()
    # 각 노드가 속한 트리의 크기 (여기서는 친구 크기)
    size = dict()

    N = int(input())

    for idx in range(N):
        a,b = input().split()
        
        # 처음 입력된 사람이라면
        if a not in root:
            root[a] = a
            size[a] = 1
        if b not in root:
            root[b] = b
            size[b] = 1
        
        union(a,b)
        print(size[find(a)])
