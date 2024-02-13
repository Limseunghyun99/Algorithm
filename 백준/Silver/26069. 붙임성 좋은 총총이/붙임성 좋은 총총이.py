num_of_input = int(input())
infected = ["ChongChong"]
tmp = []
ans = 0

for _ in range(num_of_input):
    name_A, name_B = input().split()  
    if (name_A in infected) or (name_B in infected):
        infected.append(name_A)
        infected.append(name_B)
tmp = list(set(infected))
print(len(tmp))