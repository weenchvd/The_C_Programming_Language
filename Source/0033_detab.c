/** Exercise 1.20 */

#include <stdio.h>

#define MAXLINE 1000 /* the maximum size of the input string */
#define LENGTHTAB 8

int mygetline(char line[], int lim);

int main()
{
    int len; /* length of the current line */
    char line[MAXLINE]; /* current line */
    printf("\nUse \"New Line + `` + Enter\" to output the result\n");
    while((len = mygetline(line, MAXLINE)) > 0) {
        for(int i = 0, c = 0; i < len; i++) {
            if(line[i] == '\t') {
                int n;
                n = LENGTHTAB - (c - (c / LENGTHTAB * LENGTHTAB));
                c = c + n;
                while(n > 0) {
                    printf(" ");
                    n--;
                }
            }
            else {
                printf("%c", line[i]);
                c++;
            }
        }
    }
    return 0;
}

/** mygetline: reads a string in s, returns length */
int mygetline(char s[], int lim)
{
    int c, i;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        if(c == '`' && s[i - 1] == '`') {
            return -1;
        }
        else s[i] = c;
    }
    if(c =='\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
