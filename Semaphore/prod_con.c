#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define max 3
#define buffer_size 3

int in = 0, out = 0;
sem_t empty, full;
pthread_mutex_t mutex;
int buffer[buffer_size];

void *producer(void *pno);
void *consumer(void *cno);
int main()
{
    pthread_t pro[3], con[3];
    pthread_mutex_init(&mutex);
    sem_init(&empty, 0, buffer_size);
    sem_init(&full, 0, 0);
    int a[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&pro[i], NULL, producer, &a[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&con[i], NULL, consumer, &a[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(pro[i], NULL);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_join(con[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}
void *producer(void *pno)
{
    for (int i = 0; i < 3; i++)
    {
        int item = rand() % 100;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d produced item%d at %d", *((int *)pno), buffer[in], in);
        in = (in + 1) % buffer_size;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cno)
{
    for (int i = 0; i < 3; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("consumer %d : consumed %d at %d", *((int *)cno), item, out);
        out = (out + 1) % buffer_size;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
