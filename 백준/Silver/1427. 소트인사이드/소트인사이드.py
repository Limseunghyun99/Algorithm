num = input()
numbers = []

for idx in range (len(num)):
    numbers.append(num[idx])

numbers.sort(reverse=True)

for n in range(len(numbers)):
    print(numbers[n], end='')