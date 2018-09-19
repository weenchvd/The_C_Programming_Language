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
int checksinglequotes_getnewcarriageposition(char m_text[], int currentcarriageposition);
int checkquotes_getnewcarriageposition(char m_text[], int currentcarriageposition);
int checkcomment1_getnewcarriageposition(char m_text[], int currentcarriageposition);
int checkcommentn_getnewcarriageposition(char m_text[], int currentcarriageposition);

int brace, squarebkt, roundbkt;
int errbrace, errsquarebkt, errroundbkt, errsinglequotes, errquotes, errescape, errcomment1, errcommentn;

int main()
{
    printf("Use \'New line\' + \"``\" + \"Enter\" to output the result\n");
    int len;
    brace = 0, squarebkt = FALSE, roundbkt = 0;
    errbrace = 0, errsquarebkt = 0, errroundbkt = 0, errsinglequotes = 0, errquotes = 0, errescape = 0;
    errcomment1 = 0, errcommentn = 0;
    char m_text[SIZE];
    len = getallchar(m_text, SIZE);

    for(int i = 0; i < len; i++) {
        if(m_text[i] == '{' || m_text[i] == '}') {
            checkbrace(m_text, i);
        }
        else if(m_text[i] == '[' || m_text[i] == ']') {
            checksquarebracket(m_text, i);
        }
        else if(m_text[i] == '(' || m_text[i] == ')') {
            checkroundbracket(m_text, i);
        }
        else if(m_text[i] == '\'') {
            if((i = checksinglequotes_getnewcarriageposition(m_text, (i + 1))) == -1) {
                errsinglequotes++;
                break;
            }
        }
        else if(m_text[i] == '\"') {
            if((i = checkquotes_getnewcarriageposition(m_text, (i + 1))) == -1) {
                errquotes++;
                break;
            }
        }
        else if(m_text[i] == '/' && m_text[i + 1] == '*') {
            if((i = checkcommentn_getnewcarriageposition(m_text, (i + 2))) == -1) {
                errcommentn++;
                break;
            }
        }
        else if(m_text[i] == '*' && m_text[i + 1] == '/') {
            errcommentn++;
        }
        else if(m_text[i] == '/' && m_text[i + 1] == '/') {
            if((i = checkcomment1_getnewcarriageposition(m_text, (i + 2))) == -1) {
                errcomment1++;
                break;
            }
        }
    }

    if(brace > 0) {
        errbrace = errbrace + brace;
        brace = 0;
    }
    if(roundbkt > 0) {
        errroundbkt = errroundbkt + roundbkt;
        roundbkt = 0;
    }
    if(squarebkt == TRUE) {
        errsquarebkt++;
        squarebkt = FALSE;
    }

    if(errbrace > 0 || errsquarebkt > 0 || errroundbkt > 0 || errsinglequotes > 0 || errquotes > 0 ||
    errescape > 0 || errcomment1 > 0 || errcommentn > 0) {
        if(errbrace > 0) {
            printf("Inconsistencies in brace: %3d\n", errbrace);
        }
        if(errsquarebkt > 0) {
            printf("Inconsistencies in square brackets: %3d\n", errsquarebkt);
        }
        if(errroundbkt > 0) {
            printf("Inconsistencies in parentheses: %3d\n", errroundbkt);
        }
        if(errsinglequotes > 0) {
            printf("Inconsistencies in single quotes: %3d\n", errsinglequotes);
        }
        if(errquotes > 0) {
            printf("Inconsistencies in quotes: %3d\n", errquotes);
        }
        if(errescape > 0) {
            printf("Inconsistencies in escape sequences: %3d\n", errescape);
        }
        if(errcomment1 > 0) {
            printf("Inconsistencies in single-line comments: %3d\n", errcomment1);
        }
        if(errcommentn > 0) {
            printf("Inconsistencies in multi-line comments: %3d\n", errcommentn);
        }
    }
    else {
        printf("No mismatches found\n");
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
    if(m_text[i] == '[' && squarebkt == TRUE) {
        errsquarebkt++;
    }
    else if(m_text[i] == '[' && squarebkt == FALSE) {
        squarebkt = TRUE;
    }
    else if(m_text[i] == ']' && squarebkt == TRUE) {
        squarebkt = FALSE;
    }
    else if(m_text[i] == ']' && squarebkt == FALSE) {
        errsquarebkt++;
    }
}

void checkroundbracket(char m_text[], int i)
{
    if(m_text[i] == '(') {
        roundbkt++;
    }
    else if(m_text[i] == ')' && roundbkt > 0) {
        roundbkt--;
    }
    else if(m_text[i] == ')' && roundbkt == 0) {
        errroundbkt++;
    }
}

int checksinglequotes_getnewcarriageposition(char m_text[], int i)
{
    if(m_text[i] != '\0') {
        if(m_text[i] == '\\') {
            if(m_text[i + 1] != '\0' && m_text[i + 2] != '\0') {
                if(m_text[i + 1] != 'n' && m_text[i + 1] != 't' && m_text[i + 1] != 'v' && m_text[i + 1] != 'b' &&
                        m_text[i + 1] != 'r' && m_text[i + 1] != 'f' && m_text[i + 1] != 'a' && m_text[i + 1] != '?' &&
                        m_text[i + 1] != '0' && m_text[i + 1] != '\\' && m_text[i + 1] != '\'' && m_text[i + 1] != '\"') {
                    errescape++;
                }
                if(m_text[i + 2] == '\'') {
                    return (i + 2);
                }
                else {
                    errsinglequotes++;
                    return (i + 1);
                }
            }
            else {
                return -1;
            }
        }
        else {
            if(m_text[i + 1] != '\0') {
                if(m_text[i + 1] == '\'') {
                    return (i + 1);
                }
                else {
                    errsinglequotes++;
                    return i;
                }
            }
            else {
                return -1;
            }
        }
    }
    else {
        return -1;
    }
}

int checkquotes_getnewcarriageposition(char m_text[], int i)
{
    while(m_text[i] != '\0') {
        if(m_text[i] == '\"') {
            return i;
        }
        else if(m_text[i] == '\n') {
            errquotes++;
            return i;
        }
        else if(m_text[i] == '\\') {
            i++;
            if(m_text[i] != 'n' && m_text[i] != 't' && m_text[i] != 'v' && m_text[i] != 'b' && m_text[i] != 'r' &&
                    m_text[i] != 'f' && m_text[i] != 'a' && m_text[i] != '?' && m_text[i] != '0' &&
                    m_text[i] != '\\' && m_text[i] != '\'' && m_text[i] != '\"') {
                errescape++;
            }
        }
        i++;
    }
    return -1;
}

int checkcomment1_getnewcarriageposition(char m_text[], int i)
{
    while(m_text[i] != '\0') {
        if(m_text[i] == '\n') {
            return i;
        }
        i++;
    }
    return -1;
}

int checkcommentn_getnewcarriageposition(char m_text[], int i)
{
    while(m_text[i] != '\0') {
        if(m_text[i] == '*' && m_text[i + 1] == '/') {
            return (i + 1);
        }
        else if(m_text[i] == '/' && m_text[i + 1] == '*') {
            errcommentn++;
        }
        i++;
    }
    return -1;
}
