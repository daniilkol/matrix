#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double sinx(double x,double e)
{
    int i=0;
    double ak=x,s=0;
    while(fabs(ak)>e)
    {
        s+=ak;
        ak*=(-x*x)/((2*i+2)*(2*i+3));
        i++;
    }
    return s;
}
double cosx(double x,double e)
{
    int i=0;
    double ak=1,s=0;
    while(fabs(ak)>e)
    {
        s+=ak;
        ak*=(-x*x)/((2*i+1)*(2*i+2));
        i++;
    }
    return s;
}
double solve(double x,double e)
{
    double p=floor(x/(2*M_PI));
    x=x-2*M_PI*p;
    if(x>M_PI)
    {
        x=x-M_PI;
        if(x>M_PI/2)
        {
            x=x-M_PI/2;
            if(x>M_PI/4)
            {
                x=x-M_PI/4;
                return -1*(cosx(x,e)*cos(M_PI/4)-sinx(x,e)*sin(M_PI/4));
            }
            return -1*cosx(x,e);
        }
        if(x>M_PI/4)
            {
                x=x-M_PI/4;
                return -1*(cosx(x,e)*sin(M_PI/4)+sinx(x,e)*cos(M_PI/4));
            }
            return -1*sinx(x,e);

    }
    if(x>M_PI/2)
    {
            x=x-M_PI/2;
            if(x>M_PI/4)
            {
                x=x-M_PI/4;
                return cosx(x,e)*cos(M_PI/4)-sinx(x,e)*sin(M_PI/4);
            }
            return cosx(x,e);
    }
    if(x>M_PI/4)
    {
                x=x-M_PI/4;
                return cosx(x,e)*sin(M_PI/4)+sinx(x,e)*cos(M_PI/4);
    }
    return sinx(x,e);
}
