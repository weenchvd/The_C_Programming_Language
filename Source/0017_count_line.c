#include <stdio.h>

/** Exercise 1.9 */

int main()
{
    int c, sp;
    sp = 0;
    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            if(sp == 0)
            {
                putchar(c);
                sp = 1;
            }
        }
        if(c != ' ')
        {
            putchar(c);
            sp = 0;
        }
    }
    return 0;
}
