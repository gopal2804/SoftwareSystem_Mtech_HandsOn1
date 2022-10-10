#include <signal.h>
#include <stdio.h> 
#include <unistd.h>

void my_handler()
{
    printf("Signal SIGSEGV has been caught!\n");
    _exit(0);
}

int main()
{
    __sighandler_t status; 

    status=signal(SIGSEGV, (void *)my_handler);
    if (status == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGSEGV); // Send segmentation fault signal

    return 0;
        
}