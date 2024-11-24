#include<stdio.h>
#include<string.h>

 struct Cars{
    char model[20];
    char make[20];
    int year; 
    int mileage;
    float price ;
} ;
void addCars(struct Cars car[20], int *count);
void search(struct Cars car[20], int count);
void display(struct Cars car[20], int count);

int main(){
    int choice, count=0;
    struct Cars car[20]; //max car = 20
    do{
    printf("\n----Car Dealership Menu----\n");
    printf("\n1.Add Cars");
    printf("\n2.Search Cars by make or model");
    printf("\n3.Display All Cars");
    printf("\n4.Exit");

    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    getchar();
    switch (choice)
    {
    case 1:
       addCars(car, &count);
        break;
    case 2:
        search(car, count);
        break;
    case 3:
        display(car, count);
        break;
    case 4:
        printf("Exit");
        break;      
    default:
        printf("Invalid choice! Please try again.");
        break;
    }

    } while(choice!=4);

    return 0;
}

void addCars(struct Cars car[20], int *count){
    if(*count >= 20){
        printf("Car list is full! Cannot add more movies.\n");
    }
    struct Cars ncar;
    printf("Enter make of the car: ");
    fgets(ncar.make, sizeof(ncar.make),stdin);
    ncar.make[strcspn(ncar.make, "\n")]='\0';
    printf("Enter model of the car: ");
    fgets(ncar.model, sizeof(ncar.model),stdin);
    ncar.make[strcspn(ncar.model, "\n")]='\0';
    
    printf("Enter year of the car: ");
    scanf("%d",&ncar.year);
    getchar();
    printf("Enter mileage of car: ");
    scanf("%d",&ncar.mileage);

    printf("Enter price of the car: ");
    scanf("%f",&ncar.price);
    getchar();
    car[*count] = ncar;
    (*count)++;
    printf("Details of Car added successfully\n");

}

void search(struct Cars car[20], int count){
    char search[50];
    int found = 0;
    printf("Enter make or model to search: ");
    scanf("%s",search);
    printf("\nSearch Results:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(car[i].make, search) != NULL || strstr(car[i].model, search) != NULL) {
            printf("\nCar %d:\n", i + 1);
            printf("Make: %s\n", car[i].make);
            printf("Model: %s\n", car[i].model);
            printf("Year: %d\n", car[i].year);
            printf("Price: $%.2f\n", car[i].price);
            printf("Mileage: %d miles\n", car[i].mileage);
            found = 1;
        }

}
    if (!found) {
        printf("No cars found with the given make or model.\n");
    }
}
void display(struct Cars car[20], int count){
    if(count == 0){
        printf("No cars to display!");
        return;
    }
     printf("\nList of Cars Available:\n");
    for (int i = 0; i < count; i++) {
        printf("\nCar %d:\n", i + 1);
        printf("Make: %s\n", car[i].make);
        printf("Model: %s\n", car[i].model);
        printf("Year: %d\n", car[i].year);
        printf("Price: $%.2f\n", car[i].price);
        printf("Mileage: %d miles\n", car[i].mileage);
    }
}



