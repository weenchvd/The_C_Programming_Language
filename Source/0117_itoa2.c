/** Exercise 3.6 */

#include <stdio.h>

#define MAXLENNUM 18
#define MAXLENSTR 101

enum boolean {FALSE, TRUE};

enum boolean itoa(int n, char a_str[], short b);
void reverse(char a_str[]);

int main()
{
    int i;
    int a_num[MAXLENNUM] = {2147483647, 2147483646, 123456789, 9111000, 8000135, 345655, 5345, 15, 2, 0,
                            -2, -15, -5345, -40981, -345098, -11000999, -2147483647, -2147483648};
    short a_len[MAXLENNUM] = {100, 120, 5, 101, 99, 0, 4, 4, 2, 3, 2, 100, 5, 0, 8, 99, 5, 20};
    char a_str[MAXLENSTR];
    printf("\033[0;35m"
           "--------------------------------------------------------------------------------\n"
           "|  Function "
           "\033[1;36m"
           "itoa(n, s[], b)"
           "\033[0;35m"
           "                                                    |\n"
           "--------------------------------------------------------------------------------\n"
           "\033[0;0m");
    printf("Numbers:\n");
    for(i = 0; i < MAXLENNUM; i++) {
        printf("\t(%02d) %d\n", i+1, a_num[i]);
    }
    printf("\033[0;33m"
           "Argument \"b\" must be from 0 to %d inclusive. 0 - field width does not change\n\n"
           "\033[0;0m", MAXLENSTR-1);
    for(i = 0; i < MAXLENNUM; i++) {
        printf("Function "
               "\033[1;36m"
               "itoa(%d, s[], %d)"
               "\033[0;0m"
               ":\n", a_num[i], a_len[i]);
        if(itoa(a_num[i], a_str, a_len[i]) == TRUE) {
            printf("\t(%02d) %s\n", i+1, a_str);
        }
    }
    return 0;
}

enum boolean itoa(int n, char a_str[], short b)
{
    if(b > MAXLENSTR-1) {
        printf("\033[31m"
               "Argument \"b\" must be no more than %d\n"
               "\033[0m", MAXLENSTR-1);
        return FALSE;
    }
    int sign;
    unsigned un;
    short i;
    i = 0;
    if((sign = n) < 0) {
        un = ~n + 1;
        b--;
    }
    else {
        un = n;
    }
    do {
        a_str[i++] = un % 10 + '0';
        b--;
    }
    while((un /= 10) > 0);
    if(b < 0 && (sign < 0 ? i+1+b : i+b) != 0) {
        printf("\033[31m"
               "Argument \"b\" must be greater than or equal to %d\n"
               "\033[0m", sign < 0 ? i+1 : i);
        return FALSE;
    }
    for( ; b > 0; b--) {
        a_str[i++] = '0';
    }
    if(sign < 0) {
        a_str[i++] = '-';
    }
    a_str[i] = '\0';
    reverse(a_str);
    return TRUE;
}

void reverse(char a_str[])
{
    int i, j, len;
    char a_tmp[MAXLENSTR];
    for(len = 0; a_str[len] != '\0'; len++) {
        a_tmp[len] = a_str[len];
    }
    for(i = 0, j = len - 1; j >= 0; j--, i++) {
        a_str[i] = a_tmp[j];
    }
    a_str[len] = '\0';
}
