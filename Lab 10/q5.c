#include<stdio.h>

void ReursiveBubbleSort(int arr[], int size);
int main(){
    int size = 5;
    int arr[] = {20,40,10,30,50};
    ReursiveBubbleSort(arr,size);
    for(int i=0; i<size; i++){
    printf("%d, ",arr[i]);
    }
    return 0;
}
void ReursiveBubbleSort(int arr[], int size){
    if(size <= 1){
        return;
    }
    int temp;
    for(int i=0; i<size - 1; i++){
        if(arr[i]>arr[i+1]){
    temp = arr[i];
    arr[i] = arr[i+1];
    arr[i+1] = temp;
    }
    }
    ReursiveBubbleSort(arr, size -1);
    
}