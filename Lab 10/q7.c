#include<stdio.h>
#define Factor 0.001

void conversion(float meters){
    static int callCount = 0;
    callCount ++;
    printf("Call %d: %.2f meters = %.2f km\n", callCount, meters, meters*Factor);
}

int main(){
    conversion(1000);
    conversion(1500);
    return 0;
}