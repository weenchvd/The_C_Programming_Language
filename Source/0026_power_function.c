#include <stdio.h>

/** Power function test */

int power(int m, int n);

int main()
{
    for (int i = 0; i < 10; i++)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}

/** base^n, n>=0, ver. 02 */
int power(int base, int n)
{
    int p;
    for(p = 1; n > 0; --n)
        p = p * base;
    return p;
}
