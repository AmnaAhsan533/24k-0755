#include<stdio.h>
void printArray(int arr[], int size){
    if(size == 0){
        return;
    }
    printf("%d ",arr[0]);
    printArray(arr + 1, size - 1);
}
int main(){
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    return 0;
}