#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#define		SIZE		10
#define     get_up 65
#define     get_down 66
#define     get_left 68
#define     get_right 67
#define		UP		1
#define		DOWN	2
#define		LEFT	3
#define		RIGHT	4 

int const ROW = 4;
int const COL = 4;
int game[4][4] = { 0 };

int getch() //getch 함수 만듦
{
    int c;
    struct termios oldattr, newattr;

    tcgetattr(STDIN_FILENO, &oldattr); // 현재 터미널 설정 읽음
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);        // CANONICAL과 ECHO 끔
    newattr.c_cc[VMIN] = 1;                     // 최소 입력 문자 수를 1로 설정
    newattr.c_cc[VTIME] = 0;                    // 최소 읽기 대기 시간을 0으로 설정
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr); // 터미널에 설정 입력
    c = getchar();                              // 키보드 입력 읽음
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); // 원래의 설정으로 복구
    return c;
}

int direction()
{
    int ch;

    while (!(ch == '\n')) // 키보드 값 받는 함수
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
        case 98:
             printf("와ㅏㅏㅏ%d", getch());
            break;
        }
    }
    return 0;
}
int main()
{
    if(direction()==4)
    printf("아싸");

    return 0;
}

