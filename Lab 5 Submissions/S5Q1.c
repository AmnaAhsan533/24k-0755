#include<stdio.h>
int main()
{
	int year;
	printf("Enter year: ");
	scanf("%d",&year);
	
	if(year%4==0)
{
	if(year%100!=0||year%400==0)
	{ 
	 printf("The year you entered is leap year");
	}
}
    else
    {
      printf("The year you entered is NOT leap year");
	}
	
	return 0;
}

