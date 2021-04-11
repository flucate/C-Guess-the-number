#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    //Control variables
    int shot;
    int attempt=1, maxAttempt=5, guessedTheNumber=0;
    int level, score=1000;

    //Repeat till player select one of the three levels
    do {
        printf("GUESSING GAME\n\n");
        printf("Select your level - (1) Amateur (2) Intermediate (3) Professional\n");
        scanf("%d", &level);
    } while (level <= 0 || level > 3);

    //Set maxAttempt according to the player level
    if (level == 1)
        maxAttempt = 15;
    else if (level == 2)
        maxAttempt = 10;
    else
        maxAttempt = 5;

    //generate random number between 0 and 100
    srand(time(0));
    int secretNumber = rand()%100;

    //Repeat till maximum number of attempts
    for (int count = 1; count <= maxAttempt; count++){

        //Read a number between 0 and 100
        printf("\nEnter a number between 1 and 100. Give a shot! : \n");
        scanf("%d", &shot);

        //Validate if given number is equal or bigger than 0
        if (shot < 0){
            printf("Given number must be equal or bigger than 0!\n");
            attempt++;
            continue;
        }

        //Store the result of a condition
        guessedTheNumber = (shot == secretNumber);
        int shotIsBigger = (shot > secretNumber);

        //Check if user guessed the number and break execution. If not, tell user if given number is bigger or smaller than secret number
        if (guessedTheNumber)
            break;
        else if (shotIsBigger)
            printf("The given number is bigger than the secret number!\n\n");
        else
            printf("The given number is smaller than the secret number!\n\n");

        attempt++;

        int lostScore = abs(shot - secretNumber) / 2;
        score = score - lostScore;

    }

    //End the game if player guesses the secret number and print the score
    if (guessedTheNumber){
        printf("\n\nCongratulations, you guessed the secret number in %d attempt(s).\n\n", attempt);
        printf("Total score: %d\n", score);
    }
    else
        printf("You lose! Good luck next time!\n\n");

    getch();

    return 0;
}
