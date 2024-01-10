#include <stdio.h>

int main(void) {
    char unit;
    float temp;
    char conversion;
    float temp_conversion;

    printf("Enter temperature unit (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    scanf(" %c", &unit);

    printf("Enter conversion unit (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    scanf(" %c", &conversion);

    printf("Enter temperature: ");
    scanf("%f", &temp);

    if ((unit == 'C' || unit == 'c') && (conversion == 'F' || conversion == 'f')) {
        // Celsius to Fahrenheit conversion
        temp_conversion = (temp * 9/5) + 32;
        printf("%.2f Celsius is %.2f Fahrenheit\n", temp, temp_conversion);
    } else if ((unit == 'C' || unit == 'c') && (conversion == 'K' || conversion == 'k')) {
        // Celsius to Kelvin conversion
        temp_conversion = temp + 273.15;
        printf("%.2f Celsius is %.2f Kelvin\n", temp, temp_conversion);
    } else if ((unit == 'F' || unit == 'f') && (conversion == 'C' || conversion == 'c')) {
        // Fahrenheit to Celsius conversion
        temp_conversion = (temp - 32) * 5/9;
        printf("%.2f Fahrenheit is %.2f Celsius\n", temp, temp_conversion);
    } else if ((unit == 'F' || unit == 'f') && (conversion == 'K' || conversion == 'k')) {
        // Fahrenheit to Kelvin conversion
        temp_conversion = ((temp - 32) * 5/9) + 273.15;
        printf("%.2f Fahrenheit is %.2f Kelvin\n", temp, temp_conversion);
    } else if ((unit == 'K' || unit == 'k') && (conversion == 'C' || conversion == 'c')) {
        // Kelvin to Celsius conversion
        temp_conversion = temp - 273.15;
        printf("%.2f Kelvin is %.2f Celsius\n", temp, temp_conversion);
    } else if ((unit == 'K' || unit == 'k') && (conversion == 'F' || conversion == 'f')) {
        // Kelvin to Fahrenheit conversion
        temp_conversion = ((temp - 273.15) * 9/5) + 32;
        printf("%.2f Kelvin is %.2f Fahrenheit\n", temp, temp_conversion);
    } else {
        printf("Invalid units selected.\n");
    }

    return 0;
}
