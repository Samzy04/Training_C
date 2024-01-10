#include <stdio.h>
#include <string.h>
//Person struct
struct Person {
    char name[12];
    int age;
};

int main(void) {
    struct Person person1;
    struct Person person2;
    // Using string copy function to initialize 'name' member of 'person1' struct
    strcpy(person1.name, "John");
    person1.age = 21;
    // Using string copy function to initialize 'name' member of 'person12' struct
    strcpy(person2.name, "Tom");
    person2.age = 23;  
    // Output the Name and Age from the struct for person1
    printf("Name: %s\n", person1.name);
    printf("Age: %d\n", person1.age);
    // Output the Name and Age from the struct for person2
    printf("Name: %s\n", person2.name);
    printf("Age: %d\n", person2.age);

    return 0;
}
