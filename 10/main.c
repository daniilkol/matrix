#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "read.h"
#include "solve.h"
int main(int argc, char** argv)
{
    int n,m,i,j;
    double* a;
    double* b;
    double* c;
    double t;
    if(!(argc==5||argc==6)||n=atoi(argv[1])<=0||m=atoi(argv[2])||k=atoi(argv[3])<=0)
    {
        printf("Usage %s n <file>\n",argv[0]);
        return 1;
    }
    if(argc==5)
        name1=argv[4];
    if(argc==6)
        name2=argv[5];
    if(!(a=(double*)malloc(m*n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(!(b=(double*)malloc(n*k*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(!(c=(double*)malloc(m*k*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(name1)
    {
        int ret1;
        ret1=read_matrix(name1,a,n,m);
        if(ret1<0)
        {
            switch(ret1)
            {
                case -1: printf("Cannot open %s\n",name1); break;
                case -2: printf("Cannot read %s\n",name1);break;
                default: printf("Unknown error %d in %s\n",ret1,name1);
            }
            free(a);
            return 3;
        }

    } else init_matrix(a,n,m);
    if(name2)
    {
        int ret2;
        ret2=read_matrix(name2,b,n,k);
        if(ret2<0)
        {
            switch(ret2)
            {
                case -1: printf("Cannot open %s\n",name2); break;
                case -2: printf("Cannot read %s\n",name2);break;
                default: printf("Unknown error %d in %s\n",ret2,name2);
            }
            free(b);
            return 3;
        }

    } else init_matrix(b,n,k);
    printf("Matrix A:\n");
    print_matrix(a,n,m);
    printf("MATRIX B:\n");
    print_vector(b,k,n);
    t=clock();
    solve(a,b,c,n,m,k);
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf("MATRIX C:\n");
    print_vector(c,k,m);
    printf("Elapse time=%.2f\n",t);
    free(a);
    free(b);
    free(c);
    return 0;
}

