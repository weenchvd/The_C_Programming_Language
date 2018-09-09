#include <stdio.h>

/** Exercise 1.14
 *  Prints a histogram of frequency of occurrence of input characters */

int main()
{
    printf("\nUse \"`` + Enter\" to output the result\n");
    int c, counter;
    counter = 0;
    int Letter[26];
    int Digit[10];
    for(int i = 0; i < 26; i++)
        Letter[i] = 0;
    for(int i = 0; i < 10; i++)
        Digit[i] = 0;

    while((c = getchar()) != EOF)
        if(c >= 'a' && c <= 'z')
            Letter[c - 'a']++;
        else if(c >= '0' && c <= '9')
            Digit[c - '0']++;
        else if(c == '`')
        {
            if(counter > 0)
                break;
            counter++;
        }

    printf("\n\"-\" is one letter\n");
    for(int i = 0; i < 26; i++)
    {
        printf("\nLetter \"%c\" |", i + 'a');
        for(int j = 0; j < Letter[i]; j++)
            printf("-");
    }
    printf("\n");
    for(int i = 0; i < 10; i++)
    {
        printf("\nDigit \"%c\"  |", i + '0');
        for(int j = 0; j < Digit[i]; j++)
            printf("-");
    }
    printf("\n");
    return 0;
}
