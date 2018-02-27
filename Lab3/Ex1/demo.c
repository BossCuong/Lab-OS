#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    switch (fork())
    {
    case 0:
        printf("Process ID: %d\n", getpid());
        break;
    default:
        printf("Parent process ID: %d\n", getpid());
        break;
    case -1:
        perror("Fork fail ");
        break;
    }

    return 0;
}