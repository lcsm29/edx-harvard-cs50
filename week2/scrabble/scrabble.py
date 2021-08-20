def main():
    l = 'A B C D E F G H I J K L M N O P  Q R S T U V W X Y  Z'.split()
    p = '1 3 3 2 1 4 2 4 1 8 5 1 3 1 1 3 10 1 1 1 1 4 4 8 4 10'.split()
    points = {l: int(p) for l, p in zip(l, p)} | {l.lower(): int(p) for l, p in zip(l, p)}
    scores = []
    i = 1
    while i < 3:
        tmp = input(f'Player {i}: ').strip(' -_=+[{]}\|;:",<.>/?!@#$%^&*()1234567890~`')
        try:
            scores.append(sum([points[c] for c in tmp]))
        except KeyError:
            continue
        i += 1
    if scores[0] == scores[1]:
        print('Tie!')
    else:
        print(f'{"Player 1" if scores[0] > scores[1] else "Player 2"} wins!')


main()
