#include <stdio.h>

/** Exercise 1.15
 * Printing a temperature table for Fahrenheit and Celsius */

float FahrToCels(int fahr);

int main()
{
    int fahr;
    printf("\nPrinting a temperature table for Fahrenheit and Celsius\n");
    printf("-------------------------------------------------------\n");
    printf("| Fahr  |  Cels |\n");
    printf("|---------------|\n");
    for(fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("| %6d| %6.1f|\n", fahr, FahrToCels(fahr));
    printf("-------------------------------------------------------\n");
    return 0;
}

float FahrToCels(int fahr)
{
    return (5.0 / 9.0) * (fahr - 32);
}
