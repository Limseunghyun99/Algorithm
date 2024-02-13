num = int(input())
index = 0
result = 666

while True:
    if '666' in str(result):
        index+=1
    if index == num:
        break
    result += 1

print(result)