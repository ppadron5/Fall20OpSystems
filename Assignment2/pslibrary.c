#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "pslibrary.h"

void fcfs(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2)
{
    printf("scheduler fcfs: \n");
}

void sjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2)
{
    printf("scheduler sjf: \n");
}

void psjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2)
{
    printf("scheduler psjf: \n");
}

void rr(char *s1, char *s2, int q, int x1, int y1, int z1, int x2, int y2, int z2)
{
    printf("scheduler rr: \n");
}