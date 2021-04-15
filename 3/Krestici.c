#include "Krestici.h"

int Check(char ***array, int n, int m, char flag)
{
    int i, j, res = 0;
    struct cell** count = (struct cell**)malloc((n+1) * sizeof(struct cell*));
    for (i = 0; i < n; i++)
    {
        count[i] = (struct cell*)malloc((m+1) * sizeof(struct cell));
        for (j = 0; j < m; j++)
        {
            if ((*array)[i][j] == flag)
            {
                count[i][j].vertical = 1;
                count[i][j].horizontal = 1;
                count[i][j].SideDiagonal = 1;
                count[i][j].MainDiagonal = 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if ((*array)[i][j] == flag)
            {
                if (i - 1 >= 0 && (*array)[i - 1][j] == flag)
                    count[i][j].vertical = count[i - 1][j].vertical + 1;

                if(i - 1 >= 0 && j - 1 >= 0 && (*array)[i - 1][j - 1] == flag)
                    count[i][j].MainDiagonal = count[i - 1][j - 1].MainDiagonal + 1;

                if (j - 1 >= 0 && (*array)[i][j - 1] == flag)
                    count[i][j].horizontal = count[i][j - 1].horizontal + 1;

                if (i - 1 >= 0 && j + 1 >= 0 && (*array)[i - 1][j + 1] == flag)
                    count[i][j].SideDiagonal = count[i - 1][j + 1].SideDiagonal + 1;

                if (count[i][j].vertical == 5
                    || count[i][j].horizontal == 5
                    || count[i][j].SideDiagonal == 5
                    || count[i][j].MainDiagonal == 5)
                {
                    res = 1;
                }
            }
        }
    }
    
    for (i = 0; i < n; i++)
        free(count[i]);
    free(count);

    return res;
}

int main()
{
    int n, m, i, j;

    printf_s("Enter field size : \nn =  ");
    while ((!(scanf_s("%d", &n))) == 1) {
        printf("Try again: ");
        while (getchar() != '\n') {}
    }
    while (getchar() != '\n') {}

    printf_s("m =  ");
    while ((!(scanf_s("%d", &m))) == 1) {
        printf("Try again: ");
        while (getchar() != '\n') {}
    }
    while (getchar() != '\n') {}

    printf_s("Enter field : \n");

    char** pole = (char**)malloc((n+1) * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        pole[i] = (char*)malloc((m+1) * sizeof(char));

        for (j = 0; j < m; j++)
        {
            scanf_s("%c", &pole[i][j]);

            while (!(pole[i][j] == 'X' || pole[i][j] == '0' || pole[i][j] == '.'))
            {
                if(pole[i][j] != '\n')
                    printf_s("Unknown character [ %c ], use only X, 0 or .\nNew character : ", pole[i][j]);
                scanf_s("%c", &pole[i][j]);
            }
        }

        while (getchar() != '\n') {}
    }

    if (Check(&pole, n, m, 'X'))
    {
        printf_s("First player wIn");
    }
    else if (Check(&pole, n, m, '0'))
    {
        printf_s("Second player wIn");
    }
    else
    {
        printf_s("Nobody wins");
    }

    for (i = 0; i < n; i++)
        free(pole[i]);
    free(pole);

    return 0;
}