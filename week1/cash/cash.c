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
        if (isdigit(s[i]) == 0 && s[i] != '.')
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    char tmp[200];
    int num_coins = 0;
    float change = 0.0;
    while (change <= 0.0)
    {
        printf("Change owed: ");
        scanf("%s", tmp);
        if (is_number(tmp) == 1)
        {
            change = atof(tmp);
            change *= 10000;
        }
    }
    int dollarized = (int) change / 100;
    while (dollarized > 0)
    {
        if (dollarized >= 25)
        {
            dollarized -= 25;
        }
        else if (dollarized >= 10)
        {
            dollarized -= 10;
        }
        else if (dollarized >= 5)
        {
            dollarized -= 5;
        }
        else if (dollarized >= 1)
        {
            dollarized -= 1;
        }
        num_coins++;
    }
    printf("%d", num_coins);
}
