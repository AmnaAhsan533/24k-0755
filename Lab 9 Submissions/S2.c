
#include<stdio.h>
#include<string.h>

int main(){
 char destination[20];
 char source[10];
 int n;
 
 printf("Enter characters for destination string: ");
  fgets(destination, 20, stdin);
  destination[strcspn(destination, "\n")]=0;

 printf("Enter characters for source string: ");
 fgets(source, 10, stdin);
 source[strcspn(source, "\n")]=0;
 printf("Enter number;");
 scanf("%d", &n);

strncat(destination, source, n);
printf("Resulting String: %s",destination);
  return 0;
}
