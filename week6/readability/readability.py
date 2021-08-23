sentences = words = letters = 0
words += 1
txt = input("Text: ")
for c in txt:
    if c in '.!?':
        sentences += 1
    elif c == ' ':
        words += 1
    elif c.isalpha():
        letters += 1
L = letters / words * 100
S = sentences / words * 100
grade = round(0.0588 * L - 0.296 * S - 15.8)
if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
