#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "pslibrary.h"

#define READY  0
#define RUNNING  1
#define WAITING  2
#define DONE  3

static char stateChars[] = {'r','R','w',0};

/* 1) handle state changes:
         running process completes CPU burst
         running process has quantum expire
         IO complete
   2) do context switch if necessary
         both ready
         one ready and CPU free
   3) append appropriate characters to character arrays
         avoid putting in multiple string terminators
*/
/* assume s1 and s2 point to buffers with enough space to hold the result */
/* assume that the int parameters are strictly greater than 0 */

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