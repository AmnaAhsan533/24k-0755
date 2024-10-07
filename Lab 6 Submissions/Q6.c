#include <stdio.h>

int main() {
  
   int t1=1, t2=2 ,i, n, nt;
   nt=t1*t2;
    printf("%d, %d, ",t1,t2);
   for(i=3; i<=9; ++i){
       printf("%d, ",nt);
       t1=t2;
       t2=nt;
       nt=t1*t2;
   }
  
    return 0;
}

