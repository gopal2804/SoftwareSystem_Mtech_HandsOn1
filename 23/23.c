#include<stdio.h>
#include<unistd.h>
int main(){
    long PIPE_BUF,OPEN_MAX;
    PIPE_BUF=pathconf(".",_PC_PIPE_BUF);
    OPEN_MAX=sysconf(_SC_OPEN_MAX);
    printf("maximum number of files can be openend within a process is %ld: \n",OPEN_MAX);
    printf("maximun amount of data that can be written to the pipe of fifo is %ld: \n",PIPE_BUF);
    return 0;
}