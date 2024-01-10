#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char string[20];
    
    printf("Enter a string: ");
    scanf("%19s", string);  
    unsigned long result = strtoul(string, NULL, 10);  
    printf("Converted value: %lu\n", result);  
    return 0;
}
