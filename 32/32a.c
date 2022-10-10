#include <sys/ipc.h>   
#include <sys/sem.h>   
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     

int main()
{
    int fd;            // File descriptor of the ticket file
    ssize_t readBytes, writeBytes; // Number of bytes read from / written to the ticket file
    off_t lseekOffset;
    int data; // Ticket data

    key_t key;      // Semaphore Key
    int id; // Semaphore Identifier
    int semctlStatus;  // Determines success of `semctl` call
    int semopStatus;   // Determines success of `semop` call

    // Create a new ticket file / open an exisiting one
    fd = open("ticket.txt", O_CREAT | O_RDWR, S_IRWXU);
    if (fd == -1)
    {
        perror("Error while creating / opening the ticket file!");
        _exit(0);
    }

    // Defines a semaphore's structure
    union semun
    {
        int val;               // Value of the semaphore
        struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
        unsigned short *array; /* Array for GETALL, SETALL */
        struct seminfo *__buf; /* Buffer for IPC_INFO (Linux-specific) */
    } semSet;

    key = ftok(".", 331);
    if (key == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }

    id = semget(key, 1, 0); // Get the semaphore if it exists
    if (id == -1)
    {
        id = semget(key, 1, IPC_CREAT | 0700); // Create a new semaphore 
        if (id == -1)
        {
            perror("Error while creating semaphore!");
            _exit(1);
        }

        semSet.val = 1; // Set a binary semaphore
        semctlStatus = semctl(id, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            perror("Error while initializing a binary sempahore!");
            _exit(1);
        }
    }

    struct sembuf semOp; // Defines the operation on the semaphore
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Press enter to obtain lock on the critical section\n");
    getchar();
    // Use semaphore to lock the critical section
    semOp.sem_op = -1;
    semopStatus = semop(id, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }
    
    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");
    // =========== Start of Critical Section ===========

    readBytes = read(fd, &data, sizeof(data));
    if (readBytes == -1)
    {
        perror("Error while reading from ticket file!");
        _exit(0);
    }
    else if (readBytes == 0) // Ticket file has no data
        data = 1;
    else
    {
        data += 1;
        lseekOffset = lseek(fd, 0, SEEK_SET);
        if (lseekOffset == -1)
        {
            perror("Error while seeking!");
            _exit(0);
        }
    }

    writeBytes = write(fd, &data, sizeof(data));
    if (writeBytes == -1)
    {
        perror("Error while writing to ticket file!");
        _exit(1);
    }

    printf("Your ticker number is - %d\n", data);

    printf("Press enter to exit from critical section!\n");
    getchar();

    // =========== End of Critical Section =============

    // Use semaphore to unlock the critical section
    semOp.sem_op = 1;
    semopStatus = semop(id, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }
    close(fd);
}