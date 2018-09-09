#include <stdio.h>

#define MAX_LENGTH 45 /* The longest dictionary word "Pneumonoultramicroscopicsilicovolcanoconiosis" */

/** Exercise 1.13
 *  Printing a histogram of the lengths of input words */

int main()
{
    printf("\nUse \"`` + Enter\" to output the result\n");
    int c, counter, CurrentLength;
    counter = CurrentLength = 0;
    int LengthWord[MAX_LENGTH];
    for(int i = 0; i < MAX_LENGTH; i++)
        LengthWord[i] = 0;
    while((c = getchar()) != EOF)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            CurrentLength++;
        else if((c == ' ' || c == '\n' || c == '\t') && (CurrentLength > 0 && CurrentLength <= MAX_LENGTH))
        {
            LengthWord[CurrentLength - 1]++;
            CurrentLength = 0;
        }
        else if(c == '`')
        {
            if(counter > 0)
                break;
            counter++;
        }
        else
        {
            CurrentLength = 0;
            counter = 0;
        }
    }
    printf("\n\"-\" is one word of specified length\n");
    for(int i = 0; i < MAX_LENGTH; i++)
    {
        printf("\nLength of word is %2d|", i + 1);
        for(int j = 0; j < LengthWord[i]; j++)
            printf("-");
    }
    printf("\n");
    return 0;
}
