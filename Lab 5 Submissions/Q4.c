#include<stdio.h>
int main()
{
	int creditScore, age;
	double income;
	printf("Enter your age:");
	scanf("%d",&age);
	
	if(age>=18&&age<=70){
		printf("Enter your income:");
     	scanf("%lf",&income);
	    printf("Enter credit score:");
	    scanf("%d",&creditScore);
		
        if(income<=50000&&creditScore>=700){
		    printf("You are eligible for loan of Rs.10,00,000");
		}
		else if(income>50000&&income<=10000000&&creditScore>=800){
		    printf("You are eligible for loan of Rs.700,000");
	    }
		else{
		printf("Sorry! You are NOT eligible for loan");
        }    
			
	}
	else{
		printf("Sorry! You are NOT eligible for loan");
   }
	return 0;
}

