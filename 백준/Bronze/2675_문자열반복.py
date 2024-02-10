num = int(input())
ans = []

for _ in range (num):
    rpt, word = input().split()
    for idx in range(len(word)):
        for _ in range(int(rpt)):
            ans += word[idx]
    for word in range(len(ans)):
        print(ans[word], end='')
    ans=[]
    print()