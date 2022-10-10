#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int main(){
    int fd1[2],fd2[2];
    pipe(fd1);
    pipe(fd2);
    int f1,f2;

    //this child will onyl be used for writing output of "ls -l" to the pipe 1 write end=STDOUT
    f1=fork();
    if(f1==0){
        dup2(fd1[1],1); //write end of pipe 1 --> STDOUT
        close(fd1[0]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("ls","ls","-l",NULL);
    }
    else{
        //this child is responsible for runnig "ls -l | grep ^d" command where input is received from the read end of pipe 1 = STDIN and output is written to the write end of pipe 2 = STDOUT
        f2=fork();
        if(f2==0){
            dup2(fd2[1],1);
            dup2(fd1[0],0);
            close(fd1[1]);
            close(fd2[0]);
            execlp("grep","grep","^d",NULL);
        }
        else{
            //this  parent is responsible for runnig "ls-l | grep ^d | wc" command where input is received from  read-end of pipe 2 -- STDIN and output is written to STDOUT 
            dup2(fd2[0],0);
            close(fd1[0]);
            close(fd1[1]);
            close(fd2[1]);
            execlp("wc","wc",NULL);
        }
    }
}