#include <pthread.h> 
#include <stdio.h>   

void *thread_func(void *arg)
{
    printf("Running thread ID is: %lu\n", pthread_self());
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, thread_func, NULL);

    pthread_exit(NULL);

    return 0;
}