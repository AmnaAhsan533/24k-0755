#include<stdio.h>
#include<string.h>
void ReverseString(char *string, char *reverse);

int main(){
    char string[50];
    char reverse[50];
    printf("Enter a word that you want to reverse: ");
    scanf("%s",string);
    
    ReverseString(string, reverse);

    return 0;
}
void ReverseString(char *string, char *reverse){
    int len = strlen(string);
    for(int i=0; i<len; i++ ){
        reverse[i]=string[len-i-1];
    }
    reverse[len]='\0';
    printf("Reverse String: %s",reverse);
}