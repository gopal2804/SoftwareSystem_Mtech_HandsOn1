#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd[2];
    pipe(fd);
    pid_t childPid;
    childPid=fork();
    
    if(childPid==0){
        //child process
        close(0); //close STDIN
        fcntl(fd[0],F_DUPFD,0); //STDIN will be reassigned to fd[0]
        close(fd[1]);
        execlp("wc", "wc", NULL); 
    }
    else{
        close(1); //close STDOUT
        fcntl(fd[1],F_DUPFD,1); //STDOUT will be reassigned to fd[1]
        close(fd[0]);
        execlp("ls", "ls", "-l", NULL);       
    }
}