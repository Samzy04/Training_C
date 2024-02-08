#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h> 

#define ITEM_SIZE 10
#define MAX_ITEMS 100

sem_t empty;  
sem_t full;   

char items[MAX_ITEMS][ITEM_SIZE];
int num_items = 0;

void* producer(void* arg) {
    while(1) {
        char response;
        printf("Enter an item or press '1' to stop adding: ");
        scanf(" %c", &response);
        if (response == '1') {
            break;
        }

        sem_wait(empty);  

        printf("Adding item: ");
        scanf("%s", items[num_items]);
        num_items++;

        sem_post(full);   
    }
    return NULL;
}

void* consumer(void* arg) {
    while(1) {
        char response;
        printf("Here is the list of items:\n");
        for(int i = 0; i < num_items; i++){
            printf("%s\n", items[i]);
        }
        printf("Want an item or press '1' to stop removing: ");
        scanf(" %c", &response);
        if (response == '1') {
            break;
        }

        sem_wait(full);   

        char removeItem[ITEM_SIZE]; 
        printf("Enter the item remove: ");
        scanf("%s", removeItem); 
        int found = 0;
        for(int j = 0; j < num_items; j++) {
            if(strcmp(removeItem, items[j]) == 0) {
                found = 1;
                printf("Removing item: %s\n", items[j]);
                for (int k = j; k < num_items - 1; k++) {
                    strcpy(items[k], items[k + 1]);
                }
                num_items--;
                break;
            }
        }
        if (!found) {
            printf("ITEM NOT FOUND\n");
        }

        sem_post(empty);  
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    if(pthread_create(&t1, NULL, producer, NULL) != 0) {
        return 1;
    }
    if(pthread_create(&t2, NULL, consumer, NULL) != 0) {
        return 2;
    }
    if(pthread_join(t1, NULL) != 0) {
        return 3;
    }
    if(pthread_join(t2, NULL) != 0) {
        return 4;
    }
    
    sem_close(empty);
    sem_close(full);
    
    return 0;
}
