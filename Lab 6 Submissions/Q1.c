#include <stdio.h>

int main() {
   int n,sum=0;
   do{printf("Enter number [0 to stop] : ");
   scanf("%d",&n);
   sum+=n;
   printf("Sum = %d\n",sum);
   }
   while(n!=0);  

    return 0;
}
