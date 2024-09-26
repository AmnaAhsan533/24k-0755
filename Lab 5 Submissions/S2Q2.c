#include<stdio.h>
int main()
{
	int age;
	char citizenship;
	printf("Enter your age:");
	scanf("%d",&age);
	printf("Enter the first letter of your citizenship:");
	scanf(" %c",&citizenship);
	
	if(age>=18&&citizenship=='P'||citizenship=='p'){
		printf("Many Congrats, You are eligible to vote");
	}
	else{
		printf("You are NOT eligible to vote");
	}
	return 0;
}
