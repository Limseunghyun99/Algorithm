attendance = list(range(1,31))
# print(attendance)

for _ in range (28):
    student_id = int(input())
    attendance.remove(student_id)

print(min(attendance))
print(max(attendance))