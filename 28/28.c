#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>    
#include <unistd.h>   

int main()
{
    key_t key;                   
    int id;              
    struct msqid_ds msg;               
    key = ftok(".", 1);

    id = msgget(key, IPC_CREAT | 0700);
    

    printf("Key: %d\n", key);
    printf("Message Queue Identifier: %d\n\n", id);

    msgctl(id, IPC_STAT, &msg);

    printf("Press enter to change the permissions!\n");
    getchar();

    msg.msg_perm.mode = 0577;

    return 0;
}