#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h> 

/*
This program is to showcase and demonstrate fork(), make system calls, and perform file operations.
The program has two functions, the main function and the wordcount function. The main function handles
the check for the amount of arguments as well as iterating through the list of arguments to fork and
call the wordcount function.
The wordcount function counts the number of words in supplied file by using fopen to open the file passed
to it. Once the file is open it then checks each character to see if it is a space, newline, null terminator,
or tab. If it is any one of these it increases the word count. Once finished counting it prints the file name
as well as the wordcount the function found.
*/

/*Prototype for the worcount function.
It is a void function since it only prints out the filename and number of words.
It has one argument that is the file to be counted.
*/
void wordcount(char *txtFile);

int main(int argc, char *argv[])
{
    int i;

    //Check for file input
    if( argc < 2)
    {
        printf("Too few arguments, please pass a file\n");
    }

    //Begin going through files passed to the program
    for(i = 1; i < argc; i++)
    {
        //Fork the program to run wordcount function
        if(fork() == 0 )
        {
            wordcount(argv[i]);
            return 0;
        }
    }while(wait(NULL) != -1); //Wait for processes to finish

    printf("All %d files have been counted!\n", argc - 1);

    return 0;
}

void wordcount(char *txtFile)
{
    int iCount = 0;
    char cLetter;
    FILE *pFile;

    //Opens file for reads
    pFile = fopen(txtFile, "r");

    //Loop to read until EOF
    while((cLetter = fgetc(pFile)) != EOF)
    {
        //Check for delimiters to count the words in a file
        if(cLetter == ' ' || cLetter == '\n' || cLetter == '\0')
        {
            //Increase wordcount once delimeter is hit
            iCount++;
        }
    }

    //Print file and wordcount for the process
    printf("Child process for %s: number of words is %d\n", txtFile, iCount);

    //Close file
    fclose(pFile);
}