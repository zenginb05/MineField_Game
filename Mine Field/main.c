#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define TABLE_LENGHT 8
#define MINE_COUNT 5
#define RANDOM (1 + (rand() % (TABLE_LENGHT - 2))) // [1-7]


char indicator[TABLE_LENGHT][TABLE_LENGHT];
char choice;

int woncheck = 1;
int x, y;
int foundbomb = 0;

int minecoordinate[8][8];

int indicatorvalue[TABLE_LENGHT][TABLE_LENGHT] = {0};

void remainbombcheck();

int realminecount=0;

void showindicator();
void randombombplacer();

int boxopener(int x, int y, char choice);

int main()
{
    srand(time(NULL));

    printf("Hello our MineField game \n");

    for (int i = 0; i < TABLE_LENGHT; i++) // We added '_' to all incator index.
    {
        for (int j = 0; j < TABLE_LENGHT; j++)
        {
            indicator[i][j] = 254;
        }
    }

    randombombplacer();

    showindicator();
    printf("\n\n");

    indicatorvalueprinter(); // It's hacks code row . If u want to see bomb location please delete these comment lines.
    printf("\n\n");

    while (woncheck != 0)
    {
        if (foundbomb == realminecount)
        {
            printf("You Won the game !! \n");
            printf("You Won the game !! \n");
            printf("You Won the game !! \n");
            printf("You Won the game !! \n");
            printf("You Won the game !! \n");
            continue;
        }

        printf("Please enter the value for x and y between 0-8 ==> ");
        scanf("%d %d", &x, &y);

        printf("Please enter the value for choice [o-f] ==> ");
        scanf(" %c", &choice);

        boxopener(x, y, choice);
        printf("\n\n");

        showindicator();
        printf("\n\n");
    }

    if (woncheck == 0)
    {
        printf("You LOSE!\n");
        printf("You LOSE!\n");
        printf("You LOSE!\n");
        printf("You LOSE!\n");
        printf("You LOSE!\n");
    }
}

void showindicator()
{
    for (int i = 0; i < TABLE_LENGHT; i++)
    {
        for (int j = 0; j < TABLE_LENGHT; j++)
        {
            printf("%c   ", indicator[i][j]);
        }
        printf("\n\n");
    }
}

void randombombplacer()
{

    for (int i = 0; i < MINE_COUNT; i++)
    {
        indicator[RANDOM][RANDOM] = ' ';
    }

    for (int i = 0; i < TABLE_LENGHT; i++)
    {
        for (int j = 0; j < TABLE_LENGHT; j++)
        {
            if (indicator[i][j] == ' ')
            {
                minecoordinate[i][j] = indicator[i][j];
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (minecoordinate[i][j] == 32)
            {

                indicatorvalue[i + 1][j + 1]++;
                indicatorvalue[i - 1][j - 1]++;
                indicatorvalue[i + 1][j - 1]++;
                indicatorvalue[i - 1][j + 1]++;

                indicatorvalue[i][j - 1]++;
                indicatorvalue[i][j + 1]++;
                indicatorvalue[i - 1][j]++;
                indicatorvalue[i + 1][j]++;
            }
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (minecoordinate[i][j] == 32)
            {   
                realminecount++;
                indicatorvalue[i][j] = 99;
            }
        }
    }

    for (int i = 0; i < TABLE_LENGHT; i++)
    {
        for (int j = 0; j < TABLE_LENGHT; j++)
        {
            if (indicator[i][j] == ' ')
            {
                indicator[i][j] = 254;
            }
        }
    }
}

int boxopener(int x, int y, char choice)
{

    while (((x - 1) <= 0) && ((x - 1) >= 8) && ((y - 1) <= 0) && ((y - 1) >= 8))
    {
        printf("Invalued value please enter again [0-8] => ");
        scanf("%d %d", &x, &y);
    }

    while ((choice != 'o') && (choice != 'f'))
    {
        printf("Invalued value please enter again [o-f] => ");
        scanf(" %c", &choice);
    }

    switch (choice)
    {
    case 'o':
        if (indicatorvalue[x - 1][y - 1] == 99)
        {
            indicator[x - 1][y - 1] = 'X';
            woncheck = 0;
        }
        else
        {
            indicator[x - 1][y - 1] = (indicatorvalue[x - 1][y - 1] + 48);
        }
        break;

    case 'O':
        if (indicatorvalue[x - 1][y - 1] == 99)
        {
            indicator[x - 1][y - 1] = 'X';
            woncheck = 0;
        }
        else
        {
            indicator[x - 1][y - 1] = (indicatorvalue[x - 1][y - 1] + 48);
        }
        break;

    case 'f':
        indicator[x - 1][y - 1] = 'F';
        if (indicatorvalue[x - 1][y - 1] == 99)
        {
            foundbomb++;
        }

        break;

    case 'F':
        indicator[x - 1][y - 1] = 'F';
        if (indicatorvalue[x - 1][y - 1] == 99)
        {
            foundbomb++;
        }
        break;
    }
}

void indicatorvalueprinter()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d    ", indicatorvalue[i][j]);
        }
        printf("\n\n");
    }
}
