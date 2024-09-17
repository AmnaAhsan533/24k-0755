#include <stdio.h>

int main()
{
   int Number;
   printf("Enter number:");
   scanf("%d",&Number);
   
   int Rem=Number%3;
   if(Rem==0)
   {
   	printf("This number is multiple of 3");

   }
   else
   {
   	printf("This number is not multiple of 3");
   }

    return 0;
}
