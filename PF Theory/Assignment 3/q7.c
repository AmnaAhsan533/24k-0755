#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    float rating;
    int runtime;  // in minutes
    char encoding[50];
} ContentMetadata;

double** createEngagementMatrix(int numUsers, int numCategories) {
    double** matrix = (double**)malloc(numUsers * sizeof(double*));
    for (int i = 0; i < numUsers; i++) {
        matrix[i] = (double*)malloc(numCategories * sizeof(double));
        for (int j = 0; j < numCategories; j++) {
            matrix[i][j] = 0.0;  
        }
    }
    return matrix;
}

float*** createDeviceMatrix(int numUsers, int numDevices, int numPreferences) {
    float*** matrix = (float***)malloc(numUsers * sizeof(float**));
    for (int i = 0; i < numUsers; i++) {
        matrix[i] = (float**)malloc(numDevices * sizeof(float*));
        for (int j = 0; j < numDevices; j++) {
            matrix[i][j] = (float*)malloc(numPreferences * sizeof(float));
            for (int k = 0; k < numPreferences; k++) {
                matrix[i][j][k] = 0.0f;  
            }
        }
    }
    return matrix;
}

ContentMetadata*** createContentMetadataMatrix(int numCategories, int numContents) {
    ContentMetadata*** matrix = (ContentMetadata***)malloc(numCategories * sizeof(ContentMetadata**));
    for (int i = 0; i < numCategories; i++) {
        matrix[i] = (ContentMetadata**)malloc(numContents * sizeof(ContentMetadata*));
        for (int j = 0; j < numContents; j++) {
            matrix[i][j] = (ContentMetadata*)malloc(sizeof(ContentMetadata));
            strcpy(matrix[i][j]->title, "Unknown");
            matrix[i][j]->rating = 0.0;
            matrix[i][j]->runtime = 0;
            strcpy(matrix[i][j]->encoding, "Unknown");
        }
    }
    return matrix;
}

void freeEngagementMatrix(double** matrix, int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
void freeDeviceMatrix(float*** matrix, int numUsers, int numDevices) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

void freeContentMetadataMatrix(ContentMetadata*** matrix, int numCategories, int numContents) {
    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContents; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int numUsers = 3, numCategories = 3, numDevices = 2, numPreferences = 5, numContents = 3;
    double** engagementMatrix = createEngagementMatrix(numUsers, numCategories);
    float*** deviceMatrix = createDeviceMatrix(numUsers, numDevices, numPreferences);
    ContentMetadata*** contentMetadataMatrix = createContentMetadataMatrix(numCategories, numContents);
    engagementMatrix[0][0] = 4.5;  
    engagementMatrix[0][1] = 3.2;  
    engagementMatrix[0][2] = 2.1;  
    engagementMatrix[1][0] = 5.0;  
    engagementMatrix[1][1] = 4.8;  
    engagementMatrix[1][2] = 3.5;  
    engagementMatrix[2][0] = 3.0;  
    engagementMatrix[2][1] = 3.7;  
    engagementMatrix[2][2] = 4.2;  

    deviceMatrix[0][0][0] = 1.2; 
    deviceMatrix[0][0][1] = 2.5;  
    deviceMatrix[0][1][1] = 1.5;  

    strcpy(contentMetadataMatrix[0][0]->title, "Action Movie 1");
    contentMetadataMatrix[0][0]->rating = 4.5;
    contentMetadataMatrix[0][0]->runtime = 120;
    strcpy(contentMetadataMatrix[0][0]->encoding, "H.264");

    strcpy(contentMetadataMatrix[0][1]->title, "Action Movie 2");
    contentMetadataMatrix[0][1]->rating = 4.2;
    contentMetadataMatrix[0][1]->runtime = 110;
    strcpy(contentMetadataMatrix[0][1]->encoding, "VP9");

    strcpy(contentMetadataMatrix[0][2]->title, "Action Movie 3");
    contentMetadataMatrix[0][2]->rating = 3.8;
    contentMetadataMatrix[0][2]->runtime = 115;
    strcpy(contentMetadataMatrix[0][2]->encoding, "H.265");

    printf("Engagement score for User 1, Category 2: %.2f\n", engagementMatrix[0][1]);
    printf("Device 1 preference for User 1: %.2f\n", deviceMatrix[0][0][0]);
    printf("Title of Content in Category 1, Item 1: %s\n", contentMetadataMatrix[0][0]->title);

    freeEngagementMatrix(engagementMatrix, numUsers);
    freeDeviceMatrix(deviceMatrix, numUsers, numDevices);
    freeContentMetadataMatrix(contentMetadataMatrix, numCategories, numContents);

    return 0;
}

