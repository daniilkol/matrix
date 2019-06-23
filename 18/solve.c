#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double solve(double x,double e)
{
    int i=1,p;
    double ak,s=0;
    x=frexp(x,&p);
    ak=x-1;
    while (fabs(ak)>e)
    {
        s+=ak;
        ak*=(i/(i+1))*(1-x);
        i++;
    }
    return s+p*M_LN2;

}
