#include <stdio.h>

/** copying input to output, ver. 03 */

int main()
{
    int c;
    while(c = getchar() != EOF)
    {
        printf("%d", c);
    }
    return 0;
}
