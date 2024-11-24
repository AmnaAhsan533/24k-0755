#include<stdio.h>
#define MAX_TEMP 30

int compareTemp(int temp){
    static int exCount = 0;
    if(temp > MAX_TEMP){
        exCount ++;
    }
    printf("Exceeded Count = %d\n",exCount);
    return exCount;
}
int main(){
    compareTemp(28);
    compareTemp(32);
    compareTemp(35);
    return 0;
}
