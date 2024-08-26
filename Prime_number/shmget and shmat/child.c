#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/shm.h>
typedef struct {
    int n;
    int arr[100];
}pack_t;
int main()
{
    key_t key=1234;
    int shmid=shmget(key,sizeof(pack_t),0666);
    pack_t *shm_ptr=(pack_t*)shmat(shmid,NULL,0666);
    printf("[child] attached shared memory with key=%d id=%dand addredd=%d\n",key,shmid,shm_ptr);
    for(int i=0;i<shm_ptr->n;i++)
    {
        shm_ptr->arr[i]=2*i+1;
    }
    printf("[child]finished generating prime numbers:\n");
    shmdt((void*)shm_ptr);
    return 0;
}