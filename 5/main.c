#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "read.h"
#include "solve.h"
int main(int argc, char** argv)
{
    int n;
    double* a;
    double t;
    if(!(argc==2)||n=atoi(argv[1])<=0)
    {
        printf("Usage %s n <file>\n",argv[0]);
        return 1;
    }
    if(argc==3)
        name=argv[2];
    if(!(a=(double*)malloc(n*n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(name)
    {
        int ret;
        ret=read_matrix(name,a,n);
        if(ret<0)
        {
            switch(ret)
            {
                case -1: printf("Cannot open %s\n",name); break;
                case -2: printf("Cannot read %s\n",name);break;
                default: printf("Unknown error %d in %s\n",ret,name);
            }
            free(a);
            return 3;
        }

    } else init_matrix(a,n);
    printf("Matrix before:\n");
    print_matrix(a,n);
    t=clock();
    solve(a,n);
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf("Matrix after:\n");
    print_matrix(a,n);
    printf("Elapse time=%.2f\n",t);
    free(a);
    return 0;
}
