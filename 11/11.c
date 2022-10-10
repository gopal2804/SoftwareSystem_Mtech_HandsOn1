#include <signal.h> 
#include <stdio.h>  
#include <unistd.h> 

void handler(int sig_num)
{
    printf("Caught signal SIGINT, SIGINT number is (%d)\n", sig_num);
}

int main()
{
    int status; 
    struct sigaction action;

    
    printf("Ignoring SIGINT for 5 seconds!\n");
    action.sa_handler = SIG_IGN;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);


    
    printf("Handling SIGINT for 5 seconds!\n");
    action.sa_handler = handler;
    action.sa_flags = 0;
    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);

    return 0;
}