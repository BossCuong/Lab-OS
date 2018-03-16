#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"
int main()
{
    int *p;
    size_t size = 16, align = 64;
    p = aligned_malloc(size, align);

    if (!p)
        printf("Fail\n");
    else
        printf("Address : %p | In int is %d mod %d = % d\n", p, (int)p, align, (int)p % align);
    return 0;
}
