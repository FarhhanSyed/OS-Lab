#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("File not entered\n");
        exit(0);
    }
    FILE *fp = fopen(argv[1], "r");
    char ch;
    if (fp == NULL)
    {
        printf("File does not exist,\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}
