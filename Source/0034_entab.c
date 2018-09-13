/** Exercise 1.21
 * not finished TODO*/

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
            if(line[i] == ' ' && line[i + 1] == ' ') {
                c++;
            }
            else if(line[i] == ' ' && c > 0) {
                c++;
                int s, t, k;
                if((k = ((i + 1) / LENGTHTAB) * LENGTHTAB - (i - c + 1)) > 0) {
                    t = k / LENGTHTAB + 1;
                    s = (i + 1) - ((i + 1) / LENGTHTAB) * LENGTHTAB;
                    while(t > 0) {
                        printf("\t");
                        t--;
                    }
                }
                else {
                    s = (i + 1) - c;
                }
                while(s > 0) {
                    printf(" ");
                    s--;
                }
                c = 0;
            }
            else {
                printf("%c", line[i]);
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
        else
            s[i] = c;
    }
    if(c =='\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
