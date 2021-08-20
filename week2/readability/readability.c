#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // Get text from user
    printf("Text: ");
    char txt[1024];
    scanf("%[^\n]%*c", txt);
    int txtlen = strlen(txt);
    int sentences = 0, words = 1, letters = 0;

    for (int i = 0; i < txtlen; i++)
    {
        if (txt[i] == '.' || txt[i] == '!' || txt[i] == '?')
        {
            sentences++;
        }
        if (txt[i] == ' ')
        {
            words++;
        }
        if (isalpha(txt[i]))
        {
            letters++;
        }
    }

    // Calculate readability
    float L = (float) letters / (float) words * 100.0;
    float S = (float) sentences / (float) words * 100.0;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    if (grade < 1 || grade > 16)
    {
        if (grade < 1)
        {
            printf("Before Grade 1\n");
        }
        if (grade > 16)
        {
            printf("Grade 16+\n");
        }
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}
