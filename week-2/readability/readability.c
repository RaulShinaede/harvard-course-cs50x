#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float get_letters(string input);
float get_sentences(string input);

int main(void)
{
    string input = get_string("Text: ");

    float letters = get_letters(input);
    float sentences = get_sentences(input);

    int index = round(0.0588 * letters - 0.296 * sentences - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

int get_words(string input)
{
    int words = 1;

    for (int i = 0; i < strlen(input); i++)
    {
        if (isspace(input[i]))
        {
            words++;
        }
    }

    return words;
}

float get_letters(string input)
{
    int words = get_words(input);
    float letters = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            letters++;
        }
    }

    return letters / words * 100;
}

float get_sentences(string input)
{
    int words = get_words(input);
    float sentences = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '!' ||
            input[i] == '?' ||
            input[i] == '.')
        {
            sentences++;
        }
    }

    return sentences / words * 100;
}