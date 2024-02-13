num_of_input = int(input())
chat = []
tmp = []
ans = 0

for _ in range(num_of_input):
    name = input()
    # print("Current Name: " + name)
    # print("CHAT : ", chat)
    # print("tmp : " , chat, "\n\n")
    if(name == "ENTER"):
        chat.append(tmp)
        tmp = []
    else:
        tmp.append(name)
chat.append(tmp)

# print(chat)
for idx in range(len(chat)):
    ans += len(list(set(chat[idx])))
print(ans)

    