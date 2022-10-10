#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
    mkfifo("myfifo",0777);
    int fd;
    char buff[80];
    fd=open("myfifo",O_WRONLY);
    printf("Enter the data\n");
    scanf("%[^\n]",buff);
    write(fd,buff,sizeof(buff));
    return 0;
}
