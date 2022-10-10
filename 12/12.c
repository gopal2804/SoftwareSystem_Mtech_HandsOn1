#include <sys/types.h> 
#include <signal.h>    
#include <unistd.h>    
#include <stdio.h>     

int main()
{
    pid_t child_pid, parent_pid;
    int kill_status; 

    child_pid = fork();

    if (child_pid == -1)
        perror("Error while creating child!");
    else if (!child_pid)
    {
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        kill_status = kill(getppid(), SIGKILL);

        if (!kill_status)
        {
            printf("Successfully killed parent!\n");
            sleep(10);
            printf("Child now exiting!\n");
        }
        else
            perror("Error while killing parent!");
    }
    else
    {
        while (1);
    }
    return 0;
}