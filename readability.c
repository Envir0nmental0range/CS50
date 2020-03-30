#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
string text = get_string("Text: ");
//printf("%s\n", text);
int length = strlen(text);
int letterCount = 0;
int spaceCount = 0;
for (int i = 0 ; i < length ; i++)
{
    if ( isalpha(text[i]) != 0  )
        {
        letterCount++;
        }
}
//printf("%d letter(s)\n", letterCount);
for (int i = 0 ; i < length ; i++)
{
    if (isspace(text[i]) != 0  )
        {
        spaceCount++;
        }
}
int wordCount = spaceCount + 1;
//printf("%d word(s)\n", wordCount);
int sentenceCount = 0;
for (int i = 0 ; i < length ; i++)
{
    if ((text[i]) == '.' || (text[i]) == '!' || (text[i]) == '?' )
        {
        sentenceCount++;
        }
}
//printf("%d sentence(s)\n", sentenceCount);

// index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words in the text,
//and S is the average number of sentences per 100 words in the text.
float index, L, S;
L = 100 * (float) letterCount / (float) wordCount;
S = 100 * (float) sentenceCount / (float) wordCount;
index = 0.0588 * L - 0.296 * S - 15.8;

if (index < 1)
        {
        printf("Before Grade 1\n");
        }
if (index >= 16)
        {
        printf("Grade 16+\n");
        }
if (index >= 1 && index < 16)
        {
        index = round(index);
        int integerIndex = index;
        printf("Grade %d\n", integerIndex);
        }
}
