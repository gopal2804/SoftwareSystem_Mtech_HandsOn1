#include <signal.h> 
#include <stdio.h>  
#include <unistd.h> 

void handler()
{
    printf("\nSignal SIGINT has been caught!\n");
}

int main()
{
    __sighandler_t status; 

    printf("SIGINT will be ignored for 5 seconds\n");
    status = signal(SIGINT, SIG_IGN);
    if(status == SIG_ERR)
        perror("Error while trying to ignore signal!");
    else 
        sleep(5);

    printf("SIGINT will now be caught!\n");
    status = signal(SIGINT, (void *)handler);
    if (status == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        sleep(5);

   
    return 0;
}