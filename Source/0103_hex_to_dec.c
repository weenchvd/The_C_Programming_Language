/** Exercise 2.3 */

#include <stdio.h>

#define MAXLEN 13
#define TRUE 1
#define FALSE 0

int gethex(char array_hex_char[], int lim);
long long int htol(const char array_hex_char[]);
long long int expon(long long int x, int y);

int main()
{
    int len, trig;
    char a_hex[MAXLEN];
    trig = 1;
    printf("\033[35m"
           "--------------------------------------------------------------------\n"
           "|  This program converts a "
           "\033[1;36m"
           "hexadecimal"
           "\033[35m"
           " number to a "
           "\033[1;32m"
           "decimal"
           "\033[35m"
           " number  |\n"
           "|  Use \'New line\' + \"``\" + \"Enter\" to exit                         |\n"
           "--------------------------------------------------------------------\n"
           "\033[0m");
    while(trig) {
        printf("\033[0m"
               "\nEnter a hexadecimal number:\n"
               "\033[1;36m");
        if((len = gethex(a_hex, MAXLEN)) > 0) {
            printf("\033[1;32m"
                   "%lli\n"
                   "\033[0m", htol(a_hex));
        }
        else if(len == -1) {
            trig = 0;
        }
        else if(len == -2) {
            printf("\033[31m"
                   "Text entered is not a hexadecimal number\n"
                   "\033[0m");
        }
        else if(len == -3) {
            printf("\033[31m"
                   "Text entered is too long. Enter text not longer than %d characters\n"
                   "\033[0m", MAXLEN-1);
        }
        else if(len == -4) {
            printf("\033[31m"
                   "An error has occurred\n"
                   "\033[0m");
        }
    }
    return 0;
}

int gethex(char a_hex[], int lim)
{
    int c, i;
    int isxuppercase, isxlowercase;
    isxuppercase = FALSE;
    isxlowercase = FALSE;
    for(i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; i++) {
        if(i == 0) {
            if(c == '0') {
                a_hex[i] = c;
            }
            else if(c == '`' && (c = getchar()) == '`') {
                return -1;
            }
            else if(c == '\n') {
                return -2;
            }
            else {
                while(getchar() != '\n');
                return -2;
            }
        }
        else if(i == 1) {
            if(c == 'X') {
                isxuppercase = TRUE;
                a_hex[i] = c;
            }
            else if(c == 'x') {
                isxlowercase = TRUE;
                a_hex[i] = c;
            }
            else {
                while(getchar() != '\n');
                return -2;
            }
        }
        else if(isxuppercase == TRUE && ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
            a_hex[i] = c;
        }
        else if(isxlowercase == TRUE && ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'))) {
            if(c >= 'a' && c <= 'f') {
                a_hex[i] = c - 32;
            }
            else a_hex[i] = c;
        }
        else {
            while(getchar() != '\n');
            return -2;
        }
    }

    if(c == '\n' && i > 0) {
        a_hex[i] = '\0';
        return i;
    }
    else if(c == '\n' && i == 0) {
        return 0;
    }
    else if(i == lim) {
        while(getchar() != '\n');
        return -3;
    }
    else return -4;
}

long long int htol(const char a_hex[])
{
    int i, n, x;
    long long int dec;
    for(i = 0; a_hex[i] != '\0'; i++);
    dec = 0;
    x = 0;
    for(n = 0, i--; i > 1; n++, i--) {
        if(a_hex[i] >= '0' && a_hex[i] <= '9') {
            x = a_hex[i] - '0';
        }
        else if(a_hex[i] >= 'A' && a_hex[i] <= 'F') {
            x = a_hex[i] - 'A' + 10;
        }
        dec = dec + expon(16, n) * x;
    }
    return dec;
}

long long int expon(long long int x, int y)
{
    if(y == 0) {
        return 1;
    }
    else {
        return x * expon(x, y-1);
    }
}
