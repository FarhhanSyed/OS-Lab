#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys.ipc.h>
#include <sys/wait.h>
typedef struct
{
    int count;
    int fib[100];
} fib_t;

int main()
{
    key_t key = 1234;
    int shmid = shmget(key_t, sizeof(fib_t), 0666 | IPC_CREAT);
    fib_t *shm_ptr = (fib_t *)shmat(shmid, NULL, 0666);
    pid_t child_pid;
    printf("Attached shared memory with key=%d ,id=%d and address=%d\n", key, shmid, shm_ptr);
    printf("Enter the number of fibonacci numbers to generate:\n");
    scanf("%d", &shm_ptr->count);
    if ((child_pid = fork()) == 0)
    {
        execlp("./fib", "./fib", NULL);
    }
    else
    {
        wait(NULL);
        printf("[Parent]child finished executing\n");
        printf("[PARENT] The fibonacci sequence is:\n");
        for (int i = 0; i < shm_ptr->count; i++)
        {
            printf("%d\t", shm_ptr->fib[i]);
        }
        putchar('\n');
        printf("[parent]finished printing\n");
    }
    shmdt((void *)shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory deleted\n");
    return 0;
}
