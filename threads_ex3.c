#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 

#define ITEM_SIZE 10
#define MAX_ITEMS 100

pthread_mutex_t mutex;

char items[MAX_ITEMS][ITEM_SIZE];
int num_items = 0; 

void* producer(void* arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        char response;
        printf("Enter an item or press '1' to stop adding: ");
        scanf(" %c", &response);
        if (response == '1') {
            pthread_mutex_unlock(&mutex);
            break;
        }
        if (num_items < MAX_ITEMS) {
            printf("Adding item: ");
            scanf("%s", items[num_items]);
            num_items++;
        } else {
            printf("Item limit reached. Stop adding.\n");
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* consumer(void* arg) {
    while(1) {
        pthread_mutex_lock(&mutex);
        char response;
        printf("Here is the list of items:\n");
        for(int i = 0; i < num_items; i++){
            printf("%s\n", items[i]);
        }
        printf("Want an item or press '1' to stop removing: ");
        scanf(" %c", &response);
        if (response == '1') {
            pthread_mutex_unlock(&mutex);
            break;
        } else {
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
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL);
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
    pthread_mutex_destroy(&mutex);
    return 0;
}
