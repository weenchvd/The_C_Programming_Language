/** Exercise 3.1 */
/** not finished TODO */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
#define MAXLENTMP 10
#define TRUE 1
#define FALSE 0

int getstr(char array_string[], int lim);
int getnumber(char array_string[], int array_number[], int quantity);
int binsearch(int x, int array_number[], int n);

int main()
{
    int len, qty;
    int err;
    int x, pos;
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
    printf("\nEnter the list of numbers in ascending order separated by spaces and press "
           "\033[1;33m"
           "ENTER"
           "\033[0;0m"
           ":\n");
    if((len = getstr(a_str, MAXLEN)) <= 0) {
        err = TRUE;
    }
    if(err == FALSE) {
        int a_num[len];
        qty = getnumber(a_str, a_num, len);
        printf("\nEnter "
               "\033[1;36m"
               "x"
               "\033[0;0m"
               ": ");
        if(getstr(a_str, MAXLEN) <= 0) {
            err = TRUE;
        }
        else {
            x = atoi(a_str);
            pos = binsearch(x, a_num, qty);
        }
    }
    if(err == FALSE) {
        if(pos > -1) {
            printf("\033[1;32m"
                   "\nNumber position"
                   "\033[0;0m"
                   ": %d\n\n", pos);
        }
        else {
            printf("\033[1;32m"
                   "\nNumber not found\n"
                   "\033[0;0m");
        }
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

int getnumber(char a_str[], int a_num[], int qty)
{
    int i, j, coun;
    char a_tmp[MAXLENTMP];
    for(i = 0, j = 0; i < qty; i++) {
        for(coun = 0; a_str[j] != ' '; coun++, j++) {
            a_tmp[coun] = a_str[j];
        }
        j++;
        a_tmp[coun] = '\0';
        a_num[i] = atoi(a_tmp);
    }
    return i;
}

int binsearch(int x, int a_num[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while(high - low > 1) {
        mid = (low + high) / 2;
        if(x < a_num[mid]) {
            high = mid-1;
        }
        else {
            low = mid;
        }
    }
    if(a_num[high] == x) {
        return high;
    }
    else if(a_num[low] == x) {
        return low;
    }
    else return -1;
}
