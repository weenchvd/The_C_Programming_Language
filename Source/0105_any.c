/** Exercise 2.4 */

#include <stdio.h>

#define MAXLEN1 10004
#define MAXLEN2 104
#define TRUE 1
#define FALSE 0

int getstr(char array_string[], int lim);
int any(char array_string1[], char array_string2[]);

int main()
{
    printf("\033[0;35m"
           "-----------------------------------------------------------------------------------------------\n"
           "|  The program returns the position in "
           "\033[1;36m"
           "string s1"
           "\033[0;35m"
           ", where the first character is located,       |\n"
           "|  which coincided with any of the symbols in "
           "\033[1;32m"
           "string s2"
           "\033[0;35m"
           ". Line wrap is considered a character  |\n"
           "|  Use \'New line\' + \"``\" + \"Enter\" to exit the program                                        |\n"
           "|  Use \'New line\' + \"``\" + \"Enter\" to complete input                                          |\n"
           "-----------------------------------------------------------------------------------------------\n"
           "\033[0;0m");
    int len1, len2;
    int p;
    short int trig, err;
    char a_s1[MAXLEN1];
    char a_s2[MAXLEN2];
    trig = TRUE;
    while(trig) {
        err = FALSE;
        printf("\n\nEnter the "
               "\033[1;36m"
               "string s1"
               "\033[0;0m"
               ":\n");
        if((len1 = getstr(a_s1, MAXLEN1)) <= 0) {
            err = TRUE;
        }
        if(err == FALSE) {
            printf("Enter the "
                   "\033[1;32m"
                   "string s2"
                   "\033[0;0m"
                   ":\n");
        }
        if(err == FALSE && (len2 = getstr(a_s2, MAXLEN2)) <= 0) {
            err = TRUE;
        }
        if(err == FALSE) {
            if((p = any(a_s1, a_s2)) > 0) {
                printf("\n\033[1;33m"
                       "Position:"
                       "\033[0;0m"
                       "\n%d\n", p);
            }
            else {
                printf("\n\033[1;33m"
                       "Not a single character from string s2 was found in string s1"
                       "\033[0;0m"
                       "\n");
            }
        }
        else if(len1 == -1 || len2 == -1) {
            trig = FALSE;
        }
        else if(len1 == -2) {
            printf("\033[31m"
                   "Text entered is too long. Enter text not longer than %d characters\n"
                   "Line wrap is considered a character\n"
                   "\033[0m", MAXLEN1-4);
            return -1;
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

int any(char a_s1[], char a_s2[])
{
    int i, n;
    for(i = 0; a_s1[i] != '\0'; i++) {
        for(n = 0; a_s2[n] != '\0'; n++) {
            if(a_s1[i] == a_s2[n]) {
                return i+1;
            }
        }
    }
    return -1;
}
