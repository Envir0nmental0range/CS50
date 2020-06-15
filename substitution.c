#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int i, j;
    string cipher = argv[1];
    if (argc < 2)
    {
        printf("error: missing command line arguments\n");
        return 1; //error check: no command line argument
    }
    if (argc > 2)
    {
        printf("error: only one command line argument accepted\n");
        return 1; //error check: multiple command line arguments
    }
    int cipherLength = strlen(cipher);
    if (cipherLength != 26)
    {
        printf("error: cipher must be exactly 26 letters\n");
        return 1; //error check: argument not 26 characters
    }
    for (i = 0; cipher[i]; i++)
    {
        if (isalpha(cipher[i]) == 0)
        {
            printf("error: cipher must contain only letters\n");
            return 1; //error check: argument contains non-letters
        }
    }
    char lowerCaseCipher[26]; // check for duplicates: cast all to lowercase
    for (i = 0; cipher[i]; i++)
    {
        lowerCaseCipher[i] = tolower(cipher[i]);
    }
    for (i = 0; i < 26; i++)
    {
        for (j = i + 1; j < 26; j++)
        {
            if (lowerCaseCipher[i] == lowerCaseCipher[j])
            {
                printf("Duplicate found in cipher: %c\n", lowerCaseCipher[i]);
                return 1;
            }
        }
    }
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string plainText = get_string("plaintext: "); // get plaintext, find length
    int length = strlen(plainText);
    int upperCases[length];
    char cipherText[length], lowerCaseCipherText[length], lowerCasePlainText[length];
    for (i = 0; i < length; i++)
    {
        lowerCasePlainText[i] = tolower(plainText[i]);
        if (lowerCasePlainText[i] == plainText[i])
        {
            upperCases[i] = 0; //record position of non-uppercase characters
        }
        else
        {
            upperCases[i] = 1; //record position of uppercase characters
        }
    }
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (ispunct(lowerCasePlainText[i]) != 0 || isspace(lowerCasePlainText[i]) != 0 || isdigit(lowerCasePlainText[i]) != 0)
            {
                lowerCaseCipherText[i] = lowerCasePlainText[i];
            }
            else
            {
                if (lowerCasePlainText[i] == alphabet[j]) //check a-z position
                {
                    lowerCaseCipherText[i] = lowerCaseCipher[j]; // assign to same
                }
            }
        }
    }
    for (i = 0; i < length; i++)
    {
        if (ispunct(lowerCasePlainText[i]) != 0 || isspace(lowerCasePlainText[i]) != 0 || isdigit(lowerCasePlainText[i]) != 0)

        {
            cipherText[i] = lowerCaseCipherText[i]; //assign punctuation
        }
        else
        {
            if (upperCases[i] == 0)
            {
                cipherText[i] = lowerCaseCipherText[i]; //assign to upper if needed
            }
            else
            {
                cipherText[i] = toupper(lowerCaseCipherText[i]);
            }
        }
    }
    printf("ciphertext: ");
    for (i = 0; i < length; i++)
    {
        printf("%c", cipherText[i]); //print output
    }
    printf("\n");
}
