#include <stdio.h>

int main() {
    FILE *pF = fopen("file.txt", "w");  // Open file in write mode

    if (pF != NULL) {
        fprintf(pF, " WAG1 G");  // Write " WAG1 G" to the file
        fclose(pF);  // Close the file
        return 0;  // Indicate successful completion
    } else {
        perror("Error opening file");  // Print an error message
        return 1;  // Indicate an error to the operating system
    }
}
