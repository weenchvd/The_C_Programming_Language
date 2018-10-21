/** Exercise 3.5 */

#include <stdio.h>
#include <limits.h>

#define MAXLENNUM 15
#define MAXLENSTR 35

void itob(int n, char a_str[], short b);
void reverse(char a_str[]);

int main()
{
    int i;
    int a_num[MAXLENNUM] = {2147483647, 2147483646, 123456789, 345655, 5345, 15, 2, 0,
                            -2, -15, -5345, -40981, -345098, -2147483647, -2147483648};
    char a_str[MAXLENSTR];
    printf("\033[0;35m"
           "--------------------------------------------------------------------------------\n"
           "|  Function "
           "\033[1;36m"
           "itob(n, s[], b)"
           "\033[0;35m"
           "                                                    |\n"
           "--------------------------------------------------------------------------------\n"
           "\033[0;0m");
    printf("Numbers:\n");
    for(i = 0; i < MAXLENNUM; i++) {
        printf("\t(%02d) %d\n", i+1, a_num[i]);
    }
    printf("\nFunction "
           "\033[1;36m"
           "itob(n, s[], 2)"
           "\033[0;0m"
           ":\n");
    for(i = 0; i < MAXLENNUM; i++) {
        itob(a_num[i], a_str, 2);
        printf("\t(%02d) %s\n", i+1, a_str);
    }
    printf("\nFunction "
           "\033[1;36m"
           "itob(n, s[], 8)"
           "\033[0;0m"
           ":\n");
    for(i = 0; i < MAXLENNUM; i++) {
        itob(a_num[i], a_str, 8);
        printf("\t(%02d) %s\n", i+1, a_str);
    }
    printf("\nFunction "
           "\033[1;36m"
           "itob(n, s[], 10)"
           "\033[0;0m"
           ":\n");
    for(i = 0; i < MAXLENNUM; i++) {
        itob(a_num[i], a_str, 10);
        printf("\t(%02d) %s\n", i+1, a_str);
    }
    printf("\nFunction "
           "\033[1;36m"
           "itob(n, s[], 16)"
           "\033[0;0m"
           ":\n");
    for(i = 0; i < MAXLENNUM; i++) {
        itob(a_num[i], a_str, 16);
        printf("\t(%02d) %s\n", i+1, a_str);
    }
    return 0;
}

void itob(int n, char a_str[], short b)
{
    int sign;
    unsigned un;
    short i;
    i = 0;
    if((sign = n) < 0) {
        un = ~n + 1;
    }
    else {
        un = n;
    }
    if(b == 2) {
        do {
            a_str[i++] = un % 2 + '0';
        }
        while((un /= 2) > 0);
    }
    else if(b == 8) {
        do {
            a_str[i++] = un % 8 + '0';
        }
        while((un /= 8) > 0);
    }
    else if(b == 10) {
        do {
            a_str[i++] = un % 10 + '0';
        }
        while((un /= 10) > 0);
    }
    else if(b == 16) {
        do {
            a_str[i] = un % 16 + '0';
            if(a_str[i] > '9') {
                a_str[i] += 7;
            }
            i++;
        }
        while((un /= 16) > 0);
    }
    else {
        printf("Only binary, octal, decimal and hexadecimal number systems are supported");
        return;
    }
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
