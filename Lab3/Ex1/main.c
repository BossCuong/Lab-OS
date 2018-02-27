#include "file.h"
#include <unistd.h>

#define MAX_SIZE 1000
int main(int argc, char *argv[])
{
    int arr[MAX_SIZE];
    int size;
    readFile(argv[1], arr, &size);

    pid_t pid = fork();
    int cnt = 0;
    if (pid == 0)
    {
        for (int i = 0; i < 10; ++i)
            if ((arr[i] % 3) == 0) ++cnt;
        printf("%d\n", cnt);
    }
    else if (pid > 0)
    {
        for (int i = 0; i < 10; ++i)
            if ((arr[i] % 2) == 0) ++cnt;
        printf("%d\n", cnt);
    }
    else if (pid == -1)
        printf("error\n");
}
