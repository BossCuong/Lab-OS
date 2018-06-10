#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>'
#define THREAD_NUM 1
unsigned int number_of_point_in_Circle;

void generate_point(void *param)
{
    unsigned int num_generate = *(unsigned int*)param;
    for (int i = 0; i < num_generate; ++i)
    {
        double x = -1.0 + ((double)rand() / RAND_MAX) * 2.0; //float in range -1 to 1
        double y = -1.0 + ((double)rand() / RAND_MAX) * 2.0; //float in range -1 to 1

        if ((x * x + y * y) <= 1)
            number_of_point_in_Circle++;
    }
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    //Total number of point
    unsigned int number_of_point = atoi(argv[1]);
    //Point to be generate for each thread
    unsigned int num_generate = number_of_point / THREAD_NUM;

    pthread_t threads[THREAD_NUM];

    //Creating N threads
    for (int i = 0; i < THREAD_NUM; ++i)
        pthread_create(&threads[i], NULL, generate_point, (void *)&num_generate);
    

    //Suspend until all thread done
    for (int i = 0; i < THREAD_NUM; ++i)
        pthread_join(threads[i], NULL);
    
    double pi;
    pi = 4 * ((double)number_of_point_in_Circle / number_of_point);
    printf("Pi is %f", pi);
    pthread_exit(NULL);
}
