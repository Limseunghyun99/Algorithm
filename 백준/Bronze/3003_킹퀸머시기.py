pieces = list(map(int, input().split(' ')))
# king, queen, look, bishop, knight, pawn
standard = [1,1,2,2,2,8]

ans = [0]*6

# print(len(pieces), len(standard))
for idx in range (len(standard)):
    ans[idx] = standard[idx] - pieces[idx]

for i in range(len(ans)):
    print(ans[i], end = ' ')