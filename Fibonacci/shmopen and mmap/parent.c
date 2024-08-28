#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcnlt.h>
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("You are not passing number\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    if (n < 1)
    {
        printf("Error input.\n");
        return 0;
    }
    pid_t pid = fork();
    if (pid == 0)
    {
        execlp("./child", "./child", argv[1], NULL);
    }
    else
    {
        wait(NULL);
        printf("[PARENT] Child finished execuring\n");

        int shm_fd = shmopen("VSS", O_RDONLY, 0666);
        void *ptr = mmap(0, 4096, PROT_READ, MAP_SHARED, shm_fd, 0);
        printf("Parent printing..\n");
        printf("%s\n", (char *)ptr);
        shm_unlink("VSS");
    }
    return 0;
}
