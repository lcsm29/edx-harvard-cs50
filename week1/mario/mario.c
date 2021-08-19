#include <stdio.h>

int main(void) {
    int height = 0;
    while (height <= 0 | height > 8)
    {
        printf("Enter the desired height (1-8): ");
        scanf("%d", &height);
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
