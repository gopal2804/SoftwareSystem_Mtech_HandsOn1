#include <signal.h>
#include <stdio.h> 
#include <unistd.h>

void my_handler()
{
    printf("Signal SIGALRM has been caught!\n");
    _exit(0);
}

int main()
{
    __sighandler_t status; 
    alarm(1); //set alarm for 1 sec

    status=signal(SIGALRM, (void *)my_handler);
    if (status == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        while(1); 

    return 0;
        
}