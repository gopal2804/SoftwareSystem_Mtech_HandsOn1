#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/ip.h>

int main(){
    struct sockaddr_in ser;
    int sd;
    char buff[80];

    //creating the raw socket descriptor
    sd=socket(AF_UNIX,SOCK_STREAM,0);

    //specify the destination address of socket
    ser.sin_addr.s_addr=INADDR_ANY;
    ser.sin_port=htons(3558);
    ser.sin_family=AF_UNIX;

    //connect client socket sd to server
    connect(sd,(void *)(&ser),sizeof(ser));

    //now connectioin is established

    //sending msg to server
    write(sd,"Hello server\n",17); 

    //receiving msg from the server
    read(sd,buff,sizeof(buff));
    printf("Message from the server is\n");
    printf("%s",buff);
    printf("\n");

    return 0;
}