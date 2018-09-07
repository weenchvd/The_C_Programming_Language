#include <stdio.h>

/** Printing a temperature table for Celsius
 * and Fahrenheit for celsius = -100, -90, ..., 100; variant with FLOAT */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -100; /* lower limit of the temperature table */
    upper = 100; /* upper limit */
    step = 10; /* step */

    celsius = lower;
    printf("\nPrinting a temperature table for Celsius and Fahrenheit\n");
    printf("-------------------------------------------------------\n");
    printf("| Cels |    Fahr|\n");
    printf("|---------------|\n");
    while(celsius <= upper)
    {
        fahr = celsius * 9.0 /5.0 + 32;
        printf("|%5.0f |%8.1f|\n", celsius, fahr);
        celsius = celsius + step;
    }
    printf("-------------------------------------------------------\n");
    return 0;
}
