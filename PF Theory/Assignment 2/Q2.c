#include <stdio.h>
#include <string.h>

#define Max_slogan 3
#define Max_length 50

int main() {
    int n = Max_slogan;
    char slogan[Max_slogan][Max_length];

    // Loop for input
    for (int i = 0; i < n; i++) {
        printf("Enter slogan %d: ", i + 1);
        fgets(slogan[i], Max_length, stdin);
        // Remove the newline character at the end if present
        unsigned int len = strlen(slogan[i]);
        if (len > 0 && slogan[i][len - 1] == '\n') {
            slogan[i][len - 1] = '\0';
        }
    }

    // Process and print the output for each slogan
    for (int i = 0; i < n; i++) {
        char current = slogan[i][0];
        int count = 1;
        printf("For \"%s\": {",slogan[i]);
        int j;
        for (j = 1; slogan[i][j] != '\0'; j++) {
            if (slogan[i][j] == current) {
                count++;
            } else {
                printf("'%c':%d, ", current, count);
                current = slogan[i][j];
                count = 1;
            }
        }
        // Print the last character count
        printf("'%c':%d", current, count);
        printf("}\n");
    }

    return 0;
}