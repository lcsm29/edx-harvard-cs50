height = 0
while(not 1 <= height <= 8):
    height = int(input("Height: "))
for line in [' ' * (height-i) + '#' * i for i in range(1, height + 1)]:
    print(line + '  ' + line[::-1])