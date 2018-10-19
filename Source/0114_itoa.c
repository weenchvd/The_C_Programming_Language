/** Exercise 3.4 */
/** not finished TODO */

#include <stdio.h>

#define MAXLENNUM 10
#define MAXLENSTR 15


void itoa(int n, char a_str[]);
void reverse(char a_str[]);

int main()
{
    int i;
    int a_num[MAXLENNUM] = {0, 15, 5345, 345655, 123456789, -2, -3456, -345098, 2147483647, -2147483648};
    char a_str[MAXLENSTR];
    printf("\033[0;35m"
           "--------------------------------------------------------------------------------\n"
           "|  Function "
           "\033[1;36m"
           "itoa(n, s[])"
           "\033[0;35m"
           "                                                       |\n"
           "--------------------------------------------------------------------------------\n"
           "\033[0;0m");
    printf("Numbers:              ");
    for(i = 0; i < MAXLENNUM; i++) {
        printf(" %d", a_num[i]);
    }
    printf("\nFunction "
           "\033[1;36m"
           "itoa(n, s[])"
           "\033[0;0m"
           ":");
    for(i = 0; i < MAXLENNUM; i++) {
        itoa(a_num[i], a_str);
        printf(" %s", a_str);
    }
    printf("\n");
    return 0;
}

void itoa(int n, char a_str[])
{
    int i, sign;
    if((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        a_str[i++] = n % 10 + '0';
    }
    while ((n /= 10) > 0);
    if(sign < 0) {
        a_str[i++] = '-';
    }
    a_str[i] = '\0';
    reverse(a_str);
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
