#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    //Converts the command line argument to an integer
    int PROC_NUM = atoi(argv[1]);
    //Checks for valid input
    if (argc < 2 || PROC_NUM < 1 || PROC_NUM > 64)
    {
        printf("Usage: schtest <number of processes> (1-64)\n");
        exit(1);
    }
    int pid;
    int status;
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
            if(i > 9)
            {
                //Converts i to a string for text output in the child process
                char str[3];
                str[0] = (i/10) + '0';
                str[1] = (i%10) + '0';
                str[2] = '\0';
                char *newArgv[] = {argv[0], argv[1], str};
                exec("schtestWork", newArgv);
                exit(1);
            }
            char str[2];
            str[0] = (i % 10) + '0';
            str[1] = '\0';

            char *newArgv[] = {argv[0], argv[1], str};
            exec("schtestWork", newArgv);
            exit(1);
        }
        //Helps to sync text output since I can't use mutex/semaphores to lock it.
        sleep(2);
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
    //Wait for all children to finish
    for(int i = 0; i < PROC_NUM; i++)
    {
        pid = wait(&status);
    }
    exit(0);
}