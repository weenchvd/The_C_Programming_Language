/** Exercise 2.1
 * not finished TODO*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

long long int expon(long long int x, int y); /** x^y */
unsigned long long int exponU(unsigned long long int x, int y); /** x^y */
long double exponF(long double x, int y); /** x^y */
long double exponFMaxPos(long double x, int y, int mantissa); /** x^y */

int main()
{
    printf("========================================================================================\n");
    printf("CHAR, bytes:           %3lu\n", sizeof(char));
    printf("SHORT INT, bytes:      %3lu\n", sizeof(short int));
    printf("INT, bytes:            %3lu\n", sizeof(int));
    printf("LONG INT, bytes:       %3lu\n", sizeof(long int));
    printf("LONG LONG INT, bytes:  %3lu\n", sizeof(long long int));
    printf("----------------------------------------------------------------------------------------\n");
    printf("Ranges from \"limits.h\"\n");
    printf("Range SIGNED CHAR:             from %22d    to %22d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range SIGNED SHORT INT:        from %22d    to %22d\n", SHRT_MIN, SHRT_MAX);
    printf("Range SIGNED INT:              from %22d    to %22d\n", INT_MIN, INT_MAX);
    printf("Range SIGNED LONG INT:         from %22li    to %22li\n", LONG_MIN, LONG_MAX);
    printf("Range SIGNED LONG LONG INT:    from %22lli    to %22lli\n", LLONG_MIN, LLONG_MAX);
    printf("Range UNSIGNED CHAR:           from %22u    to %22u\n", 0, UCHAR_MAX);
    printf("Range UNSIGNED SHORT INT:      from %22u    to %22u\n", 0, USHRT_MAX);
    printf("Range UNSIGNED INT:            from %22u    to %22u\n", 0, UINT_MAX);
    printf("Range UNSIGNED LONG INT:       from %22u    to %22lu\n", 0, ULONG_MAX);
    printf("Range UNSIGNED LONG LONG INT:  from %22u    to %22llu\n", 0, ULLONG_MAX);
    printf("----------------------------------------------------------------------------------------\n");
    printf("Ranges calculated\n");
    printf("Range SIGNED CHAR:             from %22lli    to %22lli\n",
            - expon(2, sizeof(char) * 8) / 2, expon(2, sizeof(char) * 8) / 2 - 1);
    printf("Range SIGNED SHORT INT:        from %22lli    to %22lli\n",
           - expon(2, sizeof(short int) * 8) / 2, expon(2, sizeof(short int) * 8) / 2 - 1);
    printf("Range SIGNED INT:              from %22lli    to %22lli\n",
           - expon(2, sizeof(int) * 8) / 2, expon(2, sizeof(int) * 8) / 2 - 1);
    printf("Range SIGNED LONG INT:         from %22lli    to %22lli\n",
           - (long long int) exponU(2, sizeof(long int) * 8 - 1),
           (long long int) (exponU(2, sizeof(long int) * 8 - 1) - 1));
    printf("Range SIGNED LONG LONG INT:    from %22lli    to %22lli\n",
           - (long long int) exponU(2, sizeof(long long int) * 8 - 1),
           (long long int) (exponU(2, sizeof(long long int) * 8 - 1) - 1));
    /*printf("1_____SIGNED LONG LONG INT:    from -%llu to -%llu\n",
           exponU(2, sizeof(long long int) * 8) / 2, exponU(2, sizeof(long long int) * 8) / 2 - 1);*/
    /*printf("2_____SIGNED LONG LONG INT:    from -%llu to -%llu\n",
           exponU(2, sizeof(long long int) * 8) / 2ULL, exponU(2, sizeof(long long int) * 8) / 2ULL - 1);*/
    printf("Range UNSIGNED CHAR:           from %22u    to %22llu\n", 0, exponU(2, sizeof(char) * 8) - 1);
    printf("Range UNSIGNED SHORT INT:      from %22u    to %22llu\n", 0, exponU(2, sizeof(short int) * 8) - 1);
    printf("Range UNSIGNED INT:            from %22u    to %22llu\n", 0, exponU(2, sizeof(int) * 8) - 1);
    printf("Range UNSIGNED LONG INT:       from %22u    to %22llu\n", 0, exponU(2, sizeof(long int) * 8) - 1);
    printf("Range UNSIGNED LONG LONG INT:  from %22u    to %22llu\n", 0, exponU(2, sizeof(long long int) * 8) - 1);
    printf("========================================================================================\n");
    printf("FLOAT, bytes:          %3lu\n", sizeof(float));
    printf("DOUBLE, bytes:         %3lu\n", sizeof(double));
    printf("LONG DOUBLE, bytes:    %3lu\n", sizeof(long double));
    printf("----------------------------------------------------------------------------------------\n");
    printf("Ranges from \"float.h\"\n");
    printf("Range FLOAT:                   from %22g    to %22g\n", FLT_MIN, FLT_MAX);
    printf("Range DOUBLE:                  from %22g    to %22g\n", DBL_MIN, DBL_MAX);
    printf("Range LONG DOUBLE:             from %22Lg    to %22Lg\n", LDBL_MIN, LDBL_MAX);
    /*printf("Range: from %.44f\n       to   %f\n", FLT_MIN, FLT_MAX);*/
    printf("----------------------------------------------------------------------------------------\n");
    printf("Ranges calculated\n");
    printf("Range FLOAT:                   from %22Lg    to %22Lg\n",
            1.0 / exponF(2.0, 126), exponFMaxPos(2.0, 127, 24));
    printf("Range DOUBLE:                  from %22Lg    to %22Lg\n",
           1.0 / exponF(2.0, 1022), exponFMaxPos(2.0, 1023, 53));
    printf("Range LONG DOUBLE:             from %22Lg    to %22Lg\n",
           1.0 / exponF(2.0, 16382), exponFMaxPos(2.0, 16383, 113));
    /*printf("Range: from %.44f\n       to   %f\n",
            (double) (1.0 / exponF(2.0, 126)), (double) exponFMaxPos(2.0, 127, 24));*/
    printf("========================================================================================\n");
    return 0;
}

long long int expon(long long int x, int y)
{
    if(y == 0) {
        return 1;
    }
    else {
        return x * expon(x, y - 1);
    }
}

unsigned long long int exponU(unsigned long long int x, int y)
{
    if(y == 0) {
        return 1;
    }
    else {
        return x * exponU(x, y - 1);
    }
}

long double exponF(long double x, int y)
{
    if(y == 0) {
        return 1.0L;
    }
    else {
        return x * exponF(x, y - 1);
    }
}

long double exponFMaxPos(long double x, int y, int m)
{
    if(m > 0) {
        return exponF(x, y) + exponFMaxPos(x, y - 1, m - 1);
    }
    else {
        return 0.0L;
    }
}
