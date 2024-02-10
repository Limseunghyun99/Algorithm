words = input()
total_sec = 0

times= [3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10]

for word in range(len(words)):
    total_sec += times[ord(words[word])-65]
    
print(total_sec)