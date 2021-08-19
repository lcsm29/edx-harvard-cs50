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
    // Prompt for start size
    int start;
    do
    {
        char tmp[200];
        printf("Start size: ");
        scanf("%s", tmp);
        if (is_number(tmp))
        {
            start = atoi(tmp);
        }
    }
    while (start < 9);

    // Prompt for end size
    int end;
    do
    {
        char tmp[200];
        printf("End size: ");
        scanf("%s", tmp);
        if (is_number(tmp))
        {
            end = atoi(tmp);
        }
    }
    while (end < start);

    // Calculate number of years until we reach threshold
    int years = 0;
    for (; start < end; years++)
    {
        int births = start / 3;
        int deaths = start / 4;
        start += births - deaths;
    }

    // Print number of years
    printf("Years: %i", years);
}
