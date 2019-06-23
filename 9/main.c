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
    if(!(argc==4||argc==5)||n=atoi(argv[1])<=0||m=atoi(argv[2]))
    {
        printf("Usage %s n <file>\n",argv[0]);
        return 1;
    }
    if(argc==4)
        name1=argv[3];
    if(argc==5)
        name2=argv[4];
    if(!(a=(double*)malloc(n*m*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(!(b=(double*)malloc(n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(!(c=(double*)malloc(m*sizeof(double))))
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
        ret2=read_matrix(name2,b,n,1);
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

    } else init_matrix(b,n,1);
    printf("Matrix A:\n");
    print_matrix(a,n,m);
    printf("Vector B:\n");
    print_vector(b,n);
    t=clock();
    solve(a,b,c,n,m);
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf("Vector C:\n");
    print_vector(c,m);
    printf("Elapse time=%.2f\n",t);
    free(a);
    free(b);
    free(c);
    return 0;
}

