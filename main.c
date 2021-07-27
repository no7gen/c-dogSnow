#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
    char gameField[31][31];
    char masKindOfDog[4];
    char key, kindOfDog='.';
    int x,y,xdog=15,ydog=15,snowflakes=0;
    int snowX,snowY;

    masKindOfDog[0] = '.';
    masKindOfDog[1] = 'o';
    masKindOfDog[2] = 'O';

    srand(time(NULL));

    snowX = rand() * 1.0 / RAND_MAX * 24 + 6;
    snowY = rand() * 1.0 / RAND_MAX * 24 + 6;

    do
    {
        system("cls");

        // Make a field frame
        for (y = 0; y < 31; y++)
        {
            for (x = 0; x < 31; x++)
            {
                gameField[x][y] = ' ';
                if ( x < 5 || y < 5)
                    gameField[x][y] = ' ';
                if (((x == 5 || x == 30) && y > 4) || ((y == 5 || y == 30) && x > 4))
                    gameField[x][y] = '+';
            }
        }

        //Dog
        if (snowflakes > 0 && snowflakes < 9) kindOfDog = masKindOfDog[snowflakes/3];
        if (snowflakes >= 9) kindOfDog = '@';
        gameField[xdog][ydog] = kindOfDog;

        //Snow flakes
        gameField[snowX][snowY] = '*';

        // Draw a field
        for (y = 0; y < 31; y++)
        {
            for (x = 0; x < 31; x++)
            {
                printf("%c",gameField[x][y]);
            }
            printf("\n");
        }

        printf("\n\tSnowFlakes: %d\n",snowflakes);
        printf("\n\tExit -> e");

        key = getch();

        if (key == 'w' && ydog > 6)  ydog--;
        if (key == 's' && ydog < 29) ydog++;
        if (key == 'a' && xdog > 6)  xdog--;
        if (key == 'd' && xdog < 29) xdog++;

        if (xdog == snowX && ydog == snowY)
        {
            gameField[snowX][snowY] = kindOfDog;
            snowflakes++;
            snowX = rand() * 1.0 / RAND_MAX * 24 + 6;
            snowY = rand() * 1.0 / RAND_MAX * 24 + 6;
        }
    }
    while (key != 'e');
    return 0;
}
