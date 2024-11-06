#include<stdio.h>
#include<string.h>
void CheckPrime(int number);
int main(){
    int number;
    char choice;
    do{
    printf("Enter the number to check whether it is prime or not: ");
    scanf("%d",&number);
    CheckPrime(number);
    printf("\nDo you want to check another number(y/n):");
    scanf(" %c",&choice);
    }while(choice == 'y' || choice == 'Y');
    printf("Exit");

    return 0;
}
void CheckPrime(int number){
    int count=0;
    if(number<=1){
        printf("%d is NOT Prime!",number);
        return;
    }
    for(int i=1; i<=number; i++){
        if(number%i==0){
            count++;
        }
    }
    if(count==2){
        printf("%d is Prime!",number);
    }
    else{
        printf("%d is NOT Prime!",number);
    }
}