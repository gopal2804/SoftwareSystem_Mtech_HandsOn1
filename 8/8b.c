#include <signal.h>
#include <stdio.h> 
#include <unistd.h>

void my_handler()
{
    printf("Signal SIGINT has been caught!\n");
    _exit(0);
}

int main()
{
    __sighandler_t status; 

    status=signal(SIGINT, (void *)my_handler);
    if (status == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGINT);

    return 0;
        
}