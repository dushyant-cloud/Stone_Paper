#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int player, computer;
    int playerScore, computerScore;
    int mode, winningScore;
    int wins = 0, losses = 0;
    int totalMatches = 0;
    float winRate;
    char playerName[50];
    char again;
    FILE *file;
    FILE *history;

    srand(time(NULL));

    printf("=================================\n");
    printf("     STONE PAPER SCISSORS\n");
    printf("=================================\n");

    printf("\nEnter your name: ");
    fgets(playerName, sizeof(playerName), stdin);

    playerName[strcspn(playerName, "\n")] = '\0';

    do {
        playerScore = 0;
        computerScore = 0;

        printf("\nWelcome, %s! 👋\n", playerName);

        printf("\nChoose Game Mode:\n");
        printf("1. Best of 3\n");
        printf("2. Best of 5\n");
        printf("Enter your choice: ");
        scanf("%d", &mode);

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

        /* Open history file */
        history = fopen("game_history.txt", "a");

        if (history != NULL) {
            fprintf(history, "\n=================================\n");
            fprintf(history, "Player: %s\n", playerName);

            if (winningScore == 2)
                fprintf(history, "Mode: Best of 3\n");
            else
                fprintf(history, "Mode: Best of 5\n");

            fprintf(history, "=================================\n");
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

            /* Save round history */
            if (history != NULL) {
                fprintf(history, "Round: You = ");

                if (player == 1)
                    fprintf(history, "Stone");
                else if (player == 2)
                    fprintf(history, "Paper");
                else
                    fprintf(history, "Scissors");

                fprintf(history, " | Computer = ");

                if (computer == 1)
                    fprintf(history, "Stone");
                else if (computer == 2)
                    fprintf(history, "Paper");
                else
                    fprintf(history, "Scissors");
            }

            if (player == computer) {
                printf("Result: DRAW!\n");

                if (history != NULL)
                    fprintf(history, " | Result = DRAW\n");
            }
            else if ((player == 1 && computer == 3) ||
                     (player == 2 && computer == 1) ||
                     (player == 3 && computer == 2)) {

                printf("Result: YOU WIN!\n");
                playerScore++;

                if (history != NULL)
                    fprintf(history, " | Result = WIN\n");
            }
            else {
                printf("Result: COMPUTER WINS!\n");
                computerScore++;

                if (history != NULL)
                    fprintf(history, " | Result = LOSS\n");
            }

            printf("\nScore -> %s: %d | Computer: %d\n",
                   playerName, playerScore, computerScore);
        }

        totalMatches++;

        printf("\n=================================\n");
        printf("          MATCH RESULT\n");
        printf("=================================\n");

        printf("%s: %d\n", playerName, playerScore);
        printf("Computer: %d\n", computerScore);

        if (playerScore > computerScore) {
            printf("\n🎉 YOU WIN THE MATCH!\n");
            wins++;

            if (history != NULL)
                fprintf(history, "FINAL RESULT: %s WON\n", playerName);
        }
        else {
            printf("\n💻 COMPUTER WINS THE MATCH!\n");
            losses++;

            if (history != NULL)
                fprintf(history, "FINAL RESULT: COMPUTER WON\n");
        }

        if (history != NULL) {
            fprintf(history, "Final Score: %s %d - Computer %d\n",
                    playerName, playerScore, computerScore);
            fclose(history);
        }

        /* Statistics */
        winRate = ((float)wins / totalMatches) * 100;

        printf("\n===== STATISTICS =====\n");
        printf("Player: %s\n", playerName);
        printf("Matches: %d\n", totalMatches);
        printf("Wins: %d\n", wins);
        printf("Losses: %d\n", losses);
        printf("Win Rate: %.2f%%\n", winRate);

        /* Save statistics */
        file = fopen("stats.txt", "w");

        if (file == NULL) {
            printf("\nError: Could not save statistics.\n");
        }
        else {
            fprintf(file, "STONE PAPER SCISSORS - STATISTICS\n");
            fprintf(file, "Player: %s\n", playerName);
            fprintf(file, "Matches: %d\n", totalMatches);
            fprintf(file, "Wins: %d\n", wins);
            fprintf(file, "Losses: %d\n", losses);
            fprintf(file, "Win Rate: %.2f%%\n", winRate);

            fclose(file);

            printf("\nStatistics saved to stats.txt\n");
        }

        printf("\nGame history saved to game_history.txt\n");

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("\nThanks for playing, %s! 👋\n", playerName);

    return 0;
}