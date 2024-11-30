#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void initializeInventory(char ***speciesSupplies[], int *numSpecies, int **numSupplies);
void addSupplies(char **speciesSupplies[], int *numSupplies, int speciesIndex);
void updateSupply(char **speciesSupplies[], int numSupplies[], int speciesIndex);
void removeSpecies(char ***speciesSupplies[], int **numSupplies, int *numSpecies);
void displayInventory(char **speciesSupplies[], int numSpecies, int *numSupplies);

int main() {
    char ***speciesSupplies = NULL;
    int *numSupplies = NULL; // Array to track the number of supplies per species
    int numSpecies = 0;

    int choice;

    do {
        printf("\n--- Pets in Heart Inventory System ---\n");
        printf("1. Initialize Inventory\n");
        printf("2. Add Supplies for a Species\n");
        printf("3. Update Supply for a Species\n");
        printf("4. Remove a Species\n");
        printf("5. Display Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initializeInventory(&speciesSupplies, &numSpecies, &numSupplies);
                break;
            case 2:
                if (numSpecies == 0) {
                    printf("Initialize the inventory first!\n");
                } else {
                    int speciesIndex;
                    printf("Enter species index (0 to %d): ", numSpecies - 1);
                    scanf("%d", &speciesIndex);
                    if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                        addSupplies(speciesSupplies, numSupplies, speciesIndex);
                    } else {
                        printf("Invalid species index!\n");
                    }
                }
                break;
            case 3:
                if (numSpecies == 0) {
                    printf("Initialize the inventory first!\n");
                } else {
                    int speciesIndex;
                    printf("Enter species index (0 to %d): ", numSpecies - 1);
                    scanf("%d", &speciesIndex);
                    if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                        updateSupply(speciesSupplies, numSupplies, speciesIndex);
                    } else {
                        printf("Invalid species index!\n");
                    }
                }
                break;
            case 4:
                if (numSpecies == 0) {
                    printf("No species to remove!\n");
                } else {
                    removeSpecies(&speciesSupplies, &numSupplies, &numSpecies);
                }
                break;
            case 5:
                displayInventory(speciesSupplies, numSpecies, numSupplies);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    // Free allocated memory before exiting
    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; j < numSupplies[i]; j++) {
            free(speciesSupplies[i][j]); // Free each supply
        }
        free(speciesSupplies[i]); // Free species
    }
    free(speciesSupplies); // Free species list
    free(numSupplies);     // Free supplies count array

    return 0;
}

// Initialize inventory
void initializeInventory(char ***speciesSupplies[], int *numSpecies, int **numSupplies) {
    printf("Enter the number of species: ");
    scanf("%d", numSpecies);

    *speciesSupplies = (char ***)malloc(*numSpecies * sizeof(char **));
    *numSupplies = (int *)calloc(*numSpecies, sizeof(int));

    for (int i = 0; i < *numSpecies; i++) {
        (*speciesSupplies)[i] = NULL; // No supplies allocated initially
    }

    printf("Inventory initialized with %d species.\n", *numSpecies);
}

// Add supplies for a species
void addSupplies(char **speciesSupplies[], int *numSupplies, int speciesIndex) {
    int count;
    printf("Enter the number of supplies to add for species %d: ", speciesIndex);
    scanf("%d", &count);

    speciesSupplies[speciesIndex] = (char **)realloc(speciesSupplies[speciesIndex],
                                                     (numSupplies[speciesIndex] + count) * sizeof(char *));

    for (int i = 0; i < count; i++) {
        printf("Enter supply name: ");
        char buffer[100];
        scanf("%s", buffer);
        speciesSupplies[speciesIndex][numSupplies[speciesIndex] + i] = strdup(buffer);
    }

    numSupplies[speciesIndex] += count;
    printf("Supplies added for species %d.\n", speciesIndex);
}

// Update a supply for a species
void updateSupply(char **speciesSupplies[], int numSupplies[], int speciesIndex) {
    int supplyIndex;
    printf("Enter the supply index to update (0 to %d): ", numSupplies[speciesIndex] - 1);
    scanf("%d", &supplyIndex);

    if (supplyIndex >= 0 && supplyIndex < numSupplies[speciesIndex]) {
        printf("Enter the new name for the supply: ");
        char buffer[100];
        scanf("%s", buffer);
        free(speciesSupplies[speciesIndex][supplyIndex]);
        speciesSupplies[speciesIndex][supplyIndex] = strdup(buffer);
        printf("Supply updated.\n");
    } else {
        printf("Invalid supply index!\n");
    }
}

// Remove a species
void removeSpecies(char ***speciesSupplies[], int **numSupplies, int *numSpecies) {
    int speciesIndex;
    printf("Enter the species index to remove (0 to %d): ", *numSpecies - 1);
    scanf("%d", &speciesIndex);

    if (speciesIndex >= 0 && speciesIndex < *numSpecies) {
        for (int i = 0; i < (*numSupplies)[speciesIndex]; i++) {
            free((*speciesSupplies)[speciesIndex][i]); // Free each supply
        }
        free((*speciesSupplies)[speciesIndex]); // Free the species

        for (int i = speciesIndex; i < *numSpecies - 1; i++) {
            (*speciesSupplies)[i] = (*speciesSupplies)[i + 1];
            (*numSupplies)[i] = (*numSupplies)[i + 1];
        }

        (*speciesSupplies) = (char ***)realloc(*speciesSupplies, (*numSpecies - 1) * sizeof(char **));
        (*numSupplies) = (int *)realloc(*numSupplies, (*numSpecies - 1) * sizeof(int));
        (*numSpecies)--;

        printf("Species removed.\n");
    } else {
        printf("Invalid species index!\n");
    }
}

// Display inventory
void displayInventory(char **speciesSupplies[], int numSpecies, int *numSupplies) {
    printf("\n--- Current Inventory ---\n");
    for (int i = 0; i < numSpecies; i++) {
        printf("Species %d:\n", i);
        for (int j = 0; j < numSupplies[i]; j++) {
            printf("  Supply %d: %s\n", j, speciesSupplies[i][j]);
        }
    }
}

