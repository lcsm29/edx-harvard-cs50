#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int is_number(char s[])
{
    int i = 0;
    for (; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    // If there is no argument, or multiple keys were given, or the key was not a number, print usage and exit
    if (argc != 2 || is_number(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // If the key is negative, print usage and exit
    int key = atoi(argv[1]) % 26;
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get plaintext from user
    printf("plaintext: ");
    char plain[1024];
    scanf("%[^\n]%*c", plain);
    int txtlen = strlen(plain);

    // Print ciphertext encrypted using key
    printf("ciphertext: ");
    for (int i = 0; i < txtlen; i++)
    {
        if (isalpha(plain[i]))
        {
            if (isupper(plain[i]))
            {
                printf("%c", ((plain[i] - 'A' + key) % 26) + 'A');
            }
            else
            {
                printf("%c", ((plain[i] - 'a' + key) % 26) + 'a');
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
