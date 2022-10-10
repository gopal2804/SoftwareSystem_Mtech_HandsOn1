#include <signal.h> 
#include <unistd.h> 
#include <stdio.h>  
#include <stdlib.h> 

void handler()
{
    printf("Received SIGSTOP signal!\n");
    _exit(0);
}

int main()
{
    __sighandler_t status;
    pid_t pid = getpid();

    printf("Process ID: %d\n", pid);

    status = signal(SIGSTOP, handler);
    if (status == SIG_ERR)
        perror("Error while catching signal!");

    printf("Putting the process to sleep for 30s\n");
    sleep(30);
    return 0;
}

