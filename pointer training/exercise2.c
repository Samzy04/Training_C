#include <stdio.h>

int main(){
    int a = 5;
    int b = 8;
    int *p1 = &a;
    int *p2 = &b;
    int pointer = *p1;
    *p1 = *p2;
    *p2 = pointer;
    printf("A = %d\n",*p1);
    printf("A = %d\n",*p2);
}