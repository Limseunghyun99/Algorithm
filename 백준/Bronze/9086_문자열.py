num = int(input())
words_list = []

for _ in range (num):
    words_list.append(input())

for word in words_list:
    print(word[0]+word[-1])