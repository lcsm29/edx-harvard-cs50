def luhn(n, sum_digit=0):
    for i in ''.join([str(int(i) * 2) for i in str(n)[::-1][1::2]]):
        sum_digit += int(i)
    sum_digit += sum([int(i) for i in str(n)[::-1][::2]])
    return sum_digit % 10 == 0


number = 0
cards = 'VISA MASTERCARD AMEX INVALID'.split()
while len(str(number)) <= 9:
    try:
        number = int(input('Number: '))
    except ValueError:
        pass
snum = str(number)
if luhn(number) and len(snum) in (13, 15, 16):
    if len(str(number)) in (13, 16) and snum[0] == '4':
        print('VISA')
    elif len(str(number)) == 16 and snum[:2] in ('51', '52', '53', '54', '55'):
        print('MASTERCARD')
    elif len(str(number)) == 15 and snum[:2] in ('34', '37'):
        print('AMEX')
    else:
        print('INVALID')
else:
    print('INVALID')
