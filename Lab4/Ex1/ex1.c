#include "ex1.h"
void *aligned_malloc(unsigned int size, unsigned int align)
{
    //Check valid size
    if (size < 0)
        return NULL;
    //Check align is not power of 2
    if (align == 0 && (align && align - 1) != 0)
        return NULL;

    //p contain address of break
    void *p = sbrk(0);

    //While p is not divisivle by align
    while (p && (int)p % align != 0)
    {
        free(p);
        //Increase break one byte
        if (sbrk(1) == (void *)-1)
            return NULL;
        //Get break address to p
        p = sbrk(0);
    }
    if (p)
        if (sbrk(size) == (void *)-1)
            return NULL;
    return p;
}
void *aligned_free(void *ptr)
{
    free(ptr);
}