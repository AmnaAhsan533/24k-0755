#include<stdio.h>

int main()
{

	int Tax_rate,Salary;
	printf("Enter Tax Rate:",Tax_rate);
	scanf("%d",&Tax_rate);
	printf("Enter Salary:",Salary);
	scanf("%d",&Salary);
	int Tax, Net_pay;
	printf("Tax:%d",Tax=Tax_rate/100*Salary);
	printf("Net Pay:%d",Net_pay=Salary-Tax);
	
    return 0;	
}