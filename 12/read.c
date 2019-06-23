#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "read.h"
int read_matrix (const char* name, double* a,int n)
{
    FILE*fp;
    int i;
    if(!(fp=fopen(name,"r")))
        return -1;
    for(i=0;i<n;i++)
       {
            if (fscanf(fp,"%lf",a+i)!=1)
            {
            if(feof(fp))
                {
                fclose(fp);
                return -2;
                }
            }
        }
    fclose(fp);
    return i;
}
#define MAX_N 8
void print_matrix(double* a,int n)
{
    int i,j;
    int n_max=(n>MAX_N?MAX_N:n);
    for(i=0;i<n_max;i++)
    {
        printf("  %.2f",a[i]);
        printf("\n");
    }
}
