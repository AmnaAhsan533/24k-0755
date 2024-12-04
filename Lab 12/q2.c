#include<stdio.h>
#include<stdlib.h>

void MatrixMul(int **mat1, int **mat2, int m, int n);
int main(){
    int m, n;
    printf("Enter the size of matrix\nRows: ");
    scanf("%d",&m);
    printf("Columns: ");
    scanf("%d",&n);
    int **mat1 = (int**)malloc(m * sizeof(int*));

    for(int i=0; i<n; i++){
        mat1[i] = (int*)malloc(n * sizeof(int));
    }
    int **mat2 = (int**)malloc(n * sizeof(int*));
    for(int i=0; i<n; i++){
        mat2[i] = (int*)malloc(n * sizeof(int));
    }
    printf("Enter elements of matrix 1\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("Enter elements of matrix 2\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&mat2[i][j]);
        }
    }

    MatrixMul(mat1,mat2, m, n);

    for(int i=0; i<m; i++){
        free(mat1[i]);
    }
    free(mat1);

    for(int i=0; i<m; i++){
        free(mat2[i]);
    }
    free(mat2);
    return 0;
}
void MatrixMul(int **mat1, int **mat2,int m, int n){
    int **result = (int**)malloc(m * sizeof(int*));
    for(int i=0; i<n; i++){
        result[i] = (int*)malloc(n * sizeof(int));
    }
     int sum = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                sum += mat1[i][k] * mat2[k][j];
           } 
            result[i][j] = sum;
            sum = 0;
        }
    }
    printf("Result\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<m; i++){
        free(result[i]);
    }
    free(result);
}