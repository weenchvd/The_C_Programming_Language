/** Exercise 2.4
 * not finished TODO*/

#include <stdio.h>

#define MAXLEN1 10001
#define MAXLEN2 501

int getstr(char array_string[], int lim);
void squeeze(char array_string1[], char array_string2[]);

int main()
{
    printf("\033[35m"
           "---------------------------------------------------------------------------------------------\n"
           "|  This program removes from the string "
           "\033[1;36m"
           "s1"
           "\033[35m"
           " all the characters that appear in the string "
           "\033[1;32m"
           "s2"
           "\033[35m"
           "  |\n"
           "|  Use \'New line\' + \"``\" + \"Enter\" to exit the program                                      |\n"
           "|  Use \'New line\' + \"``\" + \"Enter\" to complete input                                        |\n"
           "---------------------------------------------------------------------------------------------\n\n"
           "\033[0m");
    int len1, len2;
    int trig;
    char a_s1[MAXLEN1];
    char a_s2[MAXLEN2];
    trig = 1;
    while(trig) {
        printf("Enter the string "
               "\033[1;36m"
               "s1"
               "\033[0m"
               ":\n");
        if((len1 = getstr(a_s1, MAXLEN1)) > 0 && (len2 = getstr(a_s2, MAXLEN2)) > 0) {
            squeeze(a_s1, a_s2);
            printf("Result:\n%s\n", a_s1);
        }
        else if(len1 == -1 || len2 == -1) {
            trig = 0;
        }
        else if(len1 == -2) {
            printf("\033[31m"
                   "Text entered is too long. Enter text not longer than %d characters\n"
                   "\033[0m", MAXLEN1-1);
        }
        else if(len2 == -2) {
            printf("\033[31m"
                   "Text entered is too long. Enter text not longer than %d characters\n"
                   "\033[0m", MAXLEN2-1);
        }
        else if(len1 == -100 || len2 == -100) {
            printf("\033[31m"
                   "An error has occurred\n"
                   "\033[0m");
        }
    }

    return 0;
}

int getstr(char a_s[], int lim)
{
    int i, c;
    int coun;
    int lim1;
    lim1 = lim-1+3;
    for(i = coun = 0; i < lim1 && (c = getchar()) != EOF; i++) {
        a_s[i] = c;
        if(a_s[i] == '`') {
            if(coun > 0) {
                break;
            }
            else coun++;
        }
        else coun = 0;
    }
    if(a_s[0] == '`' && a_s[1] == '`') {
        return -1;
    }
    else if(i == lim1) {
        return -2;
    }
    else if(c == EOF) {
        return -100;
    }
    else {
        a_s[i-2] = '\0';
        return i-2;
    }
}

void squeeze(char a_s1[], char a_s2[])
{

}
