T = int(input())

# 포스트오더를 뒤집는다는 가정하에 위 오른쪽 왼쪽 순
def build(tree):
    x = tree.pop()
    if x == 'nil':  return 'nil'

    right = build(tree)
    left = build(tree)

    # 좌우 대소 관계 맞춰주기, 기준은 바껴도 상관없음
    if left>right : left,right = right, left

    return f'({x},{left},{right})'

for _ in range(T):
    tree_A = list(input().split())
    tree_B = list(input().split())

    #END 쳐내
    tree_A.pop()
    tree_B.pop()

    A = build(tree_A)
    B = build(tree_B)

    if A==B:    print('true')
    else:   print('false')