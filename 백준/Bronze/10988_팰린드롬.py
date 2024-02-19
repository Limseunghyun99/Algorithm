words = input()
flag = 1

for idx in range (int(len(words)//2)):
    if(words[idx]==words[len(words)-idx-1]):
        continue
    else:
        flag = 0
        break
print(flag)