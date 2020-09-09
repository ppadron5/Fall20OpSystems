#include <stdio.h>

void wordcount(char *argFile);

int main(int argc, char *argv[])
{
    int i;

    printf("Number of args is %d\n", argc);

    for(i = 1; i < argc; i++)
    {
        //printf("%s\n", argv[i]);
        wordcount(argv[i]);
    }

    return 0;
}

void wordcount(argFile)
{
    int iCount = 0;
    char cLetter;
    FILE *pFile;

    printf("%s\n", argFile);
    /*pFile = fopen(arg, "r");

    while((cLetter = fgets(pFile)) != EOF)
    {
        if(cLetter == ' ' || cLetter == '\n')
        {
            iCount++;
        }
    }

    printf("Word count is %d", iCount);
    fclose(pFile);
    */
}