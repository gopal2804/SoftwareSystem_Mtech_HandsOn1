#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main(){
    fd_set rfds;
    struct timeval tv;
    tv.tv_sec=10;
    mkfifo("myfifo",0777);
    int fd;
    fd=open("myfifo",O_RDONLY);
    FD_ZERO(&rfds);
    FD_SET(fd,&rfds);
    if(!select(fd+1,&rfds,NULL,NULL ,&tv)){
        printf("No data is available for reading yet\n");
    }
    else{
        printf("Data is available now\n");
    }
    //do other task
    return 0;
}