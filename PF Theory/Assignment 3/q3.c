#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int validateEmail(char* email);
int main(){
    char* email;
    int result;
    printf("Enter your email address: ");
    
    email = (char*)malloc(20*sizeof(char)); //assuming max email length of 20 characters
    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }
    scanf("%s",email);
    result = validateEmail(email);
    if(result == 1){
        printf("Valid Email");
    } else {
        printf("Invalid Email");
    }
    free(email);
    return 0;
}

int validateEmail(char* email){
    int count = 0, flag = 0, index = -1;
    for(int i=0; i<strlen(email); i++){
        if(email[i] == '@'){
            count++;
            index = i;
        }
        if(index != -1 && email[i] == '.' && i > index){
            flag = 1;
        }
    }
    if (index == 0 || index == strlen(email) - 1) {
        return 0; // Local part or domain part is empty
    }
    if(count == 1 && flag == 1){
        return 1;
    } else{
        return 0;
    }

}