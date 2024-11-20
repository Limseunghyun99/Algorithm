num = int(input())
meetings = list(range(num))
ans = 0
endPoint = 0

for idx in range(num):
    s,e = map(int,input().split())
    meetings[idx] = (s,e)

# sort with end time -> start time
meetings = sorted(meetings, key=lambda meetings:(meetings[1], meetings[0]))

for newStart, newEnd in meetings:
    if endPoint <= newStart:
        ans += 1
        endPoint = newEnd
print(ans)
