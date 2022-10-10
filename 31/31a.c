#include <sys/types.h> 
#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <unistd.h>    
#include <stdio.h>     

int main()
{
    key_t key;
    int id;
    int status;

    union semun {
        int val; // Value of the semaphore
    } semSet;

    key = ftok(".", 'g');
    if (key == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }

    id = semget(key, 1, IPC_CREAT | 0777);

    if(id == -1) {
        perror("Error while creating semaphore!");
        _exit(1);
    }

    semSet.val = 1; // 1 -> binary semaphore

    status = semctl(id, 0, SETVAL, semSet);

    if(status == -1) {
        perror("Error while initalizing semaphore!");
        _exit(0);
    }
    return 0;
}