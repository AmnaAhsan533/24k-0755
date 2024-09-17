#include<stdio.h>
int main()
{
	int customer_ID, unit_consumed;
	char customer_name[10];
	float amount,total_amount,surcharge;
	printf("Enter your ID:",customer_ID);
	scanf("%d",&customer_ID);
	
	printf("Enter your name:",customer_name);
	scanf(" %s",&customer_name);
	
	printf("Enter Units consumed:",unit_consumed);
	scanf("%d",&unit_consumed);
	
	if(unit_consumed<=199)
	{
		amount=unit_consumed*16.20;
		printf("Amount charges @Rs.16.20 per unit:%.2f",amount);
	}
	else if(unit_consumed>=200&&unit_consumed<300)
	{
		amount=unit_consumed*20.10;
		printf("Amount charges @Rs.20.10 per unit:%.2f",amount);
	}
	else if(unit_consumed>=300&&unit_consumed<500)
	{
		amount=unit_consumed*27.10;
		printf("Amount charges @Rs.27.10 per unit:%.2f",amount);	
	}
	else if(unit_consumed>=500)
	{
		amount=unit_consumed*35.90;
		printf("Amount charges @Rs.35.90 per unit:%.2f",amount);
	}
	if(amount>18000)
	{
		printf("\nSurcharge Amount:%.2f",surcharge=amount*0.15);
	}
	else
	{
		printf("\nSurcharge Amount:%.2f",surcharge=0);
	}
	total_amount=amount+surcharge;
	printf("\nNet Amount Paid by the Customer:%.2f",total_amount);	
	
	return 0;
}

