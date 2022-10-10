#include <sys/time.h>     
#include <sys/resource.h> 
#include <stdio.h>        

void print(char *text, rlim_t soft, rlim_t hard, char *unit)
{
    printf("%s - \n", text);

    printf("\tSoft Limit: ");
    if (soft == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", soft, unit);

    printf("\tHard Limit: ");
    if (hard == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", hard, unit);

    printf("====================\n");
}

int main()
{
    int status;                   
    struct rlimit resourceLimits; 

    
    status = getrlimit(RLIMIT_AS, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_AS!");
    else
        print("Max size of process's virtual memory", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    status = getrlimit(RLIMIT_CORE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_CORE!");
    else
        print("Max size of a core file", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    
    status = getrlimit(RLIMIT_CPU, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_CPU!");
    else
        print("Max CPU time that the process can consume", resourceLimits.rlim_cur, resourceLimits.rlim_max, "seconds");

    
    status = getrlimit(RLIMIT_DATA, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_DATA!");
    else
        print("Max size of process's data segement", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    
    status = getrlimit(RLIMIT_FSIZE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_FSIZE!");
    else
        print("Max size of files that  the  process  may  create", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    
    status = getrlimit(RLIMIT_LOCKS, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_LOCKS!");
    else
        print("Max number of locks that a process may establish", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    
    status = getrlimit(RLIMIT_MEMLOCK, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_MEMLOCK!");
    else
        print("Max number of bytes of memory that may be locked into RAM", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    
    status = getrlimit(RLIMIT_MSGQUEUE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_MSGQUEUE!");
    else
        print("Max number of bytes of that can be allocated for POSIX message queues", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    
    status = getrlimit(RLIMIT_NICE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_NICE!");
    else
        print("Ceiling of the process's nice value", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    
    status = getrlimit(RLIMIT_NOFILE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_NOFILE!");
    else
        print("Max file descriptor", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    
    status = getrlimit(RLIMIT_NPROC, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_NPROC!");
    else
        print("Limit on the number of threads", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    
    status = getrlimit(RLIMIT_RSS, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_RSS!");
    else
        print("Limit on the  number of virtual pages resident in the RAM", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    
    status = getrlimit(RLIMIT_RTPRIO, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_RTPRIO!");
    else
        print("Ceiling on the real-time priority", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    
    status = getrlimit(RLIMIT_RTTIME, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_RTTIME!");
    else
        print("Amount of CPU time that a  process scheduled  under a real-time scheduling policy", resourceLimits.rlim_cur, resourceLimits.rlim_max, "ms");

    
    status = getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_SIGPENDING!");
    else
        print("The number of signals that may be queued", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    
    status = getrlimit(RLIMIT_SIGPENDING, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_STACK!");
    else
        print("Maximum  size of the process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    return 0;
}