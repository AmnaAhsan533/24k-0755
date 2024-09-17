#include<stdio.h>
int main()
{
   float operand1,operand2;
   printf("Enter operand 1:");
   scanf("%f", &operand1);
   
   char operator;
   printf("\nEnter operator:");
   scanf(" %c",&operator);
   
    printf("\nEnter operand 2:");
    scanf("%f",&operand2);
    float result;
   
   switch(operator)
   {
   	case '+':
   		result=operand1+operand2;
   		printf("\n Result=%.3f",result);
   		break;
   	case '-':
   		result=operand1-operand2;
	   printf("\n Result=%.3f ",result);
	   break;
	case '*':
		result=operand1*operand2;
	   printf("\n Result=%.3f",result);
	   
	   break;
	case '/':
		result=operand1/operand2;
	   printf("\n Result=%.3f",result);
	   break; 
	default:
	   printf("Invalid operator");      	
   }
    return 0;
}
