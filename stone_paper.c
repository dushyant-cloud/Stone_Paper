#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void playGame(char playerName[], int *wins, int *losses,
              int *totalMatches, int *currentStreak, int *bestStreak);

void showStatistics(char playerName[], int wins, int losses,
                    int totalMatches, int currentStreak, int bestStreak);

void showRules();
void showHistory();

void resetStatistics(int *wins, int *losses, int *totalMatches,
                     int *currentStreak, int *bestStreak);

void loadStatistics(int *wins, int *losses, int *totalMatches,
                    int *currentStreak, int *bestStreak);

void saveStatistics(char playerName[], int wins, int losses,
                    int totalMatches, int currentStreak, int bestStreak);

void showAchievements(int wins, int currentStreak, int bestStreak);


/* ================= MAIN ================= */

int main() {

    int choice;

    int wins = 0;
    int losses = 0;
    int totalMatches = 0;

    int currentStreak = 0;
    int bestStreak = 0;

    char playerName[50];

    srand(time(NULL));

    printf("=================================\n");
    printf("     STONE PAPER SCISSORS\n");
    printf("=================================\n");

    printf("\nEnter your name: ");

    fgets(playerName, sizeof(playerName), stdin);

    playerName[strcspn(playerName, "\n")] = '\0';


    /* Load previous statistics */

    loadStatistics(&wins,
                   &losses,
                   &totalMatches,
                   &currentStreak,
                   &bestStreak);


    if (totalMatches > 0) {

        printf("\n✅ Previous statistics loaded!\n");

        printf("Matches: %d | Wins: %d | Losses: %d\n",
               totalMatches,
               wins,
               losses);

        printf("Current Streak: %d | Best Streak: %d\n",
               currentStreak,
               bestStreak);
    }


    do {

        printf("\n=================================\n");
        printf("           MAIN MENU\n");
        printf("=================================\n");

        printf("Welcome, %s! 👋\n\n", playerName);

        printf("1. 🎮 Play Game\n");
        printf("2. 📊 Statistics\n");
        printf("3. 📜 Game History\n");
        printf("4. 📖 Rules\n");
        printf("5. 🏆 Achievements\n");
        printf("6. 🔄 Reset Statistics\n");
        printf("7. 🚪 Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch (choice) {

            case 1:

                playGame(playerName,
                         &wins,
                         &losses,
                         &totalMatches,
                         &currentStreak,
                         &bestStreak);

                break;


            case 2:

                showStatistics(playerName,
                               wins,
                               losses,
                               totalMatches,
                               currentStreak,
                               bestStreak);

                break;


            case 3:

                showHistory();

                break;


            case 4:

                showRules();

                break;


            case 5:

                showAchievements(wins,
                                 currentStreak,
                                 bestStreak);

                break;


            case 6:

                resetStatistics(&wins,
                                &losses,
                                &totalMatches,
                                &currentStreak,
                                &bestStreak);

                break;


            case 7:

                printf("\nThanks for playing, %s! 👋\n",
                       playerName);

                printf("Goodbye!\n");

                break;


            default:

                printf("\n❌ Invalid choice! Please choose 1-7.\n");
        }

    } while (choice != 7);


    return 0;
}


/* ================= PLAY GAME ================= */

void playGame(char playerName[],
              int *wins,
              int *losses,
              int *totalMatches,
              int *currentStreak,
              int *bestStreak) {

    int player;
    int computer;

    int playerScore;
    int computerScore;

    int mode;
    int winningScore;

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

            fprintf(history,
                    "\n=================================\n");

            fprintf(history,
                    "Player: %s\n",
                    playerName);

            if (winningScore == 2)
                fprintf(history,
                        "Mode: Best of 3\n");
            else
                fprintf(history,
                        "Mode: Best of 5\n");

            fprintf(history,
                    "=================================\n");
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

                printf("\n❌ Invalid choice! Try again.\n");

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


        printf("%s: %d\n",
               playerName,
               playerScore);

        printf("Computer: %d\n",
               computerScore);


        /* ================= PLAYER WINS ================= */

        if (playerScore > computerScore) {

            printf("\n🎉 YOU WIN THE MATCH!\n");

            (*wins)++;

            /* Increase current streak */

            (*currentStreak)++;


            /* Update best streak */

            if (*currentStreak > *bestStreak) {

                *bestStreak = *currentStreak;

                printf("🔥 NEW BEST WIN STREAK: %d!\n",
                       *bestStreak);
            }

            else {

                printf("🔥 Current Win Streak: %d\n",
                       *currentStreak);
            }


            if (history != NULL)
                fprintf(history,
                        "FINAL RESULT: %s WON\n",
                        playerName);
        }


        /* ================= PLAYER LOSES ================= */

        else {

            printf("\n💻 COMPUTER WINS THE MATCH!\n");

            (*losses)++;


            if (*currentStreak > 0) {

                printf("💔 Your %d-match win streak ended!\n",
                       *currentStreak);
            }


            /* Reset current streak */

            *currentStreak = 0;


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

            fprintf(history,
                    "Current Win Streak: %d\n",
                    *currentStreak);

            fclose(history);
        }


        /* Save statistics */

        saveStatistics(playerName,
                       *wins,
                       *losses,
                       *totalMatches,
                       *currentStreak,
                       *bestStreak);


        printf("\nGame saved to game_history.txt");
        printf("\nStatistics saved to stats.txt");


        /* Achievement notification */

        if (*currentStreak == 3) {

            printf("\n🏆 ACHIEVEMENT UNLOCKED!");
            printf("\n🔥 3-Win Streak!");
        }

        else if (*currentStreak == 5) {

            printf("\n🏆 ACHIEVEMENT UNLOCKED!");
            printf("\n🔥 5-Win Streak!");
        }

        else if (*currentStreak == 10) {

            printf("\n🏆 ACHIEVEMENT UNLOCKED!");
            printf("\n🔥 10-Win Streak!");
        }


        printf("\n\nPlay another match? (y/n): ");

        scanf(" %c", &again);


    } while (again == 'y' || again == 'Y');
}


/* ================= SAVE STATISTICS ================= */

void saveStatistics(char playerName[],
                    int wins,
                    int losses,
                    int totalMatches,
                    int currentStreak,
                    int bestStreak) {

    FILE *file;

    file = fopen("stats.txt", "w");


    if (file != NULL) {

        float winRate = 0;


        if (totalMatches > 0)
            winRate =
                ((float)wins / totalMatches) * 100;


        fprintf(file,
                "STONE PAPER SCISSORS - STATISTICS\n");

        fprintf(file,
                "Player: %s\n",
                playerName);

        fprintf(file,
                "Matches: %d\n",
                totalMatches);

        fprintf(file,
                "Wins: %d\n",
                wins);

        fprintf(file,
                "Losses: %d\n",
                losses);

        fprintf(file,
                "Win Rate: %.2f%%\n",
                winRate);

        fprintf(file,
                "Current Streak: %d\n",
                currentStreak);

        fprintf(file,
                "Best Streak: %d\n",
                bestStreak);


        fclose(file);
    }
}


/* ================= LOAD STATISTICS ================= */

void loadStatistics(int *wins,
                    int *losses,
                    int *totalMatches,
                    int *currentStreak,
                    int *bestStreak) {

    FILE *file;

    char line[200];


    file = fopen("stats.txt", "r");


    if (file == NULL) {

        return;
    }


    while (fgets(line,
                  sizeof(line),
                  file) != NULL) {


        if (sscanf(line,
                   "Matches: %d",
                   totalMatches) == 1) {

            continue;
        }


        if (sscanf(line,
                   "Wins: %d",
                   wins) == 1) {

            continue;
        }


        if (sscanf(line,
                   "Losses: %d",
                   losses) == 1) {

            continue;
        }


        if (sscanf(line,
                   "Current Streak: %d",
                   currentStreak) == 1) {

            continue;
        }


        if (sscanf(line,
                   "Best Streak: %d",
                   bestStreak) == 1) {

            continue;
        }
    }


    fclose(file);
}


/* ================= STATISTICS ================= */

void showStatistics(char playerName[],
                    int wins,
                    int losses,
                    int totalMatches,
                    int currentStreak,
                    int bestStreak) {

    float winRate = 0;


    if (totalMatches > 0)
        winRate =
            ((float)wins / totalMatches) * 100;


    printf("\n=================================\n");
    printf("          STATISTICS\n");
    printf("=================================\n");


    printf("Player: %s\n",
           playerName);

    printf("Matches: %d\n",
           totalMatches);

    printf("Wins: %d\n",
           wins);

    printf("Losses: %d\n",
           losses);

    printf("Win Rate: %.2f%%\n",
           winRate);

    printf("🔥 Current Win Streak: %d\n",
           currentStreak);

    printf("🏆 Best Win Streak: %d\n",
           bestStreak);
}


/* ================= ACHIEVEMENTS ================= */

void showAchievements(int wins,
                      int currentStreak,
                      int bestStreak) {

    printf("\n=================================\n");
    printf("          ACHIEVEMENTS\n");
    printf("=================================\n");


    /* First Win */

    if (wins >= 1)
        printf("🏆 [UNLOCKED] First Victory\n");
    else
        printf("🔒 [LOCKED] First Victory - Win 1 match\n");


    /* 3 Win Streak */

    if (bestStreak >= 3)
        printf("🔥 [UNLOCKED] 3-Win Streak\n");
    else
        printf("🔒 [LOCKED] 3-Win Streak - Win 3 matches in a row\n");


    /* 5 Win Streak */

    if (bestStreak >= 5)
        printf("🔥 [UNLOCKED] 5-Win Streak\n");
    else
        printf("🔒 [LOCKED] 5-Win Streak - Win 5 matches in a row\n");


    /* 10 Win Streak */

    if (bestStreak >= 10)
        printf("🔥 [UNLOCKED] 10-Win Streak\n");
    else
        printf("🔒 [LOCKED] 10-Win Streak - Win 10 matches in a row\n");


    printf("\nCurrent Streak: %d\n",
           currentStreak);

    printf("Best Streak: %d\n",
           bestStreak);
}


/* ================= RULES ================= */

void showRules() {

    printf("\n=================================\n");
    printf("             RULES\n");
    printf("=================================\n");


    printf("\n🪨 Stone beats Scissors\n");
    printf("📄 Paper beats Stone\n");
    printf("✂️ Scissors beats Paper\n");


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

        printf("\n📜 No game history found.\n");

        return;
    }


    printf("\n=================================\n");
    printf("          GAME HISTORY\n");
    printf("=================================\n");


    while (fgets(line,
                  sizeof(line),
                  history) != NULL) {

        printf("%s", line);
    }


    fclose(history);
}


/* ================= RESET STATISTICS ================= */

void resetStatistics(int *wins,
                     int *losses,
                     int *totalMatches,
                     int *currentStreak,
                     int *bestStreak) {

    char confirm;


    printf("\nAre you sure you want to reset statistics? (y/n): ");

    scanf(" %c", &confirm);


    if (confirm == 'y' || confirm == 'Y') {

        *wins = 0;
        *losses = 0;
        *totalMatches = 0;

        *currentStreak = 0;
        *bestStreak = 0;


        FILE *file = fopen("stats.txt", "w");


        if (file != NULL) {

            fprintf(file,
                    "STONE PAPER SCISSORS - STATISTICS\n");

            fprintf(file,
                    "Statistics have been reset.\n");

            fclose(file);
        }


        printf("\n✅ Statistics reset successfully!\n");
    }

    else {

        printf("\nReset cancelled.\n");
    }
}