def solution(citations):
    citations.sort()
    for i in range(len(citations), -1, -1):
        if citations[-i] >= i:  return i