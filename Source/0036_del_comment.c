/** Exercise 1.23
 * not finished TODO*/

#include <stdio.h>

#define SIZE 100000
#define TRUE 1
#define FALSE 0

int getallchar(char m_text[], int size);
int getposition(char m_text[], int currentcarriageposition);

int cpos, isquotes, iscomment1, iscommentn;

int main()
{
    printf("Use \'New line\' + \"``\" + \"Enter\" to output the result\n");
    int len;
    cpos = -1;
    isquotes = FALSE;
    iscomment1 = FALSE;
    iscommentn = FALSE;
    char m_text[SIZE];
    len = getallchar(m_text, SIZE);
    for(int i = 0; i < len; i++) {
        if(isquotes == FALSE && m_text[i] == '/' && m_text[i + 1] == '*') {
            iscommentn = TRUE;
            i = getposition(m_text, i);
        }
        else if(isquotes == FALSE && m_text[i] == '/' && m_text[i + 1] == '/') {
            iscomment1 = TRUE;
            i = getposition(m_text, i);
        }
        else if(isquotes == FALSE && m_text[i] == '\"' && m_text[i - 1] != '\\') {
            isquotes = TRUE;
        }
        else if(isquotes == TRUE && m_text[i] == '\"' && m_text[i - 1] != '\\') {
            isquotes = FALSE;
        }
        printf("%c", m_text[i]);
    }
    return 0;
}

int getallchar(char m_text[], int size)
{
    int i, c;
    for(i = 0; i < size && (c = getchar()) != EOF; i++) {
        if(c == '`' && m_text[i - 1] == '`' && m_text[i - 2] == '\n') {
            m_text[i - 1] = '\0';
            return (i - 1);
        }
        else {
            m_text[i] = c;
        }
    }
}

int getposition(char m_text[], int ccpos)
{
    return;
}
