#include<stdio.h>
#include<stdlib.h>

struct Student{
    char name[20];
    int roll;
    float marks;
};
int main(){
    int n;
    float sum = 0.0;
    struct Student *st = NULL;
    printf("Enter no. of students: ");
    scanf("%d",&n);
    st = (struct Student*)malloc(n * sizeof(struct Student));
    if(st == NULL){
        printf("Memory allocation failed\n");
    }
    
    printf("Enter student details\n ");
    for(int i=0; i<n; i++){
        printf("For student %d\n",i+1);
        printf("Enter name: ");
        scanf("%s",(st + i)->name);
        printf("Enter roll no:");
        scanf("%d",&(st + i)->roll);
        printf("Enter marks: ");
        scanf("%f",&(st + i)->marks);
    }
    for(int i=0; i<n; i++){
        sum += (st + i)->marks;
    }
    printf("Average marks of class is %.2f",sum / n);
    free(st);
    return 0;
}