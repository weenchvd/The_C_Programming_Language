#include <stdio.h>

/** Exercise 1.8 */

int main()
{
    int c, nl, tab, sp;
    nl = 0;
    tab = 0;
    sp = 0;
    while((c = getchar()) != EOF)
    {
        if(c == '\n')
            ++nl;
        if(c == '\t')
            ++tab;
        if(c == ' ')
            ++sp;
    }
    printf("New line: %d\t Tabs: %d\t Spaces: %d\n", nl, tab, sp);
    return 0;
}
