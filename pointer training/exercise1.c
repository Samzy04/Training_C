#include <stdio.h>

void sum_of_numbers(int a,int b,int*result)
{
    *result=a+b;
}

int main(){
    int sum;
    sum_of_numbers(1,6,&sum);
    printf("sum = %d\n",sum);
}