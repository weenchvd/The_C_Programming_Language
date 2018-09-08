#include <stdio.h>

#define IN 1 /* within the word */
#define OUT 0 /* outside the word */

/** Exercise 1.12 */

int main()
{
    int c, state;
    state = OUT;
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
        {
            if (state == IN)
                printf("\n");
            state = OUT;
        }
        else if(state == OUT)
        {
            state = IN;
        }
        if(c != ' ' && c != '\n' && c != '\t')
            putchar(c);
    }
}
