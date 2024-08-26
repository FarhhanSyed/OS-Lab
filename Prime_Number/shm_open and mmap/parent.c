#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/shm.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>
int main(int argc,char *argv[])
{
    if(argc<3)
    {
        printf("minimum of 3 arguments must be passed.\n");
        exit(0);
    }
    int start=atoi(argv[1]);
    int end=atoi(agv[2]);
    if(start<2 || end<start)
    {
        printf("Error inputs:%d %d\n",start,end);
        return 0;
    }
    pid_t pid=fork();
    if(pid==0)
    {
        execlp("./child","./child",argv[1],argv[2],NULL);
        perror("execlp failed\n");
        exit(1);
    }
    else if(pid>0)
    {
        wait(NULL);
        printf("[PARENT] child finished executing\n");

        int shm_fd=shm_open("VSS",O_RDONLY,0666);
        void *ptr=mmap(0,4096,PROT_READ,MAP_SHARED,shm_fd,0);

        printf("[PARENT] Printing:%d",(char*)ptr);
        shm_unlink("VSS");
    }
    return 0;
}
