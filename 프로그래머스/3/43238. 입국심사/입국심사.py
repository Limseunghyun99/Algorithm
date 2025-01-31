def solution(n, times):
    answer = 0
    left, right = 0, max(times)*n
    
    while(left<=right):
        # mid 시간 동안 처리할 수 있는 사람 수
        mid = (left+right)//2
        tmp = sum(mid//x for x in times)
        if tmp >= n:    
            answer = mid
            right = mid -1
        else:   left = mid +1
    
    
    return answer