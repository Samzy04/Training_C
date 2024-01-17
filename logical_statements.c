#include <stdio.h>

int main(void) {
    int A;
    int B;
    int count;

    // Print values of A and B when count is a multiple of 5
    for (count = 0; count <= 20; count++) {
        if (count % 5 == 0) {
            printf("A = %d\n", count);
            printf("B = %d\n", count);
        }
    }

    // Print odd values of A in increments of 3
    for (A = 0; A <= 20; A += 3) {
        if (A % 2 != 0) {
            printf("ODD A = %d\n", A);
        }
    }

    // Print even values of B in increments of 7
    for (B = 0; B <= 20; B += 7) {
        // Note: Changed 'A' to 'B' in the condition
        if (B % 2 == 0) {
            printf("EVEN B = %d\n", B);
        }
    }

    return 0;
}
