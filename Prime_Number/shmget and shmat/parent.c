#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/shm.h>
typedef struct
{
    int n;
    int arr[100];
} pack_t;
int main()
{
    key_t key = 1234;
    int shmid = shmget(key, sizeof(pack_t), 0666 | IPC_CREAT);
    pack_t *shm_ptr = (pack_t *)shmat(shmid, NULL, 0666);
    printf("Created shared memory with key=%d , id=%d and address=%d", key, shmid, shm_ptr);
    pid_t child_pid;
    printf("[PARENT]enter n:\n");
    scanf("%d", &shm_ptr->n);
    if ((child_pid = fork()) == 0)
    {
        execlp("./child", "./child", NULL);
    }
    else
    {
        wait(NULL);
        printf("[PARENT] Child finished executing\n");
        printf("[parent] The first %d prime numbers are:\n", shm_ptr->n);
        for (int i == 0; i < shm_ptr->n; i++)
        {
            printf("%d", shm_ptr->arr[i]);
        }
        putchar('\n');
    }
    shmdt((void *)shm_ptr);
    shmctl(shm_ptr, IPC_RMID, NULL);
    printf("[PARENT]Shared memory deleted\n");
    return 0;
}
