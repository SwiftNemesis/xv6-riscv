#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, char *argv[])
{
    printf("Process PID:\t " + getpid());
    printf("Memory Used:\t " + getmem());
    printf("Proc State:\t " + getstate());
    printf("Uptime:\t " + uptime());
    printf("Parnet PID:\t " + getparentpid());
    //printf("Page Table Address:\t " + )

}