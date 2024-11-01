#include <stdio.h>
#include <string.h>

void Compress_Word(char* word, int* removed_count, char* minWord);
void Compress_Words(char words[100][100], int removed_counts[100], char minWords[100][100], int* total_removed, int word_count);

int main() {
    char words[100][100], minWords[100][100];
    int total_removed = 0;
    int removed_counts[100];
    int word_count = 0;

    printf("Enter the number of words: ");
    scanf("%d", &word_count);
    getchar(); // To consume the newline character after the number input

    // Get each word from the user
    for (int i = 0; i < word_count; i++) {
        printf("Enter word %d: ", i + 1);
        fgets(words[i], 100, stdin);
        words[i][strcspn(words[i], "\n")] = '\0'; // Remove the newline character
    }

    // Print original words
    printf("Words: {");
    for (int i = 0; i < word_count; i++) {
        printf("\"%s\"", words[i]);
        if (i < word_count - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    // Compress words
    Compress_Words(words, removed_counts, minWords, &total_removed, word_count);

    // Print minimized words
    printf("Minimized Words: {");
    for (int i = 0; i < word_count; i++) {
        printf("\"%s\"", minWords[i]);
        if (i < word_count - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    // Print total characters removed
    printf("Total Characters Removed: %d\n", total_removed);

    return 0;
}

void Compress_Word(char* word, int* removed_count, char* minWord) {
    char previous_char = '\0'; 
    int index = 0; 
    *removed_count = 0; 

    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] != previous_char) {
            minWord[index++] = word[i]; 
            previous_char = word[i]; 
        } else {
            (*removed_count)++; 
        }
    }
    minWord[index] = '\0'; 
}

void Compress_Words(char words[100][100], int removed_counts[100], char minWords[100][100], int* total_removed, int word_count) {
    *total_removed = 0; 

    for (int i = 0; i < word_count; i++) {
        int removed_count = 0;
        Compress_Word(words[i], &removed_count, minWords[i]); 
        removed_counts[i] = removed_count; 
        *total_removed += removed_count; 
    }
}
