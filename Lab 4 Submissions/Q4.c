#include <stdio.h>

int main()
{
	int cost, dis=0;
	float saved_amount, amount_after_discount;
	printf("Enter the cost of shopping:");
	scanf("%d",&cost);
	printf("Actual amount:%d\n",cost);
	
	if(cost>=500&&cost<2000)
	{
	    dis=cost*0.05;
	    
	}
	else if(cost>=2000&&cost<=4000)
	{
		dis=cost*0.1;
		
	}
	else if(cost>4000&&cost<=6000)
	{
		dis=cost*0.2;
		
	}
	else if(cost>6000)
	{
		dis=cost*0.35;
		
	}
	amount_after_discount=cost-dis;
	printf("Amount after discount is:%.2f",amount_after_discount);
	saved_amount=cost-amount_after_discount;
	printf("\nSaved amount:%.2f",saved_amount);
	
	
	return 0;
}

