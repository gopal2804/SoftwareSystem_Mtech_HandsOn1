#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     
int main()
{
     
    int status;

    status=mknod("myfifo_by_mknod_systemCall",S_IFIFO|S_IRWXU,0);

    if (status == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");
    return 0;
}