#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    int fd[2];
    pipe(fd);
    pid_t childPid;
    childPid=fork();
    
    if(childPid==0){
        //child process
        dup2(fd[0],0); //STDIN will be reassigned to fd[0]
        close(fd[1]);
        execlp("wc", "wc", NULL); 
    }
    else{
        dup2(fd[1],1); //STDOUT will be reassigned to fd[1]
        close(fd[0]);
        execlp("ls", "ls", "-l", NULL);       
    }
}