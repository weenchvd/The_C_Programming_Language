/** Exercise 2.3
 * not finished TODO*/

#include <stdio.h>

#define MAXLEN 10

int gethex(char a_hex[], int lim);
int htol(char a_hex[]);

int main()
{
    int len, trig;
    char a_hex[MAXLEN];
    trig = 1;
    printf("Use \'New line\' + \"``\" + \"Enter\" to exit\n");
    while(trig) {
        printf("Please enter the HEX number:\n");
        if((len = gethex(a_hex, MAXLEN)) > 0) {

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
}

int gethex(char a_hex[], int lim)
{
    int c, i;
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++) {
        if(c == '`' && a_hex[i-1] == '`') {
            return -1;
        }
        if(i == 8) {
            return -3;
        }
        else if(c )
        else a_hex[i] = c;
    }
    if(c == '\n' && i > 0) {
        a_hex[i] = '\0';
    }
    else if(c == '\n' && i == 0) {
        return 0;
    }
}

int htol(char a_hex[])
{

}
