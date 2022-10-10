#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
    int fd1,fd2;
    char buff1[80];
    char buff2[80];
    fd1=open("myfifo1",O_RDONLY);
    fd2=open("myfifo1",O_WRONLY);
    read(fd1,buff1,sizeof(buff2));
    printf("the contetnt of myfifio1 is %s \n", buff1);
    printf("Enter text fro myfifio2\n");
    scanf("%[^\n]",buff2);
    write(fd2,buff2,sizeof(buff2));
    return 0;
}
