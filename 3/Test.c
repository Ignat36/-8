#include "Krestici.h"
#include <assert.h>

void CheckTest()
{
    int n = 5, m = 5, i;
    char** pole = (char**)malloc((n + 1) * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        pole[i] = (char*)malloc((m + 1) * sizeof(char));
        for (int j = 0; j < m; j++)
            pole[i][j] = i == j ? 'X' : (i+j) % 3 == 0 ? '0' : '.';
    }

    assert(Check(&pole, n, m, 'X'));
    printf_s("\nCheck complited");

    for (i = 0; i < n; i++)
        free(pole[i]);
    free(pole);
}

#undef main

int main()
{
    CheckTest();
	return 0;
}