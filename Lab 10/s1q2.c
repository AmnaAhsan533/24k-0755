#include<stdio.h>
#include<string.h>
void reverseStr(char str[100]);
void reverseStr1(char str[100], int start, int end);

int main(){
char str[100];
printf("Enter string to : ");
gets(str);
reverseStr(str);
printf("%s",str);
   return 0;
}
void reverseStr(char str[100]){
    int len = strlen(str);
   reverseStr1(str, 0, len-1);
}
void reverseStr1(char str[100], int start, int end){
    if(start >= end){
        return;
    }
    else{
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverseStr1(str, start+1, end-1);
    }
}
