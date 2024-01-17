#include <stdio.h>

void counter(int count){
    printf("count:%d\n",count);
}

int main (void){
    int count = 0;
    for(int i = 0;i<10;i++){
        count+=1;
        counter(count);
    }
}