// Main create NTHREAD=4 , you give an integer  parameter <arg> the value start from 1 to NTHREADS
// Each thread run the same code and they print
// I’m thread <arg>
// they do 4 iteration
// The thread go to sleep for <arg> seconds
// The father after create the son call the pthread_exit(NULL)

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
void *print(){
    printf("thread");
    pthread_exit(NULL);
}


int main(int argc,char*argv[]){
    pthread_t threads[4];
    int t,rc;
    pthread_mutex_init(&mutex, NULL);
    for (t = 0; t < 4; t++) {
        if (pthread_create(&threads[t], NULL, &print, NULL) != 0) {
            perror("Failed to create thread");
            return 1;
        }
        sleep(2);
        printf("%d has started\n", t);
    }
    for (t = 0; t < 4; t++) {
        if (pthread_join(threads[t], NULL) != 0) {
            return 2;
        }
        printf("Thread %d has finished execution\n", t);
    }
    pthread_mutex_destroy(&mutex);
}
