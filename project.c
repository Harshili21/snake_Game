#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int height = 20, width = 20, x, y, fruitX, fruitY, flag, gameEnd, score;
void makeLogic()
{
    switch (flag)
    {
    case 1:
    {
        x--;
        break;
    }
    case 2:
    {
        x++;
        break;
    }
    case 3:
    {
        y--;
        break;
    }
    case 4:
    {
        y++;
        break;
    }
    }
}
void input()
{
    if (khbit())
    {
        switch (getch())
        {
        case 'w':
        {
            flag = 1;
            break;
        }
        case 's':
        {
            flag = 2;
            break;
        }
        case 'a':
        {
            flag = 3;
            break;
        }
        case 'd':
        {
            flag = 4;
            break;
        }
        }
    }
}
void setup()
{
    x = height / 2;
    y = width / 2;
label1:
    fruitX = rand() % 20;
    if (fruitX == 0)
    {
        goto label1;
    }
label2:
    fruitY = rand() % 20;
    if (fruitY == 0)
    {
        goto label2;
        gameEnd = 0;
        score = 0;
    }
}
void draw()
{
    system("cls");
    int i, j;
    for (i = 0; i <= height; i++)
    {
        for (j = 0; j <= width; j++)
        {
            if (i == 0 || i == height || j == 0 || j == width)
            {
                printf("*");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("0");
                }
                else if (i == fruitX && j == fruitY)
                {
                    printf("@");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main()
{
    setup();
    while (gameEnd != 1)
    {
        input();
        draw();
        makeLogic();
    }
}
