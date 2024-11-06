#include<stdio.h>
#include<string.h>
#define COLS 20

int main(){
    int n;
    printf("Enter no. of words you want to check: ");
    scanf("%d",&n);
    char array[n][COLS];
    char reversed[COLS];
printf("Enter %d words to check whether they are palindrome or not:",n);
for(int i=0; i<n; i++){
    scanf("%s",array[i]);
}

for(int i=0; i<n; i++){
    int length=strlen(array[i]);
    for(int j=0; j<length; j++){
    reversed[j]=array[i][length-j-1];
   }
    reversed[length]='\0';
    if(strcmp(array[i],reversed)==0){
    printf("\"%s\" is Palindrome\n",array[i]);
    }
    else{
        printf("\"%s\" is NOT Palindrome\n",array[i]);
    }
}
    return 0;
}