#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    // If there are no arguments, print usage and exit
    if (argc < 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // If key does not contain 26 letters, print error and exit
    char key[256];
    strcpy(key, argv[1]);
    int keylen = strlen(key);
    if (keylen != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // If key contains anything other than English alphabets, print error and exit
    for (int i = 0; i < keylen; i++)
    {
        if (!(isupper(key[i])) && !(islower(key[i])))
        {
            printf("Key must contain only English alphabets.\n");
            return 1;
        }
    }

    // If key contains duplicate letters, print error and exit
    for (int i = 0; i < keylen; i++)
    {
        for (int j = i + 1; j < keylen; j++)
        {
            if (key[i] == key[j])
            {
                printf("Key must not contain duplicate letters.\n");
                return 1;
            }
        }
    }

    // Make key uppercase
    char key_upper[26];
    for (int i = 0; i < keylen; i++)
    {
        if (islower(key[i]))
        {
            key_upper[i] = toupper(key[i]);
        }
        else
        {
            key_upper[i] = key[i];
        }
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
        int tmp = plain[i];
        if (isalpha(tmp))
        {
            if (isupper(tmp))
            {
                printf("%c", key_upper[tmp - 65]);
            }
            else if (islower(tmp))
            {
                printf("%c", key_upper[tmp - 97] + 32);
            }
        }
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}
