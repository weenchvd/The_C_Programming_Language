/** Exercise 1.17 */

#include <stdio.h>

#define MAXLINE 1000 /* the maximum size of the input string */
#define PRINTLENGTH 80 /* the minimum length of a line to print */

int mygetline(char line[], int lim);

/* print the longest line */
int main()
{
    int len; /* length of the current line */
    char line[MAXLINE]; /* current line */
    printf("\nUse \"New Line + `` + Enter\" to output the result\n");
    while((len = mygetline(line, MAXLINE)) > 0) {
        if (len > PRINTLENGTH)
            printf("%s", line);
    }
    return 0;
}

/** mygetline: reads a string in s, returns length */
int mygetline(char s[], int lim)
{
    int c, i;
    int counter = 0;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        if(c == '`')
        {
            if(counter > 0)
                return -1;
            counter++;
        }
        else s[i] = c;
    if(c =='\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
