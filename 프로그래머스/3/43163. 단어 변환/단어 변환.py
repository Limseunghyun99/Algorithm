from collections import deque

def bfs(begin, target, words):
    q = deque()
    # 시작 단어, 반복횟수
    q.append([begin,0])
    
    while q:
        cur, cnt = q.popleft()
        if cur == target:    return cnt
    
        for word in words:
            idx = 0
            # 단어에서 철자 하나씩 확인
            for i in range (len(cur)):
                if cur[i] != word[i]:   idx += 1
            # 겹치는 알파벳이 하나라면, 다음 스텝으로 
            if idx == 1:    q.append([word, cnt+1])

def solution(begin, target, words):
    if target not in words: return 0
    return bfs(begin,target,words)