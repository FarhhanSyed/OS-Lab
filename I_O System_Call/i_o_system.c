#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int n;
    char buffer[30];
    int fd = open("hel.tx", O_RDWR);
    if (fd == -1)
    {
        printf("Failed to open file\n");
        exit(0);
    }
    printf("Reading first 10 characters from the file\n");
    n = read(fd, buffer, 10);
    write(1, buffer, n);
    printf("\n");
    printf("Skipping 5 characters form the current position\n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);
    printf("\n");
    printf("GOing to 5th last character in the file\n");
    lseek(fd, -5, SEEK_END);
    n = read(fd, buffer, 5);
    write(1, buffer, n);
    printf("\n");
    printf("Going to 3rd character in the file\n");
    lseek(fd, 3, SEEK_SET);
    n = read(fd, buffer, 5);
    write(1, buffer, n);
}
