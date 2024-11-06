#include<stdio.h>
void Max_and_Min(int *array, int size);

int main(){
int size;
printf("Enter the size of array:");
scanf("%d",&size);
int array[size];
printf("\nEnter %d values for array:",size);
for(int i=0; i<size; i++){
    scanf("%d",&array[i]);
}
Max_and_Min(array,size);
    return 0;
}
void Max_and_Min(int *array, int size){
    int max=0, min=array[0];
    for(int i=0; i<size; i++){
        if(max<array[i]){
            max=array[i];
        }
        if(min>array[i]){
            min=array[i];
        }
}
printf("\nMaximum value in the given array is %d",max);
printf("\nMinimum value in the given array is %d",min);
 
}