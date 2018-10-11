/** Exercise 2.10 */
/** not finished TODO */

#include <stdio.h>

#define MAXLEN1 1004
#define TRUE 1
#define FALSE 0

int getstr(char array_string[], int lim);
void lower(char array_string[]);

int main()
{
    printf("\033[0;35m"
           "--------------------------------------------------------------------------------\n"
           "|  Function "
           "\033[1;36m"
           "lower(array_string)"
           "\033[0;35m"
           "                                                |\n"
           "|  Use \'New line\' + \"``\" + \"Enter\" to exit the program                         |\n"
           "|  Use \'New line\' + \"``\" + \"Enter\" to complete input                           |\n"
           "--------------------------------------------------------------------------------\n"
           "\033[0;0m");
    int len1;
    short int trig, err;
    char a_s1[MAXLEN1];
    trig = TRUE;
    while(trig) {
        err = FALSE;
        printf("\n\nEnter the "
               "\033[1;36m"
               "string"
               "\033[0;0m"
               ":\n");
        if((len1 = getstr(a_s1, MAXLEN1)) <= 0) {
            err = TRUE;
        }
        if(err == FALSE) {
            lower(a_s1);
            printf("\033[1;32m"
                   "\nResult"
                   "\033[0;0m"
                   ":\n%s\n", a_s1);
        }
        else if(len1 == -1) {
            trig = FALSE;
        }
        else if(len1 == -2) {
            printf("\033[31m"
                   "Text entered is too long. Enter text not longer than %d characters\n"
                   "Line wrap is considered a character\n"
                   "\033[0m", MAXLEN1-4);
            return -1;
        }
        else if(len1 == -100) {
            printf("\033[31m"
                   "An error has occurred\n"
                   "\033[0m");
            return -1;
        }
    }
    return 0;
}

int getstr(char a_s[], int lim)
{
    int i, c;
    short int trig;
    for(i = 0, trig = TRUE; i < lim && trig == TRUE && (c = getchar()) != EOF; i++) {
        a_s[i] = c;
        if(a_s[i] == '\n' && i > 1 && a_s[i-1] == '`' && a_s[i-2] == '`') {
            trig = FALSE;
            i--;
        }
    }
    if(a_s[0] == '`' && a_s[1] == '`') {
        return -1;
    }
    else if(i == lim) {
        return -2;
    }
    else if(c == EOF) {
        return -100;
    }
    else {
        a_s[i-3] = '\0';
        return i-3;
    }
}

void lower(char a_s[])
{

}
