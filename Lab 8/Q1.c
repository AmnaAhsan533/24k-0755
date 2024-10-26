#include<stdio.h>
int main(){
    int n;
    printf("Enter range: ");
    scanf("%d",&n);
    for(int i=2; i<=n; i++){
        int count=0;
        for(int k=1; k<=n; k++){
            if(i%k==0)
            count++;
        }
        if(count>2){
        continue;
        }
        else{
          printf("%d ",i);
        }
    }
    return 0;
}