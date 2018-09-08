#include <stdio.h>

/** copying input to output, ver. 02 */

int main()
{
    int c;
    while((c = getchar()) != EOF)
    {
        putchar(c);
    }
    return 0;
}
