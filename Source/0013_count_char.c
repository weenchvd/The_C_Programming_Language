#include <stdio.h>

/** Count input characters, ver. 01 */

int main()
{
    long nc;
    nc = 0;
    while(getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
    return 0;
}
