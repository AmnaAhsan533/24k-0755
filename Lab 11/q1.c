#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct player {
    char name[20];
    char team[20];
};

struct bowl {
    char type[10]; // seamer, pacer, spinner, N/A
    char arm[7];   // left or right
    struct player ply;
};

struct bat {
    char type[15];  // top order, middle order, lower order
    char handed[8]; // lefty or righty
    struct bowl ply2;
};

#define FILENAME "players.txt"

void createRecords();
void readRecords();
void updateRecords();
void deleteRecords();

void createRecords() {
    FILE *fp;
    struct bat p;

    fp = fopen(FILENAME, "a");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    printf("Enter Details of player\n");
    printf("Enter player name: ");
    fgets(p.ply2.ply.name, sizeof(p.ply2.ply.name), stdin);
    p.ply2.ply.name[strcspn(p.ply2.ply.name, "\n")] = '\0';  

    printf("Enter team name: ");
    fgets(p.ply2.ply.team, sizeof(p.ply2.ply.team), stdin);
    p.ply2.ply.team[strcspn(p.ply2.ply.team, "\n")] = '\0';  

    printf("Enter bowling type (seamer, pacer, spinner, N/A): ");
    fgets(p.ply2.type, sizeof(p.ply2.type), stdin);
    p.ply2.type[strcspn(p.ply2.type, "\n")] = '\0';  

    printf("Enter bowling arm (left or right): ");
    fgets(p.ply2.arm, sizeof(p.ply2.arm), stdin);
    p.ply2.arm[strcspn(p.ply2.arm, "\n")] = '\0';  

    printf("Enter batting type (top order, middle order, lower order): ");
    fgets(p.type, sizeof(p.type), stdin);
    p.type[strcspn(p.type, "\n")] = '\0';  

    printf("Enter batting handedness (lefty or righty): ");
    fgets(p.handed, sizeof(p.handed), stdin);
    p.handed[strcspn(p.handed, "\n")] = '\0'; 

    fprintf(fp, "%s %s %s %s %s %s\n", p.ply2.ply.name, p.ply2.ply.team, p.ply2.type, p.ply2.arm, p.type, p.handed);
    printf("Record inserted successfully.\n");

    fclose(fp);
}

void readRecords() {
    FILE *fp;
    struct bat p;

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nPlayers Records:\n");
    while (fscanf(fp, "%s %s %s %s %s %s", p.ply2.ply.name, p.ply2.ply.team, p.ply2.type, p.ply2.arm, p.type, p.handed) != EOF) {
        printf("\nPlayer Name: %s\nTeam Name: %s\nBowling type: %s\nBowling arm: %s\nBatting type: %s\nBatting handedness: %s\n",
            p.ply2.ply.name, p.ply2.ply.team, p.ply2.type, p.ply2.arm, p.type, p.handed);
    }

    fclose(fp);
}

void updateRecords() {
    FILE *fp, *tempFp;
    struct bat p[100];
    char target[20];
    int count = 0, found = 0;

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }
    tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("Temporary file cannot be created.\n");
        fclose(fp);
        return;
    }
    while (fscanf(fp, "%s %s %s %s %s %s", p[count].ply2.ply.name, p[count].ply2.ply.team, p[count].ply2.type, p[count].ply2.arm, p[count].type, p[count].handed) != EOF) {
        count++;
    }

    printf("Enter the name of the player to update: ");
    scanf("%s", target);
    getchar(); 
    for (int i = 0; i < count; i++) {
        if (strcmp(p[i].ply2.ply.name, target) == 0) {
            printf("Enter new details\nTeam name, bowling type(seamer, pacer, spinner, N/A), bowling arm(left or right), batting type(top order, middle order, lower order), batting handedness(lefty or righty)\n");
            scanf("%s %s %s %s %s", p[i].ply2.ply.team, p[i].ply2.type, p[i].ply2.arm, p[i].type, p[i].handed);
            getchar();  
            found = 1;
        }

        fprintf(tempFp, "%s %s %s %s %s %s\n", p[i].ply2.ply.name, p[i].ply2.ply.team, p[i].ply2.type, p[i].ply2.arm, p[i].type, p[i].handed);
    }

    if (!found) {
        printf("Record not found.\n");
    } else {
        printf("Record updated successfully.\n");
    }

    fclose(fp);
    fclose(tempFp);

    // Remove the original file
    remove(FILENAME);

    // Rename the temporary file to the original file name
    rename("temp.txt", FILENAME);
}

void deleteRecords() {
    FILE *fp, *tempFp;
    struct bat p[200];
    char target[20];
    int count = 0, found = 0;

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("File cannot be opened.\n");
        return;
    }

    // Create a temporary file
    tempFp = fopen("temp.txt", "w");
    if (tempFp == NULL) {
        printf("Temporary file cannot be created.\n");
        fclose(fp);
        return;
    }

    // Read all records into memory
    while (fscanf(fp, "%s %s %s %s %s %s", p[count].ply2.ply.name, p[count].ply2.ply.team, p[count].ply2.type, p[count].ply2.arm, p[count].type, p[count].handed) != EOF) {
        count++;
    }

    // Ask for player name to delete
    printf("Enter the name of the player to delete: ");
    scanf("%s", target);
    getchar();  // Consume newline after scanf

    // Write all records except the one to delete to the temporary file
    for (int i = 0; i < count; i++) {
        if (strcmp(p[i].ply2.ply.name, target) == 0) {
            found = 1;  // Record found, so we skip it
            continue;
        }

        // Write the record to the temporary file
        fprintf(tempFp, "%s %s %s %s %s %s\n", p[i].ply2.ply.name, p[i].ply2.ply.team, p[i].ply2.type, p[i].ply2.arm, p[i].type, p[i].handed);
    }

    if (!found) {
        printf("Record not found.\n");
    } else {
        printf("Record deleted successfully.\n");
    }

    fclose(fp);
    fclose(tempFp);

    // Remove the original file
    remove(FILENAME);

    // Rename the temporary file to the original file name
    rename("temp.txt", FILENAME);
}

int main() {
    int choice;
    
    while (1) {
        printf("\nCRUD Operations:\n");
        printf("1. Create Record\n");
        printf("2. Read All Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character after scanf

        switch (choice) {
            case 1:
                createRecords();
                break;
            case 2:
                readRecords();
                break;
            case 3:
                updateRecords();
                break;
            case 4:
                deleteRecords();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
