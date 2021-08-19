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

int main(void)
{
    int height = 0;
    while (height <= 0 || height > 8)
    {
        printf("Enter the desired height (1-8): ");
        char tmp[256];
        scanf("%s", tmp);
        if (is_number(tmp))
        {
            height = atoi(tmp);
        }
    }
    for (int i = 1; i <= height; i++)
    {
        int num_blanks = height - i;
        for (int j = 0; j < num_blanks; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        putchar('\n');
    }
}
