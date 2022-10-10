#include <sys/time.h>     
#include <sys/resource.h> 
#include <stdio.h>        

void print(char *text, rlim_t soft, rlim_t hard, char *unit)
{
    printf("%s - \n", text);

    printf("\tSoft Limit: ");
    if (soft == RLIM_INFINITY)
        printf("Infinite\n");
    else
        printf("%ld %s\n", soft, unit);

    printf("\tHard Limit: ");
    if (hard == RLIM_INFINITY)
        printf("Infinite\n");
    else
        printf("%ld %s\n", hard, unit);

    printf("====================\n");
}

int main()
{
    int status;                   
    struct rlimit resourceLimits; 

    // RLIMIT_CORE -> Max size of a core file
    status = getrlimit(RLIMIT_CORE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_CORE!");
    else
        print("Max size of a core file", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // New soft limit
    resourceLimits.rlim_cur = 4096; // bytes

    status = setrlimit(RLIMIT_CORE, &resourceLimits);
    if (status == -1)
        perror("Error while setting RLIMIT_CORE!");
    else
    {
        status = getrlimit(RLIMIT_CORE, &resourceLimits);
        if (status == -1)
            perror("Error while getting RLIMIT_CORE!");
        else
            print("Max size of a core file", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    }
    return 0;
}