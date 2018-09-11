/** Exercise 1.16 */

#include <stdio.h>

#define MAXLINE 1000 /* the maximum size of the input string */

int mygetline(char line[], int lim);
void copy(char to[], char from[]);

/* print the longest line */
int main()
{
    int len; /* length of the current line */
    int max; /* the length of the maximum of the rows scanned */
    char line[MAXLINE]; /* current line */
    char longest[MAXLINE]; /* longest string */
    max = 0;
    printf("\nUse \"New Line + `` + Enter\" to output the result\n");
    while((len = mygetline(line, MAXLINE)) > 0)
    {
        if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n')
        {
            int c;
            int trig = 1;
            while ((c = getchar()) != EOF && trig)
            {
                len++;
                if (c == '\n')
                    trig = 0;
            }
        }
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if(max > 0) /* was there at least one long line */
        printf("%s", longest);
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

/** copy: copies from "from" to "to"; "to" is large enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        i++;
}
