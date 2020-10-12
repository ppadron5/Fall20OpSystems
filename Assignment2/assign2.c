#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "pslibrary.h"
#include "pslibrary.c"

//Main function
int main(int argc, char *argv[])
{
    int i;

    //Check for file input
    if( argc != 8)
    {
        printf("Too few arguments, please pass exactly 7 files\n");
    }

    //Print if progam has enough inputs
    printf("Assignment 2 program written by Pedro Padron\n");

    //Begin going through files passed to the program
    for(i = 1; i < argc; i++)
    {
        printf("%s", argv[i]);
    }


    return 0;
}