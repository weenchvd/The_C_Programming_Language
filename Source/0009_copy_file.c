#include <stdio.h>

/** copying input to output, ver. 01 */

int main()
{
    int c;
    c = getchar();
    while(c != EOF)
    {
        putchar(c);
        c = getchar();
    }
    return 0;
}
