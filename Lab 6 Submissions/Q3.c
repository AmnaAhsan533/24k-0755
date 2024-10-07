#include <stdio.h>

int main() {
    int n, sum=0, count=0, i, number;
    printf("Enter number: ");
    scanf("%d",&n);
    number=n;
    while(n/10!=0){
       sum+=n%10;
       n=n/10;
       
   }
    if(sum==0){
       printf("It is NOT a multiple digit number\n");
   }
    else{
       printf("It is a multiple digit number\n");
   }
    n=number;
    if(n<=1){
      printf("%d is neither composite nor prime", n);
      return 0;
    }
        for(i=1; i<=n; i++){
            if(n%i==0)
            count++;
        }
        if(count>2){
        printf("%d is Composite number",n);
        }
        else{
          printf("%d is Prime number",n);
        }
   

    return 0;
}
