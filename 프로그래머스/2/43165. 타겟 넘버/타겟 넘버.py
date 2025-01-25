# Key Idea : 이진트리로 표현이 가능하니 트리로 만들고 BFS나 DFS로 풀자
# 종료조건 : idx == len(num) 즉,숫자 다쓴경우
# DFS 풀이 : 재귀 사용, n번째 ->
# BFS 풀이 : 더하는 경우의 수 / 뺴는 경우의 수 모두 계산해서 큐에 다 넣고 마지막에 target과 동일한지 판단해서 카운트 증가
from collections import deque
import sys
input = sys.stdin.readline()
is_bfs = True

def bfs (num, target):
    q = deque()
    count = 0
    # total, dix
    # 더하는 경우의 수랑 뺴는 경우의 수를 모두 넣는다
    q.append((0,0))
    while(q):
        cur, idx = q.popleft()
        #print(cur,idx)
        # 숫자를 다 쓰고, 목표 값과 같은 경우
        if idx == len(num):
            if cur == target:   count+=1
        else:
            q.append((cur+num[idx],idx+1))
            q.append((cur-num[idx],idx+1))
    return count
        
# def dfs (num, target)


def solution(numbers, target):
    # case 1) BFS
    if is_bfs:
        return(bfs(numbers,target))
    else:
        return answer