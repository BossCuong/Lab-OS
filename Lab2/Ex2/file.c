#include "file.h"
void readFile()
{ 
    FILE* fp;
    int n1,n2,n3,n4;

    fp = fopen("input.txt","r");
    
    while(fscanf(fp,"%d %d %d %d",&n1,&n2,&n3,&n4) != EOF)
    {
        printf("%d %d %d %d\n",n1,n2,n3,n4);
    }

    fclose(fp);
}