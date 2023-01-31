#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Time completed in 0 ticks\n");
        exit(0);
    }

    int pid = fork();
    int currentTime = uptime();

    if(pid < 0)
    {
        printf("Fork Failed\n");
        exit(1);
    }
    else if (pid == 0) 
    {
        exec(argv[1], argv+1);
        printf("Execution error, %s is not a program.\n", argv[1]);
        exit(1);
    }
    else
    {
        wait(0);
        int programTime = uptime();
        programTime -= currentTime;
        printf("Real-time in ticks: %d\n", programTime);
        exit(0);
    }

    exit(0);
}