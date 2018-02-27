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

    //Creat process B
    pid_t pid = fork();

    if (pid > 0) //In process A
    {
        wait(NULL);
        //Creat process C
        pid_t pid = fork();

        if (pid > 0) //In process A
        {
            wait(NULL);
            //Creat process D
            pid_t pid = fork();
            if (pid == 0)
                printf("Process D \t%d \t\t%d \n", getpid(), getppid());
            else if (pid == -1)
                printf("error\n");
        }
        if (pid == 0) //In process C
        {
            printf("Process C \t%d \t\t%d \n", getpid(), getppid());

            //Creat process G
            pid_t pid = fork();
            if (pid == 0)
                printf("Process G \t%d \t\t%d \n", getpid(), getppid());
            else if (pid == -1)
                printf("error\n");
        }
    }
    else if (pid == 0) //In process B
    {
        printf("Process B \t%d \t\t%d \n", getpid(), getppid());

        //Creat process E
        pid_t pid = fork();
        if (pid > 0) //In process B
        {
            wait(NULL);
            //Creat process F
            pid_t pid = fork();
            if (pid == 0)
                printf("Process F \t%d \t\t%d \n", getpid(), getppid());
            else if (pid == -1)
                printf("error\n");
        }
        else if (pid == 0) //In process E
        {
            printf("Process E \t%d \t\t%d \n", getpid(), getppid());

            //Creat process I
            pid_t pid = fork();
            if (pid == 0)
                printf("Process I \t%d \t\t%d \n", getpid(), getppid());
            else if (pid == -1)
                printf("error\n");
        }
        else if (pid == -1)
            printf("error\n");
    }
    else if (pid == -1)
        printf("error\n");
}