#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "solve.h"
int main()
{
    double t,x,e,res,p;
    printf("Input x and e:\n");
    if(scanf("%lf%lf",&x,&e)!=2)
    {
        printf("Cannot read!\n");
        return 1;
    }
    p=log(x);
    t=clock();
    res=solve(x,e);
    t=(clock()-t)/CLOCKS_PER_SEC;
    printf("OTVET:%.6f\n",res);
    printf("Real:%.6f\n",p);
    printf("Raznica:%.6f\n",fabs(p-res));
    printf("Elapse time=%.2f\n",t);
    return 0;
}


