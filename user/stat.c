#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


//enum procstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

int main(int argc, char *argv[])
{
    printf("Process PID:\t%d\n", getpid());
    printf("Memory Used:\t%d\n", getmem());
    int temp = getstate();
    switch(temp)
    {
        case 0:
            printf("Proc State:\tUNUSED\n");
            break;
        case 1:
            printf("Proc State:\tUSED\n");
            break;
        case 2:
            printf("Proc State:\tSLEEPING\n");
            break;
        case 3:
            printf("Proc State:\tRUNNABLE\n");
            break;
        case 4:
            printf("Proc State:\tRUNNING\n");
            break;
        case 5:
            printf("Proc State:\tZOMBIE\n");
            break;
    }
    printf("Uptime (ticks):\t%d\n", uptime());
    printf("Parnet PID:\t%d\n", getparentpid());
    printf("Page Tble Addr:\t%x\n", getkstack());
    return 0;
}