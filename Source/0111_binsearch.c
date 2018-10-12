/** Exercise 3.1 */
/** not finished TODO */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
#define TRUE 1
#define FALSE 0

int getstr(char array_string[], int lim);
int getnumber(char array_number_char[]);
int binsearch(int x, int array_number[], int n);

int main()
{
    int len;
    int err;
    int coun;
    char a_str[MAXLEN];
    err = FALSE;
    printf("\033[0;35m"
           "--------------------------------------------------------------------------------\n"
           "|  Function "
           "\033[1;36m"
           "binsearch(x, v[], n)"
           "\033[0;35m"
           "                                               |\n"
           "|  Use "
           "\033[1;33m"
           "CTRL+C"
           "\033[0;35m"
           " to exit                                                          |\n"
           "--------------------------------------------------------------------------------\n"
           "\033[0;0m");
    printf("\nEnter the list of numbers separated by spaces and press "
           "\033[1;33m"
           "ENTER"
           "\033[0;0m"
           ":\n");
    if((len = getstr(a_str, MAXLEN)) <= 0) {
        err = TRUE;
    }
    if(err == FALSE) {
        int a_num[len];
    }
    if(err == FALSE) {
        printf("\033[1;32m"
               "\nResult"
               "\033[0;0m"
               ": %d\n\n", bitcount(x));
    }
    else if(len == 0) {
        printf("\033[31m"
               "Nothing entered\n"
               "\033[0m");
        return -1;
    }
    else if(len == -2) {
        printf("\033[31m"
               "The number entered is not a decimal number or the number is entered incorrectly\n"
               "\033[0m");
        return -1;
    }
    else if(len == -3) {
        printf("\033[31m"
               "The list of numbers entered is too long. Enter text not longer than %d characters\n"
               "\033[0m", MAXLEN);
        return -1;
    }
    else if(len == -100) {
        printf("\033[31m"
               "An error has occurred\n"
               "\033[0m");
        return -1;
    }
    return 0;
}

int getstr(char a_str[], int lim)
{
    int c, i, coun;
    for(i = 0, coun = 0; i < lim && (c = getchar()) != EOF && c != '\n'; i++) {
        if(c >= '0' && c <= '9') {
            a_str[i] = c;
        }
        else if(c == ' ' && i > 0) {
            if(a_str[i-1] != ' ') {
                coun++;
                a_str[i] = c;
            }
            else i--;
        }
        else {
            while(getchar() != '\n');
            return -2;
        }
    }
    if(c == '\n' && i > 0) {
        if(a_str[i-1] != ' ') {
            coun++;
            a_str[i] = '\0';
            return coun;
        }
        else {
            a_str[i] = '\0';
            return coun;
        }
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

int getnumber(char a_num[])
{

}

int binsearch(int x, int a_num[], int n)
{

}
