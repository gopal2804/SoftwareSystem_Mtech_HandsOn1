#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
    int fd;
    char buff[80];
    fd=open("myfifo",O_RDONLY);
    read(fd,buff,sizeof(buff));
    printf("The text from fifo file is %s\n",buff);
    return 0;
}
