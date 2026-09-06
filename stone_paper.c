#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void playGame(char playerName[], int *wins, int *losses, int *totalMatches);
void showStatistics(char playerName[], int wins, int losses, int totalMatches);
void showRules();
void showHistory();
void resetStatistics(int *wins, int *losses, int *totalMatches);

int main() {
    int choice;
    int wins = 0;
    int losses = 0;
    int totalMatches = 0;

    char playerName[50];

    srand(time(NULL));

    printf("=================================\n");
    printf("     STONE PAPER SCISSORS\n");
    printf("=================================\n");

    printf("\nEnter your name: ");
    fgets(playerName, sizeof(playerName), stdin);

    playerName[strcspn(playerName, "\n")] = '\0';

    do {
        printf("\n=================================\n");
        printf("           MAIN MENU\n");
        printf("=================================\n");

        printf("Welcome, %s! 👋\n\n", playerName);

        printf("1. Play Game\n");
        printf("2. Statistics\n");
        printf("3. Game History\n");
        printf("4. Rules\n");
        printf("5. Reset Statistics\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                playGame(playerName, &wins, &losses, &totalMatches);
                break;

            case 2:
                showStatistics(playerName, wins, losses, totalMatches);
                break;

            case 3:
                showHistory();
                break;

            case 4:
                showRules();
                break;

            case 5:
                resetStatistics(&wins, &losses, &totalMatches);
                break;

            case 6:
                printf("\nThanks for playing, %s! 👋\n", playerName);
                printf("Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please choose 1-6.\n");
        }

    } while (choice != 6);

    return 0;
}


/* ================= PLAY GAME ================= */

void playGame(char playerName[], int *wins, int *losses, int *totalMatches) {

    int player, computer;
    int playerScore, computerScore;
    int mode, winningScore;
    char again;

    do {

        playerScore = 0;
        computerScore = 0;

        printf("\n=================================\n");
        printf("          START GAME\n");
        printf("=================================\n");

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
            printf("\nInvalid choice! Starting Best of 3.\n");
            winningScore = 2;
        }

        FILE *history = fopen("game_history.txt", "a");

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
                printf("\nInvalid choice! Try again.\n");
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

                if (history != NULL)
                    fprintf(history,
                            "Round: DRAW\n");
            }

            else if ((player == 1 && computer == 3) ||
                     (player == 2 && computer == 1) ||
                     (player == 3 && computer == 2)) {

                printf("Result: YOU WIN!\n");

                playerScore++;

                if (history != NULL)
                    fprintf(history,
                            "Round: YOU WIN\n");
            }

            else {

                printf("Result: COMPUTER WINS!\n");

                computerScore++;

                if (history != NULL)
                    fprintf(history,
                            "Round: COMPUTER WINS\n");
            }

            printf("\nScore -> %s: %d | Computer: %d\n",
                   playerName,
                   playerScore,
                   computerScore);
        }

        (*totalMatches)++;

        printf("\n=================================\n");
        printf("          MATCH RESULT\n");
        printf("=================================\n");

        printf("%s: %d\n", playerName, playerScore);
        printf("Computer: %d\n", computerScore);

        if (playerScore > computerScore) {

            printf("\n🎉 YOU WIN THE MATCH!\n");

            (*wins)++;

            if (history != NULL)
                fprintf(history,
                        "FINAL RESULT: %s WON\n",
                        playerName);
        }

        else {

            printf("\nCOMPUTER WINS THE MATCH!\n");

            (*losses)++;

            if (history != NULL)
                fprintf(history,
                        "FINAL RESULT: COMPUTER WON\n");
        }

        if (history != NULL) {
            fprintf(history,
                    "Final Score: %s %d - Computer %d\n",
                    playerName,
                    playerScore,
                    computerScore);

            fclose(history);
        }

        /* Save statistics */

        FILE *file = fopen("stats.txt", "w");

        if (file != NULL) {

            float winRate =
                ((float)(*wins) / (*totalMatches)) * 100;

            fprintf(file,
                    "STONE PAPER SCISSORS - STATISTICS\n");

            fprintf(file,
                    "Player: %s\n",
                    playerName);

            fprintf(file,
                    "Matches: %d\n",
                    *totalMatches);

            fprintf(file,
                    "Wins: %d\n",
                    *wins);

            fprintf(file,
                    "Losses: %d\n",
                    *losses);

            fprintf(file,
                    "Win Rate: %.2f%%\n",
                    winRate);

            fclose(file);
        }

        printf("\nGame saved to game_history.txt\n");

        printf("\nPlay another match? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');
}


/* ================= STATISTICS ================= */

void showStatistics(char playerName[],
                    int wins,
                    int losses,
                    int totalMatches) {

    float winRate = 0;

    if (totalMatches > 0)
        winRate = ((float)wins / totalMatches) * 100;

    printf("\n=================================\n");
    printf("          STATISTICS\n");
    printf("=================================\n");

    printf("Player: %s\n", playerName);
    printf("Matches: %d\n", totalMatches);
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);
    printf("Win Rate: %.2f%%\n", winRate);
}


/* ================= RULES ================= */

void showRules() {

    printf("\n=================================\n");
    printf("             RULES\n");
    printf("=================================\n");

    printf("\nStone beats Scissors\n");
    printf("Paper beats Stone\n");
    printf("Scissors beats Paper\n");

    printf("\nSame choice = DRAW\n");

    printf("\nBest of 3:\n");
    printf("First player to reach 2 wins wins the match.\n");

    printf("\nBest of 5:\n");
    printf("First player to reach 3 wins wins the match.\n");
}


/* ================= GAME HISTORY ================= */

void showHistory() {

    FILE *history;
    char line[200];

    history = fopen("game_history.txt", "r");

    if (history == NULL) {

        printf("\nNo game history found.\n");
        return;
    }

    printf("\n=================================\n");
    printf("          GAME HISTORY\n");
    printf("=================================\n");

    while (fgets(line, sizeof(line), history) != NULL) {
        printf("%s", line);
    }

    fclose(history);
}


/* ================= RESET STATISTICS ================= */

void resetStatistics(int *wins,
                     int *losses,
                     int *totalMatches) {

    char confirm;

    printf("\nAre you sure you want to reset statistics? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {

        *wins = 0;
        *losses = 0;
        *totalMatches = 0;

        FILE *file = fopen("stats.txt", "w");

        if (file != NULL) {
            fprintf(file,
                    "STONE PAPER SCISSORS - STATISTICS\n");
            fprintf(file,
                    "Statistics have been reset.\n");

            fclose(file);
        }

        printf("\nStatistics reset successfully!\n");
    }

    else {
        printf("\nReset cancelled.\n");
    }
}