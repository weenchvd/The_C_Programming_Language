/** Exercise 2.9 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN1 10
#define TRUE 1
#define FALSE 0

int getnumber(char array_number_char[], int lim);
int bitcount(unsigned x);

int main()
{
    int lenx;
    int err;
    int x;
    char a_numx[MAXLEN1];
    err = FALSE;
    printf("\033[0;35m"
           "--------------------------------------------------------------------\n"
           "|  Function "
           "\033[1;36m"
           "bitcount(x)"
           "\033[0;35m"
           "                                            |\n"
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
        x = atoi(a_numx);
        printf("\033[1;32m"
               "\nResult"
               "\033[0;0m"
               ": %d\n\n", bitcount(x));
    }
    else if(lenx == 0) {
        printf("\033[31m"
               "Nothing entered\n"
               "\033[0m");
    }
    else if(lenx == -2) {
        printf("\033[31m"
               "The number entered is not a decimal number or the number is entered incorrectly\n"
               "\033[0m");
    }
    else if(lenx == -3) {
        printf("\033[31m"
               "The number entered is too long\n"
               "\033[0m");
    }
    else if(lenx == -100) {
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

int bitcount(unsigned x)
{
    int b;
    for(b = 0; x != 0; b++) {
        x &= (x-1);
    }
    return b;
}
