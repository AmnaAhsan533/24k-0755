#include<stdio.h>
int main(){
    int r;
    printf("Enter rows for upper half:");
    scanf("%d",&r);

    for(int i=1; i<=r; i++){
        for(int space=r; space>i; space--){
            printf(" ");
        }
        for(int k=1; k<=i; k++){
            printf("* ");
        }
        printf("\n");
    }
    for(int i=r-1; i>=1; i--){
        for(int space=r; space>i; space--){
            printf(" ");
        }
        for(int k=1; k<=i; k++){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}