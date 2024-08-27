#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char filename[100], pattern[100], temp[200];
    printf("Enter filename:");
    scanf("%s", filename);
    printf("Enter pattern:");
    scanf("%s", pattern);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    while (!feof(fp))
    {
        fgets(temp, 100, fp);
        if (strstr(temp, pattern))
        {
            printf("%s", temp);
        }
    }
    fclose(fp);
    return 0;
}
