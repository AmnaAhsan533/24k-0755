#include<stdio.h>
int main(){
	int age,a;
	printf("Do you want to know in which stage of life are you laying?\n");
	printf("If YES then press 1 to continue\nIf NO then press 2 to exit\n");
	scanf("%d",&a);

	switch(a){
	    case 1:
	if(age<60){
			printf("\"Welcome to our program\"\n");
	        printf("Enter yuor age:");
     	    scanf(" %d",&age);
		if(age>=13&&age<20){
			printf("You are laying under the category of Teenager");
		}
		else if(age<13){
			printf("You are laying under the category of Child");
		}
		else{
			printf("You are laying under the category of Adult");
		}
	}
	else{
		printf("You are laying under the category of Senior");
	}
	printf("\nBYE!");
	    break;
	    case 2:
	    	printf("End");
	    	break;
   }
		return 0;
}
