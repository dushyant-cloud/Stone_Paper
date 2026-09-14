#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 20
#define NAME_SIZE 50
#define MAX_LEADERBOARD 10

/* =========================
   PLAYER PROFILE
   ========================= */

typedef struct {
    char name[NAME_SIZE];
    int wins;
    int losses;
    int matches;
    int xp;
    int level;
    int currentStreak;
    int bestStreak;
} PlayerProfile;

/* =========================
   GLOBAL VARIABLES
   ========================= */

PlayerProfile profiles[MAX_PLAYERS];
int profileCount = 0;
int activeProfile = -1;

/* =========================
   FUNCTION PROTOTYPES
   ========================= */

void loadProfiles();
void saveProfiles();
void createProfile();
void selectProfile();
void showProfiles();
void showCurrentProfile();
void profileMenu();

void playGame();
void twoPlayerMode();
void tournamentMode();

int getComputerMove(int player, int difficulty);
int getWinnerFromMoves(int player1, int player2);
int playTournamentMatch(char player1[], char player2[], int bestOf);

void showStatistics();
void showGameHistory();
void showRules();
void showAchievements();

void updateLeaderboard();
void showLeaderboard();

void resetProfileStatistics();

void saveHistory(char playerName[], char result[], int score1, int score2);

void clearInputBuffer();

/* =========================
   PROFILE SYSTEM
   ========================= */

void loadProfiles()
{
    FILE *file = fopen("profiles.txt", "r");

    if (file == NULL)
        return;

    profileCount = 0;

    while (profileCount < MAX_PLAYERS &&
           fscanf(file, " %49[^|]|%d|%d|%d|%d|%d|%d|%d",
                  profiles[profileCount].name,
                  &profiles[profileCount].wins,
                  &profiles[profileCount].losses,
                  &profiles[profileCount].matches,
                  &profiles[profileCount].xp,
                  &profiles[profileCount].level,
                  &profiles[profileCount].currentStreak,
                  &profiles[profileCount].bestStreak) == 8)
    {
        profileCount++;
    }

    fclose(file);
}

void saveProfiles()
{
    FILE *file = fopen("profiles.txt", "w");

    if (file == NULL)
    {
        printf("Error saving profiles!\n");
        return;
    }

    for (int i = 0; i < profileCount; i++)
    {
        fprintf(file, "%s|%d|%d|%d|%d|%d|%d|%d\n",
                profiles[i].name,
                profiles[i].wins,
                profiles[i].losses,
                profiles[i].matches,
                profiles[i].xp,
                profiles[i].level,
                profiles[i].currentStreak,
                profiles[i].bestStreak);
    }

    fclose(file);
}

void createProfile()
{
    if (profileCount >= MAX_PLAYERS)
    {
        printf("\nMaximum number of profiles reached!\n");
        return;
    }

    char name[NAME_SIZE];

    printf("\n==============================\n");
    printf("       CREATE PROFILE\n");
    printf("==============================\n");

    printf("Enter player name: ");
    scanf(" %49[^\n]", name);

    /* Check duplicate */
    for (int i = 0; i < profileCount; i++)
    {
        if (strcmp(profiles[i].name, name) == 0)
        {
            printf("\nA profile with this name already exists!\n");
            return;
        }
    }

    strcpy(profiles[profileCount].name, name);

    profiles[profileCount].wins = 0;
    profiles[profileCount].losses = 0;
    profiles[profileCount].matches = 0;
    profiles[profileCount].xp = 0;
    profiles[profileCount].level = 1;
    profiles[profileCount].currentStreak = 0;
    profiles[profileCount].bestStreak = 0;

    activeProfile = profileCount;
    profileCount++;

    saveProfiles();

    printf("\nProfile created successfully!\n");
    printf("Welcome, %s!\n", profiles[activeProfile].name);
}

void showProfiles()
{
    printf("\n==============================\n");
    printf("       AVAILABLE PROFILES\n");
    printf("==============================\n");

    if (profileCount == 0)
    {
        printf("No profiles found.\n");
        return;
    }

    for (int i = 0; i < profileCount; i++)
    {
        printf("%d. %s", i + 1, profiles[i].name);

        if (i == activeProfile)
            printf("  [ACTIVE]");

        printf("\n");
    }
}

void selectProfile()
{
    if (profileCount == 0)
    {
        printf("\nNo profiles available. Create one first.\n");
        return;
    }

    showProfiles();

    int choice;

    printf("\nSelect profile: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > profileCount)
    {
        printf("Invalid profile choice!\n");
        return;
    }

    activeProfile = choice - 1;

    printf("\nActive profile changed to: %s\n",
           profiles[activeProfile].name);
}

void showCurrentProfile()
{
    if (activeProfile == -1)
    {
        printf("\nNo active profile selected.\n");
        return;
    }

    PlayerProfile *p = &profiles[activeProfile];

    printf("\n====================================\n");
    printf("          PLAYER PROFILE\n");
    printf("====================================\n");

    printf("Player Name      : %s\n", p->name);
    printf("Matches Played   : %d\n", p->matches);
    printf("Wins             : %d\n", p->wins);
    printf("Losses           : %d\n", p->losses);
    printf("XP               : %d\n", p->xp);
    printf("Level            : %d\n", p->level);
    printf("Current Streak   : %d\n", p->currentStreak);
    printf("Best Streak      : %d\n", p->bestStreak);

    if (p->matches > 0)
    {
        float winRate =
            ((float)p->wins / p->matches) * 100;

        printf("Win Rate         : %.2f%%\n", winRate);
    }
    else
    {
        printf("Win Rate         : 0.00%%\n");
    }

    printf("====================================\n");
}

void profileMenu()
{
    int choice;

    while (1)
    {
        printf("\n====================================\n");
        printf("          PROFILE MANAGER\n");
        printf("====================================\n");

        printf("1. Create Profile\n");
        printf("2. Select Profile\n");
        printf("3. Show Profiles\n");
        printf("4. View Current Profile\n");
        printf("5. Back to Main Menu\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createProfile();
            break;

        case 2:
            selectProfile();
            break;

        case 3:
            showProfiles();
            break;

        case 4:
            showCurrentProfile();
            break;

        case 5:
            return;

        default:
            printf("Invalid choice!\n");
        }
    }
}

/* =========================
   COMPUTER AI
   ========================= */

int getComputerMove(int player, int difficulty)
{
    int randomMove;

    /*
       1 = Stone
       2 = Paper
       3 = Scissors
    */

    randomMove = (rand() % 3) + 1;

    if (difficulty == 1)
    {
        /* Easy = completely random */
        return randomMove;
    }

    if (difficulty == 2)
    {
        /* Medium = 50% counter */
        if (rand() % 2 == 0)
        {
            return (player % 3) + 1;
        }

        return randomMove;
    }

    /*
       Hard = 75% counter
    */

    if (rand() % 4 != 0)
    {
        return (player % 3) + 1;
    }

    return randomMove;
}

/* =========================
   WINNER CALCULATION
   ========================= */

int getWinnerFromMoves(int player1, int player2)
{
    if (player1 == player2)
        return 0;

    if ((player1 == 1 && player2 == 3) ||
        (player1 == 2 && player2 == 1) ||
        (player1 == 3 && player2 == 2))
    {
        return 1;
    }

    return 2;
}

/* =========================
   HISTORY
   ========================= */

void saveHistory(char playerName[], char result[],
                 int score1, int score2)
{
    FILE *file = fopen("game_history.txt", "a");

    if (file == NULL)
        return;

    fprintf(file,
            "Player: %s | Result: %s | Score: %d-%d\n",
            playerName,
            result,
            score1,
            score2);

    fclose(file);
}

void showGameHistory()
{
    FILE *file = fopen("game_history.txt", "r");

    printf("\n====================================\n");
    printf("           GAME HISTORY\n");
    printf("====================================\n");

    if (file == NULL)
    {
        printf("No game history available.\n");
        return;
    }

    char line[200];

    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line);
    }

    fclose(file);
}

/* =========================
   MAIN GAME
   ========================= */

void playGame()
{
    if (activeProfile == -1)
    {
        printf("\nPlease create/select a profile first!\n");
        return;
    }

    PlayerProfile *p = &profiles[activeProfile];

    int bestOf;
    int difficulty;
    int playerMove;
    int computerMove;
    int playerScore = 0;
    int computerScore = 0;

    printf("\n====================================\n");
    printf("             PLAY GAME\n");
    printf("====================================\n");

    printf("1. Best of 3\n");
    printf("2. Best of 5\n");

    printf("Choose format: ");
    scanf("%d", &bestOf);

    if (bestOf == 1)
        bestOf = 3;
    else if (bestOf == 2)
        bestOf = 5;
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    printf("\nDifficulty:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");

    printf("Choose difficulty: ");
    scanf("%d", &difficulty);

    if (difficulty < 1 || difficulty > 3)
    {
        printf("Invalid difficulty!\n");
        return;
    }

    int roundsNeeded = (bestOf / 2) + 1;

    while (playerScore < roundsNeeded &&
           computerScore < roundsNeeded)
    {
        printf("\n------------------------------------\n");
        printf("Choose your move:\n");
        printf("1. Stone\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("------------------------------------\n");

        printf("Your choice: ");
        scanf("%d", &playerMove);

        if (playerMove < 1 || playerMove > 3)
        {
            printf("Invalid move!\n");
            continue;
        }

        computerMove = getComputerMove(playerMove, difficulty);

        printf("\nComputer chose: ");

        if (computerMove == 1)
            printf("Stone\n");
        else if (computerMove == 2)
            printf("Paper\n");
        else
            printf("Scissors\n");

        int result =
            getWinnerFromMoves(playerMove, computerMove);

        if (result == 0)
        {
            printf("Round Draw!\n");
        }
        else if (result == 1)
        {
            printf("You won the round!\n");
            playerScore++;
        }
        else
        {
            printf("Computer won the round!\n");
            computerScore++;
        }

        printf("Score: %s %d - Computer %d\n",
               p->name,
               playerScore,
               computerScore);
    }

    p->matches++;

    if (playerScore > computerScore)
    {
        printf("\n====================================\n");
        printf("        🎉 YOU WON THE MATCH!\n");
        printf("====================================\n");

        p->wins++;
        p->currentStreak++;

        if (p->currentStreak > p->bestStreak)
            p->bestStreak = p->currentStreak;

        p->xp += 100;

        printf("+100 XP\n");
        saveHistory(p->name, "WIN",
                    playerScore, computerScore);
    }
    else
    {
        printf("\n====================================\n");
        printf("          YOU LOST THE MATCH\n");
        printf("====================================\n");

        p->losses++;
        p->currentStreak = 0;

        if (p->xp >= 25)
            p->xp -= 25;
        else
            p->xp = 0;

        printf("-25 XP\n");

        saveHistory(p->name, "LOSS",
                    playerScore, computerScore);
    }

    p->level = (p->xp / 500) + 1;

    saveProfiles();
    updateLeaderboard();

    printf("\nCurrent XP: %d\n", p->xp);
    printf("Current Level: %d\n", p->level);
}

/* =========================
   TWO PLAYER MODE
   ========================= */

void twoPlayerMode()
{
    char player1[NAME_SIZE];
    char player2[NAME_SIZE];

    int bestOf;
    int score1 = 0;
    int score2 = 0;

    printf("\n====================================\n");
    printf("           TWO PLAYER MODE\n");
    printf("====================================\n");

    printf("Player 1 name: ");
    scanf(" %49[^\n]", player1);

    printf("Player 2 name: ");
    scanf(" %49[^\n]", player2);

    printf("\n1. Best of 3\n");
    printf("2. Best of 5\n");

    printf("Choose format: ");
    scanf("%d", &bestOf);

    if (bestOf == 1)
        bestOf = 3;
    else if (bestOf == 2)
        bestOf = 5;
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    int needed = (bestOf / 2) + 1;

    while (score1 < needed && score2 < needed)
    {
        int move1, move2;

        printf("\n%s's turn\n", player1);

        printf("1. Stone\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");

        printf("Enter move: ");
        scanf("%d", &move1);

        if (move1 < 1 || move1 > 3)
        {
            printf("Invalid move!\n");
            continue;
        }

        /* Hide Player 1's move */
        for (int i = 0; i < 20; i++)
            printf("\n");

        printf("%s's turn\n", player2);

        printf("1. Stone\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");

        printf("Enter move: ");
        scanf("%d", &move2);

        if (move2 < 1 || move2 > 3)
        {
            printf("Invalid move!\n");
            continue;
        }

        int result =
            getWinnerFromMoves(move1, move2);

        if (result == 0)
        {
            printf("\nRound Draw!\n");
        }
        else if (result == 1)
        {
            printf("\n%s wins the round!\n", player1);
            score1++;
        }
        else
        {
            printf("\n%s wins the round!\n", player2);
            score2++;
        }

        printf("Score: %s %d - %s %d\n",
               player1, score1,
               player2, score2);
    }

    printf("\n====================================\n");

    if (score1 > score2)
    {
        printf("🏆 %s WINS!\n", player1);
        saveHistory(player1, "TWO PLAYER WIN",
                    score1, score2);
    }
    else
    {
        printf("🏆 %s WINS!\n", player2);
        saveHistory(player2, "TWO PLAYER WIN",
                    score2, score1);
    }

    printf("====================================\n");
}

/* =========================
   TOURNAMENT MATCH
   ========================= */

int playTournamentMatch(char player1[],
                        char player2[],
                        int bestOf)
{
    int score1 = 0;
    int score2 = 0;

    int needed = (bestOf / 2) + 1;

    while (score1 < needed && score2 < needed)
    {
        int move1, move2;

        printf("\n%s's turn\n", player1);

        printf("1. Stone\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");

        printf("Enter move: ");
        scanf("%d", &move1);

        if (move1 < 1 || move1 > 3)
        {
            printf("Invalid move!\n");
            continue;
        }

        for (int i = 0; i < 20; i++)
            printf("\n");

        printf("%s's turn\n", player2);

        printf("1. Stone\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");

        printf("Enter move: ");
        scanf("%d", &move2);

        if (move2 < 1 || move2 > 3)
        {
            printf("Invalid move!\n");
            continue;
        }

        int result =
            getWinnerFromMoves(move1, move2);

        if (result == 0)
        {
            printf("Round Draw!\n");
        }
        else if (result == 1)
        {
            printf("%s wins the round!\n", player1);
            score1++;
        }
        else
        {
            printf("%s wins the round!\n", player2);
            score2++;
        }

        printf("Score: %s %d - %s %d\n",
               player1, score1,
               player2, score2);
    }

    if (score1 > score2)
        return 1;

    return 2;
}

/* =========================
   TOURNAMENT MODE
   ========================= */

void tournamentMode()
{
    char players[4][NAME_SIZE];

    char semifinal1Winner[NAME_SIZE];
    char semifinal2Winner[NAME_SIZE];
    char champion[NAME_SIZE];

    int bestOf;

    printf("\n====================================\n");
    printf("          TOURNAMENT MODE\n");
    printf("====================================\n");

    for (int i = 0; i < 4; i++)
    {
        printf("Enter Player %d name: ", i + 1);
        scanf(" %49[^\n]", players[i]);
    }

    printf("\n1. Best of 3\n");
    printf("2. Best of 5\n");

    printf("Choose format: ");
    scanf("%d", &bestOf);

    if (bestOf == 1)
        bestOf = 3;
    else if (bestOf == 2)
        bestOf = 5;
    else
    {
        printf("Invalid choice!\n");
        return;
    }

    printf("\n====================================\n");
    printf("          SEMI-FINAL 1\n");
    printf("====================================\n");

    int result1 =
        playTournamentMatch(players[0],
                            players[1],
                            bestOf);

    if (result1 == 1)
        strcpy(semifinal1Winner, players[0]);
    else
        strcpy(semifinal1Winner, players[1]);

    printf("\nSemi-Final 1 Winner: %s\n",
           semifinal1Winner);

    printf("\n====================================\n");
    printf("          SEMI-FINAL 2\n");
    printf("====================================\n");

    int result2 =
        playTournamentMatch(players[2],
                            players[3],
                            bestOf);

    if (result2 == 1)
        strcpy(semifinal2Winner, players[2]);
    else
        strcpy(semifinal2Winner, players[3]);

    printf("\nSemi-Final 2 Winner: %s\n",
           semifinal2Winner);

    printf("\n====================================\n");
    printf("             FINAL\n");
    printf("====================================\n");

    int finalResult =
        playTournamentMatch(semifinal1Winner,
                            semifinal2Winner,
                            bestOf);

    if (finalResult == 1)
        strcpy(champion, semifinal1Winner);
    else
        strcpy(champion, semifinal2Winner);

    printf("\n====================================\n");
    printf("        🏆 TOURNAMENT CHAMPION\n");
    printf("====================================\n");

    printf("          %s\n", champion);

    printf("====================================\n");

    saveHistory(champion,
                "TOURNAMENT CHAMPION",
                0, 0);
}

/* =========================
   STATISTICS
   ========================= */

void showStatistics()
{
    if (activeProfile == -1)
    {
        printf("\nPlease select a profile first!\n");
        return;
    }

    PlayerProfile *p = &profiles[activeProfile];

    printf("\n====================================\n");
    printf("           STATISTICS\n");
    printf("====================================\n");

    printf("Player           : %s\n", p->name);
    printf("Matches          : %d\n", p->matches);
    printf("Wins             : %d\n", p->wins);
    printf("Losses           : %d\n", p->losses);
    printf("Current Streak   : %d\n", p->currentStreak);
    printf("Best Streak      : %d\n", p->bestStreak);
    printf("XP               : %d\n", p->xp);
    printf("Level            : %d\n", p->level);

    if (p->matches > 0)
    {
        float winRate =
            ((float)p->wins / p->matches) * 100;

        printf("Win Rate         : %.2f%%\n",
               winRate);
    }
    else
    {
        printf("Win Rate         : 0.00%%\n");
    }

    int nextLevelXP = p->level * 500;

    printf("XP for Next Level: %d\n",
           nextLevelXP - p->xp);

    printf("====================================\n");
}

/* =========================
   ACHIEVEMENTS
   ========================= */

void showAchievements()
{
    if (activeProfile == -1)
    {
        printf("\nPlease select a profile first!\n");
        return;
    }

    PlayerProfile *p = &profiles[activeProfile];

    printf("\n====================================\n");
    printf("           ACHIEVEMENTS\n");
    printf("====================================\n");

    printf("Player: %s\n\n", p->name);

    if (p->wins >= 1)
        printf("🏆 First Victory - UNLOCKED\n");
    else
        printf("🔒 First Victory - Locked\n");

    if (p->bestStreak >= 3)
        printf("🔥 3 Win Streak - UNLOCKED\n");
    else
        printf("🔒 3 Win Streak - Locked\n");

    if (p->bestStreak >= 5)
        printf("🔥 5 Win Streak - UNLOCKED\n");
    else
        printf("🔒 5 Win Streak - Locked\n");

    if (p->bestStreak >= 10)
        printf("🔥 10 Win Streak - UNLOCKED\n");
    else
        printf("🔒 10 Win Streak - Locked\n");

    if (p->level >= 5)
        printf("⭐ Level 5 - UNLOCKED\n");
    else
        printf("🔒 Level 5 - Locked\n");

    if (p->level >= 10)
        printf("👑 Level 10 - UNLOCKED\n");
    else
        printf("🔒 Level 10 - Locked\n");

    printf("====================================\n");
}

/* =========================
   LEADERBOARD
   ========================= */

typedef struct
{
    char name[NAME_SIZE];
    int wins;
    int losses;
    int xp;
    int level;
    int bestStreak;
} LeaderboardPlayer;

int comparePlayers(const void *a, const void *b)
{
    LeaderboardPlayer *p1 =
        (LeaderboardPlayer *)a;

    LeaderboardPlayer *p2 =
        (LeaderboardPlayer *)b;

    return p2->xp - p1->xp;
}

void updateLeaderboard()
{
    if (activeProfile == -1)
        return;

    LeaderboardPlayer players[MAX_LEADERBOARD + 1];

    int count = 0;

    FILE *file = fopen("leaderboard.txt", "r");

    if (file != NULL)
    {
        while (count < MAX_LEADERBOARD &&
               fscanf(file,
                      " %49[^|]|%d|%d|%d|%d|%d",
                      players[count].name,
                      &players[count].wins,
                      &players[count].losses,
                      &players[count].xp,
                      &players[count].level,
                      &players[count].bestStreak) == 6)
        {
            count++;
        }

        fclose(file);
    }

    int found = -1;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(players[i].name,
                   profiles[activeProfile].name) == 0)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        if (count < MAX_LEADERBOARD)
        {
            found = count;
            count++;
        }
        else
        {
            found = count - 1;
        }
    }

    strcpy(players[found].name,
           profiles[activeProfile].name);

    players[found].wins =
        profiles[activeProfile].wins;

    players[found].losses =
        profiles[activeProfile].losses;

    players[found].xp =
        profiles[activeProfile].xp;

    players[found].level =
        profiles[activeProfile].level;

    players[found].bestStreak =
        profiles[activeProfile].bestStreak;

    qsort(players,
          count,
          sizeof(LeaderboardPlayer),
          comparePlayers);

    if (count > MAX_LEADERBOARD)
        count = MAX_LEADERBOARD;

    file = fopen("leaderboard.txt", "w");

    if (file == NULL)
        return;

    for (int i = 0; i < count; i++)
    {
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

void showLeaderboard()
{
    LeaderboardPlayer players[MAX_LEADERBOARD];

    int count = 0;

    FILE *file = fopen("leaderboard.txt", "r");

    printf("\n============================================\n");
    printf("                 LEADERBOARD\n");
    printf("============================================\n");

    if (file == NULL)
    {
        printf("No leaderboard data available.\n");
        return;
    }

    while (count < MAX_LEADERBOARD &&
           fscanf(file,
                  " %49[^|]|%d|%d|%d|%d|%d",
                  players[count].name,
                  &players[count].wins,
                  &players[count].losses,
                  &players[count].xp,
                  &players[count].level,
                  &players[count].bestStreak) == 6)
    {
        count++;
    }

    fclose(file);

    qsort(players,
          count,
          sizeof(LeaderboardPlayer),
          comparePlayers);

    printf("%-5s %-20s %-8s %-8s %-8s %-8s\n",
           "Rank",
           "Player",
           "XP",
           "Level",
           "Wins",
           "Streak");

    printf("--------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%-5d %-20s %-8d %-8d %-8d %-8d\n",
               i + 1,
               players[i].name,
               players[i].xp,
               players[i].level,
               players[i].wins,
               players[i].bestStreak);
    }

    printf("============================================\n");
}

/* =========================
   RESET PROFILE
   ========================= */

void resetProfileStatistics()
{
    if (activeProfile == -1)
    {
        printf("\nPlease select a profile first!\n");
        return;
    }

    char confirm;

    printf("\nWARNING!\n");
    printf("This will reset all statistics for %s.\n",
           profiles[activeProfile].name);

    printf("Continue? (Y/N): ");
    scanf(" %c", &confirm);

    if (confirm == 'Y' || confirm == 'y')
    {
        profiles[activeProfile].wins = 0;
        profiles[activeProfile].losses = 0;
        profiles[activeProfile].matches = 0;
        profiles[activeProfile].xp = 0;
        profiles[activeProfile].level = 1;
        profiles[activeProfile].currentStreak = 0;
        profiles[activeProfile].bestStreak = 0;

        saveProfiles();
        updateLeaderboard();

        printf("\nStatistics reset successfully!\n");
    }
    else
    {
        printf("\nReset cancelled.\n");
    }
}

/* =========================
   RULES
   ========================= */

void showRules()
{
    printf("\n====================================\n");
    printf("              RULES\n");
    printf("====================================\n");

    printf("1. Stone beats Scissors.\n");
    printf("2. Scissors beats Paper.\n");
    printf("3. Paper beats Stone.\n");
    printf("4. Same choices result in a draw.\n");
    printf("5. Best of 3 requires 2 round wins.\n");
    printf("6. Best of 5 requires 3 round wins.\n");
    printf("7. Match win gives +100 XP.\n");
    printf("8. Match loss removes 25 XP.\n");
    printf("9. Every 500 XP increases your level.\n");

    printf("====================================\n");
}

/* =========================
   INPUT BUFFER
   ========================= */

void clearInputBuffer()
{
    int c;

    while ((c = getchar()) != '\n' &&
           c != EOF);
}

/* =========================
   MAIN
   ========================= */

int main()
{
    srand((unsigned int)time(NULL));

    loadProfiles();

    if (profileCount > 0)
        activeProfile = 0;

    int choice;

    while (1)
    {
        printf("\n\n");
        printf("============================================\n");
        printf("        STONE PAPER SCISSORS GAME\n");
        printf("============================================\n");

        if (activeProfile != -1)
        {
            printf("Active Player: %s\n",
                   profiles[activeProfile].name);
        }
        else
        {
            printf("Active Player: None\n");
        }

        printf("============================================\n");

        printf("1. Play Game\n");
        printf("2. Profile Manager\n");
        printf("3. Two Player Mode\n");
        printf("4. Tournament Mode\n");
        printf("5. Statistics\n");
        printf("6. Game History\n");
        printf("7. Rules\n");
        printf("8. Achievements\n");
        printf("9. Leaderboard\n");
        printf("10. Reset Profile Statistics\n");
        printf("11. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            playGame();
            break;

        case 2:
            profileMenu();
            break;

        case 3:
            twoPlayerMode();
            break;

        case 4:
            tournamentMode();
            break;

        case 5:
            showStatistics();
            break;

        case 6:
            showGameHistory();
            break;

        case 7:
            showRules();
            break;

        case 8:
            showAchievements();
            break;

        case 9:
            showLeaderboard();
            break;

        case 10:
            resetProfileStatistics();
            break;

        case 11:
            saveProfiles();

            if (activeProfile != -1)
                updateLeaderboard();

            printf("\nThanks for playing!\n");
            printf("Goodbye!\n");

            return 0;

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}