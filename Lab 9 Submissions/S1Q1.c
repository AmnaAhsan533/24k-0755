#include<stdio.h>
int product(int a, int b);
int main(){
 int a, b;
  
 printf("Product: %d", product(a, b));
  return 0;
}
int product(int a, int b){
  printf("Enter two numbers\n");
  scanf("%d %d", &a, &b);
  return a*b;
}
