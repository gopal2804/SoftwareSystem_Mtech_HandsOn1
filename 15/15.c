#include<stdio.h>
#include<unistd.h>
int main(){
    int fd[2];
    char buff[80];
    pipe(fd);
    if(fork()){
        printf("you are in the parent process\n");
        printf("enter data that you want to send to child process using pipe\n");
        scanf("%[^\n]",buff);
        write(fd[1],buff,sizeof(buff));
        printf("out of parent process\n");
    }
    else{
        printf("you are in the child process\n");
        printf("the data received from the parent is \n");
        read(fd[0],buff,sizeof(buff));
        printf("%s",buff);
        printf("\n");
        printf("out of the child process\n");
    }
    return 0;
}