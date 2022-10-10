#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main(){
    int fd;
    fd=open("myfifo",O_WRONLY);
    char buff[80];
    printf("Enter data\n");
    scanf("%[^\n]",buff);
    write(fd,buff,sizeof(buff));
    return 0;
}