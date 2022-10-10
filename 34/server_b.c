#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdio.h>      
#include <unistd.h>     
#include <pthread.h>    


void *communicate(int *fd)
{

    ssize_t readBytes, writeBytes;
    char dataFromClient[100];

    writeBytes = write(*fd, "I'm the server!", 15);
    if (writeBytes == -1)
        perror("Error while writing to network via socket!");
    else
        printf("Data sent to client!\n");

    readBytes = read(*fd, dataFromClient, 100);
    if (readBytes == -1)
        perror("Error while reading from network via socket!");
    else
        printf("Data from client: %s\n", dataFromClient);

    close(*fd);
}

int main()
{
    int sd, nsd;
    int client_size;

    struct sockaddr_in server, client;

    pthread_t thread;

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1)
    {
        perror("Error while creating socket!");
        _exit(0);
    }
    printf("Server side socket successfully created!\n");

    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    bind(sd, (void *)&server, sizeof(server));
    printf("Binding to socket was successful!\n");

    listen(sd, 2);
    printf("Now listening for connections on a socket!\n");

    while (1)
    {
        client_size = (int)sizeof(client);
        nsd = accept(sd, (void *)&client, &client_size);
        if (nsd == -1)
            perror("Error while accepting a connection!");
        else
        {   
            pthread_create(&thread, NULL, (void *)communicate, &nsd);
        }
    }

    close(sd);

    return 0;
}