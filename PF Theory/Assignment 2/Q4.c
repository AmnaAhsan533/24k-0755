#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100
#define MAX_LENGTH 100

void groupScrambledTransactions(char transactions[][MAX_LENGTH], int n);
void sortString(char *str);

int main() {
    char input[1000];
    char transactions[MAX_TRANSACTIONS][MAX_LENGTH];
    int n = 0;

    // Take input for transactions in a single line
    printf("Enter the transactions (separated by space, max %d transactions):\n", MAX_TRANSACTIONS);
    fgets(input, sizeof(input), stdin);

    // Tokenize the input string to get individual transactions
    char *token = strtok(input, " \n");
    while (token != NULL && n < MAX_TRANSACTIONS) {
        strcpy(transactions[n], token);
        n++;
        token = strtok(NULL, " \n");
    }

    // Group and print the scrambled transactions
    groupScrambledTransactions(transactions, n);
    
    return 0;
}
// Function to sort characters in a string
void sortString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                // Swap characters
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

// Function to group scrambled transactions
void groupScrambledTransactions(char transactions[][MAX_LENGTH], int n) {
    char grouped[MAX_TRANSACTIONS][MAX_LENGTH][MAX_LENGTH]; // Array to store groups
    int groupCount[MAX_TRANSACTIONS] = {0}; // Count of transactions in each group
    int groupIndex = 0; // Number of groups

    for (int i = 0; i < n; i++) {
        // Create a copy of the transaction to sort
        char sortedTransaction[MAX_LENGTH];
        strcpy(sortedTransaction, transactions[i]);
        sortString(sortedTransaction);
        
        // Check if this sorted transaction already exists in any group
        int found = 0;
        for (int j = 0; j < groupIndex; j++) {
            // Compare with the first element of the current group
            char sortedGroupTransaction[MAX_LENGTH];
            strcpy(sortedGroupTransaction, grouped[j][0]);
            sortString(sortedGroupTransaction);
            
            if (strcmp(sortedTransaction, sortedGroupTransaction) == 0) {
                // Add the transaction to the existing group
                strcpy(grouped[j][groupCount[j]], transactions[i]);
                groupCount[j]++;
                found = 1;
                break;
            }
        }
        
        // If not found, create a new group
        if (!found) {
            strcpy(grouped[groupIndex][0], transactions[i]);
            groupCount[groupIndex] = 1;
            groupIndex++;
        }
    }

    // Print the grouped transactions
    printf("[");
    for (int i = 0; i < groupIndex; i++) {
        printf("[");
        for (int j = 0; j < groupCount[i]; j++) {
            printf("\'%s\'", grouped[i][j]);
            if (j < groupCount[i] - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < groupIndex - 1) {
                printf(", ");
            }
    }
     printf("]");
}