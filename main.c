// Snake Water Gun game

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int won(char computer[], char user[])
{
    if (strcmp(user, computer) != 0)
    {   
        if (strcmp(user, "snake") == 0 && strcmp(computer, "water") == 0)
        {
            return 1;
        }

        else if (strcmp(user, "snake") == 0 && strcmp(computer, "gun") == 0)
        {
            return 0;
        }

        else if (strcmp(user, "water") == 0 && strcmp(computer, "gun") == 0)
        {
            return 1;
        }

        else if (strcmp(user, "water") == 0 && strcmp(computer, "snake") == 0)
        {
            return 0;
        }

        else if (strcmp(user, "gun") == 0 && strcmp(computer, "snake") == 0)
        {
            return 1;
        }

        else if (strcmp(user, "gun") == 0 && strcmp(computer, "water") == 0)
        {
            return 0;
        }
        
    }
    return 0;
}

int main()
{

    char name[100], user_opt[6];
    char *options[5], *random;
    static int computer, user;
    int again;

    options[0] = "snake";
    options[1] = "water";
    options[2] = "gun";

    printf("-------------------Snake Water Gun Game---------------\nHere we go.........\n");
    printf("By the way What's your name?\n\n");
    gets(name);

    do
    {
        srand(time(NULL));
        random = options[rand() % 3];

        printf("\nWhat's your option:\n");
        scanf("%s", &user_opt);

        while (strcmp(random, user_opt) == 0) // avoiding draws
        {
            random = options[rand() % 3];
        }
        
        // snake > water , water > gun , gun > snake
        if (strcmp(user_opt, "snake") == 0 || strcmp(user_opt, "water") == 0 || strcmp(user_opt, "gun") == 0)
        {
            int won_ = won(random, user_opt);
            if (won_ == 1)
            {
                user++;
            }

            else if (won_ == 0 && (strcmp(user_opt, random) != 0))
            {
                computer++;
            }
            
            printf("\nComputer says: %s\n", random);
            printf("\nComputer:   %d\n", computer);
            printf("%s:   %d\n", name, user);
        }

        else
        {
            printf("\nHeyo! Enter valid option:\n");
        }

        printf("\nAgain? Seriously.:  (yes/no) (1/0):\n");
        scanf("%d", &again);

        if(again == 0)
        {
            if(computer > user)
            {
                printf("\nComputer Won :(\n");
            }

            else if(user > computer)
            {
                printf("\nHurray! You Won :)\n");
            }

            else
            {
                printf("Thats a Damn Draw\n");
            }

            printf("Goodbye!.......\n");
        }

    } while (again != 0);

    getch();
    return 0;
}