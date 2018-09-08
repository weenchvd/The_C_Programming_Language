#include <stdio.h>

#define IN 1 /* within the word */
#define OUT 0 /* outside the word */

/** Counting of lines, words and symbols of the input stream */

int main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF)
    {
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if(state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("Lines: %d\tWords: %d\tChars: %d\n", nl, nw, nc);
}
