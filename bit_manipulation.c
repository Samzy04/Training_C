#include <stdio.h>

int main(void) {
    unsigned short Prot = 0xB7B2;
    //Extracting Type (6 bits)
    unsigned short type_field = Prot & 0xFC00;//mask for Type
    type_field = type_field >> 10;
    //Extracting Priority (3 bits)
    unsigned short priority_field = Prot & 0x0380;//mask for Priority
    priority_field = priority_field >> 7;
    //Extracting ID (7 bits)
    unsigned short ID_field = Prot & 0x007F;//mask for ID

    // Print the values of the fields
    printf("Type: %u\n", type_field);
    printf("Priority: %u\n", priority_field);
    printf("ID: %u\n", ID_field);

    return 0;
}
