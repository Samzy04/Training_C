#include <stdio.h>
#include <string.h>

int main() {
    // Declare and initialize a character array 'Str'
    char Str[] = "ANITA MAX WYNN!!";

    // Initialize a counter variable 'count'
    int count = 0;

    // Find the length of the string using 'strlen'
    int length = strlen(Str);

    // Loop through each character in the string
    for (int i = 0; i <= length; i++) {
        // Increment the counter for each character
        count += 1;
    }

    // Print the count of characters in the string
    printf("String count = %d\n", count);

    return 0;
}
