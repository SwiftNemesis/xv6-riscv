#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[])
{
    if(argc > 2)
    {
        printf("Too many arguments, example format: time ARGUMENT.");
        return 1;
    }
    else if(argc < 2)
    {
        printf("Not enough arguments, example format: time ARGUMENT.");
    }

    int pid = fork();
    int currentTime = uptime();

    if(pid < 0)
    {
        printf("Fork Failed");
        return 1;
    }
    if (pid == 0) 
    {
        exec(argv[1], argv+1);
        return 0;
    }
    if (pid > 0)
    {
        wait(0);
        int programTime = uptime();
        programTime = programTime - currentTime;
        printf("%s completed in %d ticks\n", argv[1], programTime);
        return 0;
    }

    return 0;
}