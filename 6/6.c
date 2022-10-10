#include <pthread.h>
#include <stdio.h>  
#include<unistd.h> 

void *thread_func(void *arg)
{
    printf("Running in thread\n");
}

int main()
{
    pthread_t thread_one, thread_two, thread_three;

    
    pthread_create(&thread_one, NULL, thread_func, NULL);
    pthread_create(&thread_two, NULL, thread_func, NULL);
    pthread_create(&thread_three, NULL, thread_func, NULL);

    // Wait for the threads to terminate and then terminate the main process
    pthread_exit(NULL);
    return 0;
}