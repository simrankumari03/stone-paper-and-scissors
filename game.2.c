#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int generateRandomNumber(int n) {
    srand(time(NULL));
    return rand() % n;
}

int greater(char c1, char c2) {
    // Return 1 if c1 wins, 0 if c2 wins, -1 for a draw
    if (c1 == c2) {
        return -1; // Draw
    }

    if ((c1 == 'r' && c2 == 's') || (c1 == 'p' && c2 == 'r') || (c1 == 's' && c2 == 'p')) {
        return 1; // c1 wins
    } else {
        return 0; // c2 wins
    }
}

int main() {
    int playerScore = 0, compScore = 0, temp;
    char playerChar, compChar;
    char dict[] = {'r', 'p', 's'}; // Dictionary for 'rock', 'paper', 'scissors'

    printf("WELCOME TO THE ROCK PAPER, SCISSORS GAME\n");
int i;
    for ( i = 0; i < 3; i++) {
        // Take player input
        printf("Player 1's turn\n");
        printf("Choose 1 for Rock, 2 for Paper, and 3 for Scissors: ");
        scanf("%d", &temp);
        getchar();  // To clear the newline character from the buffer
        playerChar = dict[temp - 1];
        printf("You chose %c\n", playerChar);

        // Generate computer's input
        printf("Computer's turn\n");
        temp = generateRandomNumber(3) + 1;
        compChar = dict[temp - 1];
        printf("Computer chose %c\n", compChar);

        // Determine who wins the round
        int result = greater(playerChar, compChar);
        if (result == 1) {
            printf("You win this round!\n");
            playerScore++;
        } else if (result == 0) {
            printf("Computer wins this round!\n");
            compScore++;
        } else {
            printf("It's a draw!\n");
        }

        printf("Scores after round %d: Player: %d, Computer: %d\n", i + 1, playerScore, compScore);
    }

    // Determine the overall winner after 3 rounds
    if (playerScore > compScore) {
        printf("You win the game!\n");
    } else if (playerScore < compScore) {
        printf("computer wins the game \n");
    } else {
        printf("It's a draw!\n");
    }
return 0;
}

