#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t child_pid, my_pid, parent_pid;
    child_pid = fork();
    if (child_pid < 0)
    {
        printf("Fork failed,Exiting!!\n");
        exit(0);
    }

    if (child_pid == 0)
    {
        my_pid = getpid();
        parent_pid = getppid();
        printf("[CHILD] This is child Process\n");
        printf("[CHILD] my pid:%d\n", my_pid);
        printf("[CHILD] My parents pid :%d\n", parent_pid);
        printf("[CHILD] CHild exiting!!\n");
        exit(0);
    }
    else
    {
        printf("This is Parent Process.\n");
        my_pid = getpid();
        parent_pid = getppid();
        printf("[PARENT] My pid:%d\n", my_pid);
        printf("[PARENT] My Parent pid:%d\n", parent_pid);
        printf("[PARENT] Sleeping for 10 sseconds\n");
        sleep(10);
        printf("Child pid%d has ended,but still has an entry in the process tabel\n", child_pid);
        printf("IT is a Zombie Process\n");
    }
    return 0;
}
