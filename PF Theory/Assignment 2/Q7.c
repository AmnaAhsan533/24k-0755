#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#define ROWS 6
#define COLS 5

void GenerateArray(char array[ROWS][COLS], const char *last_4_digits);
void PrintArray(char array[ROWS][COLS]);
int SearchString(char array[ROWS][COLS], const char *search_str);


int main(){
char array[ROWS][COLS];
char last_4_digits[] = "0755";
char search_str[100];
int score = 0;

srand(time(0));
GenerateArray(array, last_4_digits);

while(1){
    printf("Generated Array\n");
    PrintArray(array);

    printf("Enter the string to search (or 'END' to repopulate array and quit): ");
    scanf("%s",search_str);
   for (int i = 0; search_str[i]; i++) {
        search_str[i] = toupper(search_str[i]);
    }
    
    if(strcmp(search_str, "END")==0){
        printf("Re-populating the array...\n");
        GenerateArray(array, last_4_digits);
        PrintArray(array);
        break;
    }
     // Search for string and update score
        if (SearchString(array, search_str)) {
            score++;
            printf("%s is present. Score: %d\n", search_str, score);
        } else {
            score--;
            printf("%s is not present. Score: %d\n", search_str, score);
        }
   }
 
    return 0;
}
//Function to Generate Random Characters
void GenerateArray(char array[ROWS][COLS], const char *last_4_digits){
    for(int i=0; i<ROWS-1; i++){
        for(int j=0; j<COLS; j++){
            array[i][j] = 'A' + rand() % 26;      
            }
    }
    for(int j=0; j<COLS-1; j++){
        array[ROWS-1][j] = last_4_digits[j];
    }
    array[ROWS-1][COLS-1] = 'A' + rand() % 26;
}
//Function to Print Array
void PrintArray(char array[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%c ",array[i][j]);
        }
        printf("\n");
    }
}
//Function to Search Array
int SearchString(char array[ROWS][COLS], const char *search_str){
    int len=strlen(search_str);
    char temp[COLS+1];
    //Horizontal Search
    for(int i=0; i<ROWS; i++){
        strncpy(temp, array[i], COLS);
        temp[COLS]='\0';
        if(strstr(temp, search_str)!=NULL){
            return 1;//found
        }
    }

    //Vertical Search
     for(int j=0; j<COLS; j++){
        for(int i=0; i<ROWS; i++){
            temp[i]=array[i][j];
        }
        temp[ROWS]='\0';
        if(strstr(temp, search_str)!=NULL){
            return 1;//found
        }
    }
    return 0;//not found
}