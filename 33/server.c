#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/ip.h>

int main(){
    struct sockaddr_in ser,cli;
    int sd,nsd;
    char buff[80];

    //creating the raw socket descriptor
    sd=socket(AF_UNIX,SOCK_STREAM,0);

    //specify the destination address of socket
    ser.sin_addr.s_addr=INADDR_ANY;
    ser.sin_port=htons(3558);
    ser.sin_family=AF_UNIX;

    //now server will be created
    bind(sd,(void *)(&ser),sizeof(ser));

    //5 is size of the wait queue for connection
    listen(sd,5);

    //accept connection from client and put its details in client
    //server will wait at tgis line till a client connects with proper IP address and port number
    int client=(int)(sizeof(cli));
    nsd=accept(sd,(void *)(&cli),&client);


    //now connection is established

    //reading data received from the client
    read(nsd,buff,sizeof(buff));
    printf("Message from the client is \n");
    printf("%s\n",buff);

    //sending message to client
    write(nsd,"Ack from Server\n",17);

    return 0;

}