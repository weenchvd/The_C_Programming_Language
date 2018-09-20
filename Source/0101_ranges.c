/** Exercise 2.1
 * not finished TODO*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

long long int exponentiation(long long int x, int y); /** x^y */

int main()
{
    printf("----------------------------------------------------------------------------------------\n");
    printf("Ranges from \"limits.h\"\n");
    printf("Range SIGNED CHAR:             from %22d    to %22d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range SIGNED SHORT INT:        from %22d    to %22d\n", SHRT_MIN, SHRT_MAX);
    printf("Range SIGNED INT:              from %22d    to %22d\n", INT_MIN, INT_MAX);
    printf("Range SIGNED LONG INT:         from %22li    to %22li\n", LONG_MIN, LONG_MAX);
    printf("Range SIGNED LONG LONG INT:    from %22lli    to %22lli\n", LLONG_MIN, LLONG_MAX);
    printf("Range UNSIGNED CHAR:           from 0 to %22d\n", UCHAR_MAX);
    printf("Range UNSIGNED SHORT INT:      from 0 to %22d\n", USHRT_MAX);
    printf("Range UNSIGNED INT:            from 0 to %22d\n", UINT_MAX);
    printf("Range UNSIGNED LONG INT:       from 0 to %22li\n", ULONG_MAX);
    printf("Range UNSIGNED LONG LONG INT:  from 0 to %22lli\n", ULLONG_MAX);
    printf("----------------------------------------------------------------------------------------\n");
    printf("Ranges calculated\n");
    printf("Range SIGNED CHAR:             from %22lli    to %22lli\n",
            exponentiation(2, sizeof(char) * 8) / 2 - exponentiation(2, sizeof(char) * 8),
            exponentiation(2, sizeof(char) * 8) - exponentiation(2, sizeof(char) * 8) / 2 - 1);
    printf("Range SIGNED SHORT INT:        from %22lli    to %22lli\n",
           exponentiation(2, sizeof(short int) * 8) / 2 - exponentiation(2, sizeof(short int) * 8),
           exponentiation(2, sizeof(short int) * 8) - exponentiation(2, sizeof(short int) * 8) / 2 - 1);
    printf("Range SIGNED INT:              from %22lli    to %22lli\n",
           exponentiation(2, sizeof(int) * 8) / 2 - exponentiation(2, sizeof(int) * 8),
           exponentiation(2, sizeof(int) * 8) - exponentiation(2, sizeof(int) * 8) / 2 - 1);
    printf("Range SIGNED LONG INT:         from %22lli    to %22lli\n",
           exponentiation(2, sizeof(long int) * 8) / 2 - exponentiation(2, sizeof(long int) * 8),
           exponentiation(2, sizeof(long int) * 8) - exponentiation(2, sizeof(long int) * 8) / 2 - 1);
    printf("Range SIGNED LONG LONG INT:    from %22lli    to %22lli\n",
           exponentiation(2, sizeof(long long int) * 8) / 2 - exponentiation(2, sizeof(long long int) * 8),
           exponentiation(2, sizeof(long long int) * 8) - exponentiation(2, sizeof(long long int) * 8) / 2 - 1);
    printf("Range UNSIGNED CHAR:           from 0 to %22lli\n", exponentiation(2, sizeof(char) * 8) - 1);
    printf("Range UNSIGNED SHORT INT:      from 0 to %22lli\n", exponentiation(2, sizeof(short int) * 8) - 1);
    printf("Range UNSIGNED INT:            from 0 to %22lli\n", exponentiation(2, sizeof(int) * 8) - 1);
    printf("Range UNSIGNED LONG INT:       from 0 to %22lli\n", exponentiation(2, sizeof(long int) * 8) - 1);
    printf("Range UNSIGNED LONG LONG INT:  from 0 to %22lli\n", exponentiation(2, sizeof(long long int) * 8) - 1);
    printf("----------------------------------------------------------------------------------------\n");
    return 0;
}

long long int exponentiation(long long int x, int y)
{
    if (y == 0) {
        return 1;
    }
    else {
        return x * exponentiation(x, y - 1);
    }
}
