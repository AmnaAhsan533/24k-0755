#include<stdio.h>

int main(){
   int array[10], sum=0;
    for(int i=0; i<=9; i++){
    printf("Enter values for array:");
    scanf("%d",&array[i]);
    }
    int  min=array[0], max=array[0];
    for(int i=0; i<10; i++){
        if(max<array[i])
        max=array[i];
    }
    printf("Maximum = %d",max);

    for(int i=0; i<10; i++){
        if(min>array[i])
        min=array[i];
    }
    printf("\nMinimum = %d",min);

    return 0;
}
