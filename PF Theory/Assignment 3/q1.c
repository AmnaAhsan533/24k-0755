#include<stdio.h>
#include<string.h>
struct date{
    int day;
    int month;
    int year;
};
struct Employee {
    int employeeCode;
    char employeeName[20];
    struct date dateOfJoining;
};

void user_input(struct Employee *emp);
void display(struct Employee *emp, struct date current_date, int *count);
int main(){
        struct Employee emp[4];
        struct date current_date;
        int count = 0;

       for(int i=0; i<4; i++){
        printf("\nEnter details for employee %d", i+1);
        user_input(&emp[i]);
       }

       printf("\nEnter current date (day month year) to calculate tenure: ");
    scanf("%d %d %d", &current_date.day, &current_date.month, &current_date.year);

    printf("\nDetails of employees with tenure more than 3 years");
    for(int i=0; i<4; i++){
        display(&emp[i], current_date, &count);
    }
    printf("\nCount of such employees is/are %d",count);

    return 0;
}
void user_input(struct Employee *emp){
    printf("\nEnter employee code: ");
    scanf("%d",&emp->employeeCode);
    printf("Enter employee name: ");
    getchar();
    fgets(emp->employeeName, 20, stdin);
    emp->employeeName[strcspn(emp->employeeName, "\n")] = '\0';
    printf("Enter date of joining (day month year): ");
    scanf("%d %d %d",&emp->dateOfJoining.day,  &emp->dateOfJoining.month, &emp->dateOfJoining.year);
    
}
void display(struct Employee *emp ,struct date current_date, int *count){
  
    int tenure = current_date.year - emp->dateOfJoining.year;
    if(current_date.month < emp->dateOfJoining.month || current_date.month == emp->dateOfJoining.month && current_date.day < emp->dateOfJoining.day){
        tenure --;
    }
if(tenure > 3){
    
    printf("\nEmploye code: %d", emp->employeeCode);
    printf("\nEmployee Name: %s", emp->employeeName);
    printf("\nDate of joining: %d/%d/%d",emp->dateOfJoining.day, emp->dateOfJoining.month, emp->dateOfJoining.year);
    printf("\nTenure: %d years\n",tenure);
    (*count) ++;
}
}