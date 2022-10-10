#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>    
#include <stdio.h>     
int main()
{
     
    int status;

    status=mkfifo("myfifo_by_mkfifo_libraryFunction",0744);

    if (status == -1)
        perror("Error while creating FIFO file!");
    else
        printf("Succesfully created FIFO file. Check using `ll` or `ls -l` command!\n");
    return 0;
}