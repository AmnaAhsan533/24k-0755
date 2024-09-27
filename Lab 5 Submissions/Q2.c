
#include<stdio.h>
int main()
{
	//a=points for attendance b=points for assignment c=points for exam result
	int attendance,a,b,c;
	int assignmentScore, examResult;
	float totalpoints;
	printf("Enter your attendace: ");
	scanf("%d",&a);
	printf("Enter your assignment score: ");
	scanf("%d",&b);
    printf("Enter your exam result: ");
	scanf("%d",&c);
		   
	totalpoints=(a*0.1)+(b*0.2)+(c*0.7);
	printf("\nTotal points=%.2f\n",totalpoints);
	
	if(totalpoints>=90&&totalpoints<=100){
		if(totalpoints>=95&&totalpoints<=100){
			printf("Grade A+");
		}
		else{
			printf("Grade A-");
		}
	}
	else if(totalpoints>=80&&totalpoints<90){
		if(totalpoints>=85&&totalpoints<90){
			printf("Grade B+");
		}
		else{
			printf("Grade B-");
		}
	}
	else if(totalpoints>=70&&totalpoints<80){
		if(totalpoints>=75&&totalpoints<80){
			printf("Grade C+");
		}
		else{
			printf("Grade C-");
		}
	}
	else if(totalpoints>=60&&totalpoints<70){
		if(totalpoints>=75&&totalpoints<70){
			printf("Grade D+");
		}
		else{
			printf("Grade D-");
		}
	}
	else if(totalpoints>=50&&totalpoints<60){
		if(totalpoints>=65&&totalpoints<60){
			printf("Grade E+");
		}
		else{
			printf("Grade E-");
		}
	}
		if(totalpoints<50){
		   printf("Grade F");
	}	
	return 0;
}
	
