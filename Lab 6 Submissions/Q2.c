#include <stdio.h>

int main() {
   int n, sum=0;
   printf("Enter number: ");
   scanf("%d",&n);
   while(n/10!=0){
       sum+=n%10;
       n=n/10;
       
   }
   if(sum==0){
       printf("n is NOT a multiple digit number");
   }
   else{
       printf("n is a multiple digit number");
   }
    return 0;
}
