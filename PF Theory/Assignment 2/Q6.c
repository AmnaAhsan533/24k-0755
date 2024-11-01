#include<stdio.h>
int FirstMove(int n);
int main(){
    int n;
    printf("Enter the number of matchsticks:");
    scanf("%d",&n);
    int result = FirstMove(n);
    if(result==-1){
        printf("It's impossible for A to guarentee a win!\n");
    }
    else{
        printf("A should pick %d matchstick(s) on his first turn to guarentee a win.\n", result);
    }

    return 0;
}
int FirstMove(int n){
    if(n%5==0)
    return -1;
    else
    return n%5;
}