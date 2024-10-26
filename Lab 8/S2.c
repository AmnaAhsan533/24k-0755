#include<stdio.h>
int main(){
    int matrix[2][2], transpose[2][2], i,j;
    printf("Enter values for 2*2 matrix:\n");
    for (i = 0; i<2; i++) {
        for(j=0; j<2; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
     printf("Matrix\n");
      for (i = 0; i<2; i++) {
        for(j=0; j<2; j++){
            printf("%d",matrix[i][j]);
        }
   printf("\n");
    }
    printf("Transpose\n");
    for (j = 0; j<2; j++) {
        for(i=0; i<2; i++){
            printf("%d",matrix[i][j]);
        }
   printf("\n");
    }
    
/*int a;
    a= matrix[0][1];// temp=a
     matrix[0][1]=matrix[1][0];//a=b
     matrix[1][0]=a;//b=temp
    
    printf("Transpose\n");
    
     for (int i = 0; i<2; i++) {
        for(int j=0; j<2; j++){
            printf("%d",matrix[i][j]);
        }
   printf("\n");
    }*/

    return 0;
}