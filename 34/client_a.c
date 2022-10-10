#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>

void main()
{
    int sd;

    struct sockaddr_in server;

    ssize_t readBytes, writeBytes;
    char dataFromServer[100];

    sd = socket(AF_INET, SOCK_STREAM, 0);
    printf("Client side socket successfully created!\n");

    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    connect(sd, (void *)&server, sizeof(server));
    printf("Client to serrver connection successfully established!\n");

    readBytes = read(sd, dataFromServer, 100);
    if (readBytes == -1)
        perror("Error while reading from network via socket!");
    else
        printf("Data from server: %s\n", dataFromServer);

    writeBytes = write(sd, "I'm the client!", 15);
    if (writeBytes == -1)
        perror("Error while writing to network via socket!");
    else
        printf("Data sent to server!");

    close(sd);
}