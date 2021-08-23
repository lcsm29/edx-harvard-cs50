while True:
    owed = input("Change owed: ")
    try:
        owed = int(float(owed) * 100)
        if owed < 0:
            continue
        else:
            break
    except ValueError:
        pass
num_coins = 0
while owed > 0:
    if owed >= 25:
        owed -= 25
    elif owed >= 10:
        owed -= 10
    elif owed >= 5:
        owed -= 5
    else:
        owed -= 1
    num_coins += 1
print(num_coins)
