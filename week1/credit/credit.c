#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_number(char s[])
{
    int i = 0;
    if (s[i] == '-')
    {
        i++;
    }
    for (; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int get_digit(long long n)
{
    int length = 0;
    for (; n >= 1; length++)
    {
        n /= 10;
    }
    return length;
}

int luhn_verification(long long n, int digit)
{
    int doublesum = 0, nondoublesum = 0;
    for (int i = 0; i < digit; i++)
    {
        if (i % 2 == 0)
        {
            nondoublesum += n % 10;
        }
        else
        {
            int tmp = (n % 10) * 2;
            if (tmp >= 10)
            {
                doublesum += tmp % 10 + 1;
            }
            else
            {
                doublesum += n % 10 * 2;
            }
        }
        n /= 10;
    }
    if ((doublesum + nondoublesum) % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    long long card_number = 0;
    int digit = 0, fdigit = 0, sdigit = 0;
    while (digit <= 9)
    {
        printf("Enter a card number: ");
        char tmp[256];
        scanf("%s", tmp);
        if (is_number(tmp))
        {
            card_number = atoll(tmp);
            fdigit = tmp[0] - '0';
            sdigit = tmp[1] - '0';
            digit = get_digit(card_number);
        }
    }
    int verified = luhn_verification(card_number, digit);
    if (verified == 1 && (fdigit == 4 && (digit == 13 || digit == 16)))
    {
        printf("VISA\n");
    }
    else if (verified == 1 && (fdigit == 5 && ((1 <= sdigit) && (sdigit <= 5)) && digit == 16))
    {
        printf("MASTERCARD\n");
    }
    else if (fdigit == 3 && (sdigit == 4 || sdigit == 7) && digit == 15)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
