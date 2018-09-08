#include <stdio.h>

/** Exercise 1.10 */

int main()
{
    int c;
    while((c = getchar()) != EOF)
    {
        if(c == '\t')
            printf("\\t");
        if(c == '\b')
            printf("\\b");
        if(c != '\t')
        {
            if(c != '\b')
                putchar(c);
        }
    }
    return 0;
}
