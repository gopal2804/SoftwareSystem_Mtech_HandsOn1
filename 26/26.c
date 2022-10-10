#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>     
#include <unistd.h>    
#include<string.h>

int main()
{
    struct msg{
        long int m_type;
        char message[80];
    }myq;
    key_t key;                   
    int id;              

    key = ftok(".", 'e');

    id = msgget(key,IPC_CREAT|0777);


    printf("Key: %d\n", key);
    printf("Message Queue id: %d\n\n", id);

    myq.m_type=1;

    printf("Enter message text\n");
    scanf("%[^\n]",myq.message);
    
    int size=strlen(myq.message);
    
    msgsnd(id,&myq,size+1,0);

    return 0;
}