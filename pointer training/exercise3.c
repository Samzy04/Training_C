#include <stdio.h>

int *pointer;
void swap(int **dp1,int **dp2){
    pointer = *dp1;
    *dp1 = *dp2;
    *dp2 = pointer;
}

int main(){
    int dp1 = 5;
    int dp2 = 9;
    int *dp1ptr = &dp1;
    int *dp2ptr = &dp2;
    swap(&dp1ptr,&dp2ptr);
    printf("A = %d\n", *dp1ptr);
    printf("B = %d\n", *dp2ptr);
    return 0;
}