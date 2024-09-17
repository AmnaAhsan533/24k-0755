#include<stdio.h>
int main()
{
	
	char character;
	printf("Enter character:");
	scanf("%c",&character);
	
	if(character>=65&&character<=90)
	{
		printf("Your character is Capital alphabet");
        }
		
		else if(character>=97&&character<=122)
	{
		printf("Your character is Small alphabet");
	}
		
		else if(character>=32&&character<=47 || character>=58&&character<=64 || character>=91&&character<=96 || character>=123&&character<=126)
	{
		printf("Your character is Special character");
	}
		
		else if(character>=48&&character<=57)
	{
		printf("Your character is digit");
	}
    
	else
	{
	   printf("Invalid input");	
	}	
	
	
    return 0;
}

