#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    int fd[2];
    pipe(fd);
    pid_t childPid;
    childPid=fork();
    
    if(childPid==0){
        //child is used responsible for running the ls -l | wc command where input is recieved from the read end of pipe
        //child process 
        close(0); //close STDIN
        dup(fd[0]); //STDIN will be reassigned to fd[0]
        close(fd[1]);
        execlp("wc", "wc", NULL); 
    }
    else{
        //parent is used for writing the output of ls -l command to the pipe write end -- STDOUT
        close(1); //close STDOUT
        dup(fd[1]); //STDOUT will be reassigned to fd[1]
        close(fd[0]);
        execlp("ls", "ls", "-l", NULL);       
    }
}