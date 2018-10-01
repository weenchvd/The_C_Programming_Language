/** Exercise 2.2 */

/** This is copy of program from Exercise 1.19 */
#include <stdio.h>

#define MAXLINE 1000 /* the maximum size of the input string */

int mygetline(char line[], int lim);
void reverse(char s[]);

int main()
{
    int len; /* length of the current line */
    char line[MAXLINE]; /* current line */
    printf("\nUse \"New Line + `` + Enter\" to output the result\n");
    while((len = mygetline(line, MAXLINE)) > 0) {
        if(len > 2) {
            reverse(line);
        }
        printf("%s", line);
    }
    return 0;
}

/** mygetline: reads a string in s, returns length */
int mygetline(char s[], int lim)
{
    int c, i, trig;
    /*for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        if(c == '`' && s[i - 1] == '`') {
            return -1;
        }
        else s[i] = c;
    }*/
    i = 0;
    trig = 1;
    while(trig) {
        if(i < lim - 1) {
            if((c = getchar()) != EOF) {
                if(c != '\n') {
                    if(c == '`' && s[i - 1] == '`') {
                        return -1;
                    }
                    else s[i] = c;
                    i++;
                }
                else trig = 0;
            }
            else trig = 0;
        }
        else trig = 0;
    }
    if(c =='\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

/** reverse string */
void reverse(char s[])
{
    char tmp[MAXLINE];
    int length;
    for(length = 0; s[length] != '\n'; length++) {
        tmp[length] = s[length];
    }
    for(int i = 0, j = length - 1; j >= 0; j--, i++) {
        s[i] = tmp[j];
    }
    s[length] = '\n';
    s[length + 1] = '\0';
}
