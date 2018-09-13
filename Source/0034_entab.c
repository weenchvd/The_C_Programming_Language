/** Exercise 1.21 */

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
        //int nt = 0, ns = 0;
        for(int i = 0, c = 0; i < len; i++) {
            if(line[i] == ' ' && line[i + 1] == ' ') {
                c++;
            }
            else if(line[i] == ' ' && c > 0) {
                c++;
                int s, t, k;
                if((k = ((i + 1) / LENGTHTAB) * LENGTHTAB) > (i + 1 - c)) {
                    if((i + 1 - c) - ((i + 1 - c) / LENGTHTAB) * LENGTHTAB == 0) {
                        t = (k - (i + 1 - c)) / LENGTHTAB;
                    }
                    else {
                        t = (k - (i + 1 - c)) / LENGTHTAB + 1;
                    }
                    s = (i + 1) - k;
                    //nt = nt + t;
                    while(t > 0) {
                        printf("\t");
                        t--;
                    }
                }
                else {
                    s = c;
                }
                //ns = ns + s;
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
        //printf("\nNumbers of TABS: %4d\nNumbers of SPACES (exclude single spaces): %4d\n", nt, ns);
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
