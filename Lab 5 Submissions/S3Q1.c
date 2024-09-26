
#include<stdio.h>
int main()
{
	int num1, num2;
	printf("\'Enter two numbers\'\nfirst:");
	scanf("%d",&num1);
   	
	printf("\nsecond:");
	scanf("%d",&num2);
	
	(num1>num2)?printf("First Number is maximum"):printf("Second Number is maximum");
	
	
	return 0;
}

