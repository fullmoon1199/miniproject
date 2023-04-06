#include <stdio.h>
#include <string.h>

// 랭킹 정보를 저장할 구조체
typedef struct
{
    int score;
    char name[20];
} Ranking;

// 랭킹 정보를 저장할 배열
Ranking ranking[10];

// 랭킹 정보를 초기화하는 함수
void init_ranking()
{
    for (int i = 0; i < 10; i++)
    {
        ranking[i].score = 0;
        strcpy(ranking[i].name, "");
    }
}

// 새로운 점수와 이름을 랭킹에 추가하는 함수
void add_score(int score, char *name)
{
    for (int i = 0; i < 10; i++)
    {
        if (score > ranking[i].score)
        {
            // 새로운 점수를 랭킹에 추가
            for (int j = 9; j > i; j--)
            {
                ranking[j] = ranking[j - 1];
            }
            ranking[i].score = score;
            strcpy(ranking[i].name, name);
            break;
        }
    }
}

// 랭킹을 출력하는 함수
void print_ranking()
{
    printf("----- 랭킹 -----\n");
    for (int i = 0; i < 10; i++)
    {
        if (ranking[i].score > 0)
        {
            printf("%d위: %s (%d점)\n", i + 1, ranking[i].name, ranking[i].score);
        }
    }
}

// 랭킹 정보를 파일에 저장하는 함수
void save_ranking()
{
    FILE *fp = fopen("ranking.txt", "w");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        fprintf(fp, "%d %s\n", ranking[i].score, ranking[i].name);
    }
    fclose(fp);
}

// 랭킹 정보를 파일에서 불러오는 함수
void load_ranking()
{
    FILE *fp = fopen("ranking.txt", "r");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        fscanf(fp, "%d %s", &ranking[i].score, ranking[i].name);
    }
    fclose(fp);
}

int main()
{
    // 랭킹 정보 초기화
    init_ranking();

    // 파일에서 랭킹 정보 불러오기
    load_ranking();

    int score;
    char name[20];
    printf("이름을 입력하세요: ");
    scanf("%s", name);
    printf("점수를 입력하세요: ");
    scanf("%d", &score);
    add_score(score, name);

    // 랭킹 출력
    print_ranking();

    // 파일에 랭킹 정보 저장하기
    save_ranking();

    return 0;
}