#include<stdio.h>

int main(){
    int array[2][3][3]={
        {{1,2,3},{4,5,6},{7,8,9}},
        {{2,4,6},{1,3,5},{1,4,8}}
    };
    int sum[2]={0};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
               sum[i]+= array[i][j][k];
            }
        }
    }
    for(int i=0; i<2; i++){
        printf("Sum of elements on %d page is: %d\n",i+1,sum[i]);
    }


    return 0;
}