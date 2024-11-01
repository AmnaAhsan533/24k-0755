#include<stdio.h>
void UserInput(int *count, int values[]);
void HorizontalHistogram(int count, int values[]);
void VerticalHistogram(int count, int values[]);


int main(){
    int values[100], count;
    UserInput(&count, values);
    HorizontalHistogram(count, values);
    VerticalHistogram(count, values);


    return 0;
}
// Input Handling
void UserInput(int *count, int values[]){
    printf("Enter the number of values: ");
    scanf("%d",count);
    printf("Enter the values\n");
    for(int i=0; i< *count; i++){
        scanf("%d",&values[i]);
    }
}
//Horizontal Histogram
void HorizontalHistogram(int count, int values[]){
    printf("\nHorizontal Histogram\n");
     for(int i=0; i<count; i++){
        printf("Value %d:",i+1);
        for(int j=1; j<=values[i]; j++){
            printf("*");
        }
        printf("\n");
     }
}
// Vertical Histogram
void VerticalHistogram(int count, int values[]){
    int max=values[0];
    for(int i=0; i<count; i++){
        if(max<values[i]){
            max=values[i];
        }
    }

    printf("\nVertical Histogram\n");
    for(int i=max; i>0; i--){
        for(int j=0; j<count; j++){
            if(values[j]>=i)
            printf("* ");
            else printf("  ");
        }
        printf("\n");
    }

    for(int i=0; i<count; i++){
        printf("%d ",values[i]);
    }
}