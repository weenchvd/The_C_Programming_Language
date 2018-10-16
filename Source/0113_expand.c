/** Exercise 3.3 */
/** not finished TODO */

#include <stdio.h>

#define MAXLEN1 10004
#define MAXLEN2 MAXLEN1

enum boolean {FALSE, TRUE};

int getstr(char array_string[], int lim);
void expand(char array_string1[], char array_string2[]);


int main()
{
    printf("\033[0;35m"
           "--------------------------------------------------------------------------------\n"
           "|  Function "
           "\033[1;36m"
           "expand(s1, s2)"
           "\033[0;35m"
           "                                                     |\n"
           "|  Use "
           "\033[1;33m"
           "\'New line\'+``+ENTER"
           "\033[0;35m"
           " to complete input or exit                           |\n"
           "|  Use "
           "\033[1;33m"
           "CTRL+C"
           "\033[0;35m"
           " to exit                                                          |\n"
           "--------------------------------------------------------------------------------\n"
           "\033[0;0m");
    int len1, len2;
    short int trig, err;
    char a_s1[MAXLEN1];
    char a_s2[MAXLEN2];
    len1 = 0;
    trig = TRUE;
    while(trig) {
        err = FALSE;
        printf("\n\nEnter the "
               "\033[1;36m"
               "string t"
               "\033[0;0m"
               ":\n");
        if((len2 = getstr(a_s2, MAXLEN2)) <= 0) {
            err = TRUE;
        }
        if(err == FALSE) {
            expand(a_s1, a_s2);
            printf("\n\033[1;32m"
                   "Result:"
                   "\033[0;0m"
                   "\n%s\n", a_s2);
        }
        else if(len1 == -1 || len2 == -1) {
            trig = FALSE;
        }
        else if(len2 == -2) {
            printf("\033[31m"
                   "Text entered is too long. Enter text not longer than %d characters\n"
                   "Line wrap is considered a character\n"
                   "\033[0m", MAXLEN2-4);
            return -1;
        }
        else if(len1 == -100 || len2 == -100) {
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

void expand(char a_s1[], char a_s2[])
{
    int i, j;
    for(i = j = 0; a_s2[i] != '\0'; i++, j++) {
        switch(a_s2[i]) {
            case '\n': a_s1[j++] = '\\'; a_s1[j] = 'n'; break;
            case '\t': a_s1[j++] = '\\'; a_s1[j] = 't'; break;
            default: a_s1[j] = a_s2[i]; break;
        }
    }
    a_s1[j] = '\0';
}
