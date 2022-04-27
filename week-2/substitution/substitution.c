#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include <stdlib.h>

bool validate_key(string key);
void cipher_input(string input, string key);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!validate_key(argv[1]))
    {
        return 1;
    }

    string input = get_string("plaintext: ");

    cipher_input(input, argv[1]);

    return 0;
}

string toLower(string str, size_t len)
{
    string str_lower = calloc(len + 1, sizeof(char));

    for (int i = 0; i < len; ++i)
    {
        str_lower[i] = tolower(str[i]);
    }
    return str_lower;
}


bool validate_key(string key)
{
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    string lower_key = toLower(key, strlen(key));

    for (int i = 0; i < strlen(lower_key); i++)
    {
        if (!isalpha(lower_key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }

        for (int j = 0; j < strlen(lower_key); j++)
        {
            if (i == j)
            {
                continue;
            }

            if (lower_key[i] == lower_key[j])
            {
                printf("Key must not contain repeated characters.\n");
                return false;
            }
        }
    }

    return true;
}

void cipher_input(string input, string key)
{
    string lower_input = toLower(input, strlen(input));
    string cipher_text = calloc(strlen(input) + 1, sizeof(char));

    for (int i = 0; i < strlen(lower_input); i++)
    {
        if (!isalpha(lower_input[i]))
        {
            cipher_text[i] = lower_input[i];
            continue;
        }

        int index = ((int)lower_input[i]) - 97;

        if (islower(input[i]))
        {
            cipher_text[i] = tolower(key[index]);
        }
        else
        {
            cipher_text[i] = toupper(key[index]);
        }
    }

    printf("ciphertext: %s\n", cipher_text);
}