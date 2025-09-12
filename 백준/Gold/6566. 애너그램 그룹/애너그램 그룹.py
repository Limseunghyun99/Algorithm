import collections
 
anagrams = collections.defaultdict(list)
li = []
tmp = []
 
while True:
    try:
        word = input()
        li.append(word)
    except EOFError:
        break
 
for i in li:
    anagrams["".join(sorted(i))].append(i)
 
max_len = -1
for i in anagrams.keys():
    sorted_anagram = sorted(anagrams[i])
    max_len = max(max_len, len(sorted_anagram))
    tmp.append(sorted_anagram)
tmp.sort(key=lambda x: (max_len - len(x), x[0])) #크기별로 나열 & 사전 순으로 나열
for i in range(min(len(tmp), 5)):
    print(f'Group of size {len(tmp[i])}: {" ".join([elem for elem in sorted(list(set(tmp[i])))])} .')