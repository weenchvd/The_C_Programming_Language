/** Exercise 2.6 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN1 10
#define MAXLEN2 5
#define TRUE 1
#define FALSE 0

int getnumber(char array_number_char[], int lim);
int setbits(int x, short p, short n, int y);

int main()
{
    int lenx, leny, lenp, lenn;
    int err;
    int x, y;
    short p, n;
    char a_numx[MAXLEN1];
    char a_numy[MAXLEN1];
    char a_nump[MAXLEN2];
    char a_numn[MAXLEN2];
    err = FALSE;
    leny = 1;
    lenp = 1;
    lenn = 1;
    printf("\033[0;35m"
           "--------------------------------------------------------------------\n"
           "|  Function "
           "\033[1;36m"
           "setbits(x, p, n, y)"
           "\033[0;35m"
           "                                    |\n"
           "|  Use \"Ctrl\" + \"C\" to exit                                        |\n"
           "--------------------------------------------------------------------\n"
           "\033[0;0m");
    printf("\nEnter "
           "\033[1;36m"
           "x"
           "\033[0;0m"
           ": ");
    if((lenx = getnumber(a_numx, MAXLEN1)) <= 0) {
        err = TRUE;
    }
    if(err == FALSE) {
        printf("Enter "
               "\033[1;36m"
               "p"
               "\033[0;0m"
               ": ");
        if((lenp = getnumber(a_nump, MAXLEN2)) <= 0) {
            err = TRUE;
        }
    }
    if(err == FALSE) {
        printf("Enter "
               "\033[1;36m"
               "n"
               "\033[0;0m"
               ": ");
        if((lenn = getnumber(a_numn, MAXLEN2)) <= 0) {
            err = TRUE;
        }
    }
    if(err == FALSE) {
        printf("Enter "
               "\033[1;36m"
               "y"
               "\033[0;0m"
               ": ");
        if((leny = getnumber(a_numy, MAXLEN1)) <= 0) {
            err = TRUE;
        }
    }
    if(err == FALSE) {
        x = atoi(a_numx);
        p = (short) atoi(a_nump);
        n = (short) atoi(a_numn);
        y = atoi(a_numy);
        printf("\033[1;32m"
               "\nResult"
               "\033[0;0m"
               ": %d\n\n", setbits(x, p, n, y));
    }
    else if(lenx == 0 || lenp == 0 || lenn == 0 || leny == 0) {
        printf("\033[31m"
               "Nothing entered\n"
               "\033[0m");
    }
    else if(lenx == -2 || lenp == -2 || lenn == -2 || leny == -2) {
        printf("\033[31m"
               "The number entered is not a decimal number or the number is entered incorrectly\n"
               "\033[0m");
    }
    else if(lenx == -3 || lenp == -3 || lenn == -3 || leny == -3) {
        printf("\033[31m"
               "The number entered is too long\n"
               "\033[0m");
    }
    else if(lenx == -100 || lenp == -100 || lenn == -100 || leny == -100) {
        printf("\033[31m"
               "An error has occurred\n"
               "\033[0m");
    }
    return 0;
}

int getnumber(char a_num[], int lim)
{
    int c, i;
    for(i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; i++) {
        if(c >= '0' && c <= '9') {
            a_num[i] = c;
        }
        else {
            while(getchar() != '\n');
            return -2;
        }
    }
    if(c == '\n' && i > 0) {
        a_num[i] = '\0';
        return i;
    }
    else if(c == '\n' && i == 0) {
        return 0;
    }
    else if(i == lim) {
        while(getchar() != '\n');
        return -3;
    }
    else return -100;
}

int setbits(int x, short p, short n, int y)
{
    if(p+1 > n) {
        return (x & ~(~(~0 << n) << (p+1-n))) | ((y & ~(~0 << n)) << (p+1-n));
    }
    else if(p+1 == n) {
        return (x & (~0 << n)) | (y & ~(~0 << n));
    }
    else if(p+1 < n) {
        /*return (x & (~0 << (p+1))) | (y & ~(~0 << (p+1)));*/ //variant 1
        /*return (x & (~0 << (p+1))) | ((y & ~(~0 << n)) >> (n-(p+1)));*/ //variant 2
        return (x & (~0 << (p+1))) | ((y & ~(~0 << n)) >> (n-(p+1)));
    }
}
