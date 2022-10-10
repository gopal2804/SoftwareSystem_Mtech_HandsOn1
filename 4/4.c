#include <sys/time.h>  
#include <sys/types.h> 
#include <unistd.h>    
#include <stdio.h>     

// Import for __rdtsc()
#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

int main()
{
    int start, end, pid;
    int i = 0;

    start = __rdtsc();
    while(i < 100) {
        pid = getpid();
        i++;
    }
    end = __rdtsc();

    printf("Pid of the process is: %d\n", pid);
    printf("Time taken : %d ns \n", (end - start));
    return 0;
}