#include<stdio.h>
int main(){
    int matrix1[3][3], matrix2[3][3];
    //input for matrix 1
    printf("Enter values for matrix 1\n");
    for(int i=0; i<3; i++){
       for(int j=0; j<3; j++){
        printf("[%d][%d]",i,j);
        scanf("%d",&matrix1[i][j]);
       }        
    }
    printf("Enter values for matrix 2\n");
    //input for matrix 2
    for(int i=0; i<3; i++){
       for(int j=0; j<3; j++){
        printf("[%d][%d]",i,j);
        scanf("%d",&matrix2[i][j]);
       }        
    }
    //Displaying matrix 1
     printf("Matrix 1\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\t",matrix1[i][j]);
        }
        printf("\n");
    }
    //Displaying matrix 2
     printf("Matrix 2\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\t",matrix2[i][j]);
        }
        printf("\n");
    }
    int product[3][3], sum=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                sum+= matrix1[i][k]*matrix2[k][j];
            }
            product[i][j]=sum;
            sum=0;
        }
    }
printf("Product\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d\t",product[i][j]);
        }
        printf("\n");
    }

    return 0;
}