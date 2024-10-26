#include<stdio.h>
int main(){
    int n;
    printf("Enter range: ");
    scanf("%d",&n);
    int i;
   for( i=1; i<=1; i++){   
    for(int j=n; j>0; j--){
        if(j%2==0){
        continue;
      }
       printf("%d ",j);
    }   
    }
    return 0;
}