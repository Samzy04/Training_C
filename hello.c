#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    //items in the store
    float apple = 5.89;
    float pinapple = 3.56;
    float orange = 2.09;
    float banana = 1.99;
    float peach = 1.99;
    float mango = 1.99;
    char chosen_item[10];
    char budget_str[20];  
    float budget;

    printf("apple: £%5.2f\n", apple);
    printf("pinapple: £%5.2f\n", pinapple);
    printf("orange: £%5.2f\n", orange);
    printf("banana: £%5.2f\n", banana);
    printf("peach: £%5.2f\n", peach);
    printf("mango: £%5.2f\n", mango);

    printf("Choose an item: ");
    //ensures that no more characters than the size of the array are read.
    fgets(chosen_item, sizeof(chosen_item), stdin);

    //remove new line character
    chosen_item[strcspn(chosen_item, "\n")] = '\0';

    printf("Enter your budget: ");
    fgets(budget_str, sizeof(budget_str), stdin);

    //convert string to a float
    budget = strtof(budget_str, NULL);
    //compare chosens string with the fruits and calculating remaining budget
    if (strcmp(chosen_item, "apple") == 0) {
        printf("You have selected apple. Remaining budget: £%5.2f\n", budget - apple);
    } else if (strcmp(chosen_item, "pinapple") == 0) {
        printf("You have selected pinapple. Remaining budget: £%5.2f\n", budget - pinapple);
    } else if (strcmp(chosen_item, "orange") == 0) {
        printf("You have selected orange. Remaining budget: £%5.2f\n", budget - orange);
    } else if (strcmp(chosen_item, "banana") == 0) {
        printf("You have selected banana. Remaining budget: £%5.2f\n", budget - banana);
    } else if (strcmp(chosen_item, "peach") == 0) {
        printf("You have selected peach. Remaining budget: £%5.2f\n", budget - peach);
    } else if (strcmp(chosen_item, "mango") == 0) {
        printf("You have selected mango. Remaining budget: £%5.2f\n", budget - mango);
    } else {
        printf("Invalid selection.\n");
    }

    return 0;
}
