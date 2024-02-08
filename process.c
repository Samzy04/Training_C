#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("I am %d the process of %d\n", getpid(), getppid());
    } else {
        printf("I am the father. My son is: %d\n", pid);
    }
    return 0; // Added return statement
}


