#include<stdio.h>
void PrintGrid(char grid[5][5]);
void PlayerMove(char grid[5][5], char move, int *playerX, int *playerY, int *itemsCollected);

int main(){
    char grid[5][5]={
        {'I','.','.','.','X'},
        {'.','X','.','I','.'},
        {'I','.','X','.','I'},
        {'.','I','.','X','.'},
        {'X','.','I','P','.'}
    };
    int playerX=4, playerY=3; //player position grid[4][3]
    char move;
    int itemsCollected=0; 
    printf("Welcome to the Adventure Game!\n");
    printf("Collect items 'I' and avoid obstacles 'X'.\n");
    printf("Use W:up, S:down, A:left, D:right to move. Press 'Q' to quit.\n");
    while(1){
    PrintGrid(grid);
    printf("Items collectd: %d\n", itemsCollected);
    printf("Enter your move:");
    scanf(" %c",&move);

    if(move=='Q' || move=='q'){
        printf("You quit the game.\n");
        break;
    }
    PlayerMove(grid, move, &playerX, &playerY, &itemsCollected);
    }
    printf("Game Over! Total items collectd: %d", itemsCollected);
    return 0;
}

//Function to display current grid
void PrintGrid(char grid[5][5]){
    printf("Game Board\n");
    for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%c ", grid[i][j]);
            }
            printf("\n");
        }
}
//Function to move the player on the grid
void PlayerMove(char grid[5][5], char move, int *playerX, int *playerY, int *itemsCollected){
    int newX = *playerX;
    int newY = *playerY;

//Determine new position
switch(move){
    case 'W': case 'w': newX--;
    break; //Up
    case 'S': case 's': newX++;
    break; //Down
    case 'A': case 'a': newY--;
    break; //Left
    case 'D': case 'd': newY++;
    break; //Right
    default: printf("Invalid input! Use W, A, S, D or Q\n");
    return;
} 
//Validate new position
if(newX<0 || newX >= 5 || newY<0 || newY >= 5){
    printf("You can't move outside the grid!\n");
    return;
}
//Check if there is an obstacle
if(grid[newX][newY]=='X'){
    printf("You cant move because there is an obstacle!\n");
    return;
}
//Check if there is an item
if(grid[newX][newY]=='I'){
    (*itemsCollected)++;
    printf("You collected an item!\nTotal items: %d", *itemsCollected);
}
//Move player to new position
grid[*playerX][*playerY]='.'; //Clear old position
*playerX=newX;
*playerY=newY;
grid[*playerX][*playerY]='P'; //Set new postion
}