#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double stepen (int k)
{
    int i;
    double e=1;
    for (i=1;i<=k;i++)
        e*=M_E;
    return e;

}
double solve(double x,double e)
{
    int i=1,t;
    double ak=1,s=0;
    if(x>0)
    {
        t=(int)x;
        x=x-t;
        while (fabs(ak)>e)
        {
                s+=ak;
                ak*=x/i;
                i++;
        }

        return s*stepen(t);
    }
    if(x<0)
    {
        x=fabs(x);
        t=(int)x;
        x=x-t;
        while (fabs(ak)>e)
        {
                s+=ak;
                ak*=x/i;
                i++;
        }

        return 1/(s*stepen(t));

    }

    return 1.0;

}
