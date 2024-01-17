#include <stdio.h>

// Function definition for 'func'
// Takes a character array 'name' and an integer 'age' as parameters
void func(char name[], int age) {
    // Print a greeting with the provided name
    printf("Hello %s\n", name);

    // Print the provided age
    printf("You are %d\n", age);
}

// Main function
int main(void) {
    // Declare and initialize a character array 'name'
    char name[] = "Samzy";

    // Declare and initialize an integer 'age'
    int age = 20;

    // Call the 'func' function with 'name' and 'age' as arguments
    func(name, age);

    // Indicate successful completion
    return 0;
}
