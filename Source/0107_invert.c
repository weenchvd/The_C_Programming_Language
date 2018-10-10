/** Exercise 2.7 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN1 10
#define MAXLEN2 5
#define TRUE 1
#define FALSE 0

int getnumber(char array_number_char[], int lim);
int invert(int x, short p, short n);

int main()
{
    int lenx, lenp, lenn;
    int err;
    int x;
    short p, n;
    char a_numx[MAXLEN1];
    char a_nump[MAXLEN2];
    char a_numn[MAXLEN2];
    err = FALSE;
    lenp = 1;
    lenn = 1;
    printf("\033[0;35m"
           "--------------------------------------------------------------------\n"
           "|  Function "
           "\033[1;36m"
           "invert(x, p, n)"
           "\033[0;35m"
           "                                        |\n"
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
        x = atoi(a_numx);
        p = (short) atoi(a_nump);
        n = (short) atoi(a_numn);
        printf("\033[1;32m"
               "\nResult"
               "\033[0;0m"
               ": %d\n\n", invert(x, p, n));
    }
    else if(lenx == 0 || lenp == 0 || lenn == 0) {
        printf("\033[31m"
               "Nothing entered\n"
               "\033[0m");
    }
    else if(lenx == -2 || lenp == -2 || lenn == -2 ) {
        printf("\033[31m"
               "The number entered is not a decimal number or the number is entered incorrectly\n"
               "\033[0m");
    }
    else if(lenx == -3 || lenp == -3 || lenn == -3) {
        printf("\033[31m"
               "The number entered is too long\n"
               "\033[0m");
    }
    else if(lenx == -100 || lenp == -100 || lenn == -100) {
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

int invert(int x, short p, short n)
{
    if(p+1 > n) {
        return (x & ~(~(~0 << n) << (p+1-n))) | (~x & (~(~0 << n) << (p+1-n)));
    }
    else if(p+1 == n) {
        return (x & (~0 << n)) | (~x & ~(~0 << n));
    }
    else if(p+1 < n) {
        return (x & (~0 << (p+1))) | (~x & ~(~0 << (p+1)));
    }
}
