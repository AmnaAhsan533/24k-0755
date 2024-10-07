#include <stdio.h>

int main() {
     int t1=65536;
     printf("%d, ",t1);
     for(int i=2; i<=8; i++){
        t1=t1/i;
        printf("%d,",t1);
     }
     printf("0");
    return 0;
}


