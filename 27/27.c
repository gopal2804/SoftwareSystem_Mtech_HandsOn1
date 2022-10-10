#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/msg.h>   
#include <stdio.h>     
#include <unistd.h>    
#include<string.h>
#include<stdlib.h>

int main() {

struct msg {
long int m_type;
char message[80];
} myq;

key_t key;
int mqid;

key = ftok(".", 'e');
mqid = msgget(key, 0);

myq.m_type=1;

int ret;
ret = msgrcv(mqid, &myq, sizeof(myq.message), myq.m_type,
IPC_NOWAIT);

printf("Message type: %ld\n Message: %s\n", myq.m_type, myq.message);
}