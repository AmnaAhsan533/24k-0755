#include<stdio.h>
int main()
{
	int x,y,z;
	printf("Enter three numbers\nNumber 1:");scanf("%d",&x);
	printf("\nNumber 2:");scanf("%d",&y);
	printf("\nNumber 3:");scanf("%d",&z);
	
	if(x>y){
		if(x>z){
			printf("%d is greatest",x);
		}
		else{
			printf("%d is greatest",z);
		}
	}
	else if(y>x){
			if(y>z){
				printf("%d is greatest",y);
			}
			else{
				printf("%d is greatest",z);
			}
	   }
	else{
			printf("%d is greatest",z);
	}   
	
	return 0;
}

