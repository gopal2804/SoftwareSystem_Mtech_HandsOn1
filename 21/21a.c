#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
    mkfifo("myfifo1",0777);
    mkfifo("myfifo2",0777);
    int fd1,fd2;
    char buff1[80];
    char buff2[80];
    fd1=open("myfifo1",O_WRONLY);
    fd2=open("myfifo1",O_RDONLY);
    printf("Enter the data for myfifo1\n");
    scanf("%[^\n]",buff1);
    write(fd1,buff1,sizeof(buff1));
    read(fd2,buff2,sizeof(buff2));
    printf("The contetnt of myfifo2 is %s\n",buff2);
    return 0;
}
