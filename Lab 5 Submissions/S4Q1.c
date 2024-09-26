#include<stdio.h>
int main()
{
	int x, y;
	printf("\'Enter two numbers\'\nfirst:");
	scanf("%d",&x);
   	
	printf("\nsecond:");
	scanf("%d",&y);
	
	x=x^y;
	y=x^y;
	x=x^y;
	
	printf("Two numbers after swap are:\n%d\n%d",x,y);
	
	
	
	
	return 0;
}
