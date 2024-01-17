#include <stdio.h>
#include <string.h>

int main() {
    char Word[] = "apple";
    char Sentence[] = "I bought an apple, enjoyed the sweet taste of the apple, and shared the apple with my friend.";

    int count = 0;
    char *ptr = Sentence;

    // Iterate through the sentence, strstr(ptr, Word) searches for the first occurrence of the word (Word) within the string 
    while ((ptr = strstr(ptr, Word)) != NULL) {
        // If the word is found, increment the count
        count += 1;
        // Move the pointer to the next character
        ptr += strlen(Word);
    }

    printf("The word '%s' appears %d times in the sentence.\n", Word, count);

    return 0;
}
