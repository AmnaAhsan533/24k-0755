#include <stdio.h>
#include <string.h>
struct TravelPackage {
    char packageName[100];
    char destination[100];
    int duration;    
    float cost;       
    int seatsAvailable; 
};

void addPackage(struct TravelPackage packages[], int *numPackages) {
    struct TravelPackage newPackage;

    printf("Enter the package name: ");
    getchar();  
    fgets(newPackage.packageName, 100, stdin);
    newPackage.packageName[strcspn(newPackage.packageName, "\n")] = '\0';

    printf("Enter the destination: ");
    fgets(newPackage.destination, 100, stdin);
    newPackage.destination[strcspn(newPackage.destination, "\n")] = '\0'; 

    printf("Enter the duration of the package (in days): ");
    scanf("%d", &newPackage.duration);

    printf("Enter the cost of the package: ");
    scanf("%f", &newPackage.cost);

    printf("Enter the number of seats available: ");
    scanf("%d", &newPackage.seatsAvailable);

    packages[*numPackages] = newPackage;  
    (*numPackages)++;  
    printf("Travel package added successfully!\n");
}

void displayPackages(struct TravelPackage packages[], int numPackages) {
    if (numPackages == 0) {
        printf("No travel packages available.\n");
        return;
    }

    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < numPackages; i++) {
        printf("\nPackage Name: %s\n", packages[i].packageName);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Seats Available: %d\n", packages[i].seatsAvailable);
    }
}
void bookPackage(struct TravelPackage packages[], int numPackages) {
    char packageName[100];
    int found = 0;

    printf("Enter the package name you want to book: ");
    getchar(); 
    fgets(packageName, 100, stdin);
    packageName[strcspn(packageName, "\n")] = '\0'; 

    for (int i = 0; i < numPackages; i++) {
        if (strcmp(packages[i].packageName, packageName) == 0) {
            found = 1;
            if (packages[i].seatsAvailable > 0) {
                printf("Booking confirmed for package: %s\n", packages[i].packageName);
                packages[i].seatsAvailable--;  
                printf("Remaining seats: %d\n", packages[i].seatsAvailable);
            } else {
                printf("Sorry, no seats available for this package.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Package not found.\n");
    }
}
int main() {
    struct TravelPackage packages[100];  //max packages = 100
    int numPackages = 0;  
    int choice;
    do {
        printf("\nTravel Package Menu:\n");
        printf("1. Add a new travel package\n");
        printf("2. Display available travel packages\n");
        printf("3. Book a travel package\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPackage(packages, &numPackages);
                break;
            case 2:
                displayPackages(packages, numPackages);
                break;
            case 3:
                bookPackage(packages, numPackages);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
