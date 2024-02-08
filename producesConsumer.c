#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> 
#include <semaphore.h>

#define BUFFER_SIZE 10

sem_t empty;
sem_t full;
pthread_mutex_t mutex;  
int buffer[BUFFER_SIZE];  
int in = 0;
int out = 0;

void* producer(void* arg){
    int item;
    while(1){
        item = rand() % 100;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;

        printf("Produced item: %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        sleep(rand() % 2);
    }
}

void* consumer(void* arg){
    int read;
    while(1){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        for(int i = 0; i < BUFFER_SIZE; i++){
            read = buffer[out];
            out = (out + 1) % BUFFER_SIZE;
            printf("Got: %d\n", read);
        }
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}

int main(int argc, char* argv[]){
    sem_unlink(empty);
    sem_unlink(full);
    
    pthread_t t1, t2;
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    if(pthread_create(&t1, NULL, consumer, NULL) != 0){
        perror("Failed to create consumer thread");
        return 1;
    }
    if(pthread_create(&t2, NULL, producer, NULL) != 0){
        perror("Failed to create producer thread");
        return 2;
    }
    if(pthread_join(t1, NULL) != 0){
        perror("Failed to join consumer thread");
        return 3;
    }
    if(pthread_join(t2, NULL) != 0){
        perror("Failed to join producer thread");
        return 4;
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
