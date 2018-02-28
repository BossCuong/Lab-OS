#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, int *argv[])
{
    printf("Name\t\tID\t\tParent ID\n");
    printf("--------------------------------------------\n");
    //Process A
    printf("Process A \t%d \t\t%d \n", getpid(), getppid());

    pid_t pid = fork(); //Creat process B

    if (pid == 0) //Process B
    {
        printf("Process B \t%d \t\t%d \n", getpid(), getppid());

        pid_t pid = fork(); //Creat process E

        if (pid == 0) //Process E
        {
            printf("Process E \t%d \t\t%d \n", getpid(), getppid());

            pid_t pid = fork(); //Creat process I

            if (pid == 0)
                printf("Process I \t%d \t\t%d \n", getpid(), getppid());
            else if (pid == -1)
                printf("error\n");
        }
        else if (pid > 0) //Process B
        {
            wait(NULL);

            pid_t pid = fork(); //Creat process F

            if (pid == 0)
                printf("Process F \t%d \t\t%d \n", getpid(), getppid());
            else if (pid == -1)
                printf("error\n");
        }
        else if (pid == -1)
            printf("error\n");
    }
    else if (pid > 0) //Process A
    {
        wait(NULL);

        pid_t pid = fork(); //Creat process C

        if (pid == 0) //In process C
        {
            printf("Process C \t%d \t\t%d \n", getpid(), getppid());

            pid_t pid = fork(); //Creat process G

            if (pid == 0)
                printf("Process G \t%d \t\t%d \n", getpid(), getppid());
            else if (pid == -1)
                printf("error\n");
        }
        else if (pid > 0) //Process A
        {
            wait(NULL);

            pid_t pid = fork(); //Creat process D

            if (pid == 0)
                printf("Process D \t%d \t\t%d \n", getpid(), getppid());
            else if (pid == -1)
                printf("error\n");
        }
    }
    else if (pid == -1)
        printf("error\n");
}
