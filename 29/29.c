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

    printf("Press enter to change the permissions!\n");
    getchar();

    msgctl(id, IPC_RMID, &msg);
    
    return 0;
}