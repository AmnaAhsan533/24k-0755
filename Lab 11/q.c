#include<stdio.h>
#include<string.h>

struct player{
char name[20];
char team[20];
};

struct bowl{
char type[10]; // seemer, pacer, spinner// N/A
char arm[5]; //left or right
struct player ply;
};

struct bat{
char type[10]; // top order, middle order, lower order
char handed[8]; //lefty or righty
struct bowl ply2;
};
#define FILENAME "players.txt"
void createRecords();
void readRecords();
void updateRecords(char *name);
void deleteRecords(char *name);

int main(){
     int choice;
    char name[20];

    while (1) {
        printf("\nCRUD Operations:\n");
        printf("1. Create Record\n");
        printf("2. Read All Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createRecord();
                break;
            case 2:
                readRecords();
                break;
            case 3:
                printf("Enter the name of the player to update: ");
                scanf("%s", name);
                updateRecord(name);
                break;
            case 4:
                printf("Enter the name of the player to delete: ");
                scanf("%s", name);
                deleteRecord(name);
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
//Create new record
void createRecords(){
    FILE *ptr = fopen(FILENAME, "a");
    if(!ptr){
        printf("Error opening file!");
        return;
    } 
    struct bat newRecord;
    printf("Enter player name: ");
    scanf("%s",newRecord.ply2.ply.name);
    printf("Enter team name: ");

    scanf("%s",newRecord.ply2.ply.team);
    printf("Enter bowling type (seamer/pacer/spinner/N/A): ");
    scanf("%s", newRecord.ply2.type);
    printf("Enter bowling arm (left/right/N/A): ");
    scanf("%s", newRecord.ply2.arm);

    printf("Enter batting type (top/middle/lower/N/A): ");
    scanf("%s", newRecord.type);
    printf("Enter batting handedness (lefty/righty/N/A): ");
    scanf("%s", newRecord.handed);

    fwrite(&newRecord, sizeof(struct bat), 1, ptr);
    fclose(ptr);
    printf("Record added successfully.\n");
}
//Read and display all records
void readRecords(){
    FILE *ptr = fopen(FILENAME, "r");
    if(!ptr){
        printf("Error opening file!");
        return;
    } 
    struct bat record;
    printf("\nPlayer Records:\n");
    while(fread(&record, sizeof(struct bat), 1, ptr)){
        printf("Name: %s, Team: %s\n", record.ply2.ply.name, record.ply2.ply.team);
        printf("Bowling Type: %s, Arm: %s\n", record.ply2.type, record.ply2.arm);
        printf("Batting Type: %s, Handedness: %s\n\n", record.type, record.handed);
    }
    fclose(ptr);
}
//Update a record by player name
void updateRecords(char *name){
    FILE *ptr = fopen(FILENAME, "r");
    if(!ptr){
        printf("Error opening file!");
        return;
    } 
    struct bat record;
    int found = 0;
    while(fread(&record, sizeof(struct bat), 1, ptr)){
        if(strcmp(record.ply2.ply.name, name) == 0){
            printf("Updating record for %s...\n", name);

            printf("Enter new team name: ");
            scanf("%s", record.ply2.ply.team);

            printf("Enter new bowling type (seamer/pacer/spinner/N/A): ");
            scanf("%s", record.ply2.type);
            printf("Enter new bowling arm (left/right/N/A): ");
            scanf("%s", record.ply2.arm);

            printf("Enter new batting type (top/middle/lower/N/A): ");
            scanf("%s", record.type);
            printf("Enter new batting handedness (lefty/righty/N/A): ");
            scanf("%s", record.handed);
            fseek(ptr, -sizeof(struct bat), SEEK_CUR);
            fwrite(&record, sizeof(struct bat), 1, ptr);
            found = 1;
            printf("Record updated successfully.\n");
            break;
        }
    }
     if (!found) {
        printf("No record found for player: %s\n", name);
    }

    fclose(ptr);

}
void deleteRecords(char *name){
     FILE *ptr = fopen(FILENAME, "rb");
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!ptr || !tempFile) {
        perror("Error opening file");
        return;
    }

    struct bat record;
    int found = 0;

    while (fread(&record, sizeof(struct bat), 1, ptr)) {
        if (strcmp(record.ply2.ply.name, name) != 0) {
            fwrite(&record, sizeof(struct bat), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(ptr);
    fclose(tempFile);

    if (found) {
        remove(FILENAME);
        rename("temp.dat", FILENAME);
        printf("Record deleted successfully.\n");
    } else {
        printf("No record found for player: %s\n", name);
    }
    } 

