#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/shm.h>  
#include <unistd.h>  
#include <stdio.h>

 int main(){
    //1)writing into shared memory
    key_t key;
    int shmid;
    char *data;
    char *read_only;
    key=ftok(".",'f');

    //create shared memory of size 1024 bytes
    shmid=shmget(key,1024,IPC_CREAT|0744);

    //printing the shmid
    printf("The shared memory id is %d\n",shmid);

    //return value of shmat is pointer to the start of shared memory which we can just as char * pointer for reading and writing
    data=(char *)shmat(shmid,0,0);

    sprintf(data,"Hello");

    //reading from shared memory 
    printf("Data from the shared memory is %s\n",data);

    //detaching the shared memory
    printf("Deteaching the pointer to shared memory\n");
    shmdt(data);
    shmdt(read_only);

    //removing the shared memory 
    shmctl(shmid,IPC_RMID,NULL);

    //checking the shared memory sagment 
    execlp("ipcs","ipcs","-m",NULL);

    return 0;

 }
