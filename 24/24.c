#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>     
#include <unistd.h>   
int main()
{
    key_t key;
    int id;
    key=ftok(".",'a');
    id=msgget(key,IPC_CREAT|IPC_EXCL|0777);
    printf("The key of the message queue is %d \n",key);
    printf("The message queue id is %d\n",id);
    return 0;
}