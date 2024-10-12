#include<stdio.h>

int main(){
    int array[10], sum=0;
    for(int i=0; i<=9; i++){
    printf("Enter values for array:");
    scanf("%d",&array[i]);
    sum+=array[i];
    }
    printf("Sum = %d",sum);
    return 0;
}

