#include<stdio.h>
void SwapIntegers(int a,int b);
int main(){
     int a,b;
     printf("Enter two values to swap:\n");
     scanf("%d\n%d",&a,&b);
     SwapIntegers(a,b);
    return 0;
}
//Function to swap integers
void SwapIntegers(int a,int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("Values after swap:\n%d\n%d",a ,b);
}