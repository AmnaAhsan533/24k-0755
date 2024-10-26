#include<stdio.h>
int main(){
    int matrix[3][3];
    printf("Enter values for 3*3 matrix\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("[%d][%d]: ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Matrix\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
    int j, min, max, flag=0;
    for(int i=0; i<3; i++){

        min=matrix[i][0];
        int a=0;
        for(j=0; j<3; j++){    
            if(min>matrix[i][j]){
                min=matrix[i][j];
                a=j;
            }
        }
        max=matrix[0][a];
        for(int k=0; k<3; k++){
            if(max<matrix[k][a]){
                max=matrix[k][a];
            }
        }

        if(min==max){
        printf("Saddle point is at index [%d][%d]: %d",i,a,max);
        flag=1;
    }
    }

    if(flag==0){
        printf("No Saddle point");
    }


    return 0;
}