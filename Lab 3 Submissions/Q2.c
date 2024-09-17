#include<stdio.h>

int main() 

{
	int a;
	int b;
	int c;
	printf("Enter 1st value:",a);
	scanf("%d",&a);
	printf("Enter 2nd value:",b);
	scanf("%d",&b);
	c=a;
	a=b;
	b=c;
        printf("1st value:%d\n2nd value:%d",a,b);
	
	return 0;
}