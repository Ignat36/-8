#ifndef KRESTICI_H
#define KRESTICI_H

#include <stdio.h>
#include <stdlib.h>

struct cell
{
    int vertical;
    int horizontal;
    int SideDiagonal;
    int MainDiagonal;
};

int Check(char*** array, int n, int m, char flag);

#endif
