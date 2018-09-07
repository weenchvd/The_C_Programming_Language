#include <stdio.h>

/** Printing a temperature table for Fahrenheit
 * and Celsius for fahr = 0, 20, ..., 300 */

int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower limit of the temperature table */
    upper = 300; /* upper limit */
    step = 20; /* step */

    fahr = lower;
    while(fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d %6d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}
