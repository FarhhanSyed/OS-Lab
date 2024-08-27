#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t child_pid, parent_pid, my_pid;
    child_pid = fork();
    if (child_pid < 0)
    {
        printf("Fork failed!.Exiting..\n");
        exit(1);
    }

    if (child_pid == 0)
    {
        printf("[CHILD] Inside CHild Process\n");
        my_pid = getpid();
        parent_pid = getppid();
        printf("[CHILD] My pid:%d\n", my_pid);
        printf("[CHILD] My parents pid:%d\n", parent_pid);
        printf("[CHILD] Sleeping for 10 seconds\n");
        sleep(10);
        printf("[CHILD] My parent has ended,Orphan Process\n");
    }
    else
    {
        printf("[PARENT] Inside Parent Process\n");
        my_pid = getpid();
        parent_pid = getppid();
        printf("[PARENT] My pid:%d\n", my_pid);
        printf("[PARENT] My parents pid:%d\n", parent_pid);
        printf("Exiting..\n");
        exit(0);
    }
    return 0;
}
