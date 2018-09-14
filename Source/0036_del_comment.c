/** Exercise 1.23
 * not finished TODO*/

#include <stdio.h>

#define SIZE 5000

int getallchar(char m_text[], int size);

int main()
{
    printf("Use \'New line\' + \"``\" + \"Enter\" to output the result\n");
    int len;
    char m_text[SIZE];
    len = getallchar(m_text, SIZE);

    return 0;
}

int getallchar(char m_text[], int size)
{
    int i, c;
    for(i = 0; i < size && (c = getchar()) != EOF; i++) {
        if(c == ' ' && m_text[i - 1] == ' ' && m_text[i - 2] == '\n') {
            m_text[i - 1] = '\0';
            return (i - 1);
        }
        else {
            m_text[i] = c;
        }
    }
}
