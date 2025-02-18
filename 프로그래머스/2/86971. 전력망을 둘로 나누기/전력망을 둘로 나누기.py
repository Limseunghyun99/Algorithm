# 트리형태인데 서로 개수를 비슷하게 맞춰본다
# 음...유니온 파인드에서 랭크맞춰주면 되는거 아닌가
# 근데 값이 그냥 rank니까 그냥...구현하면 되는거 아님?

# input [v1,v2] : v1<->v2

def find(x, parent):
    if parent[x] < 0:   return x
    parent [x] = find(parent[x], parent)
    return parent[x]

def union(a,b,parent):
    root_a = find(a, parent)
    root_b = find(b, parent)
    
    # 만약에 부모가 같은 경우
    if root_a == root_b:    return False

    #root_b 의 랭크가 더 큰경우 작은쪽에 연결
    if parent[root_a] < parent[root_b]:
        parent[root_a] += parent[root_b]
        parent[root_b] = root_a
    #root_a 의 랭크가 더 큰경우 작은쪽에 연결    
    elif parent[root_a] > parent[root_b]:
        parent[root_b] += parent[root_a]
        parent[root_a] = root_b
    
    else:
        parent[root_b] += parent[root_a]
        parent[root_a] = root_b
    return True

def solution(n, wires):
    answer = 101
    
    for pivot in range(len(wires)): 
        parent = [-1] *(n+1)
    
        #간선 하나씩 지우면서 uf
        # pivot 기준으로 쪼갬
        for a,b in (wires[:pivot] + wires[pivot+1:]):   
            union(a,b,parent)
        # union하고 나서 pivot 기준으로 나눠준 두 트리 크기를 비교
        sub1 = parent[find(wires[pivot][0],parent)]
        sub2 = parent[find(wires[pivot][1],parent)]
        answer = min(answer, abs(sub1-sub2))
    return answer