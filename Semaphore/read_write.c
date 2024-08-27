#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
sem_t wrt;
pthread_mutex_t mutex;
int cnt = 1;
int numreader = 0;

void *reader(void *rno);
void *writer(void wno *);
int main()
{
    pthread_t red[3], wri[3];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);
    int a[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&red[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&wri[i], NULL, (void *)writer, (void *)&a[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_join(red[i], NULL);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_join(wri[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}

void *reader(void *rno)
{
    pthread_mutex_lock(&mutex);
    numreader++;
    if (numreader == 1)
        sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);

    printf("Reader:%d read cnt as %d\n", *((int *)rno), cnt);

    pthread_mutex_lock(&mutex);
    numreader--;
    if (numreader == 0)
        sem_post(&wrt);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *writer(void *wno)
{
    sem_wait(&wrt);
    cnt *= 2;
    printf("Writer:%d modified cnt as %d\n", *((int *)wno), cnt);
    sem_post(&wrt);

    return NULL;
}
