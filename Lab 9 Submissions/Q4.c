#include<stdio.h>
void Calculate(int a, int b, int choice);
int main(){
    int a, b, choice;
    printf("Enter two values to perform operation:\n");
    scanf("%d %d",&a,&b);
    printf("Which function do you want to perform?\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your coice: ");
    scanf("%d",&choice);
    Calculate(a, b, choice);


    return 0;
}
void Calculate(int a, int b, int choice){
    switch(choice){
        case 1: printf("Result = %d",a + b);
        break;
        case 2: printf("Result = %d",a - b);
        break;
        case 3: printf("Result = %d",a * b);
        break;
        case 4: if(b!=0){
            printf("Result = %.2f",(float)a / b);
        } else{
            printf("Error! Division by zero is not allowed.\n");
        }
        break;
        default: printf("Invalid input!");
        break;
    }
}
