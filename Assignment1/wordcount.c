#include <stdio.h>

void wordcount(arg);

int main(int argc, char *argv[])
{
    int i;

    printf("Number of args is %d\n", argc);

    for(i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
        wordcount(argv[i]);
    }

    return 0;
}

void wordcount(arg)
{
    int iCount = 0;
    char cLetter;
    FILE *pFile;

    pFile = fopen(arg, "r");

    while((cLetter = fgets(pFile)) != EOF)
    {
        if(cLetter == ' ' || cLetter == '\n')
        {
            iCount++;
        }
    }

    printf("Word count is %d", iCount);
    fclose(pFile);

}