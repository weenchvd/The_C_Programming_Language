/** Exercise 2.3
 * not finished TODO*/

#include <stdio.h>

#define MAXLEN 10
#define TRUE 1
#define FALSE 0

int gethex(char a_hex[], int lim);
int htol(char a_hex[]);

int main()
{
    int len, trig;
    char a_hex[MAXLEN];
    trig = 1;
    printf("This program converts a HEX number to decimal\n");
    printf("Use \'New line\' + \"``\" + \"Enter\" to exit\n");
    while(trig) {
        printf("Please enter the HEX number:\n");
        if((len = gethex(a_hex, MAXLEN)) > 0) {
            printf("Decimal:\n%d", htol(a_hex));
        }
        else if(len == -1) {
            trig = 0;
        }
        else if(len == -2) {
            printf("Text entered is not a HEX number!\n");
        }
        else if(len == -3) {
            printf("Text entered is too long. Enter text not longer than %d characters\n", MAXLEN-1);
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
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++) {
        if(c == '`') {
            if(getchar() == '`') {
                return -1;
            }
            else return -2;
        }
        if(i == 0) {
            if(c == '0') {
                a_hex[i] = c;
            }
            else return -2;
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
            else return -2;
        }
        else if(i == 8) {
            return -3;
        }
        else if(isxuppercase == TRUE && ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'))) {
            a_hex[i] = c;
        }
        else if(isxlowercase == TRUE && ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f'))) {
            a_hex[i] = c;
        }
        else return -2;
    }
    if(c == '\n' && i > 0) {
        a_hex[i] = '\0';
        return i;
    }
    else if(c == '\n' && i == 0) {
        return 0;
    }
    return -2;
}

int htol(char a_hex[])
{

}
