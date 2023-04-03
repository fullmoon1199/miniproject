#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define get_up 65
#define get_down 66
#define get_left 68
#define get_right 67
#define get_back 98

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define BACK 5

int const ROW = 4;
int const COL = 4;
int game[4][4] = {0};
int subm[4][4] = {0};

int const GAME_OVER = 1;
int const GAME_WIN = 2;
int const GAME_CONTINUE = 3;

typedef int gamenum;
gamenum game_2 = 2;
gamenum game_4 = 4;
gamenum game_8 = 8;
gamenum game_16 = 16;
gamenum game_32 = 32;
gamenum game_64 = 64;
gamenum game_128 = 128;
gamenum game_256 = 256;
gamenum game_512 = 512;
gamenum game_1024 = 1024;
gamenum game_2048 = 2048;

/*
 * print the array
 * */
void mprint()
{
    for (int i = 0; i < ROW; ++i)
    {
        printf("---------------------------------\n");
        for (int j = 0; j < COL; ++j)
        {
            if (game[i][j] == 0)
            {
                printf("| \t");
            }
            else
            {
                printf("| %d\t", game[i][j]);
            }
        }
        printf("|\n");
    }
    printf("---------------------------------\n");
}

int createNumber()
{
    int x = -1;
    int y = -1;
    int times = 0;
    int maxTimes = ROW * COL;
    int whitch = rand() % 3;
    do
    {
        x = rand() % ROW;
        y = rand() % COL;
        ++times;
    } while (game[x][y] != 0 && times <= maxTimes);

    // full
    if (times >= maxTimes)
    {
        return 0;
    }
    else
    {
        gamenum num;
        if (whitch == 0)
        {
            num = game_4;
        }
        else if (whitch)
        {
            num = game_2;
        }
        game[x][y] = num;
    }

    return 1;
}
int wall() //벽에 다 몰았을 때 난수생성을 막아주는 함수 막혀있으면 0 뚫려있으면 1
{
    int jud = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
        if(subm[i][j] != game[i][j])
        jud++;
        }
    }
    if (jud == 0)
    return 1;
    else
    return 0;
}
void process(int direction)
{
    switch (direction)
    {
    case UP:
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                subm[i][j] = game[i][j];
            }
        }
        // top not move
        for (int row = 1; row < ROW; ++row)
        {
            for (int crow = row; crow >= 1; --crow)
            {

                for (int col = 0; col < COL; ++col)
                {

                    // last is space
                    if (game[crow - 1][col] == 0)
                    {
                        game[crow - 1][col] = game[crow][col];
                        game[crow][col] = 0;
                    }
                    else
                    {
                        // merge
                        if (game[crow - 1][col] == game[crow][col])
                        {

                            game[crow - 1][col] *= 2;
                            game[crow][col] = 0;
                        }
                    }
                }
            }
        }
        break;
    case DOWN:
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                subm[i][j] = game[i][j];
            }
        }
        for (int row = ROW - 2; row >= 0; --row)
        {
            for (int crow = row; crow < ROW - 1; ++crow)
            {
                for (int col = 0; col < COL; ++col)
                {
                    if (game[crow + 1][col] == 0)
                    {
                        game[crow + 1][col] = game[crow][col];
                        game[crow][col] = 0;
                    }
                    else
                    {
                        if (game[crow + 1][col] == game[crow][col])
                        {
                            game[crow + 1][col] *= 2;
                            game[crow][col] = 0;
                        }
                    }
                }
            }
        }
        break;
    case LEFT:
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                subm[i][j] = game[i][j];
            }
        }
        for (int col = 1; col < COL; ++col)
        {
            for (int ccol = col; ccol >= 1; --ccol)
            {
                for (int row = 0; row < ROW; ++row)
                {
                    if (game[row][ccol - 1] == 0)
                    {
                        game[row][ccol - 1] = game[row][ccol];
                        game[row][ccol] = 0;
                    }
                    else
                    {
                        if (game[row][ccol - 1] == game[row][ccol])
                        {
                            game[row][ccol - 1] *= 2;
                            game[row][ccol] = 0;
                        }
                    }
                }
            }
        }
        break;
    case RIGHT:
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                subm[i][j] = game[i][j];
            }
        }
        for (int col = COL - 2; col >= 0; --col)
        {
            for (int ccol = col; ccol <= COL - 2; ++ccol)
            {
                for (int row = 0; row < ROW; ++row)
                {
                    if (game[row][ccol + 1] == 0)
                    {
                        game[row][ccol + 1] = game[row][ccol];
                        game[row][ccol] = 0;
                    }
                    else
                    {
                        if (game[row][ccol + 1] == game[row][ccol])
                        {
                            game[row][ccol + 1] *= 2;
                            game[row][ccol] = 0;
                        }
                    }
                }
            }
        }
        break;
    case BACK:
        for (int i = 0; i <= 3; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                game[i][j] = subm[i][j];
            }
        }
    }
}

int getch()
{
    int c;
    struct termios oldattr, newattr;

    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    newattr.c_cc[VMIN] = 1;
    newattr.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return c;
}

int direction()
{
    int ch;

    while (1)
    {
        ch = getch();
        switch (ch)
        {
        case get_left:
            return 3;
            break;
        case get_right:
            return 4;
            break;
        case get_up:
            return 1;
            break;
        case get_down:
            return 2;
            break;
        case get_back:
            return 5;
            break;
        }
    }
}

int judgeStatus()
{
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            if (game[i][j] == 2048)
            {
                return GAME_WIN;
                break;
            }
        }
    }

    // check row
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL - 1; ++j)
        {
            if (!game[i][j] || (game[i][j] == game[i][j + 1]))
            {
                return GAME_CONTINUE;
                break;
            }
        }
    }

    // check col
    for (int j = 0; j < COL; ++j)
    {
        for (int i = 0; i < ROW - 1; ++i)
        {
            if (!game[i][j] || (game[i][j] == game[i + 1][j]))
            {
                return GAME_CONTINUE;
                break;
            }
        }
    }

    return GAME_OVER;
}

int main()
{

    srand((unsigned int)time(NULL));
    createNumber();
    createNumber();
    mprint();
    int dir = 0;
    int status = -1;

    while (1)
    {
        dir = direction();
        status = judgeStatus();
        if (dir && status == GAME_CONTINUE)
        {
            process(dir);
            wall();            
            if (dir != 5 && wall() == 0)
            {
                createNumber();
            }
            mprint();
        }
        else if (status == GAME_WIN)
        {
            mprint();
            printf("\n ^_^    You Win    ^_^ \n");
            break;
        }
        else if (status == GAME_OVER)
        {
            mprint();
            printf("\n -_-    You lose    -_- \n");
            break;
        }
    }

    return 0;
}