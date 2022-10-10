#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>     
#include <unistd.h>    

int main()
{
    key_t key;                   
    int id; 
    struct msqid_ds messageQueueInfo; 
    int msgctlStatus;                 

    key = ftok(".", 1);

    id = msgget(key, IPC_CREAT | 0700);


    printf("Key: %d\n", key);
    printf("Message Queue id: %d\n\n", id);

    msgctlStatus = msgctl(id, IPC_STAT, &messageQueueInfo);

    if (msgctlStatus == -1)
    {
        perror("Error while getting Message Queue info!");
        _exit(0);
    }

    printf("Access Permission: %od\n", messageQueueInfo.msg_perm.mode);
    printf("UID: %d\n", messageQueueInfo.msg_perm.uid);
    printf("GID: %d\n", messageQueueInfo.msg_perm.gid);
    printf("Time of last message sent: %ld\n", messageQueueInfo.msg_stime);
    printf("Time of last message received: %ld\n", messageQueueInfo.msg_rtime);
    printf("Size of queue: %ld\n", messageQueueInfo.__msg_cbytes);
    printf("Number of messages in the queue: %ld\n", messageQueueInfo.msg_qnum);
    printf("Maximum number of bytes allowed in the queue: %ld\n", messageQueueInfo.msg_qbytes);
    printf("PID of last sent message: %d\n", messageQueueInfo.msg_lspid);
    printf("PID of last received message: %d\n", messageQueueInfo.msg_lrpid);
    return 0;
}