#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int player, computer;
    int playerScore, computerScore;
    int mode;
    char again;
    char playerName[50];

    printf("Enter your name: ");
    fgets(playerName, sizeof(playerName), stdin);
    playerName[strcspn(playerName, "\n")] = '\0'; // Remove newline character

    srand(time(NULL));

    do {
        playerScore = 0;
        computerScore = 0;

        printf("\n=================================\n");
        printf("     STONE PAPER SCISSORS\n");
        printf("=================================\n");

        printf("\nChoose Game Mode:\n");
        printf("1. Best of 3\n");
        printf("2. Best of 5\n");
        printf("Enter your choice: ");
        scanf("%d", &mode);

        int winningScore;

        if (mode == 1) {
            winningScore = 2;
            printf("\n===== BEST OF 3 =====\n");
        }
        else if (mode == 2) {
            winningScore = 3;
            printf("\n===== BEST OF 5 =====\n");
        }
        else {
            printf("Invalid choice! Starting Best of 3.\n");
            winningScore = 2;
            printf("\n===== BEST OF 3 =====\n");
        }

        while (playerScore < winningScore &&
               computerScore < winningScore) {

            printf("\nChoose your option:\n");
            printf("1. Stone\n");
            printf("2. Paper\n");
            printf("3. Scissors\n");

            printf("Enter your choice: ");
            scanf("%d", &player);

            if (player < 1 || player > 3) {
                printf("Invalid choice! Try again.\n");
                continue;
            }

            computer = (rand() % 3) + 1;

            printf("\nYou chose: ");

            if (player == 1)
                printf("Stone\n");
            else if (player == 2)
                printf("Paper\n");
            else
                printf("Scissors\n");

            printf("Computer chose: ");

            if (computer == 1)
                printf("Stone\n");
            else if (computer == 2)
                printf("Paper\n");
            else
                printf("Scissors\n");

            if (player == computer) {
                printf("Result: DRAW!\n");
            }
            else if ((player == 1 && computer == 3) ||
                     (player == 2 && computer == 1) ||
                     (player == 3 && computer == 2)) {

                printf("Result: YOU WIN!\n");
                playerScore++;
            }
            else {
                printf("Result: COMPUTER WINS!\n");
                computerScore++;
            }

            printf("\nScore -> You: %d | Computer: %d\n",
                   playerScore, computerScore);
        }

        printf("\n=================================\n");
        printf("          MATCH RESULT\n");
        printf("=================================\n");

        printf("\nFinal Score -> You: %d | Computer: %d\n",
               playerScore, computerScore);

        if (playerScore > computerScore)
            printf("\n🎉 YOU WIN THE MATCH!\n");
        else
            printf("\n💻 COMPUTER WINS THE MATCH!\n");

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("\nThanks for playing! 👋\n");

    return 0;
}