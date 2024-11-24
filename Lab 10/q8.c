#include<stdio.h>

int linearSearch(int arr[], int size, int target, int index);

int main(){
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter target element to search: ");
    scanf("%d",&target);
    int result = linearSearch(arr, size, target, 0);
    if(result != -1){
        printf("Element %d is found at index %d.",target, result);
    } else {
        printf("Element %d not found in the array.",target);
    }

    return 0;
}
int linearSearch(int arr[], int size, int target, int index){
    if(index >= size){
        return -1;
    }
    if(arr[index] == target){
        return index;
    }
    return linearSearch(arr, size, target, index + 1);
}