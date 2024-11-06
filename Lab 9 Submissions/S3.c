#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define ROWS 5
#define COLS 20

int main(){
int found=0;
char array[ROWS][COLS]={
    "APPLE",
    "BANANA",
    "MANGO",
    "ORANGE",
    "CHERRY"
};
char search_str[COLS];
    printf("Enter any fruit name you want to search: ");
    scanf("%s",search_str);
   for (int i = 0; search_str[i]; i++) {
        search_str[i] = toupper(search_str[i]);
    }
    
     // Search for string 
     for (int i = 0; i<ROWS; i++){
        if(strcmp(array[i],search_str)==0){
            found=1;
            break;
        }
     }           
    if (found==1) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }

    return 0;
}
