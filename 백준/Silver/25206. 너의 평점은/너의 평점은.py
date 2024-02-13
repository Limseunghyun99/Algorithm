num_of_class = 20
grades = {"A+":4.5, "A0":4.0, "B+":3.5, "B0":3.0, "C+":2.5, 
          "C0":2.0, "D+":1.5, "D0":1.0, "F":0.0, "P":False}

total_grade = 0.0
total_credit = 0.0

for _ in range (num_of_class):
    _, credit, grade = input().split()
    # if grade is pass
    if (grade == "P"):
        continue
    else:
        total_grade += float(credit)*grades[grade]
        total_credit += float(credit)
if not total_grade:
    print(0.000000)
else:
    print(round(total_grade/total_credit, 6))
