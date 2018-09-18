/** Exercise 1.24
 * not finished TODO*/

#include <stdio.h>

#define SIZE 10000
#define TRUE 1
#define FALSE 0

int getallchar(char m_text[], int size);
void checkbrace(char m_text[], int currentcarriageposition);
void checksquarebracket(char m_text[], int currentcarriageposition);
void checkroundbracket(char m_text[], int currentcarriageposition);
void checksinglequotes(char m_text[], int currentcarriageposition);
void checkquotes(char m_text[], int currentcarriageposition);
void checkescape(char m_text[], int currentcarriageposition);
void checkcommentn(char m_text[], int currentcarriageposition);
int getnewcarriagepositioncomment1(char m_text[], int currentcarriageposition);
int getnewcarriagepositioncommentn(char m_text[], int currentcarriageposition);

int brace, squarebkt, roundbkt, singlequotes, quotes, esc, commentn;
int isbrace, issquarebkt, isroundbkt, issinglequotes, isquotes, isesc, iscomment1, iscommentn;
int errbrace, errsquarebkt, errroundbkt, errsinglequotes, errquotes, erresc, errcommentn;

int main()
{
    printf("Use \'New line\' + \"``\" + \"Enter\" to output the result\n");
    int len;
    brace = 0, squarebkt = 0, roundbkt = 0, singlequotes = 0, quotes = 0, esc = 0, commentn = 0;
    isbrace = FALSE, issquarebkt = FALSE, isroundbkt = FALSE, issinglequotes = FALSE, isquotes = FALSE;
    isesc = FALSE, iscommentn = FALSE;
    errbrace = 0, errsquarebkt = 0, errroundbkt = 0, errsinglequotes = 0, errquotes = 0, erresc = 0, errcommentn = 0;
    char m_text[SIZE];
    len = getallchar(m_text, SIZE);
    for(int i = 0; i < len; i++) {
        if((m_text[i] == '{' || m_text[i] == '}') &&
        issinglequotes == FALSE && isquotes == FALSE && iscommentn == FALSE) {
            checkbrace(m_text, i);
        }
        else if((m_text[i] == '[' || m_text[i] == ']') &&
        issinglequotes == FALSE && isquotes == FALSE && iscommentn == FALSE) {
            checksquarebracket(m_text, i);
        }
        else if() {

        }
        else if(m_text[i] == '/' && m_text[i + 1] == '*') {
            if((i = getnewcarriagepositioncommentn(m_text, (i + 2)) == -1) {
                errcommentn++;
                break;
            }
        }
        else if(m_text[i] == '/' && m_text[i + 1] == '/') {
            i = getnewcarriagepositioncomment1(m_text, (i + 2));
        }
    }


    if(brace > 0) {
        errbrace = errbrace + brace;
        brace = 0;
    }


    if(errbrace > 0) {
        printf("");
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

void checkbrace(char m_text[], int i)
{
    if(m_text[i] == '{') {
        brace++;
    }
    else if(m_text[i] == '}' && brace > 0) {
        brace--;
    }
    else if(m_text[i] == '}' && brace == 0) {
        errbrace++;
    }
}

void checksquarebracket(char m_text[], int i)
{
    if(m_text[i] == '[') {
        issquarebkt = TRUE;
    }
    else if(m_text[i] == ']' && issquarebkt == TRUE) {
        issquarebkt = FALSE;
    }
    else if(m_text[i] == ']' && issquarebkt == FALSE) {
        errsquarebkt++;
    }
}

void checkroundbracket(char m_text[], int i)
{

}

void checksinglequotes(char m_text[], int i)
{

}

void checkquotes(char m_text[], int i)
{

}

void checkescape(char m_text[], int i)
{

}

void checkcommentn(char m_text[], int i)
{

}

int getnewcarriagepositioncomment1(char m_text[], int i)
{

}

int getnewcarriagepositioncommentn(char m_text[], int i)
{

}
