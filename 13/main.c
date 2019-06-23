#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "read.h"
#include "solve.h"
int main()
{
    const char *name1="a.txt";
    const char *name2="b.txt";
    int n,ret1,ret2;
    double* x;
    double* y;
    double t,x0,res;
    printf("Input n and x0:\n");
    if(scanf("%d%lf",&n,&x0)!=2)
    {
        printf("Cannot read!\n");
        return 1;
    }
    if(!(x=(double*)malloc(n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    if(!(y=(double*)malloc(n*sizeof(double))))
    {
        printf("Not enough memory");
        return 2;
    }
    ret1=read_matrix(name1,x,n);
            if(ret1<0)
            {
                switch (ret1)
                {
                    case -1:
                        printf("Cannot open%s\n",name1);
                        break;
                    case -2:
                        printf("Cannot read%s\n",name1);
                        break;
                    default:
                        printf("Unknown error%s\n",name1);
                        break;
                }
                free(x);
                return 3;
            }
    ret2=read_matrix(name2,y,n);
            if(ret2<0)
            {
                switch (ret2)
                {
                    case -1:
                        printf("Cannot open%s\n",name2);
                        break;
                    case -2:
                        printf("Cannot read%s\n",name2);
                        break;
                    default:
                        printf("Unknown error%s\n",name2);
                        break;
                }
                free(y);
                return 3;
            }

    printf("X:\n");
    print_matrix(x,n);
    printf("Y:\n");
    print_matrix(y,n);
    t=clock();
    res=solve(x,y,n,x0);
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf("OTVET:%.2lf\n",res);
    printf("Elapse time=%.2f\n",t);
    free(x);
    free(y);
    return 0;
}
