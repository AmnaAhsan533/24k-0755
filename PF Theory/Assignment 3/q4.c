#include <stdio.h>
#include <stdlib.h>

#define EMPLOYEE 3
#define EVAL_PERIOD 3

struct Employee {
    int* ratings;
    int total_score;
};

void inputEmployees(int** ratings, int numEmployees, int numPeriods);
void displayPerformance(int** ratings, int numEmployees, int numPeriods);
int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods);
int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods);
int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods);

void inputEmployees(int** ratings, int numEmployees, int numPeriods) {
    printf("Enter ratings (1-10) for each employee across all evaluation periods:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("\nFor Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            do {
                printf("  Period %d: ", j + 1);
                scanf("%d", &ratings[i][j]);
                if (ratings[i][j] < 1 || ratings[i][j] > 10) {
                    printf("Invalid input! Ratings must be between 1 and 10.\n");
                }
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}

void displayPerformance(int** ratings, int numEmployees, int numPeriods) {
    printf("\nThe performance ratings for each employee across all evaluation periods:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods) {
    int max = 0, index = 0;
    for (int i = 0; i < numEmployees; i++) {
        int sum = 0;
        for (int j = 0; j < numPeriods; j++) {
            sum += ratings[i][j];
        }
        if (max < sum) {
            max = sum;
            index = i;
        }
    }
    return index;
}

int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods) {
    int maxAvg = 0, bestPeriod = 0;
    for (int j = 0; j < numPeriods; j++) {
        int sum = 0;
        for (int i = 0; i < numEmployees; i++) {
            sum += ratings[i][j];
        }
        int avg = sum / numEmployees;
        if (avg > maxAvg) {
            maxAvg = avg;
            bestPeriod = j;
        }
    }
    return bestPeriod;
}

int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods) {
    int min = 1000, index = 0;
    for (int i = 0; i < numEmployees; i++) {
        int sum = 0;
        for (int j = 0; j < numPeriods; j++) {
            sum += ratings[i][j];
        }
        if (sum < min) {
            min = sum;
            index = i;
        }
    }
    return index;
}

int main() {
    int** ratings;
    ratings = (int**)malloc(EMPLOYEE * sizeof(int*));
    for (int i = 0; i < EMPLOYEE; i++) {
        ratings[i] = (int*)malloc(EVAL_PERIOD * sizeof(int));
    }

    inputEmployees(ratings, EMPLOYEE, EVAL_PERIOD);
    displayPerformance(ratings, EMPLOYEE, EVAL_PERIOD);

    int best = findEmployeeOfTheYear(ratings, EMPLOYEE, EVAL_PERIOD);
    int worst = findWorstPerformingEmployee(ratings, EMPLOYEE, EVAL_PERIOD);
    int bestPeriod = findHighestRatedPeriod(ratings, EMPLOYEE, EVAL_PERIOD);

    printf("\nEmployee of the Year: Employee %d\n", best + 1);
    printf("Best Rated Period: Period %d\n", bestPeriod + 1);
    printf("Worst Performing Employee: Employee %d\n", worst + 1);

    // Free allocated memory
    for (int i = 0; i < EMPLOYEE; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
