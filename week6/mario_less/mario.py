height = 0
while not (1 <= height <= 8):
    try:
        height = int(input("Height: "))
    except ValueError:
        height = 0
for line in [' ' * (height-i) + '#' * i for i in range(1, height + 1)]:
    print(line)
