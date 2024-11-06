#include<stdio.h>
int EvenOdd(int n);
int main(){
 int n;
  
 printf("Enter number:");
 scanf("%d",&n);
 int result = EvenOdd(n);
 if(result==1){
  printf("Given number is EVEN");
 } 
 else{
  printf("Given number is ODD");
 }

  return 0;
}
int EvenOdd(int n){
  if(n%2==0)
  return 1;
  else return 0;
}