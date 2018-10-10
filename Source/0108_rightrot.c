/** Exercise 2.7 */
/** not finished TODO */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN1 10
#define MAXLEN2 5
#define TRUE 1
#define FALSE 0

int getnumber(char array_number_char[], int lim);
int rightrot(int x, short n);

int main()
{
    int lenx, lenn;
    int err;
    int x;
    short n;
    char a_numx[MAXLEN1];
    char a_numn[MAXLEN2];
    err = FALSE;
    lenn = 1;
    printf("\033[0;35m"
           "--------------------------------------------------------------------\n"
           "|  Function "
           "\033[1;36m"
           "rightrot(x, n)"
           "\033[0;35m"
           "                                         |\n"
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
               "n"
               "\033[0;0m"
               ": ");
        if((lenn = getnumber(a_numn, MAXLEN2)) <= 0) {
            err = TRUE;
        }
    }
    if(err == FALSE) {
        x = atoi(a_numx);
        n = (short) atoi(a_numn);
        printf("\033[1;32m"
               "\nResult"
               "\033[0;0m"
               ": %d\n\n", rightrot(x, n));
    }
    else if(lenx == 0 || lenn == 0) {
        printf("\033[31m"
               "Nothing entered\n"
               "\033[0m");
    }
    else if(lenx == -2 || lenn == -2 ) {
        printf("\033[31m"
               "The number entered is not a decimal number or the number is entered incorrectly\n"
               "\033[0m");
    }
    else if(lenx == -3 || lenn == -3) {
        printf("\033[31m"
               "The number entered is too long\n"
               "\033[0m");
    }
    else if(lenx == -100 || lenn == -100) {
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

int rightrot(int x, short n)
{

}
