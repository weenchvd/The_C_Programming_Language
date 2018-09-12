#include <stdio.h>

#define MAXLINE 1000 /* the maximum size of the input string */

int max; /* the length of the maximum of the rows scanned */
char line[MAXLINE]; /* current line */
char longest[MAXLINE]; /* longest string */

int mygetline(void);
void copy(void);

/* print the longest line */
int main()
{
    int len; /* length of the current line */
    extern int max;
    extern char longest[];
    max = 0;
    printf("\nUse \"New Line + `` + Enter\" to output the result\n");
    while((len = mygetline()) > 0)
        if(len > max) {
            max = len;
            copy();
        }
    if(max > 0) /* was there at least one long line */
        printf("%s", longest);
    return 0;
}

/** mygetline: specialized version */
int mygetline(void)
{
    int c, i;
    extern char line[];
    for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        if(c == '`' && line[i - 1] == '`') {
                return -1;
        }
        else line[i] = c;
    }
    if(c =='\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

/** copy: specialized version */
void copy(void)
{
    int i;
    extern char line[], longest[];
    i = 0;
    while((longest[i] = line[i]) != '\0')
        i++;
}
