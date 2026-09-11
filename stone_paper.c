#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10

/* ================= STRUCTURES ================= */

struct Player {
    char name[50];
    int wins;
    int losses;
    int xp;
    int level;
    int bestStreak;
};


/* ================= FUNCTION DECLARATIONS ================= */

void playGame(char playerName[], int *wins, int *losses,
              int *totalMatches, int *currentStreak, int *bestStreak,
              int *xp, int *level);

void twoPlayerMode();

void showStatistics(char playerName[], int wins, int losses,
                    int totalMatches, int currentStreak,
                    int bestStreak, int xp, int level);

void showRules();
void showHistory();

void resetStatistics(int *wins, int *losses, int *totalMatches,
                     int *currentStreak, int *bestStreak,
                     int *xp, int *level);

void loadStatistics(int *wins, int *losses, int *totalMatches,
                    int *currentStreak, int *bestStreak,
                    int *xp, int *level);

void saveStatistics(char playerName[], int wins, int losses,
                    int totalMatches, int currentStreak,
                    int bestStreak, int xp, int level);

void showAchievements(int wins, int currentStreak,
                      int bestStreak, int level);

int getComputerMove(int player, int difficulty);

void updateLeaderboard(char playerName[], int wins, int losses,
                       int xp, int level, int bestStreak);

void showLeaderboard();

int comparePlayers(const void *a, const void *b);


/* ================= MAIN ================= */

int main() {

    int choice;

    int wins = 0;
    int losses = 0;
    int totalMatches = 0;

    int currentStreak = 0;
    int bestStreak = 0;

    int xp = 0;
    int level = 1;

    char playerName[50];

    srand(time(NULL));


    printf("=================================\n");
    printf("     STONE PAPER SCISSORS\n");
    printf("=================================\n");

    printf("\nEnter your name: ");

    fgets(playerName, sizeof(playerName), stdin);

    playerName[strcspn(playerName, "\n")] = '\0';


    /* Load saved statistics */

    loadStatistics(&wins,
                   &losses,
                   &totalMatches,
                   &currentStreak,
                   &bestStreak,
                   &xp,
                   &level);


    if (totalMatches > 0) {

        printf("\nPrevious statistics loaded!\n");

        printf("Matches: %d | Wins: %d | Losses: %d\n",
               totalMatches, wins, losses);

        printf("Current Streak: %d | Best Streak: %d\n",
               currentStreak, bestStreak);

        printf("Level: %d | XP: %d\n",
               level, xp);
    }


    do {

        printf("\n=================================\n");
        printf("           MAIN MENU\n");
        printf("=================================\n");

        printf("Welcome, %s!\n", playerName);

        printf("Level %d | XP %d\n\n",
               level, xp);

        printf("1. Play Game\n");
        printf("2. Two Player Mode\n");
        printf("3. Statistics\n");
        printf("4. Game History\n");
        printf("5. Rules\n");
        printf("6. Achievements\n");
        printf("7. Leaderboard\n");
        printf("8. Reset Statistics\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);


        switch (choice) {

            case 1:

                playGame(playerName,
                         &wins,
                         &losses,
                         &totalMatches,
                         &currentStreak,
                         &bestStreak,
                         &xp,
                         &level);

                break;


            case 2:

                twoPlayerMode();

                break;


            case 3:

                showStatistics(playerName,
                               wins,
                               losses,
                               totalMatches,
                               currentStreak,
                               bestStreak,
                               xp,
                               level);

                break;


            case 4:

                showHistory();

                break;


            case 5:

                showRules();

                break;


            case 6:

                showAchievements(wins,
                                 currentStreak,
                                 bestStreak,
                                 level);

                break;


            case 7:

                showLeaderboard();

                break;


            case 8:

                resetStatistics(&wins,
                                &losses,
                                &totalMatches,
                                &currentStreak,
                                &bestStreak,
                                &xp,
                                &level);

                break;


            case 9:

                printf("\nThanks for playing, %s!\n",
                       playerName);

                printf("Final Level: %d\n", level);
                printf("Final XP: %d\n", xp);

                printf("Goodbye!\n");

                break;


            default:

                printf("\nInvalid choice! Please choose 1-9.\n");
        }

    } while (choice != 9);


    return 0;
}


/* ================================================= */
/*                  COMPUTER GAME                    */
/* ================================================= */

void playGame(char playerName[],
              int *wins,
              int *losses,
              int *totalMatches,
              int *currentStreak,
              int *bestStreak,
              int *xp,
              int *level) {

    int player;
    int computer;

    int playerScore;
    int computerScore;

    int mode;
    int winningScore;

    int difficulty;

    char again;


    do {

        playerScore = 0;
        computerScore = 0;


        printf("\n=================================\n");
        printf("          START GAME\n");
        printf("=================================\n");


        /* ================= DIFFICULTY ================= */

        printf("\nChoose Difficulty:\n");

        printf("1. Easy\n");
        printf("2. Medium\n");
        printf("3. Hard\n");

        printf("\nEnter difficulty: ");
        scanf("%d", &difficulty);


        if (difficulty < 1 || difficulty > 3) {

            printf("\nInvalid difficulty!\n");
            printf("Defaulting to Easy.\n");

            difficulty = 1;
        }


        printf("\nDifficulty: ");

        if (difficulty == 1)
            printf("EASY\n");

        else if (difficulty == 2)
            printf("MEDIUM\n");

        else
            printf("HARD\n");


        /* ================= GAME MODE ================= */

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


            if (difficulty == 1)
                fprintf(history,
                        "Difficulty: Easy\n");

            else if (difficulty == 2)
                fprintf(history,
                        "Difficulty: Medium\n");

            else
                fprintf(history,
                        "Difficulty: Hard\n");


            if (winningScore == 2)
                fprintf(history,
                        "Mode: Best of 3\n");

            else
                fprintf(history,
                        "Mode: Best of 5\n");


            fprintf(history,
                    "=================================\n");
        }


        /* ================= GAME LOOP ================= */

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


            computer = getComputerMove(player, difficulty);


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


            /* ================= RESULT ================= */

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


        /* ================= MATCH RESULT ================= */

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

            printf("\nYOU WIN THE MATCH!\n");

            (*wins)++;

            (*currentStreak)++;


            if (*currentStreak > *bestStreak) {

                *bestStreak = *currentStreak;

                printf("NEW BEST STREAK: %d!\n",
                       *bestStreak);
            }


            *xp += 100;

            printf("+100 XP!\n");


            int newLevel = (*xp / 500) + 1;


            if (newLevel > *level) {

                *level = newLevel;

                printf("\nLEVEL UP!\n");

                printf("You are now Level %d!\n",
                       *level);
            }


            if (history != NULL)
                fprintf(history,
                        "FINAL RESULT: %s WON\n",
                        playerName);
        }


        /* ================= PLAYER LOSES ================= */

        else {

            printf("\nCOMPUTER WINS THE MATCH!\n");

            (*losses)++;


            if (*currentStreak > 0) {

                printf("Your %d-match streak ended!\n",
                       *currentStreak);
            }


            *currentStreak = 0;


            if (*xp >= 25)
                *xp -= 25;

            else
                *xp = 0;


            printf("-25 XP\n");


            *level = (*xp / 500) + 1;


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
                    "Current Streak: %d\n",
                    *currentStreak);

            fprintf(history,
                    "Level: %d\n",
                    *level);

            fprintf(history,
                    "XP: %d\n",
                    *xp);

            fclose(history);
        }


        saveStatistics(playerName,
                       *wins,
                       *losses,
                       *totalMatches,
                       *currentStreak,
                       *bestStreak,
                       *xp,
                       *level);


        updateLeaderboard(playerName,
                          *wins,
                          *losses,
                          *xp,
                          *level,
                          *bestStreak);


        printf("\nGame saved.");
        printf("\nLeaderboard updated!");

        printf("\nCurrent XP: %d",
               *xp);

        printf("\nCurrent Level: %d\n",
               *level);


        printf("\nPlay another match? (y/n): ");

        scanf(" %c", &again);


    } while (again == 'y' || again == 'Y');
}


/* ================================================= */
/*                  TWO PLAYER MODE                  */
/* ================================================= */

void twoPlayerMode() {

    char player1[50];
    char player2[50];

    int player1Move;
    int player2Move;

    int player1Score;
    int player2Score;

    int mode;
    int winningScore;

    char again;


    do {

        player1Score = 0;
        player2Score = 0;


        printf("\n=================================\n");
        printf("         TWO PLAYER MODE\n");
        printf("=================================\n");


        /* ================= PLAYER NAMES ================= */

        printf("\nEnter Player 1 name: ");

        scanf(" %49[^\n]", player1);


        printf("Enter Player 2 name: ");

        scanf(" %49[^\n]", player2);


        /* ================= GAME MODE ================= */

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

            printf("\nInvalid choice!");
            printf(" Starting Best of 3.\n");

            winningScore = 2;
        }


        /* ================= HISTORY ================= */

        FILE *history = fopen("game_history.txt", "a");


        if (history != NULL) {

            fprintf(history,
                    "\n=================================\n");

            fprintf(history,
                    "TWO PLAYER MATCH\n");

            fprintf(history,
                    "Player 1: %s\n",
                    player1);

            fprintf(history,
                    "Player 2: %s\n",
                    player2);


            if (winningScore == 2)
                fprintf(history,
                        "Mode: Best of 3\n");

            else
                fprintf(history,
                        "Mode: Best of 5\n");

            fprintf(history,
                    "=================================\n");
        }


        /* ================= GAME LOOP ================= */

        while (player1Score < winningScore &&
               player2Score < winningScore) {


            /* ================= PLAYER 1 ================= */

            printf("\n---------------------------------\n");
            printf("%s's Turn\n",
                   player1);

            printf("---------------------------------\n");

            printf("1. Stone\n");
            printf("2. Paper\n");
            printf("3. Scissors\n");

            printf("Enter your choice: ");

            scanf("%d", &player1Move);


            if (player1Move < 1 ||
                player1Move > 3) {

                printf("\nInvalid choice!");

                continue;
            }


            /* Hide Player 1's move */

            printf("\n\n\n\n\n\n\n\n\n\n");

            printf("---------------------------------\n");
            printf("%s's Turn\n",
                   player2);

            printf("---------------------------------\n");

            printf("1. Stone\n");
            printf("2. Paper\n");
            printf("3. Scissors\n");

            printf("Enter your choice: ");

            scanf("%d", &player2Move);


            if (player2Move < 1 ||
                player2Move > 3) {

                printf("\nInvalid choice!");

                continue;
            }


            /* ================= SHOW MOVES ================= */

            printf("\n=================================\n");
            printf("             ROUND\n");
            printf("=================================\n");


            printf("%s chose: ",
                   player1);

            if (player1Move == 1)
                printf("Stone\n");

            else if (player1Move == 2)
                printf("Paper\n");

            else
                printf("Scissors\n");


            printf("%s chose: ",
                   player2);

            if (player2Move == 1)
                printf("Stone\n");

            else if (player2Move == 2)
                printf("Paper\n");

            else
                printf("Scissors\n");


            /* ================= RESULT ================= */

            if (player1Move == player2Move) {

                printf("\nResult: DRAW!\n");

                if (history != NULL)
                    fprintf(history,
                            "Round: DRAW\n");
            }


            else if ((player1Move == 1 &&
                      player2Move == 3) ||

                     (player1Move == 2 &&
                      player2Move == 1) ||

                     (player1Move == 3 &&
                      player2Move == 2)) {

                printf("\n%s WINS THE ROUND!\n",
                       player1);

                player1Score++;


                if (history != NULL)
                    fprintf(history,
                            "Round Winner: %s\n",
                            player1);
            }


            else {

                printf("\n%s WINS THE ROUND!\n",
                       player2);

                player2Score++;


                if (history != NULL)
                    fprintf(history,
                            "Round Winner: %s\n",
                            player2);
            }


            printf("\nScore:\n");

            printf("%s: %d\n",
                   player1,
                   player1Score);

            printf("%s: %d\n",
                   player2,
                   player2Score);
        }


        /* ================= FINAL RESULT ================= */

        printf("\n=================================\n");
        printf("         MATCH RESULT\n");
        printf("=================================\n");


        printf("%s: %d\n",
               player1,
               player1Score);

        printf("%s: %d\n",
               player2,
               player2Score);


        if (player1Score > player2Score) {

            printf("\n🏆 %s WINS THE MATCH!\n",
                   player1);


            if (history != NULL)
                fprintf(history,
                        "FINAL WINNER: %s\n",
                        player1);
        }

        else {

            printf("\n🏆 %s WINS THE MATCH!\n",
                   player2);


            if (history != NULL)
                fprintf(history,
                        "FINAL WINNER: %s\n",
                        player2);
        }


        if (history != NULL) {

            fprintf(history,
                    "Final Score: %s %d - %s %d\n",
                    player1,
                    player1Score,
                    player2,
                    player2Score);

            fprintf(history,
                    "=================================\n");

            fclose(history);
        }


        printf("\nTwo-player match saved to history.");


        printf("\n\nPlay another two-player match? (y/n): ");

        scanf(" %c", &again);


    } while (again == 'y' || again == 'Y');
}


/* ================================================= */
/*                  COMPUTER AI                      */
/* ================================================= */

int getComputerMove(int player, int difficulty) {

    int randomMove;
    int chance;


    if (difficulty == 1) {

        return (rand() % 3) + 1;
    }


    else if (difficulty == 2) {

        chance = rand() % 100;


        if (chance < 50)
            return (rand() % 3) + 1;


        if (player == 1)
            return 2;

        else if (player == 2)
            return 3;

        else
            return 1;
    }


    else {

        chance = rand() % 100;


        if (chance < 75) {

            if (player == 1)
                return 2;

            else if (player == 2)
                return 3;

            else
                return 1;
        }


        randomMove = (rand() % 3) + 1;

        return randomMove;
    }
}


/* ================================================= */
/*                  SAVE STATISTICS                  */
/* ================================================= */

void saveStatistics(char playerName[],
                    int wins,
                    int losses,
                    int totalMatches,
                    int currentStreak,
                    int bestStreak,
                    int xp,
                    int level) {

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

        fprintf(file,
                "XP: %d\n",
                xp);

        fprintf(file,
                "Level: %d\n",
                level);


        fclose(file);
    }
}


/* ================================================= */
/*                  LOAD STATISTICS                  */
/* ================================================= */

void loadStatistics(int *wins,
                    int *losses,
                    int *totalMatches,
                    int *currentStreak,
                    int *bestStreak,
                    int *xp,
                    int *level) {

    FILE *file;

    char line[200];


    file = fopen("stats.txt", "r");


    if (file == NULL)
        return;


    while (fgets(line,
                  sizeof(line),
                  file) != NULL) {


        if (sscanf(line,
                   "Matches: %d",
                   totalMatches) == 1)
            continue;


        if (sscanf(line,
                   "Wins: %d",
                   wins) == 1)
            continue;


        if (sscanf(line,
                   "Losses: %d",
                   losses) == 1)
            continue;


        if (sscanf(line,
                   "Current Streak: %d",
                   currentStreak) == 1)
            continue;


        if (sscanf(line,
                   "Best Streak: %d",
                   bestStreak) == 1)
            continue;


        if (sscanf(line,
                   "XP: %d",
                   xp) == 1)
            continue;


        if (sscanf(line,
                   "Level: %d",
                   level) == 1)
            continue;
    }


    fclose(file);
}


/* ================================================= */
/*                  STATISTICS                       */
/* ================================================= */

void showStatistics(char playerName[],
                    int wins,
                    int losses,
                    int totalMatches,
                    int currentStreak,
                    int bestStreak,
                    int xp,
                    int level) {

    float winRate = 0;


    if (totalMatches > 0)
        winRate =
            ((float)wins / totalMatches) * 100;


    printf("\n=================================\n");
    printf("          STATISTICS\n");
    printf("=================================\n");


    printf("Player: %s\n", playerName);

    printf("Matches: %d\n", totalMatches);

    printf("Wins: %d\n", wins);

    printf("Losses: %d\n", losses);

    printf("Win Rate: %.2f%%\n", winRate);

    printf("Current Win Streak: %d\n",
           currentStreak);

    printf("Best Win Streak: %d\n",
           bestStreak);

    printf("XP: %d\n", xp);

    printf("Level: %d\n", level);

    printf("\nXP needed for next level: %d\n",
           (level * 500) - xp);
}


/* ================================================= */
/*                  ACHIEVEMENTS                     */
/* ================================================= */

void showAchievements(int wins,
                      int currentStreak,
                      int bestStreak,
                      int level) {

    printf("\n=================================\n");
    printf("          ACHIEVEMENTS\n");
    printf("=================================\n");


    if (wins >= 1)
        printf("[UNLOCKED] First Victory\n");
    else
        printf("[LOCKED] First Victory\n");


    if (bestStreak >= 3)
        printf("[UNLOCKED] 3-Win Streak\n");
    else
        printf("[LOCKED] 3-Win Streak\n");


    if (bestStreak >= 5)
        printf("[UNLOCKED] 5-Win Streak\n");
    else
        printf("[LOCKED] 5-Win Streak\n");


    if (bestStreak >= 10)
        printf("[UNLOCKED] 10-Win Streak\n");
    else
        printf("[LOCKED] 10-Win Streak\n");


    if (level >= 5)
        printf("[UNLOCKED] Level 5\n");
    else
        printf("[LOCKED] Level 5\n");


    if (level >= 10)
        printf("[UNLOCKED] Level 10\n");
    else
        printf("[LOCKED] Level 10\n");


    printf("\nCurrent Streak: %d\n",
           currentStreak);

    printf("Best Streak: %d\n",
           bestStreak);

    printf("Current Level: %d\n",
           level);
}


/* ================================================= */
/*                  RULES                            */
/* ================================================= */

void showRules() {

    printf("\n=================================\n");
    printf("             RULES\n");
    printf("=================================\n");


    printf("\nStone beats Scissors\n");
    printf("Paper beats Stone\n");
    printf("Scissors beats Paper\n");

    printf("\nSame choice = DRAW\n");


    printf("\nBest of 3:\n");
    printf("First player to reach 2 round wins wins.\n");


    printf("\nBest of 5:\n");
    printf("First player to reach 3 round wins wins.\n");


    printf("\nXP SYSTEM:\n");
    printf("+100 XP for a match victory\n");
    printf("-25 XP for a match loss\n");
    printf("500 XP = 1 Level\n");


    printf("\nDIFFICULTY:\n");
    printf("Easy   - Random computer moves\n");
    printf("Medium - 50%% chance to counter\n");
    printf("Hard   - 75%% chance to counter\n");


    printf("\nTWO PLAYER MODE:\n");
    printf("Player 1 competes against Player 2.\n");
    printf("Both players choose their moves manually.\n");


    printf("\nLEADERBOARD:\n");
    printf("Top 10 players are ranked by XP.\n");
}


/* ================================================= */
/*                  GAME HISTORY                     */
/* ================================================= */

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


    while (fgets(line,
                  sizeof(line),
                  history) != NULL) {

        printf("%s", line);
    }


    fclose(history);
}


/* ================================================= */
/*                  RESET STATISTICS                 */
/* ================================================= */

void resetStatistics(int *wins,
                     int *losses,
                     int *totalMatches,
                     int *currentStreak,
                     int *bestStreak,
                     int *xp,
                     int *level) {

    char confirm;


    printf("\nAre you sure you want to reset statistics? (y/n): ");

    scanf(" %c", &confirm);


    if (confirm == 'y' || confirm == 'Y') {

        *wins = 0;
        *losses = 0;
        *totalMatches = 0;

        *currentStreak = 0;
        *bestStreak = 0;

        *xp = 0;
        *level = 1;


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


/* ================================================= */
/*                  LEADERBOARD                      */
/* ================================================= */

int comparePlayers(const void *a,
                    const void *b) {

    struct Player *playerA =
        (struct Player *)a;

    struct Player *playerB =
        (struct Player *)b;


    return playerB->xp - playerA->xp;
}


/* ================= UPDATE LEADERBOARD ================= */

void updateLeaderboard(char playerName[],
                       int wins,
                       int losses,
                       int xp,
                       int level,
                       int bestStreak) {

    struct Player players[MAX_PLAYERS + 1];

    int count = 0;
    int found = 0;

    int i;

    FILE *file;


    file = fopen("leaderboard.txt", "r");


    if (file != NULL) {

        while (count < MAX_PLAYERS &&
               fscanf(file,
                      "%49[^|]|%d|%d|%d|%d|%d\n",
                      players[count].name,
                      &players[count].wins,
                      &players[count].losses,
                      &players[count].xp,
                      &players[count].level,
                      &players[count].bestStreak) == 6) {

            count++;
        }


        fclose(file);
    }


    for (i = 0; i < count; i++) {

        if (strcmp(players[i].name,
                   playerName) == 0) {

            players[i].wins = wins;
            players[i].losses = losses;
            players[i].xp = xp;
            players[i].level = level;
            players[i].bestStreak = bestStreak;

            found = 1;

            break;
        }
    }


    if (!found) {

        if (count < MAX_PLAYERS + 1) {

            strcpy(players[count].name,
                   playerName);

            players[count].wins = wins;
            players[count].losses = losses;
            players[count].xp = xp;
            players[count].level = level;
            players[count].bestStreak = bestStreak;

            count++;
        }
    }


    qsort(players,
          count,
          sizeof(struct Player),
          comparePlayers);


    if (count > MAX_PLAYERS)
        count = MAX_PLAYERS;


    file = fopen("leaderboard.txt", "w");


    if (file != NULL) {

        for (i = 0; i < count; i++) {

            fprintf(file,
                    "%s|%d|%d|%d|%d|%d\n",
                    players[i].name,
                    players[i].wins,
                    players[i].losses,
                    players[i].xp,
                    players[i].level,
                    players[i].bestStreak);
        }


        fclose(file);
    }
}


/* ================= SHOW LEADERBOARD ================= */

void showLeaderboard() {

    struct Player players[MAX_PLAYERS];

    int count = 0;

    int i;

    FILE *file;


    file = fopen("leaderboard.txt", "r");


    if (file == NULL) {

        printf("\n=================================\n");
        printf("          LEADERBOARD\n");
        printf("=================================\n");

        printf("\nNo leaderboard data found yet.\n");

        printf("Play a game to enter the leaderboard!\n");

        return;
    }


    while (count < MAX_PLAYERS &&
           fscanf(file,
                  "%49[^|]|%d|%d|%d|%d|%d\n",
                  players[count].name,
                  &players[count].wins,
                  &players[count].losses,
                  &players[count].xp,
                  &players[count].level,
                  &players[count].bestStreak) == 6) {

        count++;
    }


    fclose(file);


    qsort(players,
          count,
          sizeof(struct Player),
          comparePlayers);


    printf("\n");
    printf("===============================================================\n");
    printf("                     LEADERBOARD\n");
    printf("===============================================================\n");

    printf("%-5s %-20s %-8s %-8s %-8s %-8s\n",
           "Rank",
           "Player",
           "XP",
           "Level",
           "Wins",
           "Streak");

    printf("---------------------------------------------------------------\n");


    for (i = 0; i < count; i++) {

        printf("%-5d %-20s %-8d %-8d %-8d %-8d\n",
               i + 1,
               players[i].name,
               players[i].xp,
               players[i].level,
               players[i].wins,
               players[i].bestStreak);
    }


    printf("===============================================================\n");

    printf("\nRanking is based on XP.\n");
}