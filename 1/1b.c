#include <sys/time.h> 
#include <signal.h>   
#include <unistd.h>   
#include <stdio.h>    

int main(int argc, char *argv[])
{
    int status; // Determines success of `setitimer` call

    struct itimerval time;

    if (argc != 2)
    {
        printf("Pass 1 for 10s timer or 2 for 10us timer\n");
        _exit(0);
    }

    if ((int)(*argv[1] - 48) == 1)
    {
        // Setting a interval timer for 10s
        time.it_interval.tv_sec = 0;
        time.it_interval.tv_usec = 0;
        time.it_value.tv_sec = 10;
        time.it_value.tv_usec = 0;
    }
    else if ((int)(*argv[1] - 48) == 2)
    {
        // Setting a interval timer for 10us
        time.it_interval.tv_sec = 0;
        time.it_interval.tv_usec = 0;
        time.it_value.tv_sec = 0;
        time.it_value.tv_usec = 10;
    }

    status = setitimer(ITIMER_VIRTUAL, &time, 0);
    if (status == -1)
        perror("Error while setting an interval timer!");

    while(1);
    
    return 0;
}