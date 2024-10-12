#include<stdio.h>

int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int array[n], reversed_array[n];
    printf("Enter n values for array\n");
    for(int i=0; i<n; i++){
    printf("[%d]:",i);
    scanf("%d",&array[i]);
    reversed_array[i] = array[n-1-i];
    }
    for(int i=0; i<n; i++){
         reversed_array[i] = array[n-1-i];
    }

    for(int i=0; i<n; i++){
        printf("%d ",reversed_array[i]);
    }
   
   
   


    return 0;
}