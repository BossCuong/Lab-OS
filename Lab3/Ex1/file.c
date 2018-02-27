#include "file.h"
void readFile(char* fname,int *arr,int* size)
{ 
    FILE* fp;
    int n1,i;

    fp = fopen(fname,"r");
    
    while(fscanf(fp,"%d",&n1) != EOF)
    {
        arr[i] = n1;
        ++i;
    }
    *size = i + 1;
    fclose(fp);
}