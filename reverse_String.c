#include <stdio.h>
#include <string.h>

int main (){
    // Declare and initialize a character array
    char Str[]= "qwerty";
    // Find the length of the string
    int length = strlen(Str);
    // Print characters in reverse order
    printf("String in reverse order: ");
    for(int i = length -1;i >=0;i--){
        // Print each character in reverse order
        printf("%c",Str[i]);
    }
    // Print a newline after the reversed string
    printf("\n");
    return 0;
}