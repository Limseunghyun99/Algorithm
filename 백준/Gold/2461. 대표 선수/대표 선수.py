import sys
import heapq

input = sys.stdin.readline

N, M = map(int, input().split())

classes = []
heap = []
max_value = 0

for class_idx in range(N):
    arr = list(map(int, input().split()))
    arr.sort()
    classes.append(arr)

    heapq.heappush(heap, (arr[0], class_idx, 0))
    max_value = max(max_value, arr[0])

answer = float('inf')

while True:
    min_value, class_idx, student_idx = heapq.heappop(heap)

    answer = min(answer, max_value - min_value)

    next_idx = student_idx + 1

    if next_idx == M:
        break

    next_value = classes[class_idx][next_idx]
    heapq.heappush(heap, (next_value, class_idx, next_idx))

    max_value = max(max_value, next_value)

print(answer)