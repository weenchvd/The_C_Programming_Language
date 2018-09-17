/** Exercise 1.24
 * not finished TODO*/

#include <stdio.h>

#define SIZE 10000
#define TRUE 1
#define FALSE 0

int getallchar(char m_text[], int size);

int main()
{
    int len, brace, squarebkt, roundbkt, singlequotes, quotes, esc, comment;
    char m_text[SIZE];
    len = getallchar(m_text, SIZE);
    for(int i = 0; i < len; i++) {

    }
    printf("");
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
