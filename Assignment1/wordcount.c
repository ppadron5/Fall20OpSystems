#include <stdio.h>

void wordcount(char *txtFile);

int main(int argc, char *argv[])
{
    int i;

    printf("Number of file args is %d\n", argc - 1);

    if( argc < 2)
    {
        printf("Too few arguments, please pass a file\n");
    }

    for(i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
        wordcount(argv[i]);
    }

    return 0;
}

void wordcount(char *txtFile)
{
    int iCount = 0;
    char cLetter;
    FILE *pFile;

    printf("%s\n", txtFile);
    pFile = fopen(txtFile, "r");

    /*while((cLetter = fgets(pFile)) != EOF)
    {
        if(cLetter == ' ' || cLetter == '\n')
        {
            iCount++;
        }
    }

    printf("Word count is %d", iCount);
    fclose(pFile);*/
}