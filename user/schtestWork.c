#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define ROWS 100000
#define COLS 100000

int main(int argc, char *argv[])
{
    printf("Process %s started (priority 0x%x)\n", argv[2], getpri());
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {}
    }
    printf("Process %s finished (priority 0x%x)\n", argv[2], getpri());
    return 0;
}