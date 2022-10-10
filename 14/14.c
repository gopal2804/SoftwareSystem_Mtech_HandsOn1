#include<stdio.h>
#include<unistd.h>

int main(){
    int fd[2];
    int pipe_status;
    char buff[80];
    pipe_status=pipe(fd);
    if(pipe_status==-1){
        perror("error while creating the pipe");
    }
    else{
        printf("Enter the data to be written in the write end of the pipe\n");
        scanf("%[^\n]",buff);
        write(fd[1],buff,sizeof(buff));
        printf("The data read from the pipe read end is\n");
        read(fd[0],buff,sizeof(buff));
        printf("%s",buff);
        printf("\n");
    }
    return 0;
}