#include <stdio.h>
#include <string.h>

struct Player {
    int ballScores[12];
    char playerName[20];
    int totalScore;
};

void playGame(struct Player* player1, struct Player* player2);
int validateScore(int score);
void findWinner(struct Player player1, struct Player player2);
void displayMatchScoreboard(struct Player player1, struct Player player2);

int main() {
    struct Player player1, player2;
    printf("Enter Player 1's Name: ");
    scanf("%s", player1.playerName);
    printf("Enter Player 2's Name: ");
    scanf("%s", player2.playerName);
    playGame(&player1, &player2);
    findWinner(player1, player2);
    displayMatchScoreboard(player1, player2);
    return 0;
}
void playGame(struct Player* player1, struct Player* player2) {
    player1->totalScore = 0;
    player2->totalScore = 0;
        printf("Players can enter scores between 0 and 6 for each ball");
    for (int i = 0; i < 12; i++) {
        int score;
        
        printf("\n%s's turn for Ball %d: ", player1->playerName, i + 1);
        scanf("%d", &score);

        if (validateScore(score)) {
            player1->ballScores[i] = score;
            player1->totalScore += score;
        } else {
            printf("Invalid score. Marking this ball as 0 runs.\n");
            player1->ballScores[i] = 0;
        }
        printf("%s's turn for Ball %d: ", player2->playerName, i + 1);
        scanf("%d", &score);

        if (validateScore(score)) {
            player2->ballScores[i] = score;
            player2->totalScore += score;
        } else {
            printf("Invalid score. Marking this ball as 0 runs.\n");
            player2->ballScores[i] = 0;
        }
    }
}

// Function to validate the score
int validateScore(int score) {
    return (score >= 0 && score <= 6);
}

// Function to find the winner
void findWinner(struct Player player1, struct Player player2) {
    printf("\n--- Match Result ---\n");
    if (player1.totalScore > player2.totalScore) {
        printf("Winner: %s with %d runs.\n", player1.playerName, player1.totalScore);
    } else if (player2.totalScore > player1.totalScore) {
        printf("Winner: %s with %d runs.\n", player2.playerName, player2.totalScore);
    } else {
        printf("It's a tie! Both players scored %d runs.\n", player1.totalScore);
    }
}

// Function to display scoreboard
void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\n--- Match Scoreboard ---\n");
    printf("%-15s| %-15s\n", player1.playerName, player2.playerName);

    for (int i = 0; i < 12; i++) {
        printf("Ball %2d: %-4d | Ball %2d: %-4d\n", i + 1, player1.ballScores[i], i + 1, player2.ballScores[i]);
    }

    printf("\nTotal Score: %-4d| Total Score: %-4d\n", player1.totalScore, player2.totalScore);
    printf("Average Score: %-5.2f| Average Score: %-5.2f\n",(float)player1.totalScore / 12, (float)player2.totalScore / 12);
}

