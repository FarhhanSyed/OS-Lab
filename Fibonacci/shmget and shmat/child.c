#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
typedef struct
{
    int count;
    int arr[100];
} fib_t;

int main()
{
    key_t key = 1234;
    int shmid = shmget(key, sizeof(fib_t), 0666);
    fib_t *shm_ptr = (fib_t *)shmat(shmid, NULL, 0666);
    printf("Attched to shared memory with key=%d ,id=%d and address=%p\n", key, shmid, shm_ptr);
    int n = shm_ptr->count;
    if (n <= 0)
    {
        printf("[CHILD]Invalid number of fibonacci numbers generated\n");
        return 1;
    }

    if (n > 0)
        shm_ptr->arr[0] = 0;
    if (n > 1)
        shm_ptr->arr[1] = 1;

    for (int i = 2; i < shm_ptr->count; i++)
    {
        shm - ptr->arr[i] = shm_ptr->arr[i - 1] + shm_ptr->arr[i - 2];
    }
    shmdt((void *)shm_ptr);
    return 0;
}
