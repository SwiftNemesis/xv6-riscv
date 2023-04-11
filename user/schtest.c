#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define ROWS 100000
#define COLS 100000

int math(int procnum)
{
    printf("Process %d started (priority 0x%x)\n", procnum, getpri());
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {}
    }
    printf("Process %d finished (priority 0x%x)\n", procnum, getpri());
    return 0;
}

int main(int argc, char *argv[])
{
    //Converts the command line argument to an integer
    int PROC_NUM = atoi(argv[1]);
    //Checks for valid input
    if (argc < 2 || PROC_NUM < 1 || PROC_NUM > 60)
    {
        printf("Usage: schtest <number of processes> (1-60)\n");
        exit(1);
    }
    int pid;
    int prio = 0x0C;
    //Forks the number of processes specified by the user
    for (int i = 0; i < PROC_NUM; i++)
    {
        pid = fork();
        if(pid < 0)
        {
            printf("Fork Failed\n");
            exit(1);
        }
        else if (pid == 0)
        {
            setpri(prio);
            math(i);
            exit(0);
        }
        prio++;
        if(prio > 0x0F)
        {
            prio = 0x0A;
        }
        else if (prio == 0x0E)
        {
            prio = 0x0F;
        }
    }
    for(int i = 0; i < PROC_NUM; i++)
    {
        wait(&pid);
    }
    return 0;
}