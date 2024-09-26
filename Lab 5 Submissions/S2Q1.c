#include<stdio.h>
int main()
{
	int number;
	printf("Enter number that you want to check:");
	scanf("%d",&number);
	
	if(number%3==0&&number%5==0) {
		printf("\"The number you entered is divisible by both 3 and 5\"");
	}
	else{
		printf("\"The number you entered is NOT divisible by both 3 and 5\"");
	}
	
	return 0;
}
