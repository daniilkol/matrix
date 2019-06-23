#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "solve.h"
#include "solve.c"
int main()
{
    double t,x,e,res,p;
    printf("Input x and e:\n");
    if(scanf("%lf%lf",&x,&e)!=2)
    {
        printf("Cannot read!\n");
        return 1;
    }
    p=sin(x);
    if(x>=0)
    {
        t=clock();
        res=solve(x,e);
        t=(clock()-t)/CLOCKS_PER_SEC;
    } else
        {
            t=clock();
            res=-1*solve(fabs(x),e);
            t=(clock()-t)/CLOCKS_PER_SEC;
        }
    printf("OTVET:%.6lf\n",res);
    printf("Real:%.6lf\n",p);
    printf("Raznica:%.6lf\n",fabs(p-res));
    printf("Elapse time=%.2f\n",t);
    return 0;
}


