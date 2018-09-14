/** Exercise 1.22 */

#include <stdio.h>

#define MAXLINE 5000 /* the maximum size of the input string */
#define NPOSITION 20

int mygetline(char line[], int lim);
int newcarriageposition(char line[], int currentcarriageposition);
int printlongword(char line[], int currentcarriageposition);

int main()
{
    int len; /* length of the current line */
    char line[MAXLINE]; /* current line */
    printf("\nUse \"New Line + `` + Enter\" to output the result\n");
    while((len = mygetline(line, MAXLINE)) > 0) {
        int i, j;
        for(i = j = 0; i < len - 1; i = j) {
            j = newcarriageposition(line, i);
            if(j == i) {
                j = printlongword(line, i);
            }
            else {
                for(int k = i; k < j; k++) {
                    printf("%c", line[k]);
                }
                printf("\n");
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
        else {
            s[i] = c;
        }
    }
    if(c =='\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

int newcarriageposition(char line[], int ccposition)
{
    int j;
    for(j = ccposition + NPOSITION; j > ccposition; j--) {
        if(line[j] == ' ' || line[j] == '\t') {
            return (j + 1);
        }
        else if(line[j] == '\n') {
            return j;
        }
    }
    return j;
}

int printlongword(char line[], int ccposition)
{
    int j;
    for(j = ccposition + NPOSITION - 1; ccposition < j; ccposition++) {
        printf("%c", line[ccposition]);
    }
    printf("-\n");
    return j;
}
