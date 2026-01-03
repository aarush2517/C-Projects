// GUESS THE NUMBER GAME 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

int main()
{
    char ans[5], name[50], difficulty[10];
    int age, tries = 0, guess, i;

    srand(time(0));  

    printf("\n------  WELCOME TO : GUESS THE NUMBER GAME  ------\n\n");
    printf("Type (Yes) to play the game and (No) for not to play :");
    scanf(" %[^\n]", ans);
    strlwr(ans);

    if (strcmp(ans, "yes") == 0)
    {
        printf("\nRegister your personal details : \n");
        printf("Enter your full name sir/ma'am : ");
        scanf(" %[^\n]", name);
        printf("Enter your age sir/ma'am : ");
        scanf("%d", &age);

        printf("\n\n        ---RULES AND GAME SENSE---  \n");
        printf("1)A random number will be generated every game.\n");
        printf("2)Select the difficulty(easy,mid,hard).\n");
        printf("3)Guess the number and celebrate if guessed correct.\n");
        printf("4)If wrong then guess again with the help of hint.");

        Sleep(2500);

        printf("\n\n[1]Easy : 10 Tries \n[2]Medium : 5 Tries \n[3]Hard : 3 Tries");
        printf("\nEnter the difficulty level (Eg-easy) : ");
        scanf(" %[^\n]", difficulty);
        strlwr(difficulty);

        if (strcmp(difficulty, "easy") == 0)
            tries = 10;
        else if (strcmp(difficulty, "medium") == 0)
            tries = 5;
        else if (strcmp(difficulty, "hard") == 0)
            tries = 3;
        else
        {
            printf("INVALID DIFFICULTY !!");
            return 0;
        }

        int game_stopper = 0;

        do
        {
            int key = (rand() % 20) + 1;   
            int win = 0;                 
            printf("\nLet's Begin !!\n");
            Sleep(1000);

            for (i = 0; i < tries; i++)
            {
                printf("\nEnter your guessed number : ");
                scanf("%d", &guess);

                if (key == guess)
                {
                    Sleep(2000);
                    printf("\n- CONGRULATIONS !! you won");
                    printf("\n- Check Record.txt for the scorecard !!");
                    win = 1;
                    break;
                }

                if (key > guess)
                    printf("\n- HINT: Guess is lower than the answer\n");
                else
                    printf("\n- HINT: Guess is higher than the answer\n");

                printf("- You have %d Tries left \n", tries - i - 1);
            }

            if (win == 0)   
            {
                Sleep(2000);
                printf("\n- OOPS....YOU LOST :( THE ANSWER WAS %d \n", key);
            }
            else
            {

                FILE *ptr;
                ptr = fopen("Record.txt", "r+");   

                if (ptr == NULL)
                {
                    printf("File opening failed\n");
                    return 1;
                }

                fprintf(ptr, "---- LEADERBOARD ----\n");

                if (strcmp(difficulty, "easy") == 0)
                {
                    if (i + 1 <= 2)
                        fprintf(ptr, "- %s -> Guessed in %d tries : Points -> 100 (%s)\n", name, i + 1, difficulty);
                    else if (i + 1 <= 5)
                        fprintf(ptr, "- %s -> Guessed in %d tries : Points -> 80 (%s)\n", name, i + 1, difficulty);
                    else
                        fprintf(ptr, "- %s -> Guessed in %d tries : Points -> 40 (%s)\n", name, i + 1, difficulty);
                }

                if (strcmp(difficulty, "medium") == 0)
                {
                    if (i + 1 <= 2)
                        fprintf(ptr, "- %s -> Guessed in %d tries : Points -> 100 (%s)\n", name, i + 1, difficulty);
                    else if (i + 1 <= 3)
                        fprintf(ptr, "- %s -> Guessed in %d tries : Points -> 80 (%s)\n", name, i + 1, difficulty);
                    else
                        fprintf(ptr, "- %s -> Guessed in %d tries : Points -> 40 (%s)\n", name, i + 1, difficulty);
                }

                if (strcmp(difficulty, "hard") == 0)
                {
                    if (i + 1 <= 1)
                        fprintf(ptr, "- %s -> Guessed in %d tries : Points -> 100 (%s)\n", name, i + 1, difficulty);
                    else if (i + 1 <= 2)
                        fprintf(ptr, "- %s -> Guessed in %d tries : Points -> 80 (%s)\n", name, i + 1, difficulty);
                    else
                        fprintf(ptr, "- %s -> Guessed in %d tries : Points -> 40 (%s)\n", name, i + 1, difficulty);
                }

                fclose(ptr);
            }

            printf("\nEnter any number to play again & 1 TO STOP THE GAME : ");
            scanf("%d", &game_stopper);

        } while (game_stopper != 1);
    }
    else
    {
        printf("NO PROBLEM. ENJOY YOUR DAY !");
    }

    return 0;
}
