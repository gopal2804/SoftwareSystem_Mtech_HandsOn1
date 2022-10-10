//fd1 - child can write and parent read
//fd2 - child can read and parent write

#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){

    //declaring the variables
    int fd1[2],fd2[2];
    char buff1[80];
    char buff2[80];

    //opening the pipe
    pipe(fd1);
    pipe(fd2);

    //main logic
    if(!fork()){
        //child process
        close(fd1[0]); //closing read end of child in pipe 1
        close(fd2[1]); //closing write end of child in pipe 2
        printf("enter data you want to send to parent from child\n");
        scanf("%[^\n]",buff1);
        write(fd1[1],buff1,sizeof(buff1));
        printf("data received from the parent end is\n");
        read(fd2[0],buff2,sizeof(buff2));
        printf("%s",buff2);
        printf("\n");
        
    }
    else{

        //parent process
        close(fd1[1]); //closing write end of parent in pipe 1
        close(fd2[0]); //closing read end of parent in pipe 2
        printf("The message received from the child is \n");
        read(fd1[0],buff1,sizeof(buff1));
        printf("%s",buff1);
        printf("\n");
        printf("enter data you want to send to child process\n");
        scanf("%[^\n]",buff2);
        write(fd2[1],buff2,sizeof(buff2));
    }
    return 0;
}