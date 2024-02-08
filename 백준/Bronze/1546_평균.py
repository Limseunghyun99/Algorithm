num = int(input())
scores = list(map(int, input().split()))

max_score = max(scores)
#print(max_score)
average = 0.0

for idx in range (num):
    scores[idx] = (scores[idx]/max_score)*100

print(sum(scores)/num)