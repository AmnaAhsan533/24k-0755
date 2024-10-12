#include<stdio.h>
int main(){
    int n, max=0;
    printf("Enter n: ");
    scanf("%d",&n);
    int array[n];
    printf("Enter %d values for array\n",n);
    for(int i=0; i<n; i++){
        scanf("%d",&array[i]);
    }
    for(int i=0; i<n; i++){
        if(max<array[i])
        max=array[i];
    }
    int count[max+1];
    for(int i=0; i<=max; i++){
        count[i]=0;
    }
     for(int i=0; i<n; i++){
        count[array[i]]++;
    }
     for(int i=0; i<=max; i++){
        if(count[i]>1){
            printf("%d occurs %d times\n",i,count[i]);
        }
    }
    return 0;
}