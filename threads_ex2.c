#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define DATABASESIZE  10

int start = 1;
int end = 10;

pthread_mutex_t mutex;
int database[DATABASESIZE];

void* writers(){
    pthread_mutex_lock(&mutex);
    for(int j=0; j<DATABASESIZE && start <= end; j++){
        database[j] = start;
        start++;
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* readers(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("Numbers in array are:");
    for (int i = 0; i < DATABASESIZE; i++) {
        printf(" %d", database[i]);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char* argv[]){
    pthread_t t1, t2;
    pthread_mutex_init(&mutex, NULL);
    if(pthread_create(&t1, NULL, writers, NULL) != 0){
        return 1;
    }
    if(pthread_create(&t2, NULL, readers, NULL) != 0){
        return 2;
    }
    if(pthread_join(t1, NULL) != 0){
        return 3;
    }
    if(pthread_join(t2, NULL) != 0){
        return 4;
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}
