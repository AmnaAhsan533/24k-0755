#include<stdio.h>

int main()
{

	int Tax_rate,Salary;
	printf("Enter Tax Rate:",Tax_rate);
	scanf("%d",&Tax_rate);
	printf("Enter Salary:",Salary);
	scanf("%d",&Salary);
	float Tax;
	printf("Tax:%.2f\n",Tax=(Tax_rate/100.0)*Salary);
	float Net_pay;
	printf("Net Pay:%.2f",Net_pay=Salary-Tax);
	
	
    return 0;	
}
