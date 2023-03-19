#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


//enum procstate { UNUSED, USED, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

int main(int argc, char *argv[])
{
    printf("Process PID:\t%d\n", getpid());
    printf("Priority:\t0x0%x\n", getpri());
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
    printf("Page Tble Addr:\t%x\n\n", getkstack());

    printf("Testing setpri() and getpri()... for Project #5A\n\n");
    // FOR TESTING PURPOSES OF PROJECT #5A OF SETPRI();
    int test = 0x0A;
    for (int i = 0; i < 6; i++)
    {
        printf("Changing priority to 0x0%x...\n", test);
        setpri(test);
        printf("Priority:\t0x0%x\n", getpri());
        test++;
    }
    
    printf("Change priority to invalid value... 0x12\n");
    setpri(0x12);
    printf("Priority:\t0x0%x\n", getpri());
    return 0;
}