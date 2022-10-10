#include <sys/types.h>
#include <signal.h>   
#include <unistd.h>   
#include <stdio.h>    
#include <stdlib.h> 

int main(int argc, char *argv[])
{
    int killStatus; 
    pid_t pid;

    if (argc != 2)
    {
        printf("Pass the PID of the process to whom the SIGSTOP signal is to be sent!\n");
        _exit(0);
    }

    pid = atoi(argv[1]);

    killStatus = kill(pid, SIGSTOP);

    if(!killStatus) 
        printf("Successfully sent SIGSTOP signal to process (%d)\n", pid);
    else 
        perror("Error while sending signal!");
    return 0;
}