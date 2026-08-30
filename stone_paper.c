#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player, computer;
    int playerScore = 0, computerScore = 0;
    int rounds;

    srand(time(NULL));

    printf("==== STONE PAPER SCISSORS ====\n");

    printf("Enter num of rounds :- ");
    scanf("%d", &rounds);

    for (int i = 1; i <= rounds; i++) {

        printf("\n--- Round %d --\n", i);

        printf("1. Stone\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");

        printf("Enter your choice (1-3): ");
        scanf("%d", &player);

        if (player < 1 || player > 3 ) {
            printf("Invalid choice! Try again. \n");
            i--;
            continue;
        }

        computer = (rand() % 3) + 1;

        printf("Computer chose: ");

        if (computer == 1)
            printf("Stone\n");
        else if (computer == 2)
            printf("Paper\n");
        else
            printf("Scissors\n");

        if (player == computer) {
            printf("Result: DRAW!!\n");
    }
    else if ((player == 1 && computer == 3) || (player == 2 && computer == 1) || (player == 3 && computer == 2)) {

        printf("Result: YOU WIN!! \n");
        playerScore++;
    }
    else {
        printf("Result: COMPUTER WINS!! \n");
        computerScore++;
    }
}

printf("\n========== FINAL RESULT ==========\n");
printf("Your Score: %d\n", playerScore);
printf("Computer Score: %d\n", computerScore);

if (playerScore > computerScore)
    printf("YOU WINNN!!!!!\n");
else if (computerScore > playerScore)
    printf("COMPUTER WINSS!!!!\n");
else
printf("IT'S A DRAW!!!!! \n");

return 0;
}